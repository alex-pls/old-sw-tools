#include "stdafx.h"
#include "Mail.h"
#include "MailDlg.h"
#include "CCmc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CMailApp, CWinApp)
	//{{AFX_MSG_MAP(CMailApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CMailApp::CMailApp()
{
}

CMailApp theApp;

BOOL CMailApp::InitInstance()
{
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

  //Settings will be stored in the registry
  SetRegistryKey(_T("PJ Naughter"));

  //Check that CMC is installed
  CCMCSession session;
  if (!session.CMCInstalled())
  {
    AfxMessageBox(_T("CMC is not installed on this machine"), MB_OK | MB_ICONSTOP);
    return FALSE;
  }

  //Bring up the main dialog
	CMailDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}
