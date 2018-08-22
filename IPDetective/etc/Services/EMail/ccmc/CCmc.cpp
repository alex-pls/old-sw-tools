/*
Module : CCMC.CPP
Purpose: Defines the implementation for an MFC wrapper class for sending an email using CMC (Common Messaging Calls)
Created: PJN / 11-05-1999
History: 28-03-2000 1. Provision of a sample app which implements a mini mail sender.
                    2. Added a CMapiMessage::AddMultipleRecipients method similar to my SMTP class.
                    3. Fixed an access violation which was occurring in CCMCSession::Send in the attachement array.

         02-04-2000 1. Password field in the configuration dialog now uses ES_PASSWORD edit control style.
                    2. Password value used for CMC logon is now stored in the registry encrypted instead of as plain text.



Copyright (c) 1999 - 2000 by PJ Naughter.  
All rights reserved.


*/



/////////////////////////////////  Includes  //////////////////////////////////

#include "stdafx.h"
#include "CCmc.h"
#include <afxpriv.h>




//////////////////////////////// Statics / Macros /////////////////////////////

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif




////////////////////////////////// Implementation /////////////////////////////

BOOL CCMCMessage::AddMultipleRecipients(const CString& sRecipients, RECIPIENT_TYPE RecipientType)
{
	ASSERT(sRecipients.GetLength()); //An empty string is now allowed
	
	//Loop through the whole string, adding recipients as they are encountered
	int length = sRecipients.GetLength();
	TCHAR* buf = new TCHAR[length + 1];	// Allocate a work area (don't touch parameter itself)
	_tcscpy(buf, sRecipients);
	for (int pos=0, start=0; pos<=length; pos++)
	{
		//Valid separators between addresses are ',' or ';'
		if ((buf[pos] == _T(',')) || (buf[pos] == _T(';')) || (buf[pos] == 0))
		{
			buf[pos] = 0;	//Redundant when at the end of string, but who cares.
      CString sTemp(&buf[start]);

			// Now divide the substring into friendly names and e-mail addresses
      CString To = sTemp;

      //Finally add the new recipient to the array of recipients
			To.TrimRight();
			To.TrimLeft();
      if (To.GetLength())
      {
        switch (RecipientType)
        {
          case TO:  m_To.Add(To); break;
          case CC:  m_CC.Add(To); break;
          case BCC: m_To.Add(To); break;
          default: ASSERT(FALSE); break;
        }
      }

      //Move on to the next position
			start = pos + 1;
		}
	}
	delete[] buf;
	return TRUE;
}



CCMCSession::CCMCSession()
{
  m_hSession = 0;
  m_nLastError = 0;
  m_hCMC = NULL;
  m_lpfncmc_logon = NULL;
  m_lpfncmc_logoff = NULL;
  m_lpfncmc_send = NULL;
  m_lpfncmc_look_up = NULL;
  m_lpfncmc_free = NULL;
  Initialise();
}

CCMCSession::~CCMCSession()
{
  //Logoff if logged on
  Logoff();

  //Unload the CMC dll
  Deinitialise();
}

void CCMCSession::Initialise() 
{
  //First make sure the "WIN.INI" entry for CMC is present
	BOOL bCMCInstalled = (::GetProfileInt(_T("MAIL"), _T("CMC"), 0) != 0);

  //Determine the dll which houses CMC
  TCHAR szDllName[_MAX_PATH];
  if (!::GetProfileString(_T("Mail"), _T("CMCDLLNAME32"), _T(""), szDllName, _MAX_PATH))
    _tcscpy(szDllName, _T("CMC.DLL"));

  //Check to see can we find the dll
  bCMCInstalled = (::SearchPath(NULL, szDllName, NULL, 0, NULL, NULL) != 0);
    
  if (bCMCInstalled)
  {
    //Load up the CMC dll and get the function pointers we are interested in
    m_hCMC = LoadLibrary(szDllName);
    if (m_hCMC)
    {
      m_lpfncmc_logon   = (LPCMC_LOGON) GetProcAddress(m_hCMC, "cmc_logon");
      m_lpfncmc_logoff  = (LPCMC_LOGOFF) GetProcAddress(m_hCMC, "cmc_logoff");
      m_lpfncmc_send    = (LPCMC_SEND) GetProcAddress(m_hCMC, "cmc_send");
      m_lpfncmc_look_up = (LPCMC_LOOK_UP) GetProcAddress(m_hCMC, "cmc_look_up");
      m_lpfncmc_free    = (LPCMC_FREE) GetProcAddress(m_hCMC, "cmc_free");
  
      //If any of the functions are not installed then fail the load
      if (m_lpfncmc_logon == NULL ||
          m_lpfncmc_logoff == NULL ||
          m_lpfncmc_send == NULL ||
          m_lpfncmc_look_up == NULL ||
          m_lpfncmc_free == NULL)
      {
        TRACE(_T("Failed to get one of the CMC functions pointers in %s\n"), szDllName);
        Deinitialise();
      }
    }
  }
  else
    TRACE(_T("CMC is not installed on this computer\n"));
}

