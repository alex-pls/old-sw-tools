/*
Module : CCMC.H
Purpose: Defines the interface for an MFC wrapper class for sending an email using CMC (Common Messaging Calls)
Created: PJN / 11-05-1999
History: None

Copyright (c) 1999 - 2000 by PJ Naughter.  
All rights reserved.

*/

#ifndef __CCMC_H__
#define __CCMC_H__


#ifndef _XCMC_H
#include <xcmc.h>
#endif




// Function pointer Defines 

typedef CMC_return_code (FAR PASCAL CMC_LOGON)(
    CMC_string              service,
    CMC_string              user,
    CMC_string              password,
    CMC_object_identifier   character_set,
    CMC_ui_id               ui_id,
    CMC_uint16              caller_cmc_version,
    CMC_flags               logon_flags,
    CMC_session_id FAR      *session,
    CMC_extension FAR       *logon_extensions
);
typedef CMC_LOGON FAR *LPCMC_LOGON;

typedef CMC_return_code (FAR PASCAL CMC_LOGOFF)(
    CMC_session_id          session,
    CMC_ui_id               ui_id,
    CMC_flags               logoff_flags,
    CMC_extension FAR       *logoff_extensions
);
typedef CMC_LOGOFF FAR *LPCMC_LOGOFF;

typedef CMC_return_code (FAR PASCAL CMC_SEND)(
    CMC_session_id          session,
    CMC_message FAR         *message,
    CMC_flags               send_flags,
    CMC_ui_id               ui_id,
    CMC_extension FAR       *send_extensions
);

typedef CMC_SEND FAR *LPCMC_SEND;

typedef CMC_return_code (FAR PASCAL CMC_LOOK_UP)(
    CMC_session_id          session,
    CMC_recipient FAR       *recipient_in,
    CMC_flags               look_up_flags,
    CMC_ui_id               ui_id,
    CMC_uint32 FAR          *count,
    CMC_recipient FAR * FAR *recipient_out,
    CMC_extension FAR       *look_up_extensions
);

typedef CMC_LOOK_UP FAR *LPCMC_LOOK_UP;

typedef CMC_return_code (FAR PASCAL CMC_FREE)(
    CMC_buffer              memory
);

typedef CMC_FREE FAR *LPCMC_FREE;



//Class which encapsulates a CMC mail message
class CCMCMessage
{
public:
//Enums
	enum RECIPIENT_TYPE { TO, CC, BCC };

//Methods
  BOOL AddMultipleRecipients(const CString& sRecipients, RECIPIENT_TYPE RecipientType);

//Member variables
  CStringArray  m_To;               //The To: Recipients
  CStringArray  m_CC;               //The CC: Recipients
  CStringArray  m_BCC;              //The BCC Recipients
  CString       m_sSubject;         //The Subject of the message
  CString       m_sBody;            //The Body of the message
  CStringArray  m_Attachments;      //Files to attach to the email
  CStringArray  m_AttachmentTitles; //Titles to use for the email file attachments
};



//The class which encapsulates the CMC connection
class CCMCSession
{
public:
//Constructors / Destructors
  CCMCSession();
  ~CCMCSession();

//Logon / Logoff Methods
  BOOL Logon(const CString& sProfileName, const CString& sPassword = CString(), CWnd* pParentWnd = NULL);
  BOOL LoggedOn() const;
  BOOL Logoff();

//Send a message
  BOOL Send(CCMCMessage& mesage);

//General CMC support
  BOOL CMCInstalled() const;

//Error Handling
  CMC_return_code GetLastError() const;

protected:
//Methods
  void Initialise();
  void Deinitialise(); 

//Data
  CMC_session_id  m_hSession;        //CMC Session handle
  CMC_return_code m_nLastError;      //Last CMC error value
  HINSTANCE       m_hCMC;            //Instance handle of the CMC dll
  LPCMC_LOGON     m_lpfncmc_logon;   //cmc_logon function pointer
  LPCMC_LOGOFF    m_lpfncmc_logoff;  //cmc_logoff function pointer
  LPCMC_SEND      m_lpfncmc_send;    //cmc_send function pointer
  LPCMC_LOOK_UP   m_lpfncmc_look_up; //cmc_look_up function pointer
  LPCMC_FREE      m_lpfncmc_free;    //cmc_free function pointer
};


#endif //__CCMC_H__