// Registry.h: interface for the CRegistry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGISTRY_H__08F26279_A63D_11D3_B73D_0050DA34A2BA__INCLUDED_)
#define AFX_REGISTRY_H__08F26279_A63D_11D3_B73D_0050DA34A2BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Crypt.h"

class CRegistry
{
public:
	CRegistry(HKEY hKey = HKEY_CURRENT_USER);
	virtual ~CRegistry();
	
	BOOL Open(HKEY hKey, LPCTSTR lpszPath, const REGSAM& dwMask = KEY_ALL_ACCESS);
	BOOL Open(LPCTSTR lpszPath, const REGSAM& dwMask = KEY_ALL_ACCESS);
	void Close();
	
	BOOL VerifyKey(LPCTSTR lpszPath, const BOOL& bOpen = FALSE, const REGSAM& dwMask = KEY_ALL_ACCESS);
	BOOL VerifyKey(HKEY hKey, LPCTSTR lpszPath, const BOOL& bOpen = FALSE, const REGSAM& dwMask = KEY_ALL_ACCESS);
	BOOL VerifyValue(LPCTSTR lpszValue);
	BOOL VerifyValue(HKEY hKey, LPCTSTR lpszValue);
	
	BOOL CreateKey(HKEY hKey, LPCTSTR lpszPath, const BOOL& bOpen = FALSE, const DWORD& dwOptions = REG_OPTION_NON_VOLATILE, const REGSAM& dwMask = KEY_ALL_ACCESS);
	BOOL CreateKey(LPCTSTR lpszPath, const BOOL& bOpen = FALSE, const DWORD& dwOptions = REG_OPTION_NON_VOLATILE, const REGSAM& dwMask = KEY_ALL_ACCESS);
	
	BOOL DeleteKey(HKEY hKey, LPCTSTR lpszPath);
	BOOL DeleteKey(LPCTSTR lpszPath);
	BOOL DeleteValue(HKEY hKey, LPCTSTR lpszValue);
	BOOL DeleteValue(LPCTSTR lpszValue);
	
	BOOL WriteString(LPCTSTR lpszKey, LPCTSTR lpszData);
	BOOL WriteDWORD(LPCTSTR lpszKey, const DWORD& dwData);
	BOOL WriteWnd(LPCTSTR lpszKey, CWnd* pWnd);
	BOOL WriteObj(LPCTSTR lpszKey, CObject& object, LPCTSTR lpszPassword = NULL, const CCrypt::Algorithm& eAlgorithm = CCrypt::Algorithm::eMD5);
	
	BOOL ReadString(LPCTSTR lpszKey, CString& sData);
	BOOL ReadDWORD(LPCTSTR lpszKey, DWORD& dwData);
	BOOL ReadWnd(LPCTSTR lpszKey, CWnd* pWnd);
	BOOL ReadObj(LPCTSTR lpszKey, CObject& object, LPCTSTR lpszPassword = NULL, const CCrypt::Algorithm& eAlgorithm = CCrypt::Algorithm::eMD5);
protected:
	BOOL Encrypt(BYTE*& pByte, DWORD& dwSize, LPCTSTR lpszPassword, const CCrypt::Algorithm& eAlgorithm);
	BOOL Decrypt(BYTE*& pByte, DWORD& dwSize, LPCTSTR lpszPassword, const CCrypt::Algorithm& eAlgorithm);
	
protected:
	HKEY m_hKey;
	CString	m_sPath;
	


public:
	// *** Templates ***
	template<class T>
	AFX_INLINE BOOL WriteRaw(LPCTSTR lpszKey, const T& type, LPCTSTR lpszPassword = NULL, const CCrypt::Algorithm& eAlgorithm = CCrypt::Algorithm::eMD5)
	{
		ASSERT(lpszKey);
		
		CMemFile file;
		CArchive ar(&file, CArchive::store);
		
		ar.Write(&type, sizeof(T));
		ar.Close();
		
		DWORD dwSize = file.GetLength();

#ifdef _DEBUG
		if (dwSize > 2048)
			TRACE1("CRegistry::WriteType - Object size = %d (> 2048) better use a file !\n", dwSize);
#endif

		BYTE* pByte = file.Detach();
		
		if (lpszPassword)
			if (!Encrypt(pByte, dwSize, lpszPassword, eAlgorithm))
				return FALSE;
			
		LONG lResult = RegSetValueEx(m_hKey, lpszKey, NULL, REG_BINARY, pByte, dwSize);
			
		if (pByte)
			free(pByte);
			
		if(lResult == ERROR_SUCCESS)
			return TRUE;
			
		return FALSE;
	}

	template<class T>
	AFX_INLINE BOOL ReadRaw(LPCTSTR lpszKey, T& type, LPCTSTR lpszPassword = NULL, const CCrypt::Algorithm& eAlgorithm = CCrypt::Algorithm::eMD5)
	{
		ASSERT(lpszKey);
		
		DWORD dwType = -1;
		DWORD dwSize = -1;
		BYTE* pByte = NULL;
		
		LONG lResult = RegQueryValueEx(m_hKey, lpszKey, NULL, &dwType, pByte, &dwSize);
		
		if (lResult == ERROR_SUCCESS && dwType == REG_BINARY)
			pByte = new BYTE[dwSize];		
		
		lResult = RegQueryValueEx(m_hKey, lpszKey, NULL, &dwType, pByte, &dwSize);
		if (lResult == ERROR_SUCCESS && dwType == REG_BINARY)
		{
			if (lpszPassword)
				if (!Decrypt(pByte, dwSize, lpszPassword, eAlgorithm))
					return FALSE;
				
			CMemFile file(pByte, dwSize);
			CArchive ar(&file, CArchive::load);
				
			ar.Read(&type, dwSize);
			ar.Close();
				
			file.Close();
				
			delete pByte;
			return TRUE;
		}
		
		delete pByte;
		return FALSE;
	}


