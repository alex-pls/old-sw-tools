// IPCTrace.h : main header file for the IPCTrace application
//

#if !defined(AFX_IPCTRACE_H__F4EE0DC6_5BF1_47CA_8C64_4DAC46F701D6__INCLUDED_)
#define AFX_IPCTRACE_H__F4EE0DC6_5BF1_47CA_8C64_4DAC46F701D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CIPCTraceApp:
// See IPCTrace.cpp for the implementation of this class
//

class CIPCTraceApp : public CWinApp
{
public:
	CIPCTraceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCTraceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CIPCTraceApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCTRACE_H__F4EE0DC6_5BF1_47CA_8C64_4DAC46F701D6__INCLUDED_)
