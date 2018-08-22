// IPCTraceClientDlg.h : header file
//

#if !defined(AFX_IPCTRACECLIENTDLG_H__57A8462E_D2BF_4F95_9ED2_6B7C2D9934C9__INCLUDED_)
#define AFX_IPCTRACECLIENTDLG_H__57A8462E_D2BF_4F95_9ED2_6B7C2D9934C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIPCTraceClientDlg dialog

class CIPCTraceClientDlg : public CDialog
{
// Construction
public:
	CIPCTraceClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIPCTraceClientDlg)
	enum { IDD = IDD_IPCTRACECLIENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCTraceClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIPCTraceClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnTrace();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCTRACECLIENTDLG_H__57A8462E_D2BF_4F95_9ED2_6B7C2D9934C9__INCLUDED_)
