
#include <atlbase.h>
#include "software.h"
#include "network.h"

//Modem Checker


bool CModemCheck::IsModemInstalled()
{
	DWORD dwCount = 0;

	if( m_OSVersionCheck.IsOS("NT") || m_OSVersionCheck.IsOS("2000") || m_OSVersionCheck.IsOS("XP") )
	{
		if(m_CRegKey.Open( HKEY_LOCAL_MACHINE,"SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E96D-E325-11CE-BFC1-08002BE10318}" ) == ERROR_SUCCESS)
		{
			if( RegQueryInfoKey(m_CRegKey.m_hKey,NULL,NULL,NULL,&dwCount,NULL,NULL,NULL,NULL,NULL,NULL,NULL) == ERROR_SUCCESS )
			{
				m_CRegKey.Close();
				if( dwCount >= 1)
					return TRUE;
			}
			else
			{
				m_CRegKey.Close();
			}
		}
	}
	else 
	{
		if(m_CRegKey.Open( HKEY_LOCAL_MACHINE,"System\\CurrentControlSet\\Services\\Class\\Modem" ) ==ERROR_SUCCESS)
		{
			if( RegQueryInfoKey(m_CRegKey.m_hKey,NULL,NULL,NULL,&dwCount,NULL,NULL,NULL,NULL,NULL,NULL,NULL) == ERROR_SUCCESS )
			{
				m_CRegKey.Close();
				if( dwCount >= 1)
					return TRUE;
			}
			else
			{
				m_CRegKey.Close();
			}
		}
	}
	return FALSE;
}

void CModemCheck::StartModemInstallation()
{
	WinExec("rundll32.exe shell32.dll,Control_RunDLL Modem.cpl,,add",1);
}

////////////////////////////////////////////////////////////////////////////////


//Dial-up Networking(DUN), Remote Access Service(RAS) Checker.

bool CRASCheck::IsRASInstalled()
{
	DWORD dwLen;
	if( m_OSVersionCheck.IsOS("NT") || m_OSVersionCheck.IsOS("2000") || m_OSVersionCheck.IsOS("XP") ) 
	{
		if(m_CRegKey.Open(HKEY_LOCAL_MACHINE,"SYSTEM\\CurrentControlSet\\Services\\RemoteAccess") == ERROR_SUCCESS)
		{
			m_CRegKey.Close();
			return TRUE;
		}
	}
	else if(m_OSVersionCheck.IsOS("ME"))
	{
		if( m_CRegKey.Open( HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\OptionalComponents\\RNA\\" ) == ERROR_SUCCESS)
		{
			AnsiString szTemp;
			if(m_CRegKey.QueryValue(NULL,"Installed",&dwLen)==ERROR_SUCCESS)
			{
				if(m_CRegKey.QueryValue(szTemp,"Installed",&dwLen)==ERROR_SUCCESS)
				{
					szTemp.ReleaseBuffer();
					m_CRegKey.Close();

					szTemp.TrimLeft();
					szTemp.TrimRight();

					if(szTemp.IsEmpty())
					{
						MessageBox(0,"Sorry! Unable to detect whether Dial-up Networking is already installed or not.","Dial-up Networking Checker",MB_ICONERROR);
						PostQuitMessage(0);
					}
					
					if(szTemp.CompareNoCase("1")==0)
						return TRUE;
				}
			}
		}
	}
	else  
	{
		if(m_CRegKey.Open(HKEY_LOCAL_MACHINE,"System\\CurrentControlSet\\Services\\RemoteAccess\\NetworkProvider") == ERROR_SUCCESS)
		{
			m_CRegKey.Close();
			return TRUE;
		}
	}

	return FALSE;
};

void CRASCheck::StartRASInstallation()
{
	if( m_OSVersionCheck.IsOS("NT") || m_OSVersionCheck.IsOS("2000") || m_OSVersionCheck.IsOS("XP") )
	{
		WinExec("rasphone.exe",1);
	}
	else
	{
		WinExec("rundll.exe setupx.dll,InstallHinfSection rna 0 rna.inf",1);
	}
};



