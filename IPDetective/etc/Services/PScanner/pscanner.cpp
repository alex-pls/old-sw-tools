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

#include <winsock2.h>

#include "pscanner.h"

#pragma hdtstop         //Added
#pragma argsused




using namespace std;


int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            // Code to run when the DLL is loaded
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

extern "C" bool __declspec(dllexport) WINAPI Scan(int MethodID, TMemo *Report)
 {
        switch (MethodID)
          {
          case 0: //LameScan()
                  break;
          };

        return true;
 };

extern "C" bool __declspec(dllexport) WINAPI LameScan(AnsiString strHostOrIP, LIVE_PORTS *pPorts, unsigned int nPort, TMemo *Report)
{
	struct servent		*pServent;
	struct sockaddr_in	sa_in;
	struct hostent		*pHostEnt;
	int					sock;
        WSADATA wsad;

	if(strHostOrIP == "")
		return false;

        Report->Lines->Add("");
        Report->Lines->Add("__________Starting Lame Port Scanner to " + strHostOrIP);

	pHostEnt = gethostbyname( ( char *) strHostOrIP.c_str());

	if(pHostEnt == NULL)
                {
                Report->Lines->Add("ERROR|\tCannot resolve " + strHostOrIP);
		return false;
                };

        if( WSAStartup( 0x0101, &wsad ) )          //  Initialize sockets here
                {
                MessageBox( NULL, "Sockets initialization failed!", "LamePortScanner", MB_OK | MB_ICONSTOP );
                return false;
                };

	sa_in.sin_family = AF_INET;
	sa_in.sin_port = htons(nPort);
	memcpy(&(sa_in.sin_addr.s_addr), pHostEnt->h_addr, sizeof(int));

	sock = socket(AF_INET, SOCK_STREAM, 6);

	if(sock == 0)
                {
                Report->Lines->Add("ERROR|\tCannot initialize socket.");
                WSACleanup();
		return false;
                };

	// check for available ports:
	if((pServent = getservbyport(htons(nPort), NULL)) != (struct servent *)NULL)
	{
		// existing port.

	}
	if(connect(sock, (struct sockaddr *)&sa_in, sizeof(sa_in)))
	{
                Report->Lines->Add(InterpretError( WSAGetLastError() ));
                WSACleanup();
		return FALSE;
	}
	else
	{
		
		if(pServent)
		{
			pPorts->strName = pServent->s_name;
			//pPorts->strAliases = pServent->s_aliases;
			pPorts->s_port = nPort;
			pPorts->strProto = pServent->s_proto;
		}
		else
		{
			pPorts->strName = "Unknown";
			//pPorts->strAliases = pServent->s_aliases;
			pPorts->s_port = nPort;
			pPorts->strProto = "Unknown";
		}
	}

	closesocket(sock);
        WSACleanup();
	return TRUE;
}


AnsiString InterpretError(unsigned int nErrCode)
{
	AnsiString strRet = "";
	switch(nErrCode)
	{
	case WSANOTINITIALISED: 
		strRet = "A successful WSAStartup must occur before using this function.";
		break;
	case WSAENETDOWN :
		strRet = "The network subsystem has failed. ";
		break;
	case WSAEADDRINUSE :
		strRet = "The specified address is already in use. ";
		break;
	case WSAEINTR:
		strRet = "The (blocking) call was canceled through WSACancelBlockingCall. ";
		break;
	case WSAEINPROGRESS :
		strRet = "A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. ";
		break;
	case WSAEALREADY :
		strRet = "A nonblocking connect call is in progress on the specified socket. ";
		break;
	case WSAEADDRNOTAVAIL :
		strRet = "The specified address is not available from the local machine. ";
		break;
	case WSAEAFNOSUPPORT :
		strRet = "Addresses in the specified family cannot be used with this socket. ";
		break; 
	case WSAECONNREFUSED :
		strRet = "The attempt to connect was forcefully rejected. ";
		break;
	case WSAEFAULT :
		strRet = "The name or the namelen parameter is not a valid part of the user address space, the namelen parameter is too small, or the name parameter contains incorrect address format for the associated address family. ";
		break;
	case WSAEINVAL :
		strRet = "The parameter s is a listening socket, or the destination address specified is not consistent with that of the constrained group the socket belongs to. ";
		break;
	case WSAEISCONN :
		strRet = "The socket is already connected (connection-oriented sockets only). ";
		break;
	case WSAENETUNREACH :
		strRet = "The network cannot be reached from this host at this time. ";
		break;
	case WSAENOBUFS :
		strRet = "No buffer space is available. The socket cannot be connected. ";
		break;
	case WSAENOTSOCK :
		strRet = "The descriptor is not a socket. ";
		break;
	case WSAETIMEDOUT :
		strRet = "Attempt to connect timed out without establishing a connection. ";
		break;
	case WSAEWOULDBLOCK :
		strRet = "The socket is marked as nonblocking and the connection cannot be completed immediately. Use select to determine the completion of the connection request by checking to see if the socket is writable. ";
		break;
	case WSAEACCES :
		strRet = "Attempt to connect datagram socket to broadcast address failed because setsockopt option SO_BROADCAST is not enabled. ";
		break;
	default:
		strRet = "Undefined";
	}
	return strRet;
}

