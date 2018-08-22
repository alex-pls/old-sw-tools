
#include <atlbase.h>
#include <vcl.h>
#include "software.h"



//Operating System Information Checker

AnsiString OsVersionChecker::GetSystemVersion(void)
	{
           AnsiString szSysInfo;
	   OSVERSIONINFOEX osvi;
	   BOOL bOsVersionInfoEx;

	   ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	   osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	   if( !(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi)) )
	   {
		  osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		  if (! GetVersionEx ( (OSVERSIONINFO *) &osvi) ) 
			 return szSysInfo;
	   };

	   switch (osvi.dwPlatformId)
	   {
		  case VER_PLATFORM_WIN32_NT:
                         {
			 if ( osvi.dwMajorVersion <= 4 )
				szSysInfo="Microsoft Windows NT";

			 if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
				szSysInfo="Microsoft Windows 2000";

			 if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1 )
				szSysInfo="Microsoft Windows XP";
			 break;
                         }
		  case VER_PLATFORM_WIN32_WINDOWS:
                         {
			 if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0)
			 {
				 szSysInfo = "Microsoft Windows 95";
			  };

			 if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 10)
			 {
				 szSysInfo += "Microsoft Windows 98";
			 };

			 if (osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 90)
			 {
				 szSysInfo = "Microsoft Windows Me";
			 };
			 break;
                         }
		  case VER_PLATFORM_WIN32s:
			 szSysInfo = "Microsoft Win32s";
			 break;
	   };
	   return szSysInfo; 
	};

bool OsVersionChecker::IsOS(AnsiString szOsName)
	{
		if(szOsName == "NT")
		{
			if( GetSystemVersion() == "Microsoft Windows NT")
				return TRUE;
		}
		else if(szOsName == "XP")
		{
			if( GetSystemVersion() == "Microsoft Windows 2000")
				return TRUE;
		}
		else if(szOsName == "2000")
		{
			if( GetSystemVersion() == "Microsoft Windows XP")
				return TRUE;
		}
		else if(szOsName == "95")
		{
			if( GetSystemVersion() == "Microsoft Windows 95")
				return TRUE;
		}
		else if(szOsName == "98")
		{
			if( GetSystemVersion() == "Microsoft Windows 98")
				return TRUE;
		}
		else if(szOsName == "ME")
		{
			if( GetSystemVersion() == "Microsoft Windows Me")
				return TRUE;
		}
		return false;
	};



////////////////////////////////////////////////////////////////////////////////
