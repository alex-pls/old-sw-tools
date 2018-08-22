// Registry.cpp: implementation of the CRegistry class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Registry.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Crypt.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



/******************************* CRegistry::CRegistry ********************************
description:
   Constructor

@hKey[in]:
   Section key

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:05:35
creator: Frank
*****************************************************************************************/
CRegistry::CRegistry(HKEY hKey /* = HKEY_CURRENT_USER */)
{
	ASSERT(hKey);
	m_hKey = hKey;
}



/****************************** CRegistry::~CRegistry *******************************
description:
   Destructor

access: public, state: virtual
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:06:00
creator: Frank
*****************************************************************************************/
CRegistry::~CRegistry()
{
	Close();
}



/********************************** CRegistry::Open ***********************************
description:
   Open the a specified key of the registry

@hKey[in]:
   Section key
@lpszPath[in]:
   Path to open
@dwMask[in]:
   Access mask

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:07:17
creator: Frank
*****************************************************************************************/
BOOL CRegistry::Open(HKEY hKey, 
										 LPCTSTR lpszPath,
										 const REGSAM& dwMask /* = KEY_ALL_ACCESS */)
{
	ASSERT(hKey);
	ASSERT(lpszPath);

	m_sPath = lpszPath;

	LONG lResult = RegOpenKeyEx(hKey, lpszPath, NULL, dwMask, &m_hKey);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/********************************** CRegistry::Open ***********************************
description:
   Open the "standard" key of the registry

@lpszPath[in]:
   Path to open
@dwMask[in]:
   Access mask

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:07:54
creator: Frank
*****************************************************************************************/
BOOL CRegistry::Open(LPCTSTR lpszPath,
										 const REGSAM& dwMask /* = KEY_ALL_ACCESS */)
{
	ASSERT(m_hKey);
	ASSERT(lpszPath);

	m_sPath = lpszPath;

	LONG lResult = RegOpenKeyEx(m_hKey, lpszPath, NULL, dwMask, &m_hKey);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/********************************** CRegistry::Close ***********************************
description:
   Closes the registry

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:08:11
creator: Frank
*****************************************************************************************/
void CRegistry::Close()
{
	if (m_hKey)
		RegCloseKey(m_hKey);
}



/******************************** CRegistry::VerifyKey *********************************
description:
   Verifies a specified key

@hKey[in]:
   Section key
@lpszPath[in]:
   Path to verify
@bOpen[in]:
   TRUE opens the key if exists
@dwMask[in]:
   Access mask

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:09:43
creator: Frank
*****************************************************************************************/
BOOL CRegistry::VerifyKey(HKEY hKey,
													LPCTSTR lpszPath,
													const BOOL& bOpen /* = FALSE */,
													const REGSAM& dwMask /* = KEY_ALL_ACCESS */)
{
	ASSERT(hKey);
	ASSERT(lpszPath);
	
	LONG lResult = RegOpenKeyEx(hKey, lpszPath, NULL, dwMask, &hKey);

	if (bOpen && lResult == ERROR_SUCCESS)
	{
		m_hKey = hKey;
		return TRUE;
	}
	else if (lResult == ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		return TRUE;
	}
	else
		return FALSE;
}



/******************************** CRegistry::VerifyKey *********************************
description:
   Verifies a specified key

@lpszPath[in]:
   Path to verify
@bOpen[in]:
   TRUE opens the key if exists
@dwMask[in]:
   Access mask

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:10:25
creator: Frank
*****************************************************************************************/
BOOL CRegistry::VerifyKey(LPCTSTR lpszPath,
													const BOOL& bOpen /* = FALSE */,
													const REGSAM& dwMask /* = KEY_ALL_ACCESS */)
{
	ASSERT(m_hKey);
	ASSERT(lpszPath);
	
	HKEY hKey = NULL;

	LONG lResult = RegOpenKeyEx(m_hKey, lpszPath, NULL, dwMask, &hKey);

	if (bOpen && lResult == ERROR_SUCCESS)
	{
		m_hKey = hKey;
		return TRUE;
	}
	else if (lResult == ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		return TRUE;
	}
	else
		return FALSE;
}



/******************************* CRegistry::VerifyValue ********************************
description:
   Verifies a specified value

@hKey[in]:
   Section key
@lpszValue[in]:
   The value

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:11:25
creator: Frank
*****************************************************************************************/
BOOL CRegistry::VerifyValue(HKEY hKey,
														LPCTSTR lpszValue)
{
	ASSERT(hKey);
	ASSERT(lpszValue);

	LONG lResult = RegQueryValueEx(hKey, lpszValue, NULL, NULL, NULL, NULL);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************* CRegistry::VerifyValue ********************************
description:
   Verifies a specified value

@lpszValue[in]:
   The value

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:10:53
creator: Frank
*****************************************************************************************/
BOOL CRegistry::VerifyValue(LPCTSTR lpszValue)
{
	ASSERT(m_hKey);
	ASSERT(lpszValue);

	LONG lResult = RegQueryValueEx(m_hKey, lpszValue, NULL, NULL, NULL, NULL);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************** CRegistry::CreateKey *********************************
description:
   Creates a key

@hKey[in]:
   Section key
@lpszPath[in]:
   Path to create
@bOpen[in]:
   TRUE opens the key if it was created successfully
@dwOptions[in]:
   Create a volatile or non volatile key
@dwMask[in]:
   Access mask

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:12:54
creator: Frank
*****************************************************************************************/
BOOL CRegistry::CreateKey(HKEY hKey,
													LPCTSTR lpszPath,
													const BOOL& bOpen /* = FALSE */,
													const DWORD& dwOptions /* = REG_OPTION_NON_VOLATILE */,
													const REGSAM& dwMask /* = KEY_ALL_ACCESS */)
{
	ASSERT(hKey);
	ASSERT(lpszPath);

	DWORD dwDisp = -1;

	LONG lResult = RegCreateKeyEx(hKey, lpszPath, NULL, NULL, dwOptions, dwMask, NULL, &hKey, &dwDisp);

	if (bOpen)
		m_hKey = hKey;
	else
		RegCloseKey(hKey);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************** CRegistry::CreateKey *********************************
description:
   Creates a key

@lpszPath[in]:
   Path to create
@bOpen[in]:
   TRUE opens the key if it was created successfully
@dwOptions[in]:
   Create a volatile or non volatile key
@dwMask[in]:
   Access mask

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:13:40
creator: Frank
*****************************************************************************************/
BOOL CRegistry::CreateKey(LPCTSTR lpszPath,
														const BOOL& bOpen /* = FALSE */,
														const DWORD& dwOptions /* = REG_OPTION_NON_VOLATILE */,
														const REGSAM& dwMask /* = KEY_ALL_ACCESS */)
{
	ASSERT(m_hKey);
	ASSERT(lpszPath);

	HKEY hKey = NULL;
	LONG lResult = -1;
	DWORD dwDisp = -1;

	if (bOpen)
		lResult = RegCreateKeyEx(m_hKey, lpszPath, NULL, NULL, dwOptions, dwMask, NULL, &m_hKey, &dwDisp);
	else
	{
		lResult = RegCreateKeyEx(m_hKey, lpszPath, NULL, NULL, dwOptions, dwMask, NULL, &hKey, &dwDisp);
		RegCloseKey(hKey);
	}

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************** CRegistry::DeleteKey *********************************
description:
   Deletes a key

@hKey[in]:
   Section key
@lpszPath[in]:
   Path to delete

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:14:07
creator: Frank
*****************************************************************************************/
BOOL CRegistry::DeleteKey(HKEY hKey,
														LPCTSTR lpszPath)
{
	ASSERT(hKey);
	ASSERT(lpszPath);

	LONG lResult = RegDeleteKey(hKey, lpszPath);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************** CRegistry::DeleteKey *********************************
description:
   Deletes a key

@lpszPath[in]:
   Path to delete

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:14:19
creator: Frank
*****************************************************************************************/
BOOL CRegistry::DeleteKey(LPCTSTR lpszPath)
{
	ASSERT(m_hKey);
	ASSERT(lpszPath);

	LONG lResult = RegDeleteKey(m_hKey, lpszPath);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************* CRegistry::DeleteValue ********************************
description:
   Deletes a value

@hKey[in]:
   Section key
@lpszValue[in]:
   Value to delete

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:14:41
creator: Frank
*****************************************************************************************/
BOOL CRegistry::DeleteValue(HKEY hKey,
															LPCTSTR lpszValue)
{
	ASSERT(hKey);
	ASSERT(lpszValue);

	LONG lResult = RegDeleteValue(hKey, lpszValue);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************* CRegistry::DeleteValue ********************************
description:
   Deletes a value

@lpszValue[in]:
   Value to delete

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:14:59
creator: Frank
*****************************************************************************************/
BOOL CRegistry::DeleteValue(LPCTSTR lpszValue)
{
	ASSERT(m_hKey);
	ASSERT(lpszValue);

	LONG lResult = RegDeleteValue(m_hKey, lpszValue);

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************* CRegistry::WriteString ********************************
description:
   Writes a string to the registry

@lpszKey[in]:
   Key to write
@lpszData[in]:
   Data to write

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:15:40
creator: Frank
*****************************************************************************************/
BOOL CRegistry::WriteString(LPCTSTR lpszKey,
															LPCTSTR lpszData)
{
	ASSERT(m_hKey);
	ASSERT(lpszKey);
	ASSERT(lpszData);

	LONG lResult = RegSetValueEx(m_hKey, lpszKey, NULL, REG_SZ, (const BYTE*) lpszData, strlen(lpszData) + 1);

	if(lResult == ERROR_SUCCESS)
		return TRUE;
	
	return FALSE;
}



/******************************* CRegistry::ReadString ********************************
description:
   Reads a string from the registry

@lpszKey[in]:
   Key to read
@sData[out]:
   Data to read

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:16:14
creator: Frank
*****************************************************************************************/
BOOL CRegistry::ReadString(LPCTSTR lpszKey, CString& sData)
{
	ASSERT(m_hKey);
	ASSERT(lpszKey);

	DWORD dwType = -1;
	DWORD dwSize = -1;

	LONG lResult = RegQueryValueEx(m_hKey, (LPSTR) lpszKey, NULL, &dwType, NULL, &dwSize);

	if(lResult == ERROR_SUCCESS && dwType == REG_SZ)
	{
		BYTE* pByte = new BYTE[dwSize];
		lResult = RegQueryValueEx(m_hKey, (LPSTR) lpszKey, NULL, &dwType, pByte, &dwSize);
		if (lResult == ERROR_SUCCESS && dwType == REG_SZ)
		{
			sData = pByte;
			delete pByte;
			return TRUE;
		}

		delete pByte;
		return TRUE;
	}
	else
		return FALSE;
}



/******************************* CRegistry::WriteDWORD ********************************
description:
   Writes a DWORD to the registry

@lpszKey[in]:
   Key to write
@dwData[in]:
   Data to write

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:16:54
creator: Frank
*****************************************************************************************/
BOOL CRegistry::WriteDWORD(LPCTSTR lpszKey,
														 const DWORD& dwData)
{
	ASSERT(m_hKey);
	ASSERT(lpszKey);
	
	LONG lResult = RegSetValueEx(m_hKey, lpszKey, NULL, REG_DWORD, (const BYTE*) &dwData, sizeof(DWORD));

	if(lResult == ERROR_SUCCESS)
		return TRUE;

	return FALSE;
}



/******************************** CRegistry::ReadDWORD *********************************
description:
   Reads a DWORD from the registry

@lpszKey[in]:
   Key to read
@dwData[out]:
   Data to read

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:17:36
creator: Frank
*****************************************************************************************/
BOOL CRegistry::ReadDWORD(LPCTSTR lpszKey,
														DWORD &dwData)
{
	ASSERT(m_hKey);
	ASSERT(lpszKey);

	DWORD dwType = -1;
	DWORD dwSize = sizeof(DWORD);

	LONG lResult = RegQueryValueEx(m_hKey, (LPSTR) lpszKey, NULL,& dwType, (BYTE*) &dwData, &dwSize);

	if(lResult == ERROR_SUCCESS && dwType == REG_DWORD)
		return TRUE;

	return FALSE;
}



/******************************** CRegistry::WriteWnd *********************************
description:
   Writes a window position to the registry

@lpszKey[in]:
   Key to write
@pWnd[in]:
   Points to the window to write

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:18:30
creator: Frank
*****************************************************************************************/
BOOL CRegistry::WriteWnd(LPCTSTR lpszKey,
													 CWnd* pWnd)
{
	ASSERT(m_hKey);
	ASSERT(lpszKey);
	ASSERT_VALID(pWnd);

	WINDOWPLACEMENT wp;
	::ZeroMemory(&wp, sizeof(WINDOWPLACEMENT));
	wp.length = sizeof(WINDOWPLACEMENT);
	pWnd->GetWindowPlacement(&wp);

	CMemFile file;
	CArchive ar(&file, CArchive::store);

	ar << wp.flags
		 << wp.showCmd
		 << wp.ptMinPosition
		 << wp.ptMaxPosition
		 << wp.rcNormalPosition;
	ar.Close();

	DWORD dwSize = file.GetLength();
	BYTE* pByte = file.Detach();

	LONG lResult = RegSetValueEx(m_hKey, lpszKey, NULL, REG_BINARY, pByte, dwSize);

	if (pByte)
		free(pByte);

	if(lResult == ERROR_SUCCESS)
		return TRUE;
	
	return FALSE;
}



/********************************* CRegistry::ReadWnd **********************************
description:
   Reads a window from the registry

@lpszKey[in]:
   Key to read
@pWnd[in]:
   Points to the window to read

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:19:06
creator: Frank
*****************************************************************************************/
BOOL CRegistry::ReadWnd(LPCTSTR lpszKey,
													CWnd* pWnd)
{
	ASSERT(m_hKey);
	ASSERT(lpszKey);
	ASSERT_VALID(pWnd);

	DWORD dwType;
	DWORD dwSize = sizeof(WINDOWPLACEMENT);
	BYTE* pByte = new BYTE[dwSize];

	WINDOWPLACEMENT wp;
	::ZeroMemory(&wp, dwSize);
	wp.length = dwSize;

	LONG lResult = RegQueryValueEx(m_hKey, lpszKey, NULL, &dwType, pByte, &dwSize);

	if(lResult == ERROR_SUCCESS && dwType == REG_BINARY)
	{
		CMemFile file(pByte, dwSize);
		CArchive ar(&file, CArchive::load);

		ar >> wp.flags
			 >> wp.showCmd
			 >> wp.ptMinPosition
			 >> wp.ptMaxPosition
			 >> wp.rcNormalPosition;
		ar.Close();

		file.Close();
		
		pWnd->SetWindowPlacement(&wp);

		delete pByte;
		return TRUE;
	}

	delete pByte;
	return FALSE;
}



/******************************** CRegistry::WriteObj *********************************
description:
   Writes a "CObject" derived object to the registry

@lpszKey[in]:
   Key to write
@object[out]:
   Object to write to the registry
@lpszPassword[in]:
   Password used for encryption (optional)
@eAlgorithm[in]:
   Algorithm used for encryption (optional)

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:20:21
creator: Frank
*****************************************************************************************/
BOOL CRegistry::WriteObj(LPCTSTR lpszKey,
													 CObject& object,
													 LPCTSTR lpszPassword /* = NULL */,
													 const CCrypt::Algorithm& eAlgorithm /* = CCrypt::Algorithm::eMD5 */)
{
	ASSERT(m_hKey);
	ASSERT(lpszKey);
	ASSERT_VALID(&object);
	
	CMemFile file;
	CArchive ar(&file, CArchive::store);
	
	object.Serialize(ar);
	ar.Close();
	
	DWORD dwSize = file.GetLength();

#ifdef _DEBUG
		if (dwSize > 2048)
			TRACE2("CRegistry::WriteObj - Object[%s] size = %d (> 2048) better use a file !\n",
				object.GetRuntimeClass()->m_lpszClassName,
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



/********************************* CRegistry::ReadObj **********************************
description:
   Reads a "CObject" derived object from the registry

@lpszKey[in]:
   Key to read
@object[out]:
   Object to read from the registry
@lpszPassword[in]:
   Password used for decryption
@eAlgorithm[in]:
   Algorithm used for decryption

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:22:01
creator: Frank
*****************************************************************************************/
BOOL CRegistry::ReadObj(LPCTSTR lpszKey,
													CObject& object,
													LPCTSTR lpszPassword /* = NULL */,
													const CCrypt::Algorithm& eAlgorithm /* = CCrypt::Algorithm::eMD5 */)
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
		
		object.Serialize(ar);
		ar.Close();
			
		ASSERT_VALID(&object);

		file.Close();
			
		delete pByte;
		return TRUE;
	}

	delete pByte;
	return FALSE;
}



/********************************* CRegistry::Encrypt **********************************
description:
   Encryption for BYTE pointers

@pByte[out]:
   Pointer to the buffer to be encrypted. Contains encrypted data after encryption
@dwSize[out]:
   Size of buffer before and after encryption
@lpszPassword[in]:
   Password used for encryption
@eAlgorithm[in]:
   Algorithm used for encryption

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:23:04
creator: Frank
*****************************************************************************************/
BOOL CRegistry::Encrypt(BYTE*& pByte,
													DWORD& dwSize,
													LPCTSTR lpszPassword,
													const CCrypt::Algorithm& eAlgorithm)
{
	ASSERT(pByte);
	ASSERT(dwSize > 0);
	ASSERT(lpszPassword);

	BYTE* pByteOut = NULL;

	CCrypt crypt;
	if (!crypt.Encrypt(pByte, pByteOut, dwSize, lpszPassword, eAlgorithm))
		return FALSE;

	delete pByte;
	pByte = pByteOut;

	return TRUE;
}



/********************************* CRegistry::Decrypt **********************************
description:
   Decryption for BYTE pointers

@pByte[out]:
   Pointer to the buffer to be decrypted. Contains decrypted data after decryption
@dwSize[out]:
   Size of buffer before and after decryption
@lpszPassword[in]:
   Password used for decryption
@eAlgorithm[in]:
   Algorithm used for decryption

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:24:35
creator: Frank
*****************************************************************************************/
BOOL CRegistry::Decrypt(BYTE*& pByte,
													DWORD& dwSize,
													LPCTSTR lpszPassword,
													const CCrypt::Algorithm& eAlgorithm)
{
	ASSERT(pByte);
	ASSERT(dwSize > 0);
	ASSERT(lpszPassword);

	BYTE* pByteOut = NULL;

	CCrypt crypt;
	if (!crypt.Decrypt(pByte, pByteOut, dwSize, lpszPassword, eAlgorithm))
		return FALSE;

	delete pByte;
	pByte = pByteOut;

	return TRUE;
}
