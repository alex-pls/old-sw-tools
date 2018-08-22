// MainView.cpp : implementation of the CMainView class
//

#include "stdafx.h"
#include "IPCTrace.h"

#include "Doc.h"
#include "MainView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "Cfg.h"

#define BKCOLOR RGB(255, 196, 0)

/////////////////////////////////////////////////////////////////////////////
// CMainView

IMPLEMENT_DYNCREATE(CMainView, CEditView)

BEGIN_MESSAGE_MAP(CMainView, CEditView)
	//{{AFX_MSG_MAP(CMainView)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainView construction/destruction

CMainView::CMainView()
{
	m_nLineNumber = 1;

	LOGFONT lf;
	ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 15;
	lf.lfWeight = FW_REGULAR;
	_tcscpy(lf.lfFaceName, _T("Courier"));
	
	m_Font.CreateFontIndirect(&lf);

	m_BrushBk.CreateSolidBrush(BKCOLOR);
}

CMainView::~CMainView()
{
}

BOOL CMainView::PreCreateWindow(CREATESTRUCT& cs)
{
	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL | WS_HSCROLL);

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CMainView drawing

void CMainView::OnDraw(CDC* pDC)
{
	CDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CMainView diagnostics

#ifdef _DEBUG
void CMainView::AssertValid() const
{
	CEditView::AssertValid();
}

void CMainView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CDoc* CMainView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDoc)));
	return (CDoc*) m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainView message handlers

void CMainView::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();

	CEdit& edit = GetEditCtrl();
	edit.SetReadOnly();

	SetFont(&m_Font);

	CString sStartup((LPTSTR) IDS_STARTUP);
	SetWindowText(sStartup);

	edit.SetSel(sStartup.GetLength(), sStartup.GetLength());
}

HBRUSH CMainView::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetBkColor(BKCOLOR);
	return m_BrushBk;
}

void CMainView::Trace(LPCTSTR lpszTrace)
{
	ASSERT(lpszTrace);
	CString sTrace;
	if (CCfg::GetCfg().m_bAddLineNumbers)
		sTrace.Format(_T("%08d> "), m_nLineNumber++);
	else
		sTrace= _T("> ");

	sTrace += lpszTrace;
	sTrace += _T("\r\n");

	CEdit& edit = GetEditCtrl();

	CString sText;
	edit.GetWindowText(sText);
	edit.SetSel(sText.GetLength(), sText.GetLength());
	edit.ReplaceSel(sTrace);
	edit.GetWindowText(sText);
	edit.SetSel(sText.GetLength(), sText.GetLength());
}
