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

#include "finger.h"
#pragma hdtstop         //Added
#pragma argsused



#define MAXHOST   40
#define MAXUSER   40


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

extern "C" bool __declspec(dllexport) WINAPI  FingerUser(AnsiString ip, int port, TMemo* Report)
 {
		MessageBox ( NULL, "UU", ip.c_str(), MB_OK );
		MessageBox ( NULL, "UU", AnsiString(port).c_str(), MB_OK );

        return true;
 }

extern "C" bool __declspec(dllexport) WINAPI  LameFinger(AnsiString ip, int port, AnsiString user, TMemo* Report)
 {
        SOCKET                  sock;
	struct hostent		*hp;
	unsigned int		addr=0;
        WSADATA                 wsad;
        SOCKADDR_IN             server;


        Report->Lines->Add("");
        Report->Lines->Add("__________Starting Lame Finger to " + ip);



        if( WSAStartup( 0x0101, &wsad ) )          //  Initialize sockets here
                {
                Report->Lines->Add("ERROR|\tWSAStartup(0x0101) failed:" + AnsiString(WSAGetLastError()));
                return false;
                };

      // address of the finger server
	hp = gethostbyname( ( char *) ip.c_str());// load IP from hostname

	if (!hp)
		addr = inet_addr(ip.c_str());     // convert IP to inet format
	if ((!hp)  && (addr == INADDR_NONE) )
        	{
                Report->Lines->Add("ERROR|\tUnable to resolve " + ip);
                WSACleanup();
		return false;
        	};

        memset(&server, 0, sizeof(server));

	if (hp != NULL)
                memcpy(&(server.sin_addr),hp->h_addr,hp->h_length);
	else
  		server.sin_addr.s_addr = addr;
	if (hp)
		server.sin_family = hp->h_addrtype;
	else
		server.sin_family = AF_INET;

        if (port <= 0)
                {
                SERVENT FAR *fingerport;
                fingerport = getservbyname("finger", NULL);     // get default port with api
                if (fingerport != NULL)
                        server.sin_port = fingerport->s_port;
                else
                        server.sin_port = 79;                   // default port
                }
        else
                server.sin_port = (short)port;                  // load target port

        sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
                Report->Lines->Add("ERROR|\tSocket() failed:");// + AnsiString(WSAGetLastError()));
                WSACleanup();
		return false;
	};

      // establish a stream connection to server
      if (!connect(sock, (SOCKADDR *)&server, sizeof(server)))
      {
	 char msg[MAXUSER+3];
	 int msglen;

	 strcpy(msg, user.c_str());      // load username
	 strcat(msg, "\r\n");            // add newline
	 msglen = strlen(msg);

	 if (send(sock, msg, msglen, 0) == msglen)      // send finger request
	 {
	    static char buf[16384];      // receive buffer
            char * pbuff = buf;          // buffer pointer
	    int nchars; 	         // n chars just received, or error
            AnsiString currLine;         // line buffer

	    /* open a new display list and push characters
	       until either no more received or an error occurs */
	    while (( nchars = recv(sock, (char FAR *)&buf, sizeof(buf), 0)) > 0)
                {
                while (nchars--)        // repear for each char in the buffer
                   {
                    if (*pbuff == 10)   // carriage return
                        {
                        Report->Lines->Add(currLine);
                        currLine = "";  // send line and reset.
                        }
                    else                // add the char
                        currLine = currLine + AnsiString(*pbuff);
                    pbuff++;            // next char
                   }
                };

	    if (nchars < 0)             // Error receiving data
	    {
                closesocket(sock);
                Report->Lines->Add("ERROR|\tError receiving data. ["  + AnsiString(WSAGetLastError()) + "]");
                WSACleanup();
                return false;
	    };
	 }
	 else                           // Error Sending data
	    {
                closesocket(sock);
                Report->Lines->Add("ERROR|\tCan't Send data (all). ["  + AnsiString(WSAGetLastError()) + "]");
                WSACleanup();
                return false;
	    };
      }
      else // if NOT (!connect(sock, (SOCKADDR *)&server, sizeof(server)))
	    {
                closesocket(sock);
                Report->Lines->Add("ERROR|\tCannot connect to server. ["  + AnsiString(connect(sock, (SOCKADDR *)&server, sizeof(server))) + "]");
                WSACleanup();
                return false;
	    };

   closesocket(sock);		     // don't need this anymore
   WSACleanup();
   return true;
}
