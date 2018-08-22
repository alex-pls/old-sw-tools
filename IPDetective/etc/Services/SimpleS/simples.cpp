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

#include "simples.h"
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


extern "C" AnsiString __declspec(dllexport) WINAPI EnumServices(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return "Echo";
        case 1: return "DayTime";
       default: return "";
        };
 }

extern "C" AnsiString __declspec(dllexport) WINAPI GetServiceDesc(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return "Echo Service";
        case 1: return "DayTime Service";
       default: return "";
        };
 }

extern "C" int __declspec(dllexport) WINAPI GetServicePort(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return 7;
        case 1: return 13;
       default: return 0;
        };
 }

extern "C" bool __declspec(dllexport) WINAPI CallService(int ServiceID, AnsiString ip, int port, int proto, TMemo* Report)
{
switch (ServiceID)
        {
        case 0: return Echo(ip, port, proto, Report);
        case 1: return DayTime(ip, port, proto, Report);
       default: return false;
        };
 }

bool Echo(AnsiString ip, int port, int proto, TMemo* Report)
 {
	struct hostent		*hp;
	struct sockaddr_in	dest,from;
        WSADATA wsad;
	unsigned int		addr=0;

        Report->Lines->Add("");
        Report->Lines->Add("__________Starting Lame Echo to " + ip);


        if( WSAStartup( 0x0101, &wsad ) )          //  Initialize sockets here
                {
                Report->Lines->Add("ERROR|\tWSAStartup(0x0101) failed:" + AnsiString(WSAGetLastError()));
                return false;
                };

	hp = gethostbyname( ( char *) ip.c_str());

	if (!hp)
		addr = inet_addr(ip.c_str());

	if ((!hp)  && (addr == INADDR_NONE) )
        	{
                Report->Lines->Add("ERROR|\tUnable to resolve " + ip);
                WSACleanup();
		return false;
        	};

	if (hp != NULL)
                memcpy(&(dest.sin_addr),hp->h_addr,hp->h_length);
	else
  		dest.sin_addr.s_addr = addr;

	if (hp)
		dest.sin_family = hp->h_addrtype;
	else
		dest.sin_family = AF_INET;


//echo              7/tcp    Echo
//echo              7/udp    Echo



        WSACleanup();
        return true;
 };


bool DayTime(AnsiString ip, int port, int proto, TMemo* Report)
 {
       struct servent *pse; /* pointer to service
                            information entry */
       struct protoent *ppe; /* pointer to
                            protocol information
                            entry */

	struct hostent		*hp;
	struct sockaddr_in	dest;//,from;
        WSADATA                 wsad;
	unsigned int		addr=0;
        int                     type;

        Report->Lines->Add("");
        Report->Lines->Add("__________Starting Lame DayTime to " + ip);

        if( WSAStartup( 0x0101, &wsad ) )          //  Initialize sockets here
                {
                Report->Lines->Add("ERROR|\tWSAStartup(0x0101) failed:" + AnsiString(WSAGetLastError()));
                return false;
                };

	hp = gethostbyname( ( char *) ip.c_str());

	if (!hp)
		addr = inet_addr(ip.c_str());

	if ((!hp)  && (addr == INADDR_NONE) )
        	{
                Report->Lines->Add("ERROR|\tUnable to resolve " + ip);
                WSACleanup();
		return false;
        	};

	if (hp != NULL)
                memcpy(&(dest.sin_addr),hp->h_addr,hp->h_length);
	else
  		dest.sin_addr.s_addr = addr;

	if (hp)
		dest.sin_family = hp->h_addrtype;
	else
		dest.sin_family = AF_INET;


// phe  -> hp              sin -> dest


     char buf[128+1]; /* buffer for one line
                          of text */
     SOCKET s; /* socket descriptor */
     int cc;


/* Use protocol to choose a socket type */
       if (proto != 0)
              type = SOCK_DGRAM;        // UDP
       else
              type = SOCK_STREAM;       // TCP


        s = socket(AF_INET, type, 0);//ppe->p_proto);

        if (s == INVALID_SOCKET)
                {
                Report->Lines->Add("ERROR|\tCan't create a Socket.");
                WSACleanup();
		return false;
                };

/* Connect the socket */
       if (connect(s, (struct sockaddr *)&dest, sizeof(dest)) == SOCKET_ERROR)
                {
                Report->Lines->Add("ERROR|\tCan't Connect to " + ip);
                WSACleanup();
		return false;
                };

     cc = recv(s, buf, 128, 0);

ShowMessage("ciao");

     while( cc != SOCKET_ERROR && cc > 0) {
          buf[cc] = '\0';                       /* ensure null- termination */
          //(void) fputs(buf, stdout);
          Report->Lines->Add(AnsiString(buf));
          cc = recv(s, buf, 128, 0);
     }

     closesocket(s);
     WSACleanup();
     return true;
 };

