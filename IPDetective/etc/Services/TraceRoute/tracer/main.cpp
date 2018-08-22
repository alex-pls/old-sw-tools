#include "stdafx.h"
#include "tracer.h"

//Global variable used to determine whether addresses should be resolved
BOOL g_bResolveAddresses;


//Class derived to implement Trace Route
class CMyTraceRoute : public CTraceRoute
{
  virtual BOOL OnSingleHostResult(int nHostNum, const CHostTraceMultiReply& htmr);
};

BOOL CMyTraceRoute::OnSingleHostResult(int nHostNum, const CHostTraceMultiReply& htmr)
{
  if (htmr.dwError == 0)
  {
    hostent* phostent = NULL;
    if (g_bResolveAddresses)
      phostent = gethostbyaddr((char *)&htmr.Address.S_un.S_addr, 4, PF_INET);

    if (phostent)
	    _tprintf(_T("  %d\t%d ms\t%d ms\t%d ms\t%s [%d.%d.%d.%d]\n"), nHostNum, htmr.minRTT, htmr.avgRTT, 
               htmr.maxRTT, phostent->h_name, htmr.Address.S_un.S_un_b.s_b1, htmr.Address.S_un.S_un_b.s_b2, 
               htmr.Address.S_un.S_un_b.s_b3, htmr.Address.S_un.S_un_b.s_b4);
    else
	    _tprintf(_T("  %d\t%d ms\t%d ms\t%d ms\t%d.%d.%d.%d\n"), nHostNum, htmr.minRTT, htmr.avgRTT, htmr.maxRTT,
               htmr.Address.S_un.S_un_b.s_b1, htmr.Address.S_un.S_un_b.s_b2, htmr.Address.S_un.S_un_b.s_b3, 
		  		     htmr.Address.S_un.S_un_b.s_b4);
  }
  else
    _tprintf(_T("  %d\t*\t*\t*\tError:%d\n"), nHostNum, htmr.dwError);

  return TRUE;
}




class CMyCommandLineInfo : public CCommandLineInfo
{
public:
  CMyCommandLineInfo();
  virtual void ParseParam(LPCTSTR lpszParam, BOOL bFlag, BOOL bLast);

//Our specific command line options
  CString m_sHost;
  BOOL    m_bResolveAddressesToHostnames;
  UCHAR   m_nHopCount;
  UCHAR   m_nPings;
  DWORD   m_dwTimeout;
};

CMyCommandLineInfo::CMyCommandLineInfo()
{
  m_bResolveAddressesToHostnames = TRUE;
  m_nHopCount = 30;
  m_nPings = 3;
  m_dwTimeout = 5000;
}

void CMyCommandLineInfo::ParseParam(LPCTSTR lpszParam, BOOL bFlag, BOOL bLast)
{
  if (bFlag)
  {
    //Form a CString version of the parameter (just makes it easier to parse with)
    CString sParam(lpszParam);

	  if (_tcsicmp(lpszParam, _T("d")) == 0)
		  m_bResolveAddressesToHostnames = FALSE;
    else if (sParam.Find(_T("h:")) == 0 && sParam.GetLength() > 2)
      m_nHopCount = (UCHAR) _ttoi(sParam.Right(sParam.GetLength() - 2));
    else if (sParam.Find(_T("p:")) == 0 && sParam.GetLength() > 2)
      m_nPings = (UCHAR) _ttoi(sParam.Right(sParam.GetLength() - 2));
    else if (sParam.Find(_T("w:")) == 0 && sParam.GetLength() > 2)
      m_dwTimeout = (DWORD) _ttoi(sParam.Right(sParam.GetLength() - 2));
    else
      CCommandLineInfo::ParseParam(lpszParam, bFlag, bLast);
  }
  else
    m_sHost = lpszParam;
}




//Good old void main
#ifdef _UNICODE
void wmain()
#else
void main()
#endif
{
  //Parse the command line
  CMyCommandLineInfo rCmdInfo;
	for (int i = 1; i < __argc; i++)
	{
    #ifdef _UNICODE
		LPCTSTR pszParam = __wargv[i];
    #else
    LPCTSTR pszParam = __argv[i];
    #endif
		BOOL bFlag = FALSE;
		BOOL bLast = ((i + 1) == __argc);
		if (pszParam[0] == _T('-') || pszParam[0] == _T('/'))
		{
			// remove flag specifier
			bFlag = TRUE;
			++pszParam;
		}
		rCmdInfo.ParseParam(pszParam, bFlag, bLast);
	}

  g_bResolveAddresses = rCmdInfo.m_bResolveAddressesToHostnames;

  if (rCmdInfo.m_sHost.IsEmpty())
  {
		_tprintf(_T("TRACER target_name [-d] [-h:Hopcount] [-w:timeout] [-p:pingcount]\n\n"));
    _tprintf(_T("Options:\n"));
    _tprintf(_T("  -d               Do not resolve addresses to hostnames.\n"));
    _tprintf(_T("  -h:maximum_hops  Maximum number of hops to search for target.\n"));
    _tprintf(_T("  -w:timeout       Wait timeout milliseconds for each reply.\n"));
    _tprintf(_T("  -p:pingcount     The number of pings per host.\n"));
    return;
  }

  //Initialize sockets
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0)
  {
    _tprintf(_T("Failed to initialize Winsock 2 Stack\n"));
    return;
  }

  //Print the intro comment
  _tprintf(_T("\nTracing route to %s\nover a maximum of %d hops:\n\n"), rCmdInfo.m_sHost, rCmdInfo.m_nHopCount);

  //Do the actual trace route
  CTraceRouteReply trr;
  CMyTraceRoute tr;
  if (tr.Trace(rCmdInfo.m_sHost, trr, rCmdInfo.m_nHopCount, rCmdInfo.m_dwTimeout, rCmdInfo.m_nPings))
    _tprintf(_T("\nTrace complete.\n"));
	else
	  _tprintf(_T("Failed in call to tracer, GetLastError returns: %d"), GetLastError());

  WSACleanup();
}
