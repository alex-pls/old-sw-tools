// MainView.h : interface of the CMainView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINVIEW_H__6577B687_B8FF_423F_8F30_DB0F6F7A7DEA__INCLUDED_)
#define AFX_MAINVIEW_H__6577B687_B8FF_423F_8F30_DB0F6F7A7DEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDoc;

class CMainView : public CEditView
{
protected: // create from serialization only
	CMainView();
	DECLARE_DYNCREATE(CMainView)

// Attributes
public:
	CDoc* GetDocument();

// Operations
public:
	void Trace(LPCTSTR lpszTrace);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_nLineNumber;
	CFont m_Font;
	CBrush m_BrushBk;

protected:
	//{{AFX_MSG(CMainView)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MainView.cpp
inline CDoc* CMainView::GetDocument()
   { return (CDoc*) m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINVIEW_H__6577B687_B8FF_423F_8F30_DB0F6F7A7DEA__INCLUDED_)
