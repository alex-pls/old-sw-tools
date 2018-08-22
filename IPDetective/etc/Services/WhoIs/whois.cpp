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

#include "winsock.h"

#include "whois.h"
#pragma hdtstop         //Added
#pragma argsused

using namespace std;


int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            // Code to run when the DLL is loaded
                 WSADATA wsad;
                 char szServer[ 256 ];

                 if( WSAStartup( 0x0101, &wsad ) )          //  Initialize sockets here
                        {
                        MessageBox( hinst, "Sockets initialization failed!", "WinWho", MB_OK | MB_ICONSTOP );
                        return false;
                        };
            break;

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

extern "C" bool __declspec(dllexport) WINAPI  WhoIs(AnsiString server, AnsiString ip, TMemo* Report)
 {
		MessageBox ( NULL, "UU", server.c_str(), MB_OK );
		MessageBox ( NULL, "UU", ip.c_str(), MB_OK );
   struct hostent *phe;
   char szHost[ 256 ], szName[ 256 ];
   char *pszBase, *pszNext;
   SOCKET s;
   SOCKADDR_IN sin;
   int iStatus;
   BYTE *bAddr;
   char *szBuffer;
         
   
// check        szName          szHost

   phe = gethostbyname( server.c_str() );
   if( ! phe )
   {
      MessageBox( NULL, "Unable to locate specified Server!", "WinWho",
                  MB_OK | MB_ICONEXCLAMATION );
      return( FALSE );
   };

   s = socket( PF_INET, SOCK_STREAM, 0 );
   if( s != INVALID_SOCKET )
   {
      bAddr = *phe->h_addr_list;              //  Fill in connection data
      sin.sin_family = AF_INET;
      sin.sin_port = htons( IPPORT_WHOIS );
      sin.sin_addr.s_addr = *(LPDWORD)bAddr;
      iStatus = connect( s, (LPSOCKADDR)&sin, sizeof(SOCKADDR_IN) );

      if( iStatus != SOCKET_ERROR )         //  If host connection failed
      {
//         hMem = GlobalAlloc( GHND, 32780 );
//         szBuffer = GlobalLock( hMem );
         szBuffer = (char*)malloc( 32780 );

         iStatus = send( s, ip.c_str(), lstrlen(ip.c_str()), 0 );
         send( s, "\r\n", 2, 0 );

         while( 1 )
         {
            iStatus = recv( s, szBuffer + lstrlen( szBuffer ),
                            32767 - lstrlen( szBuffer ), 0 );
            if( iStatus == 0 )
               break;
         }

         iStatus = lstrlen( szBuffer );
         if( iStatus )
         {
            Report->Lines->Add("RESET !???!?!?!");
            pszBase = szBuffer;
            while( 1 )
            {
               pszNext = strchr( pszBase, '\r' );
               if( ! pszNext )
                  pszNext = strchr( pszBase, '\n' );

               if( pszNext )
               {
                  *pszNext = '\0';
                  ++pszNext;
                  if( *pszNext == '\n' )
                     ++pszNext;
               };

               Report->Lines->Add(pszBase);
               if( pszNext )
                  pszBase = pszNext;
               else
                  break;
            }
         }
        delete []szBuffer;
      }
      closesocket( s );
   }
   return true;
 }


extern "C" bool __declspec(dllexport) WINAPI  ValidateServers(AnsiString ip, int port, TMemo* Report)
 {
		MessageBox ( NULL, "UU", ip.c_str(), MB_OK );
		MessageBox ( NULL, "UU", AnsiString(port).c_str(), MB_OK );

        return true;
 }


