//---------------------------------------------------------------------------

#include <vcl.h>
//#include <windows.h>
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------
#define BUILD_DLL       //Added
#define WINDOWS

#include "winsock.h"

//#include "stdio.h"

#include "proxy.h"
#include "httproxy.h"
#pragma hdtstop         //Added
#pragma argsused

using namespace std;


int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            // Code to run when the DLL is loaded
        case DLL_PROCESS_DETACH:
            // Code to run when the DLL is freed
            break;

        case DLL_THREAD_ATTACH:
            // Code to run when a thread is created during the DLL's lifetime
            break;

        case DLL_THREAD_DETACH:
            // Code to run when a thread ends normally.
            break;
    }
    return TRUE;
}

extern "C" HRESULT __declspec(dllexport) WINAPI DllGetVersion(dllversioninfo* Release)
        {
        Release->dwmajorversion = 1;
        Release->dwminorversion = 0;
        Release->dwbuildnumber = 10;

        return 1;
        }

extern "C" void __declspec(dllexport) WINAPI YourFunctionNumberOne()
	{
//		GetModuleFileName( NULL,FileName, sizeof (FileName) );
		MessageBox ( NULL, "UU", "Message", MB_OK );

}

extern "C" bool __declspec(dllexport) WINAPI  StartHTTP(AnsiString ip, int port, TMemo* Report)
 {
		MessageBox ( NULL, "UU", ip.c_str(), MB_OK );
		MessageBox ( NULL, "UU", AnsiString(port).c_str(), MB_OK );


	// In Windows, we need to explicitly fire up the sockets interface
	WORD wVersionRequested;
	WSADATA wsaData;

	SetProcessShutdownParameters(0x100, SHUTDOWN_NORETRY);
	wVersionRequested = MAKEWORD(2, 0);
	if (WSAStartup(wVersionRequested, &wsaData) != 0)
                return 0;

	//proxy_start(8888, "127.0.0.1", 8088, proxy_callback, 0);
	proxy_start(8888, NULL, 0, proxy_callback, 0, 0);
	return 0;




        return true;
 }



int proxy_callback(char *host, char *headers, int client_sock)
{
	// sample intervention - prank redirection - just try to visit www.microsoft.com
	if (!strcmp(host, "www.microsoft.com"))
	{
		char *reply = "HTTP/1.0 302 Found\nConnection: close\nLocation: http://www.farts.com\n\n";
		send(client_sock, reply, strlen(reply), 0);
		return 1;
	}
	return 0;
}


