// IPCTrace.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "IPCTrace.h"

#include "MainFrame.h"
#include "Doc.h"
#include "MainView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "Cfg.h"
#include "Registry.h"

/////////////////////////////////////////////////////////////////////////////
// CIPCTraceApp

BEGIN_MESSAGE_MAP(CIPCTraceApp, CWinApp)
	//{{AFX_MSG_MAP(CIPCTraceApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPCTraceApp construction

CIPCTraceApp::CIPCTraceApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIPCTraceApp object

CIPCTraceApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CIPCTraceApp initialization

BOOL CIPCTraceApp::InitInstance()
{
	AfxEnableControlContainer();

#ifdef _AFXDLL
	Enable3dControls();
#else
	Enable3dControlsStatic();
#endif

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(IDR_MAINFRAME,
																				RUNTIME_CLASS(CDoc),
																				RUNTIME_CLASS(CMainFrame),
																				RUNTIME_CLASS(CMainView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open...
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	CString sRegKey((LPTSTR) IDS_REGKEY);
	
	CRegistry reg;
	reg.Open(sRegKey, KEY_READ);
	
	WINDOWPLACEMENT wp;
	ZeroMemory(&wp, sizeof(WINDOWPLACEMENT));
	wp.length = sizeof(WINDOWPLACEMENT);

	if (reg.ReadRaw(_T("Wnd"), wp))
		m_nCmdShow = wp.showCmd;

	CCfg& cfg = CCfg::GetCfg();
	reg.ReadObj(_T("Cfg"), cfg);

	// Dispatch commands specified on the command line...
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	if (cfg.m_bAlwaysOnTop)
		::SetWindowPos(m_pMainWnd->GetSafeHwnd(), HWND_TOPMOST, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOSIZE);
	else
		::SetWindowPos(m_pMainWnd->GetSafeHwnd(), HWND_NOTOPMOST, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOSIZE);

	// The one and only window has been initialized, so show and update it...
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CIPCTraceApp message handlers