	template<class T>
	AFX_INLINE BOOL WriteType(LPCTSTR lpszKey, const T& type, LPCTSTR lpszPassword = NULL, const CCrypt::Algorithm& eAlgorithm = CCrypt::Algorithm::eMD5)
	{
		ASSERT(lpszKey);
		
		CMemFile file;
		CArchive ar(&file, CArchive::store);
		
		ar << type;
		ar.Close();
		
		DWORD dwSize = file.GetLength();

#ifdef _DEBUG
		if (dwSize > 2048)
			TRACE1("CRegistry::WriteType - Object size = %d (> 2048) better use a file !\n", dwSize);
#endif

		BYTE* pByte = file.Detach();
		
		if (lpszPassword)
			if (!Encrypt(pByte, dwSize, lpszPassword, eAlgorithm))
				return FALSE;
			
		LONG lResult = RegSetValueEx(m_hKey, lpszKey, NULL, REG_BINARY, pByte, dwSize);
			
		if (pByte)
			free(pByte);
			
		if(lResult == ERROR_SUCCESS)
			return TRUE;
			
		return FALSE;
	}
	
	template<class T>
	AFX_INLINE BOOL ReadType(LPCTSTR lpszKey, T& type, LPCTSTR lpszPassword = NULL, const CCrypt::Algorithm& eAlgorithm = CCrypt::Algorithm::eMD5)
	{
		ASSERT(lpszKey);
		
		DWORD dwType = -1;
		DWORD dwSize = -1;
		BYTE* pByte = NULL;
		
		LONG lResult = RegQueryValueEx(m_hKey, lpszKey, NULL, &dwType, pByte, &dwSize);
		
		if (lResult == ERROR_SUCCESS && dwType == REG_BINARY)
			pByte = new BYTE[dwSize];		
		
		lResult = RegQueryValueEx(m_hKey, lpszKey, NULL, &dwType, pByte, &dwSize);
		if (lResult == ERROR_SUCCESS && dwType == REG_BINARY)
		{
			if (lpszPassword)
				if (!Decrypt(pByte, dwSize, lpszPassword, eAlgorithm))
					return FALSE;
				
			CMemFile file(pByte, dwSize);
			CArchive ar(&file, CArchive::load);
				
			ar >> type;
			ar.Close();
				
			file.Close();
				
			delete pByte;
			return TRUE;
		}
		
		delete pByte;
		return FALSE;
	}
	
	template<class T>
	AFX_INLINE BOOL WriteDynObj(LPCTSTR lpszKey, const T* pObject, LPCTSTR lpszPassword = NULL, const CCrypt::Algorithm& eAlgorithm = CCrypt::Algorithm::eMD5)
	{
		ASSERT(m_hKey);
		ASSERT(lpszKey);
		
		CMemFile file;
		CArchive ar(&file, CArchive::store);
		
		ar << pObject;
		ar.Close();
		
		DWORD dwSize = file.GetLength();

#ifdef _DEBUG
		if (dwSize > 2048)
			TRACE2("CRegistry::WriteDynObj - Object[%s] size = %d (> 2048) better use a file !\n",
			pObject->GetRuntimeClass()->m_lpszClassName,
			dwSize);
#endif

		BYTE* pByte = file.Detach();
		
		if (lpszPassword)
			if (!Encrypt(pByte, dwSize, lpszPassword, eAlgorithm))
				return FALSE;
			
		LONG lResult = RegSetValueEx(m_hKey, lpszKey, NULL, REG_BINARY, pByte, dwSize);
			
		if (pByte)
			free(pByte);
			
		if(lResult == ERROR_SUCCESS)
			return TRUE;
			
		return FALSE;
	}
	
	template<class T>
	AFX_INLINE BOOL ReadDynObj(LPCTSTR lpszKey, T*& pObject, LPCTSTR lpszPassword = NULL, const CCrypt::Algorithm& eAlgorithm = CCrypt::Algorithm::eMD5)
	{
		ASSERT(m_hKey);
		ASSERT(lpszKey);
		
		DWORD dwType = -1;
		DWORD dwSize = -1;
		BYTE* pByte = NULL;
		
		LONG lResult = RegQueryValueEx(m_hKey, lpszKey, NULL, &dwType, pByte, &dwSize);
		
		if (lResult == ERROR_SUCCESS && dwType == REG_BINARY)
			pByte = new BYTE[dwSize];
		
		lResult = RegQueryValueEx(m_hKey, lpszKey, NULL, &dwType, pByte, &dwSize);
		if (lResult == ERROR_SUCCESS && dwType == REG_BINARY)
		{
			if (lpszPassword)
				if (!Decrypt(pByte, dwSize, lpszPassword, eAlgorithm))
					return FALSE;
				
			CMemFile file(pByte, dwSize);
			CArchive ar(&file, CArchive::load);
				
			ar >> pObject;
			ar.Close();
				
			file.Close();
				
			delete pByte;
			return TRUE;
		}
		
		delete pByte;
		return FALSE;
	}
	
};

#endif // !defined(AFX_REGISTRY_H__08F26279_A63D_11D3_B73D_0050DA34A2BA__INCLUDED_)
