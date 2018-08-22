#include "stdafx.h"
#include "Mail.h"
#include "MailDlg.h"
#include "MailConfigurationDlg.h"
#include "CCMC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMailDlg::CMailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMailDlg)
	m_sBCC = _T("");
	m_sBody = _T("");
	m_sCC = _T("");
	m_sFile = _T("");
	m_sSubject = _T("");
	m_sTo = _T("");
	//}}AFX_DATA_INIT

  //Load in the values from the registry
  CWinApp* pApp = AfxGetApp();
  CString sSection(_T("Settings"));
	m_sProfile = pApp->GetProfileString(sSection, _T("Profile"));

  //The password is stored in the registry as a simple XOR mask
  LPBYTE byData = NULL;
  UINT nBytes = 0;
 	if (pApp->GetProfileBinary(sSection, _T("PasswordB"),	&byData, &nBytes))
  {
    for (UINT i=0; i<nBytes; i++)
      byData[i] ^= i;
    TCHAR* pszPassword = new TCHAR[nBytes + 1];
    _tcsncpy(pszPassword, (TCHAR*) byData, nBytes);
    pszPassword[nBytes] = _T('\0');
    m_sPassword = pszPassword;
    delete [] pszPassword;
    delete [] byData;
  }

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMailDlg)
	DDX_Text(pDX, IDC_BCC, m_sBCC);
	DDX_Text(pDX, IDC_BODY, m_sBody);
	DDX_Text(pDX, IDC_CC, m_sCC);
	DDX_Text(pDX, IDC_FILE, m_sFile);
	DDX_Text(pDX, IDC_SUBJECT, m_sSubject);
	DDX_Text(pDX, IDC_TO, m_sTo);
	//}}AFX_DATA_MAP

  if (pDX->m_bSaveAndValidate)
  {
    if (m_sTo.IsEmpty())
    {
      AfxMessageBox(_T("To: address is empty !"));
      pDX->PrepareEditCtrl(IDC_TO);
      pDX->Fail();
    }
  }
}

BEGIN_MESSAGE_MAP(CMailDlg, CDialog)
	//{{AFX_MSG_MAP(CMailDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONFIGURATION, OnConfiguration)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_BROWSE_FILE, OnBrowseFile)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CMailDlg::OnInitDialog()
{
  //Let the parent class do its thing
	CDialog::OnInitDialog();

  // Set big icon
	SetIcon(m_hIcon, TRUE);			
	
	return TRUE;
}

void CMailDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CMailDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMailDlg::OnConfiguration() 
{
  CMailConfigurationDlg dlg;
	dlg.m_sProfile = m_sProfile;
	dlg.m_sPassword = m_sPassword;
  if (dlg.DoModal() == IDOK)
  {
	  m_sProfile = dlg.m_sProfile;
	  m_sPassword = dlg.m_sPassword;
  }
}

void CMailDlg::OnSend() 
{
	if (UpdateData(TRUE))
  {
	  CWaitCursor wc;
	  if (m_sProfile.IsEmpty()) 
		  OnConfiguration();
	  else 
    {
		  //Create the message
		  CCMCMessage message;

      //Setup the all the recipient types for this message
		  message.AddMultipleRecipients(m_sTo, CCMCMessage::TO);
		  if (!m_sCC.IsEmpty()) 
			  message.AddMultipleRecipients(m_sCC, CCMCMessage::CC);
		  if (!m_sBCC.IsEmpty()) 
			  message.AddMultipleRecipients(m_sBCC, CCMCMessage::BCC);

      //Add the Subject and Body
		  if (!m_sSubject.IsEmpty()) 
			  message.m_sSubject = m_sSubject;
		  if (!m_sBody.IsEmpty())
			  message.m_sBody = m_sBody;

      //Add the attachement if necessary
		  if (!m_sFile.IsEmpty()) 
      {
			  message.m_Attachments.SetSize(0);
			  message.m_Attachments.Add(m_sFile);		
		  }

		  //connect to server
		  CCMCSession connection;
		  if (!connection.Logon(m_sProfile)) 
      {
        CString sMsg;
			  sMsg.Format(_T("Couldn't login to CMC!, Error:%d"), connection.GetLastError());
			  AfxMessageBox(sMsg, MB_ICONSTOP);
		  }
		  else 
      {
        //Send the message
			  if (!connection.Send(message)) 
        {
          CString sMsg;
				  sMsg.Format(_T("Couldn't send message!\nError:%d"), connection.GetLastError());
				  AfxMessageBox(sMsg, MB_ICONSTOP);
			  }
		  }
	  }
  }
}

void CMailDlg::OnBrowseFile() 
{
  CDataExchange DX(this, TRUE);
  DDX_Text(&DX, IDC_FILE, m_sFile);
	CFileDialog dlg(TRUE, NULL, m_sFile);
	if (dlg.DoModal() == IDOK) 
  {
		m_sFile = dlg.GetPathName();
    SetDlgItemText(IDC_FILE, m_sFile);
  }
}

void CMailDlg::OnDestroy() 
{
  //Let the parent class do its thing
	CDialog::OnDestroy();
	
  //Save in the values from the registry
  CWinApp* pApp = AfxGetApp();
  CString sSection(_T("Settings"));
	pApp->WriteProfileString(sSection, _T("Profile"), m_sProfile);

  //The password is stored in the registry as a simple XOR mask
  int nLength = m_sPassword.GetLength();
  TCHAR* pszPassword = new TCHAR[nLength + 1];
  _tcscpy(pszPassword, m_sPassword);
  for (int i=0; i<nLength; i++)
    pszPassword[i] ^= i;
 	pApp->WriteProfileBinary(sSection, _T("PasswordB"),	(LPBYTE) pszPassword, nLength*sizeof(TCHAR));
  delete [] pszPassword;
}
