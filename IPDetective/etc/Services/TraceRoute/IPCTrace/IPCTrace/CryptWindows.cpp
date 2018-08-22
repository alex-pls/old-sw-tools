// CryptWindows.cpp: implementation of the CCryptWindows class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CryptWindows.h"

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif

#ifndef NOCRYPT
#include <wincrypt.h>
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



/*************************** CCryptWindows::CCryptWindows ****************************
description:
   Constructor

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:01:00
creator: Frank
*****************************************************************************************/
CCryptWindows::CCryptWindows()
{
	m_bInit = Init();
}



/************************** CCryptWindows::~CCryptWindows ***************************
description:
   Destructor

access: public, state: virtual
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:01:06
creator: Frank
*****************************************************************************************/
CCryptWindows::~CCryptWindows()
{

}



/******************************** CCryptWindows::Init *********************************
description:
   Initializes the windows crypto engine

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:01:33
creator: Frank
*****************************************************************************************/
BOOL CCryptWindows::Init()
{
	// Ensure that the default cryptographic client is set up...	
	HCRYPTPROV hProv = NULL;
	HCRYPTKEY hKey = NULL;

	// Attempt to acquire a handle to the default key container...
	if (!CryptAcquireContext(&hProv, NULL, MS_DEF_PROV, PROV_RSA_FULL, 0))	
	{
		// Some sort of error occured creating the default key container...
		if (!CryptAcquireContext(&hProv, NULL, MS_DEF_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
		{
			// Error creating key container...
			return FALSE;
		}
	}
	
	// Attempt to get handle to signature key...
	if (!CryptGetUserKey(hProv, AT_SIGNATURE, &hKey))	
	{
		if (GetLastError() == NTE_NO_KEY)
		{
			// Create signature key pair...
			if (!CryptGenKey(hProv, AT_SIGNATURE, 0, &hKey))			
			{
				// Error during CryptGenKey...
				CryptReleaseContext(hProv, 0);
				return FALSE;			
			}			
			else			
			{				
				// Release provider handle...
				CryptDestroyKey(hKey);			
			}
		}
		else 		
		{
			// Error during CryptGetUserKey...
			CryptReleaseContext(hProv, 0);
			return FALSE;		
		}	
	}
	
	// Attempt to get handle to exchange key...
	if (!CryptGetUserKey(hProv, AT_KEYEXCHANGE, &hKey))	
	{
		if (GetLastError() == NTE_NO_KEY)
		{
			// Create key exchange key pair...
			if (!CryptGenKey(hProv, AT_KEYEXCHANGE, 0, &hKey))			
			{
				// Error during CryptGenKey...	
				CryptReleaseContext(hProv, 0);
				return FALSE;			
			}			
			else			
			{		
				// Release provider handle...
				CryptDestroyKey(hKey);			
			}	
		}
		else		
		{
			// Error during CryptGetUserKey...
			CryptReleaseContext(hProv, 0);
			return FALSE;		
		}
	}

	CryptReleaseContext(hProv, 0);	
	return TRUE;
}



/******************************* CCryptWindows::Encrypt ********************************
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
created: 11.09.00 - 16:02:23
creator: Frank
*****************************************************************************************/
BOOL CCryptWindows::Encrypt(BYTE*& pByte,
															DWORD& dwSize,
															LPCTSTR lpszPassword,
															const CCrypt::Algorithm& eAlgorithm)
{
	ASSERT(pByte);
	ASSERT(lpszPassword);

	if (!m_bInit)
		return FALSE;

	BOOL bResult = FALSE;	
	
	HCRYPTPROV hProv = NULL;	
	HCRYPTHASH hHash = NULL;	
	HCRYPTKEY hKey = NULL;

	DWORD dwSizePwd = sizeof(TCHAR) * _tcslen(lpszPassword);

	// Get handle to user default provider...
	if (CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0))	
	{
		ALG_ID alg;
		switch (eAlgorithm)
		{
			case CCrypt::Algorithm::eMD2:
				alg = CALG_MD2;
				break;
			case CCrypt::Algorithm::eMD5:
				alg = CALG_MD5;
				break;
			case CCrypt::Algorithm::eSHA:
				alg = CALG_SHA;
				break;
			default:
				ASSERT(FALSE);
		}

		// Create hash object...
		if (CryptCreateHash(hProv, alg, 0, 0, &hHash))		
		{
			// Hash password...
			if (CryptHashData(hHash, (BYTE*) lpszPassword, dwSizePwd, 0))			
			{
				// Create block cipher session key based on hash of the password...
				if (CryptDeriveKey(hProv, CALG_RC4, hHash, CRYPT_EXPORTABLE, &hKey))				
				{
					// Encrypt data...
					if (CryptEncrypt(hKey, 0, TRUE, 0, pByte, &dwSize, dwSize)) 						
					{
						bResult = TRUE;									
					}	
					else						
					{							
						bResult = FALSE;						
					}						
					
					// Release provider handle...
					CryptDestroyKey(hKey);
				}				
				else				
				{
					bResult = FALSE;				
				}			
			}			
			else			
			{
				bResult = FALSE;			
			}

			// Destroy session key...
			CryptDestroyHash(hHash); 
		}		
		else		
		{
			bResult = FALSE;		
		}

		CryptReleaseContext(hProv, 0);	
	}	

	return bResult;
}



/******************************* CCryptWindows::Decrypt ********************************
description:
   Decryption for BYTE pointers

@pByte[out]:
   Pointer to the buffer to be decrypted. Contains decrypted data after decryption
@dwSize[out]:
   Size of buffer before and after encryption
@lpszPassword[in]:
   Password used for decryption
@eAlgorithm[in]:
   Algorithm used for decryption

value:
   TRUE | FALSE

access: public
------------------------------------------------------------------------------------------
created: 11.09.00 - 16:03:16
creator: Frank
*****************************************************************************************/
BOOL CCryptWindows::Decrypt(BYTE*& pByte,
															DWORD& dwSize,
															LPCTSTR lpszPassword,
															const CCrypt::Algorithm& eAlgorithm)
{	
	ASSERT(pByte);
	ASSERT(lpszPassword);

	if (!m_bInit)
		return FALSE;

	BOOL bResult = FALSE;

	HCRYPTPROV hProv = NULL;		
	HCRYPTHASH hHash = NULL;		
	HCRYPTKEY hKey = NULL;		

	DWORD dwSizePwd = sizeof(TCHAR) * _tcslen(lpszPassword);

	// Get handle to user default provider...
	if (CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0))		
	{
		ALG_ID alg;
		switch (eAlgorithm)
		{
			case CCrypt::Algorithm::eMD2:
				alg = CALG_MD2;
				break;
			case CCrypt::Algorithm::eMD5:
				alg = CALG_MD5;
				break;
			case CCrypt::Algorithm::eSHA:
				alg = CALG_SHA;
				break;
			default:
				ASSERT(FALSE);
		}

		// Create hash object...
		if (CryptCreateHash(hProv, alg, 0, 0, &hHash))
		{				
			// Hash password...
			if (CryptHashData(hHash, (BYTE*) lpszPassword, dwSizePwd, 0))				
			{
				// Create block cipher session key based on hash of the password...
				if (CryptDeriveKey(hProv, CALG_RC4, hHash, CRYPT_EXPORTABLE, &hKey))					
				{
					// Decrypt data...
					if (CryptDecrypt(hKey, 0, TRUE, 0, pByte, &dwSize))
					{
						bResult = TRUE;						
					}

					// Release provider handle...
					CryptDestroyKey(hKey);
				}					
				else					
				{
					bResult = FALSE;					
				}				
			}				
			else
			{					
				bResult = FALSE;				
			}

			// Destroy session key...
			CryptDestroyHash(hHash);
		}			
		else			
		{
			bResult = FALSE;			
		}

		CryptReleaseContext(hProv, 0);		
	}		

	return bResult;
}
