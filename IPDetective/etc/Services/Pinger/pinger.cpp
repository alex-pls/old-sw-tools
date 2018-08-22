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

#include "pinger.h"

#pragma hdtstop         //Added
#pragma argsused



////////////////////////////////////////////////////////////////// LAME PING FUNCTION

/* The IP header */
typedef struct iphdr 
{
	unsigned int h_len:4;          // length of the header
	unsigned int version:4;        // Version of IP
	unsigned char tos;             // Type of service
	unsigned short total_len;      // total length of the packet
	unsigned short ident;          // unique identifier
	unsigned short frag_and_flags; // flags
	unsigned char  ttl; 
	unsigned char proto;           // protocol (TCP, UDP etc)
	unsigned short checksum;       // IP checksum

	unsigned int sourceIP;
	unsigned int destIP;

}IpHeader;

// ICMP header
typedef struct _ihdr
{
  BYTE i_type;
  BYTE i_code; /* type sub code */
  USHORT i_cksum;
  USHORT i_id;
  USHORT i_seq;
  /* This is not the std header, but we reserve space for time */
  ULONG timestamp;
}IcmpHeader;

#define ICMP_ECHO 8
#define ICMP_ECHOREPLY 0
#define ICMP_MIN 8 // minimum 8 byte icmp packet (just header)

#define DEF_PACKET_SIZE 32
#define MAX_PACKET 1024//65536

#define xmalloc(s) HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,(s))
#define xfree(p)   HeapFree (GetProcessHeap(),0,(p))
//////////////////////////////////////////////////////////////////////////////////////


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

extern "C" bool __declspec(dllexport) WINAPI Ping(int MethodID, TMemo *Report)
 {
        switch (MethodID)
          {
          case 0: //LamePing()
                  break;
          };

        return true;
 };


extern "C" bool __declspec(dllexport) WINAPI LamePing(AnsiString ip, unsigned int PingTimes, unsigned int PacketSize, TMemo *Report)
 {
	SOCKET			sockRaw;
	struct sockaddr_in	dest,from;
	struct hostent		*hp;
	int			bread,datasize;
	int			fromlen = sizeof(from);
	int			timeout = 10;
	char			*icmp_data;
	char			*recvbuf;
	unsigned int		addr=0;
	int			bwrote;


        USHORT seq_no = 0;

        Report->Lines->Add("");
        Report->Lines->Add("__________Starting Lame Ping to " + ip);


        WSADATA wsad;

        if( WSAStartup( 0x0101, &wsad ) )          //  Initialize sockets here
                {
                Report->Lines->Add("ERROR|\tWSAStartup(0x0101) failed:" + AnsiString(WSAGetLastError()));
                return false;
                };
	sockRaw = WSASocket(AF_INET, SOCK_RAW, IPPROTO_ICMP, NULL, 0,0);

	if (sockRaw == INVALID_SOCKET)
	{
                Report->Lines->Add("ERROR|\tWSASocket() failed:" + AnsiString(WSAGetLastError()));
                WSACleanup();
		return false;
	}

for (int iLoop = 0; iLoop < PingTimes; iLoop++)
        {
	bread = setsockopt(sockRaw,SOL_SOCKET,SO_RCVTIMEO,(char*)&timeout, sizeof(timeout));

	if(bread == SOCKET_ERROR)
	{
                Report->Lines->Add("ERROR|\tFailed to set recv timeout: " + AnsiString(WSAGetLastError()));
                WSACleanup();
		return false;
	}

//	timeout = 1000;

	/*bread*/bwrote = setsockopt(sockRaw,SOL_SOCKET,SO_SNDTIMEO,(char*)&timeout, sizeof(timeout));


	if(/*bread*/bwrote == SOCKET_ERROR)
	{
                Report->Lines->Add("ERROR|\tFailed to set send timeout: " + AnsiString(WSAGetLastError()));
                WSACleanup();
		return false;
	}
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

	if (PacketSize > 0)
		datasize = PacketSize;
	else
	  datasize = DEF_PACKET_SIZE;

	datasize += sizeof(IcmpHeader);

	icmp_data = (char*)xmalloc(MAX_PACKET);
	recvbuf = (char*)xmalloc(MAX_PACKET);

	if (!icmp_data)
	{
                Report->Lines->Add("ERROR|\tHeapAlloc failed " + AnsiString(GetLastError()));
                WSACleanup();
		return false;
	}

	memset(icmp_data,0,MAX_PACKET);
	Fill_Icmp_Data(icmp_data,datasize);

	//int bwrote;

	((IcmpHeader*)icmp_data)->i_cksum = 0;
	((IcmpHeader*)icmp_data)->timestamp = GetTickCount();

	((IcmpHeader*)icmp_data)->i_seq = seq_no++;
	((IcmpHeader*)icmp_data)->i_cksum = Checksum((USHORT*)icmp_data, datasize);

	bwrote = sendto(sockRaw,icmp_data,datasize,0,(struct sockaddr*)&dest, sizeof(dest));
	if (bwrote == SOCKET_ERROR)
	        {
		if (WSAGetLastError() == WSAETIMEDOUT)
		        {
                        Report->Lines->Add("ERROR|\tRequest Timed Out ");
                        WSACleanup();
		        return false;
		        };
                Report->Lines->Add("ERROR|\tsendto failed: " + AnsiString(WSAGetLastError()));
                WSACleanup();
		return false;
        	};

	if (bwrote < datasize )
		Report->Lines->Add("Wrote " + AnsiString(bwrote) + " bytes.");

	bread = recvfrom(sockRaw,recvbuf,MAX_PACKET,0,(struct sockaddr*)&from, &fromlen);


	if (bread == SOCKET_ERROR)
	        {
		if (WSAGetLastError() == WSAETIMEDOUT)
		        {
                        Report->Lines->Add("ERROR|\tRequest Timed Out ");
                        WSACleanup();
		        return false;
                        };
                Report->Lines->Add("ERROR|\trecvfrom failed: " + AnsiString(WSAGetLastError()));
                WSACleanup();
		return false;
	        };
	Decode_Resp(recvbuf,bread,&from, Report);
	xfree(icmp_data);
	xfree(recvbuf);
        };                      //close ping loop
	closesocket(sockRaw);
        WSACleanup();
        return true;
 };


