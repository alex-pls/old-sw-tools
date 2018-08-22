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

#include "tracer.h"

#pragma hdtstop         //Added
#pragma argsused



////////////////////////////////////////////////////////////////// LAME PING FUNCTION




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

extern "C" bool __declspec(dllexport) WINAPI Trace(int MethodID, TMemo *Report)
 {
        switch (MethodID)
          {
          case 0: //LameTrace()
                  break;
          };

        return true;
 };


extern "C" bool __declspec(dllexport) WINAPI LameTrace(AnsiString ip, unsigned int PacketSize, TMemo *Report)
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

	if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0) //  Initialize sockets here
                {
                Report->Lines->Add("ERROR|\tWSAStartup(0x0200) failed:" + AnsiString(WSAGetLastError()));
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


        WSACleanup();
        return true;
 };


////////////////////////////////////////////////////////////////////////


BOOL Trace(AnsiString hostname, CTraceRouteReply& trr, UCHAR nHopCount, DWORD dwTimeout, DWORD dwPingsPerHost)
{
	//For correct operation of the T2A macro, see TN059               ?????
	USES_CONVERSION;

  //Validate our parameters
  ASSERT(pszHostName);
  ASSERT(trr.GetSize() == 0); //Should be empty initially
  ASSERT(nHopCount > 0);

	//Convert to dotted notation if required
  CString sHostName(pszHostName);
 	LPSTR lpszAscii = T2A((LPTSTR) pszHostName);
	unsigned long	addr = inet_addr(lpszAscii);
	if (addr == INADDR_NONE)
	{
		//Not a dotted address, then do a lookup of the name
		hostent* hp = gethostbyname(lpszAscii);
		if (hp)
    {
      IN_ADDR tAddr;
      tAddr.S_un.S_addr = ((LPIN_ADDR)hp->h_addr)->s_addr;
      addr = ((LPIN_ADDR)hp->h_addr)->s_addr;
      sHostName.Format(_T("%d.%d.%d.%d"), tAddr.S_un.S_un_b.s_b1, tAddr.S_un.S_un_b.s_b2, tAddr.S_un.S_un_b.s_b3, tAddr.S_un.S_un_b.s_b4);
    }
		else
		{
			TRACE(_T("Could not resolve the host name %s\n"), pszHostName);
			return FALSE;
		}
	}

  //Iterate through all the hop count values
  BOOL bReachedHost = FALSE;
  for (UCHAR i=1; i<=nHopCount && !bReachedHost; i++)
  {
    CHostTraceMultiReply htrr;
    htrr.dwError = 0;
    htrr.minRTT = ULONG_MAX;
    htrr.avgRTT = 0;
    htrr.maxRTT = 0;

    //Iterate through all the pings for each host
    DWORD totalRTT = 0;
    CHostTraceSingleReply htsr;
    htsr.Address.S_un.S_addr = 0;
    htsr.dwError = 0;
    BOOL bPingError = FALSE;
    for (DWORD j=0; j<dwPingsPerHost && !bPingError; j++)
    {
	    if (Ping(sHostName, htsr, i, dwTimeout))
      {
        if (htsr.dwError == 0)
        {
          //Acumulate the total RTT
          totalRTT += htsr.RTT;

          //Store away the RTT's
          if (htsr.RTT < htrr.minRTT)
            htrr.minRTT = htsr.RTT;
          if (htsr.RTT > htrr.maxRTT)
            htrr.maxRTT = htsr.RTT;

          //Call the virtual function
          if (!OnPingResult(j+1, htsr))
          {
            SetLastError(ERROR_CANCELLED);
            return FALSE;
          }
        }
        else
        {
          htrr.dwError = htsr.dwError;
          bPingError = TRUE;
        }
      }
      else
      {
        htrr.dwError = GetLastError();
        bPingError = TRUE;
      }
    }
    htrr.Address = htsr.Address;
    if (htrr.dwError == 0)
      htrr.avgRTT = totalRTT / dwPingsPerHost;
    else
    {
      htrr.minRTT = 0;
      htrr.avgRTT = 0;
      htrr.maxRTT = 0;
    }

    //Call the virtual function
    if (!OnSingleHostResult(i, htrr))
    {
      SetLastError(ERROR_CANCELLED);
      return FALSE;
    }

    //Add to the list of hosts
    trr.Add(htrr);

    //Have we reached the final host ?
    if (addr == htrr.Address.S_un.S_addr)
      bReachedHost = TRUE;
  }

  return TRUE;
}

BOOL CTraceRoute::Ping(const CString& sHostName, CHostTraceSingleReply& htsr, UCHAR nTTL, DWORD dwTimeout, int nPacketSize)
{
  CPing ping;

  CPingReply pr;
  BOOL bSuccess = ping.PingUsingICMP(sHostName, pr, nTTL, dwTimeout, nPacketSize);

  if (bSuccess)
  {
    //Ping was successful, copy over the pertinent info
    //into the return structure
		htsr.Address.S_un.S_addr = pr.Address.S_un.S_addr;
	  htsr.RTT = pr.RTT;
  }

  //return the status
	return bSuccess; 
}

BOOL CTraceRoute::OnPingResult(int nPingNum, const CHostTraceSingleReply& htsr)
{
  //Default behaviour is just to trace the result and return
  //TRUE to allow the trace route to continue

  TRACE(_T("OnPingResult: %d, IP: %d.%d.%d.%d, RTT: %d, Error: %d\n"), nPingNum, 
        htsr.Address.S_un.S_un_b.s_b1, htsr.Address.S_un.S_un_b.s_b2, htsr.Address.S_un.S_un_b.s_b3, 
        htsr.Address.S_un.S_un_b.s_b4, htsr.RTT, htsr.dwError);

  return TRUE;
}

BOOL CTraceRoute::OnSingleHostResult(int nHostNum, const CHostTraceMultiReply& htmr)
{
  //Default behaviour is just to trace the result and return
  //TRUE to allow the trace route to continue
  TRACE(_T("OnSingleHostResult: %d, IP: %d.%d.%d.%d, Min RTT: %d, Avg RTT: %d, Max RTT: %d, Error: %d\n"), nHostNum, 
        htmr.Address.S_un.S_un_b.s_b1, htmr.Address.S_un.S_un_b.s_b2, htmr.Address.S_un.S_un_b.s_b3, 
        htmr.Address.S_un.S_un_b.s_b4, htmr.minRTT, htmr.avgRTT, htmr.maxRTT, htmr.dwError);

  return TRUE;
}
