// Crypt.cpp: implementation of the CCrypt class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Crypt.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "CryptWindows.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



/********************************** CCrypt::CCrypt ***********************************
description:
   Constructor

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 15:08:20
creator: Frank
*****************************************************************************************/
CCrypt::CCrypt()
{

}



/********************************* CCrypt::~CCrypt **********************************
description:
   Destructor

access: public, state: virtual
------------------------------------------------------------------------------------------
created: 11.09.00 - 15:08:27
creator: Frank
*****************************************************************************************/
CCrypt::~CCrypt()
{

}



/********************************** CCrypt::Encrypt ***********************************
description:
   Encryption for BYTE pointers

@pByteIn[in]:
   Pointer to the buffer to be encrypted
@pByteOut[out]:
   Pointer to the encrypted buffer
@dwSize[in][out]:
   Size of buffer before and after encryption
@lpszPassword[in]:
   Password used for encryption
@eAlgorithm[in]:
   Algorithm used for encryption

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 15:11:01
creator: Frank
*****************************************************************************************/
BOOL CCrypt::Encrypt(const BYTE* pByteIn,
											 BYTE*& pByteOut,
											 DWORD& dwSize,
											 LPCTSTR lpszPassword,
											 const Algorithm& eAlgorithm)
{	
	ASSERT(pByteIn);
	ASSERT(lpszPassword);

	BOOL bResult = FALSE;

	pByteOut = new BYTE[dwSize];
	if (!memcpy(pByteOut, pByteIn, dwSize))
		return FALSE;

	// Check which algorithm to use...
	switch (eAlgorithm)
	{
		case Algorithm::eMD2:
		case Algorithm::eMD5:
		case Algorithm::eSHA:
		{
			// Windows encryption
			CCryptWindows crypt;
			bResult = crypt.Encrypt(pByteOut, dwSize, lpszPassword, eAlgorithm);
			break;
		}
		default:
			ASSERT(FALSE);
	}

	if (!bResult)
	{
		delete pByteOut;
		pByteOut = NULL;
		return FALSE;
	}

	return TRUE;
}



/********************************** CCrypt::Decrypt ***********************************
description:
   Decryption for BYTE pointers

@pByteIn[in]:
   Pointer to the buffer to be decrypted
@pByteOut[out]:
   Pointer to the decrypted buffer
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
created: 11.09.00 - 15:12:23
creator: Frank
*****************************************************************************************/
BOOL CCrypt::Decrypt(const BYTE* pByteIn,
											 BYTE*& pByteOut,
											 DWORD& dwSize,
											 LPCTSTR lpszPassword,
											 const Algorithm& eAlgorithm)
{
	ASSERT(dwSize > 0);
	ASSERT(lpszPassword);

	BOOL bResult = FALSE;

	// Allocate a new buffer and copy the bytes...
	BYTE* pByte = new BYTE[dwSize];
	if (!memcpy(pByte, pByteIn, dwSize))
		return FALSE;
	
	// Check which algorithm to use...
	switch (eAlgorithm)
	{
		case Algorithm::eMD2:
		case Algorithm::eMD5:
		case Algorithm::eSHA:
		{
			// Windows decryption
			CCryptWindows crypt;
			bResult = crypt.Decrypt(pByte, dwSize, lpszPassword, eAlgorithm);
			break;
		}
		default:
			ASSERT(FALSE);
	}

	pByteOut = new BYTE[dwSize];
	if (!memcpy(pByteOut, pByte, dwSize))
		return FALSE;

	delete pByte;	

	if (!bResult)
	{
		delete pByteOut;
		pByteOut = NULL;
		return FALSE;
	}

	return TRUE;
}



/********************************* CCrypt::EncryptObj **********************************
description:
   Encryption for CObject derived objects

@object[in]:
   Object to be encrypted
@pData[out]:
   Pointer to the buffer 
@dwSize[out]:
   Size of buffer after decryption
@lpszPassword[in]:
   Password used for encryption
@eAlgorithm[in]:
   Algorithm used for encryption

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 15:14:24
creator: Frank
*****************************************************************************************/
BOOL CCrypt::EncryptObj(CObject& object, BYTE*& pData, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm)
{
	ASSERT(lpszPassword);
	
	BOOL bResult = TRUE;
	
	CMemFile file;
	CArchive ar(&file, CArchive::store);
	
	object.Serialize(ar);;
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



/********************************* CCrypt::DecryptObj **********************************
description:
   Decryption for CObject derived objects

@object[out]:
   Object to be decrypted
@pData[in]:
   Pointer to the buffer 
@dwSize[out]:
   Size of buffer
@lpszPassword[in]:
   Password used for decryption
@eAlgorithm[in]:
   Algorithm used for decryption

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 15:16:21
creator: Frank
*****************************************************************************************/
BOOL CCrypt::DecryptObj(CObject& object, const BYTE* pData, DWORD& dwSize, LPCTSTR lpszPassword, const Algorithm& eAlgorithm)
{
	ASSERT(dwSize > 0);
	ASSERT(lpszPassword);
		
	BYTE* pByte = NULL;
	if(!Decrypt(pData, pByte, dwSize, lpszPassword, eAlgorithm))
		return FALSE;

	CMemFile file(pByte, dwSize);
	CArchive ar(&file, CArchive::load);
			
	object.Serialize(ar);
	ar.Close();
			
	file.Close();
	
	delete pByte;
	return TRUE;
}
