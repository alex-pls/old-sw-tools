// CryptWindows.h: interface for the CCryptWindows class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CRYPTWINDOWS_H__6BECC471_57F7_11D4_B7F5_0050DA34A2BA__INCLUDED_)
#define AFX_CRYPTWINDOWS_H__6BECC471_57F7_11D4_B7F5_0050DA34A2BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Crypt.h"

class CCryptWindows  
{
public:
	CCryptWindows();
	virtual ~CCryptWindows();

	BOOL Encrypt(BYTE*& pByte, DWORD& dwSize, LPCTSTR lpszPassword, const CCrypt::Algorithm& eAlgorithm);
	BOOL Decrypt(BYTE*& pByte, DWORD& dwSize, LPCTSTR lpszPassword, const CCrypt::Algorithm& eAlgorithm);

protected:
	BOOL Init();
	BOOL m_bInit;

};

#endif // !defined(AFX_CRYPTWINDOWS_H__6BECC471_57F7_11D4_B7F5_0050DA34A2BA__INCLUDED_)