void CCMCSession::Deinitialise()
{
  if (m_hCMC)
  {
    //Unload the CMC dll and reset the function pointers to NULL
    FreeLibrary(m_hCMC);
    m_hCMC = NULL;
    m_lpfncmc_logon = NULL;
    m_lpfncmc_logoff = NULL;
    m_lpfncmc_send = NULL;
    m_lpfncmc_look_up = NULL;
    m_lpfncmc_free = NULL;
  }
}

BOOL CCMCSession::Logon(const CString& sProfileName, const CString& sPassword, CWnd* pParentWnd)
{
	//For correct operation of the T2A macro, see MFC Tech Note 59
	USES_CONVERSION;

  ASSERT(CMCInstalled());  //CMC must be installed
  ASSERT(m_lpfncmc_logon); //Function pointer must be valid

  //Initialise the function return value
  BOOL bSuccess = FALSE;

  //Just in case we are already logged in
  Logoff();

  //Setup the ascii versions of the profile name and password
  int nProfileLength = sProfileName.GetLength();
  int nPasswordLength = sPassword.GetLength();
  LPSTR pszProfileName = NULL;
  LPSTR pszPassword = NULL;
  if (nProfileLength)
  {
    pszProfileName = T2A((LPTSTR) (LPCTSTR) sProfileName);
    pszPassword = T2A((LPTSTR) (LPCTSTR) sPassword);
  }

  //Setup the cmc_ui_id & CMC_flags parameters used in the cmc_logon call
  CMC_ui_id ui_id = 0;
  CMC_flags logon_flags = 0;
  if (nProfileLength == 0)
  {
    //No profile name given, then we must interactively request a profile name
    logon_flags = CMC_ERROR_UI_ALLOWED | CMC_LOGON_UI_ALLOWED;
    if (pParentWnd)
      ui_id = (CMC_ui_id) pParentWnd->GetSafeHwnd();
    else
    {
      //No CWnd given, just use the main window of the app as the parent window
      ASSERT(AfxGetMainWnd());
      ui_id = (CMC_ui_id) AfxGetMainWnd()->GetSafeHwnd();
    }
  }

  //try to Logon to CMC
  CMC_return_code nError = m_lpfncmc_logon(NULL, (CMC_string) pszProfileName, (CMC_string) pszPassword, 
                                           NULL, ui_id, CMC_VERSION, logon_flags, &m_hSession, NULL);
  if (nError != CMC_SUCCESS)
  {
    m_nLastError = nError;
    bSuccess = FALSE;
  }
  else
  {
    m_nLastError = CMC_SUCCESS;
    bSuccess = TRUE;
  }

  return bSuccess;
}

BOOL CCMCSession::LoggedOn() const
{
  return (m_hSession != 0);
}

BOOL CCMCSession::CMCInstalled() const
{
  return (m_hCMC != NULL);
}

BOOL CCMCSession::Logoff()
{
  ASSERT(CMCInstalled());   //CMC must be installed
  ASSERT(m_lpfncmc_logoff); //Function pointer must be valid

  //Initialise the function return value
  BOOL bSuccess = FALSE;

  if (m_hSession)
  {
    //Call the cmc_logoff function
    CMC_return_code nError = m_lpfncmc_logoff(m_hSession, 0, 0, NULL); 
    if (nError != CMC_SUCCESS)
    {
      TRACE(_T("Failed in call to cmc_logoff, Error:%d"), nError);
      m_nLastError = nError;
      bSuccess = TRUE;
    }
    else
    {
      m_nLastError = CMC_SUCCESS;
      bSuccess = TRUE;
    }
    m_hSession = 0;
  }
    
  return bSuccess;
}

