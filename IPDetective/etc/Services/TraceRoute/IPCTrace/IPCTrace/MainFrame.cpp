// MainFrame.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "IPCTrace.h"
#include "MainFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "Cfg.h"
#include "MainView.h"
#include "Registry.h"

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_COPYDATA()
	ON_WM_DESTROY()
	ON_COMMAND(ID_CMD_ADDLINENUMBERS, OnCmdAddLineNumbers)
	ON_UPDATE_COMMAND_UI(ID_CMD_ADDLINENUMBERS, OnUpdateCmdAddLineNumbers)
	ON_COMMAND(ID_CMD_ALWAYSONTOP, OnCmdAlwaysOnTop)
	ON_UPDATE_COMMAND_UI(ID_CMD_ALWAYSONTOP, OnUpdateCmdAlwaysOnTop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
			
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
 	if( !CFrameWnd::PreCreateWindow(cs) )
 		return FALSE;
 
 	CString sRegKey((LPTSTR) IDS_REGKEY);
 	
 	CRegistry reg;
 	reg.Open(sRegKey, KEY_READ);
 	
 	WINDOWPLACEMENT wp;
 	ZeroMemory(&wp, sizeof(WINDOWPLACEMENT));
 	wp.length = sizeof(WINDOWPLACEMENT);
 
 	if (reg.ReadRaw(_T("Wnd"), wp))
 	{
 		cs.x = wp.rcNormalPosition.left;
 		cs.y = wp.rcNormalPosition.top;
 		cs.cx = wp.rcNormalPosition.right - wp.rcNormalPosition.left;
 		cs.cy = wp.rcNormalPosition.bottom - wp.rcNormalPosition.top;
 	}
 	
 	cs.style &= ~FWS_ADDTOTITLE; 
 	
 	return TRUE;
 }

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct) 
{
	if (pCopyDataStruct->dwData != 0x00031337)
		return FALSE;

	CMainView* pView = DYNAMIC_DOWNCAST(CMainView, GetActiveView());
	ASSERT(pView);
	ASSERT(::IsWindow(pView->GetSafeHwnd()));

	pView->Trace((LPCTSTR) pCopyDataStruct->lpData);
	
	return CFrameWnd::OnCopyData(pWnd, pCopyDataStruct);
}

void CMainFrame::OnDestroy() 
{	
	ASSERT(::IsWindow(GetSafeHwnd()));

	WINDOWPLACEMENT wp;
	ZeroMemory(&wp, sizeof(WINDOWPLACEMENT));
	wp.length = sizeof(WINDOWPLACEMENT);

	GetWindowPlacement(&wp);

	CString sRegKey((LPTSTR) IDS_REGKEY);

	CRegistry reg;
	if (!reg.VerifyKey(sRegKey, TRUE))
		reg.CreateKey(sRegKey, TRUE);

	reg.WriteRaw(_T("Wnd"), wp);
	reg.WriteObj(_T("Cfg"), CCfg::GetCfg());

	CFrameWnd::OnDestroy();
}

void CMainFrame::OnCmdAddLineNumbers() 
{
	if (CCfg::GetCfg().m_bAddLineNumbers)
		CCfg::GetCfg().m_bAddLineNumbers = FALSE;
	else
		CCfg::GetCfg().m_bAddLineNumbers = TRUE;
}

void CMainFrame::OnUpdateCmdAddLineNumbers(CCmdUI* pCmdUI) 
{
	if (CCfg::GetCfg().m_bAddLineNumbers)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(0);
}

void CMainFrame::OnCmdAlwaysOnTop() 
{
	if (CCfg::GetCfg().m_bAlwaysOnTop)
	{
		SetWindowPos(&wndNoTopMost, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOSIZE);
		CCfg::GetCfg().m_bAlwaysOnTop = FALSE;
	}
	else
	{
		SetWindowPos(&wndTopMost, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOSIZE);
		CCfg::GetCfg().m_bAlwaysOnTop = TRUE;
	}
}

void CMainFrame::OnUpdateCmdAlwaysOnTop(CCmdUI* pCmdUI) 
{
	if (CCfg::GetCfg().m_bAlwaysOnTop)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(0);
}
