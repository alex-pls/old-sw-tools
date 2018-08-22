// IPCTraceClient.h : main header file for the IPCTRACECLIENT application
//

#if !defined(AFX_IPCTRACECLIENT_H__CD5703DB_6E4B_4A8A_B2B0_6E7791E3FC80__INCLUDED_)
#define AFX_IPCTRACECLIENT_H__CD5703DB_6E4B_4A8A_B2B0_6E7791E3FC80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIPCTraceClientApp:
// See IPCTraceClient.cpp for the implementation of this class
//

class CIPCTraceClientApp : public CWinApp
{
public:
	CIPCTraceClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCTraceClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIPCTraceClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCTRACECLIENT_H__CD5703DB_6E4B_4A8A_B2B0_6E7791E3FC80__INCLUDED_)