bool Decode_Resp(char * buf, int bytes, struct sockaddr_in * from, TMemo *Report)
{
	IpHeader *iphdr;
	IcmpHeader *icmphdr;
	unsigned short iphdrlen;

	iphdr = (IpHeader *)buf;

	iphdrlen = iphdr->h_len * 4 ; // number of 32-bit words *4 = bytes

	if (bytes  < iphdrlen + ICMP_MIN) 
		Report->Lines->Add("Too few bytes from "
                                   + AnsiString( inet_ntoa(from->sin_addr) ));

	icmphdr = (IcmpHeader*)(buf + iphdrlen);

	if (icmphdr->i_type != ICMP_ECHOREPLY) 
	{
		Report->Lines->Add("ERROR|\tNOT-ECHO type (" + AnsiString(icmphdr->i_type) + ")");
		return false;
	}
	if (icmphdr->i_id != (USHORT)GetCurrentProcessId()) 
	{
		Report->Lines->Add("ERROR|\tSomeone else's packet!");
		return false;
	}
	Report->Lines->Add("");
	Report->Lines->Add("\t" + AnsiString(bytes) + " bytes from " + AnsiString(inet_ntoa(from->sin_addr)));
	Report->Lines->Add("\tICMP_Seq = " + AnsiString(icmphdr->i_seq));
	Report->Lines->Add("\tTime     = " + AnsiString(GetTickCount()-icmphdr->timestamp) + " ms");
	return true;

}

USHORT Checksum(USHORT * buffer, int size)
{
	unsigned long cksum=0;

	while(size >1) 
	{
		cksum+=*buffer++;
		size -=sizeof(USHORT);
	}
  
	if(size ) 
	{
		cksum += *(UCHAR*)buffer;
	}

	cksum = (cksum >> 16) + (cksum & 0xffff);
	cksum += (cksum >>16);
	return (USHORT)(~cksum);
}

void Fill_Icmp_Data(char * icmp_data, int datasize)
{
	IcmpHeader *icmp_hdr;
	char *datapart;

	icmp_hdr = (IcmpHeader*)icmp_data;

	icmp_hdr->i_type = ICMP_ECHO;
	icmp_hdr->i_code = 0;
	icmp_hdr->i_id = (USHORT)GetCurrentProcessId();
	icmp_hdr->i_cksum = 0;
	icmp_hdr->i_seq = 0;
  
	datapart = icmp_data + sizeof(IcmpHeader);
	  //
	  // Place some junk in the buffer.
	  //
	memset(datapart,'S', datasize - sizeof(IcmpHeader));
}
