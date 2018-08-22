// Crypt.h: interface for the CCrypt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CRYPT_H__857CC487_11E6_11D4_B7B8_0050DA34A2BA__INCLUDED_)
#define AFX_CRYPT_H__857CC487_11E6_11D4_B7B8_0050DA34A2BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCrypt
{
public:
	CCrypt();
	virtual ~CCrypt();

	enum Algorithm
	{
		eMD2 = 0,
		eMD5,
		eSHA,
	};

	BOOL Encrypt(const BYTE* pByteIn, BYTE*& pByteOut, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm);
	BOOL Decrypt(const BYTE* pByteIn, BYTE*& pByteOut, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm);
	BOOL EncryptObj(CObject& object, BYTE*& pData, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm);
	BOOL DecryptObj(CObject& object, const BYTE* pData, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm);



	// *** Templates ***
	template<class T>
	AFX_INLINE BOOL EncryptType(const T& type, BYTE*& pData, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm)
	{
		ASSERT(lpszPassword);
		
		BOOL bResult = FALSE;
		
		CMemFile file;
		CArchive ar(&file, CArchive::store);
		
		ar << type;
		ar.Close();
		
		dwSize = file.GetLength();
		BYTE* pByte = file.Detach();
		
		bResult = Encrypt(pByte, pData, dwSize, lpszPassword, eAlgorithm);
		if (!bResult)
			pData = NULL;
		
		if (pByte)
			free(pByte);
		
		return bResult;
	}
	
	template<class T>
	AFX_INLINE BOOL DecryptType(T& type, BYTE* pData, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm)
	{
		ASSERT(dwSize > 0);
		ASSERT(lpszPassword);
		
		BYTE* pByte = NULL;
		if(!Decrypt(pData, pByte, dwSize, lpszPassword, eAlgorithm))
			return FALSE;
		
		CMemFile file(pByte, dwSize);
		CArchive ar(&file, CArchive::load);
		
		ar >> type;
		ar.Close();
				
		file.Close();
		
		delete pByte;
		return TRUE;
	}
	
	template<class T>
	AFX_INLINE BOOL EncryptDynObj(const T* pObject, BYTE*& pData, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm)
	{
		ASSERT(lpszPassword);
		
		BOOL bResult = TRUE;
		
		CMemFile file;
		CArchive ar(&file, CArchive::store);
		
		ar << pObject;
		ar.Close();
		
		dwSize = file.GetLength();
		BYTE* pByte = file.Detach();
		
		bResult = Encrypt(pByte, pData, dwSize, lpszPassword, eAlgorithm);
		if (!bResult)
			pData = NULL;
		
		if (pByte)
			free(pByte);
		
		return bResult;
	}
	
	template<class T>
	AFX_INLINE BOOL DecryptDynObj(T*& pObject, const BYTE* pData, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm)
	{
		ASSERT(dwSize > 0);
		ASSERT(lpszPassword);
				
		BYTE* pByte = NULL;
		if(!Decrypt(pData, pByte, dwSize, lpszPassword, eAlgorithm))
			return FALSE;
				
		CMemFile file(pByte, dwSize);
		CArchive ar(&file, CArchive::load);
		
		ar >> pObject;
		ar.Close();
				
		file.Close();
		
		delete pByte;
		return TRUE;
	}

};

#endif // !defined(AFX_CRYPT_H__857CC487_11E6_11D4_B7B8_0050DA34A2BA__INCLUDED_)