BOOL CCMCSession::Send(CCMCMessage& message)
{
	//For correct operation of the T2A macro, see MFC Tech Note 59
	USES_CONVERSION;

  ASSERT(CMCInstalled()); //CMC must be installed
  ASSERT(m_lpfncmc_send); //Function pointer must be valid
  ASSERT(m_lpfncmc_free); //Function pointer must be valid
  ASSERT(LoggedOn());     //Must be logged on to CMC
  ASSERT(m_hSession);     //CMC session handle must be valid

  //Initialise the function return value
  BOOL bSuccess = FALSE;  

  //Create the CMC_message structure to match the message parameter send into us
  CMC_message cmcMessage;
  ZeroMemory(&cmcMessage, sizeof(cmcMessage));
  cmcMessage.subject = (CMC_string) (T2A((LPTSTR) (LPCTSTR) message.m_sSubject));
  cmcMessage.text_note = (CMC_string) (T2A((LPTSTR) (LPCTSTR) message.m_sBody));

  //Allocate the recipients array
  int nRecipients = message.m_To.GetSize() + message.m_CC.GetSize() + message.m_BCC.GetSize();
  ASSERT(nRecipients); //Must have at least 1 recipient!
  cmcMessage.recipients = new CMC_recipient[nRecipients];

  //Setup the "To" recipients
  int nRecipIndex = 0;
  int nToSize = message.m_To.GetSize();
  for (int i=0; i<nToSize; i++)
  {
    CMC_recipient& recip = cmcMessage.recipients[nRecipIndex];
    ZeroMemory(&recip, sizeof(CMC_recipient));
    recip.role = CMC_ROLE_TO;
    recip.name_type = CMC_TYPE_UNKNOWN;
    CString& sName = message.m_To.ElementAt(i);
    recip.name = (CMC_string) (T2A((LPTSTR) (LPCTSTR) sName));
    ++nRecipIndex;
  }

  //Setup the "CC" recipients
  int nCCSize = message.m_CC.GetSize();
  for (i=0; i<nCCSize; i++)
  {
    CMC_recipient& recip = cmcMessage.recipients[nRecipIndex];
    ZeroMemory(&recip, sizeof(CMC_recipient));
    recip.role = CMC_ROLE_CC;
    recip.name_type = CMC_TYPE_UNKNOWN;
    CString& sName = message.m_CC.ElementAt(i);
    recip.name = (CMC_string) (T2A((LPTSTR) (LPCTSTR) sName));
    ++nRecipIndex;
  }

  //Setup the "BCC" recipients
  int nBCCSize = message.m_BCC.GetSize();
  for (i=0; i<nBCCSize; i++)
  {
    CMC_recipient& recip = cmcMessage.recipients[nRecipIndex];
    ZeroMemory(&recip, sizeof(CMC_recipient));
    recip.role = CMC_ROLE_BCC;
    recip.name_type = CMC_TYPE_UNKNOWN;
    CString& sName = message.m_BCC.ElementAt(i);
    recip.name = (CMC_string) (T2A((LPTSTR) (LPCTSTR) sName));
    ++nRecipIndex;
  }

  //Set the last recipient flag
  cmcMessage.recipients[nRecipients-1].recip_flags = CMC_RECIP_LAST_ELEMENT;

  //Setup the attachments 
  int nAttachmentSize = message.m_Attachments.GetSize();
  int nTitleSize = message.m_AttachmentTitles.GetSize();
  if (nTitleSize)
  { 
    ASSERT(nTitleSize == nAttachmentSize); //If you are going to set the attachment titles then you must set 
                                           //the attachment title for each attachment
  }
  if (nAttachmentSize)
  {
    cmcMessage.attachments = new CMC_attachment[nAttachmentSize];
    for (i=0; i<nAttachmentSize; i++)
    {
      CMC_attachment& file = cmcMessage.attachments[i];
      ZeroMemory(&file, sizeof(CMC_attachment));
      CString& sFilename = message.m_Attachments.ElementAt(i);
      file.attach_filename = (CMC_string) (T2A((LPTSTR) (LPCTSTR) sFilename));
      file.attach_title = file.attach_filename;
      if (nTitleSize)
      {
        CString& sTitle = message.m_AttachmentTitles.ElementAt(i);
        file.attach_title = (CMC_string) (T2A((LPTSTR) (LPCTSTR) sTitle));
      }
    }

    //Set the last attachment flag
    cmcMessage.attachments[nAttachmentSize-1].attach_flags = CMC_ATT_LAST_ELEMENT;
  }

  //Do the actual send using MAPISendMail
  CMC_return_code nError = m_lpfncmc_send(m_hSession, &cmcMessage, 0, 0, NULL);
  if (nError == CMC_SUCCESS)
  {
    bSuccess = TRUE;
    m_nLastError = CMC_SUCCESS;
  }
  else
  {
    TRACE(_T("Failed to send mail message, Error:%d\n"), nError);
    m_nLastError = nError;
  }

  //Tidy up the Attachements
  if (nAttachmentSize)
    delete [] cmcMessage.attachments;
  
  //Free up the Recipients memory
  delete [] cmcMessage.recipients;

  return bSuccess;
}

ULONG CCMCSession::GetLastError() const
{
  return m_nLastError;
}

