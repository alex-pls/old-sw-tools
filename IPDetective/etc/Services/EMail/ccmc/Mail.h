#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

class CMailApp : public CWinApp
{
public:
	CMailApp();

protected:
	//{{AFX_VIRTUAL(CMailApp)
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMailApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


