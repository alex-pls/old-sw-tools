/*
Module : RASMONITOR.CPP
Purpose: Defines the implementation for a number of wrapper classes for 
         monitoring Ras connections 
Created: PJN / 18-06-1997
History: PJN / 28-09-1998 1.  Updated code to include a virtual OnDial method
                          2.  Optimized the code by using CArray::ElementAt
                          3.  Added the following member variables to CRasConnection:
                              Dial Time, whether or not the connection is currently
                              connected, Dial Duration and the RAS handle
                          4.  Renamed the connection variable of CRasConnection
                          5.  Updated the sample program to v1.1
                          6.  Updated the version info in the sample app to include 
                              the build date
                          7.  Fixed a problem when enumerating more than one ras
                              connection at a time.
                          8.  Sample app now uses LoadImage instead of LoadIcon to avoid
                              the shell first scaling up to 32*32 and then back to 16*16.
                              What this means is that the icons RasMan puts in the tray
                              notification area will not look blurred.
                          9.  Fixed a memory leak in CRasMonitor::DoCheck() when multiple
                              connections were being enumerated.
                          10. Included a new selection of tray icons in the sample app.
                          11. Added a popup menu item to bring up the help file.
         PJN / 28-10-1998 1.  Major optimisation added to reduce memory usage (c. 3 MB) 
                              on NT when Ras service is not running. Thanks to Daniel 
                              Harth for this very neat optimisation.
                          2.  Internally the code now uses a hidden window to perform 
                              the monitoring instead of a worker thread. This helps avoid 
                              potential deadlock problems which can occur as previously 
                              the code used a worker thread.
                          3.  Now uses window messages instead of virtual functions to 
                              implement class customisation
         PJN / 02-02-1999 1.  Fixed a compile problem which was occurring when code was 
                              compiled for UNICODE.
                          2.  Fixed a crash which was occuring when the code was run on NT 
                              and you do not have Ras installed.
                          3.  When running on NT, the code now only uses 
                              SC_MANAGER_ENUMERATE_SERVICE priviledges when connecting to 
                              the Service Configuration Manager.
                          4.  CRasConnection connection now includes a standard MFC 
                              Serialize method.
         PJN / 11-02-1999 1.  Now reports the following additional statistics:
                              a) Connection speed (Bytes / Second) (on Windows 95, 98 only)
                              b) Bytes sent (Windows 95, 98 & NT)
                              c) Bytes received (Windows 95, 98 & NT)
         PJN / 25-01-2000 1.  Removed a memory leak which was occuring on NT where the 
                              CPdhCounter instances in the GetInitialConnectionDetails and
                              GetCurrentConnectionDetails functions were not being tidied 
                              up. This has been accomplised by restructuring the code to 
                              create and add the counters to the performance once of in the
                              CRasConnection constructors.
                              

Copyright (c) 1998 - 2000 by PJ Naughter.  
All rights reserved.

*/


///////////////////////////// Includes ////////////////////////////////////////

#include "stdafx.h"
#include "dyndata.h"  //My own wrapper class for performance data on 95/98
#include "rasmonitor.h"





///////////////////////////// Statics / Locals ////////////////////////////////

TCHAR szNTCounterTotalBytesSent[] = _T("\\Ras Total\\Bytes Transmitted");
TCHAR szNTCounterTotalBytesRecvd[] = _T("\\Ras Total\\Bytes Received");
TCHAR sz95CounterConnectSpeed[] = _T("ConnectSpeed");
TCHAR sz95CounterTotalBytesRecvd[] = _T("TotalBytesRecvd");
TCHAR sz95CounterTotalBytesSent[]  = _T("TotalBytesXmit");
TCHAR sz95ObjName[] = _T("Dial-Up Adapter");
PFNRASENUMCONNECTIONS CRasMonitor::m_pfnRasEnumConnections=NULL;
PFNRASGETCONNECTSTATUS CRasMonitor::m_pfnRasGetConnectStatus=NULL;
HINSTANCE CRasMonitor::m_hRasApi32 = NULL;
SC_HANDLE CRasMonitor::m_hSCM = NULL;
SC_HANDLE CRasMonitor::m_hRasMan = NULL;
BOOL CRasMonitor::m_bRunningNT = FALSE;

#ifdef _DEBUG
#undef THIS_FILE
#define new DEBUG_NEW
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif




///////////////////////////// Implementation //////////////////////////////////

CRasConnection::CRasConnection() : m_NTcounterR(szNTCounterTotalBytesRecvd),
                                   m_NTcounterT(szNTCounterTotalBytesSent)
{
  ZeroMemory(&m_DialTime, sizeof(SYSTEMTIME));
  ZeroMemory(&m_ConnectionTime, sizeof(SYSTEMTIME));
  ZeroMemory(&m_HangupTime, sizeof(SYSTEMTIME));
  m_bConnected = FALSE;
  m_ConnectDuration = 0;
  m_DialDuration = 0;
  m_dwBytesReceived = 0;
  m_dwBytesSent = 0;        
  m_dwConnectionSpeed = 0;
  m_dwInitialBytesReceived = 0;
  m_dwInitialBytesSent = 0;

  //Setup the NT performance counters. Note that NT performance counters 
  //currently does not support the connection speed
  if (CRasMonitor::m_bRunningNT)
  {
    try
    {
      //Open the query
      m_NTquery.Open();

      //Add the counters
      m_NTquery.Add(m_NTcounterR);
      m_NTquery.Add(m_NTcounterT);
    }
    catch (CPdhException* pEx)
    {
      TRACE(_T("An error occurred setting up the performance values on NT\n"));
		  pEx->Delete();
    }
  }
}

CRasConnection::CRasConnection(const RASCONN& Connection) : m_NTcounterR(szNTCounterTotalBytesRecvd),
                                                            m_NTcounterT(szNTCounterTotalBytesSent)
{
  m_sName       = Connection.szEntryName;
	m_sDeviceType = Connection.szDeviceType;
	m_sDeviceName = Connection.szDeviceName;
  m_bConnected  = CRasMonitor::IsConnected(Connection.hrasconn);
  m_ConnectDuration = 0;
  m_DialDuration = 0;
  if (m_bConnected)
  {
	  GetLocalTime(&m_ConnectionTime);
    CopyMemory(&m_DialTime, &m_ConnectionTime, sizeof(SYSTEMTIME));
  }
  else
  {
    GetLocalTime(&m_DialTime);
    ZeroMemory(&m_ConnectionTime, sizeof(SYSTEMTIME));
  }
  ZeroMemory(&m_HangupTime, sizeof(SYSTEMTIME));
  m_dwBytesReceived = 0;
  m_dwBytesSent = 0;        
  m_dwConnectionSpeed = 0;

  //Setup the NT performance counters. Note that NT performance counters 
  //currently does not support the connection speed
  if (CRasMonitor::m_bRunningNT)
  {
    try
    {
      //Open the query
      m_NTquery.Open();

      //Add the counters
      m_NTquery.Add(m_NTcounterR);
      m_NTquery.Add(m_NTcounterT);
    }
    catch (CPdhException* pEx)
    {
      TRACE(_T("An error occurred setting up the performance values on NT\n"));
		  pEx->Delete();
    }
  }
}

CRasConnection::~CRasConnection()
{
  //Free up the NT performance counter if we are running on NT
  if (CRasMonitor::m_bRunningNT)
  {
    try
    {
      //Remove the counters
      m_NTquery.Remove(m_NTcounterR);
      m_NTquery.Remove(m_NTcounterT);

      //Open the query
      m_NTquery.Close();
    }
    catch (CPdhException* pEx)
    {
      TRACE(_T("An error occurred freeing up the performance values on NT\n"));
		  pEx->Delete();
    }
  }
}

void CRasConnection::GetInitialConnectionDetails()
{
  if (CRasMonitor::m_bRunningNT)
  {
    //Note that NT performance counters currently does not support the connection speed
    try
    {
      //Collect the data and interpret
      m_NTquery.Collect();

      //Interpret the results
      PDH_FMT_COUNTERVALUE Received;
      m_NTcounterR.GetFormattedValue(PDH_FMT_LONG, Received);
      if (Received.CStatus == PDH_CSTATUS_VALID_DATA)
        m_dwInitialBytesReceived = (DWORD) Received.longValue;
      else
        TRACE(_T("Failed in call to get formatted value for Bytes received\n"));

      PDH_FMT_COUNTERVALUE Txmitted;
      m_NTcounterT.GetFormattedValue(PDH_FMT_LONG , Txmitted);
      if (Txmitted.CStatus == PDH_CSTATUS_VALID_DATA)
        m_dwInitialBytesSent = (DWORD) Txmitted.longValue;
      else
        TRACE(_T("Failed in call to get formatted value for Bytes sent\n"));
    }
    catch (CPdhException* pEx)
    {
      TRACE(_T("An error occurred get the performance values on NT\n"));
		  pEx->Delete();
    }
  }
  else
  {
    //Collect the Initial Bytes received
    CDynDataCounter counter;
    if (counter.Start(sz95ObjName, sz95CounterTotalBytesRecvd))
      if (!counter.Collect(m_dwInitialBytesReceived))
        TRACE(_T("Failed to retrieve the initial bytes received\n"));

    //Collect the Initial Bytes sent
    if (counter.Start(sz95ObjName, sz95CounterTotalBytesSent))
      if (!counter.Collect(m_dwInitialBytesSent))
        TRACE(_T("Failed to retrieve the initial bytes sent\n"));

    //Collect the connection speed
    if (counter.Start(sz95ObjName, sz95CounterConnectSpeed))
      if (!counter.Collect(m_dwConnectionSpeed))
        TRACE(_T("Failed to retrieve the initial connection speed"));
    counter.Stop();

    TRACE(_T("Initially, %s, Speed:%d, Sent:%d, Recv:%d\n"), m_sName, m_dwConnectionSpeed, m_dwInitialBytesSent, m_dwInitialBytesReceived);
  }
}

void CRasConnection::GetCurrentConnectionDetails()
{
  // Check for Windows NT
  if (CRasMonitor::m_bRunningNT)
  {
    //Note that NT performance counters currently do not support the connection speed
    try
    {
      //Collect the data and interpret
      m_NTquery.Collect();

      //Interpret the results
      PDH_FMT_COUNTERVALUE Received;
      m_NTcounterR.GetFormattedValue(PDH_FMT_LONG, Received);
      if (Received.CStatus == PDH_CSTATUS_VALID_DATA)
        m_dwBytesReceived = ((DWORD) Received.longValue) - m_dwInitialBytesReceived;
      else
        TRACE(_T("Failed in call to get formatted value for Bytes received\n"));

      PDH_FMT_COUNTERVALUE Txmitted;
      m_NTcounterT.GetFormattedValue(PDH_FMT_LONG , Txmitted);
      if (Txmitted.CStatus == PDH_CSTATUS_VALID_DATA)
        m_dwBytesSent = ((DWORD) Txmitted.longValue) - m_dwInitialBytesSent;
      else
        TRACE(_T("Failed in call to get formatted value for Bytes sent\n"));
    }
    catch (CPdhException* pEx)
    {
      TRACE(_T("An error occurred get the performance values on NT\n"));
		  pEx->Delete();
    }
  }
  else
  {
    //Collect the Bytes received
    CDynDataCounter counter;
    DWORD dwData;
    if (counter.Start(sz95ObjName, sz95CounterTotalBytesRecvd))
      if (counter.Collect(dwData))
        m_dwBytesReceived = dwData - m_dwInitialBytesReceived;

    //Collect the Bytes sent
    if (counter.Start(sz95ObjName, sz95CounterTotalBytesSent))
      if (counter.Collect(dwData))
        m_dwBytesSent = dwData - m_dwInitialBytesSent;

    //Collect the connection speed
    if (counter.Start(sz95ObjName, sz95CounterConnectSpeed))
      counter.Collect(m_dwConnectionSpeed);

    TRACE(_T("%s, Speed:%d, Sent:%d, Recv:%d\n"), m_sName, m_dwConnectionSpeed, m_dwBytesSent, m_dwBytesReceived);
  }
}

void CRasConnection::SerializeTime(CArchive& ar, SYSTEMTIME& st)
{
  if (ar.IsLoading())
  {
    //Version stamp
    WORD wVersion;
    ar >> wVersion;

    //the actual data
    ar >> st.wYear;
    ar >> st.wMonth;
    ar >> st.wDayOfWeek;
    ar >> st.wDay;
    ar >> st.wHour;
    ar >> st.wMinute;
    ar >> st.wSecond;
    ar >> st.wMilliseconds;
  }
  else
  {
    //Version stamp the data
    WORD wVersion = 0x100;
    ar << wVersion;

    //the actual data
    ar << st.wYear;
    ar << st.wMonth;
    ar << st.wDayOfWeek;
    ar << st.wDay;
    ar << st.wHour;
    ar << st.wMinute;
    ar << st.wSecond;
    ar << st.wMilliseconds;
  }
}

void CRasConnection::Serialize(CArchive& ar)
{
  if (ar.IsLoading())
  {
    //Version stamp
    WORD wVersion;
    ar >> wVersion;

    ar >> m_sName;
    ar >> m_sDeviceName;
    ar >> m_sDeviceType;
    SerializeTime(ar, m_ConnectionTime);
    SerializeTime(ar, m_DialTime);
    ar >> m_bConnected;
    ar >> m_ConnectDuration;
    ar >> m_DialDuration;
    SerializeTime(ar, m_HangupTime);
    ar >> m_dwBytesReceived;
    ar >> m_dwBytesSent;        
    ar >> m_dwConnectionSpeed;
  }
  else
  {
    //Version stamp the data
    WORD wVersion = 0x100;
    ar << wVersion;

    ar << m_sName;
    ar << m_sDeviceName;
    ar << m_sDeviceType;
    SerializeTime(ar, m_ConnectionTime);
    SerializeTime(ar, m_DialTime);
    ar << m_bConnected;
    ar << m_ConnectDuration;
    ar << m_DialDuration;
    SerializeTime(ar, m_HangupTime);
    ar << m_dwBytesReceived;
    ar << m_dwBytesSent;        
    ar << m_dwConnectionSpeed;
  }
}







CRasMonitor::CRasMonitor()
{
  m_pNotificationWnd = NULL;
  m_nNotifyMessage = 0;
  m_bStarted = FALSE;
  m_bArchivedDataLoaded = FALSE;
  ZeroMemory(&m_archiveTime, sizeof(SYSTEMTIME));

  // Check for Windows NT
  OSVERSIONINFO osi;
  osi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
  GetVersionEx(&osi);
  m_bRunningNT = (osi.dwPlatformId == VER_PLATFORM_WIN32_NT);

  // SCM not supported under Windows 95/98
  if (!m_bRunningNT)
	  return;

  // Open the Service control manager
  m_hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ENUMERATE_SERVICE);
  if (m_hSCM == NULL)
  {
    TRACE(_T("CRasMonitor::CRasMonitor, Can't open SCM, GetLastError() returns: %d.\n"), GetLastError());
    return;
  }

  //Open up the RasMan service from the SCM
  m_hRasMan = OpenService(m_hSCM, _T("RasMan"), SERVICE_QUERY_STATUS);
  if (m_hRasMan == NULL)
  {
    CloseServiceHandle(m_hSCM);
	  m_hSCM = NULL;
    TRACE(_T("CRasMonitor::CRasMonitor, Can't open RasMan service, GetLastError() returns: %d.\n"), GetLastError());
    return;
  }
}

CRasMonitor::~CRasMonitor()
{
  Stop();

  //Release the RasMan service Handle
	if (m_hRasMan)
	{
		CloseServiceHandle(m_hRasMan);
    m_hRasMan = NULL;
	}

  //Release the SCM Handle
	if (m_hSCM)
	{
		CloseServiceHandle(m_hSCM);
	  m_hSCM = NULL;
	}

  //Free up the Rasapi32 handle
	if (m_hRasApi32)
	{
		FreeLibrary(m_hRasApi32);
		m_hRasApi32 = NULL;
    m_pfnRasGetConnectStatus = NULL;
    m_pfnRasEnumConnections = NULL;
	}
}

IMPLEMENT_DYNAMIC(CRasMonitor, CWnd)

BEGIN_MESSAGE_MAP(CRasMonitor, CWnd)
	//{{AFX_MSG_MAP(CRasMonitor)
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CRasMonitor::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
  //Let the parent do its thing
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
  //create the timer
	m_nTimerID = SetTimer(1, 1000, NULL);
	
	return 0;
}

void CRasMonitor::OnTimer(UINT /*nIDEvent*/) 
{
  //Perform the check
  DoCheck(FALSE);
}

BOOL CRasMonitor::Start(CWnd* pNotifyWnd, UINT nNotifyMessage)
{
  ASSERT(!m_bStarted);

  //Store away the notification window
  ASSERT(pNotifyWnd && ::IsWindow(pNotifyWnd->GetSafeHwnd()));
  m_pNotificationWnd = pNotifyWnd;

  //Store away the notification message
  m_nNotifyMessage = nNotifyMessage;

  //create the hidden window which will do the monitoring
  CRect r(0, 0, 10, 10);
  if (!CreateEx(0, AfxRegisterWndClass(0), _T("CRasMonitor Notification Window"), WS_OVERLAPPED, r, NULL, 0))
  {
    TRACE(_T("Failed in creation of hidden Ras monitoring window\n"));
    return FALSE;
  }

  m_bStarted = TRUE;

  return TRUE;
}

BOOL CRasMonitor::Stop()
{
  if (m_bStarted)
  {
    //Final check since we are closing
    DoCheck(TRUE);

    //kill the timer
    KillTimer(m_nTimerID);

    //Destroy the hidden monitoring window
    DestroyWindow();

    m_pNotificationWnd = NULL;
    m_nNotifyMessage = 0;

    m_bStarted = FALSE;
  }

  return TRUE;
}

BOOL CRasMonitor::ConnectionExists(const CString& sName)
{
  return (GetConnection(sName) != -1);
}

BOOL CRasMonitor::IsConnected(HRASCONN hConnection)
{
  RASCONNSTATUS rcs;
  rcs.dwSize = sizeof(RASCONNSTATUS);
  if (RasGetConnectStatus(hConnection, &rcs) == 0)
    return (rcs.rasconnstate == RASCS_Connected);
  else
    return FALSE;
}

int CRasMonitor::GetConnection(const CString& sName)
{
	for (int i=0; i<m_Connections.GetSize(); i++)
	{
		if (m_Connections.GetAt(i).m_sName == sName)
			return i;
	}

	return -1;
}

void CRasMonitor::OnConnect(const CRasConnection& connection)
{ 
  //Display some debug info
  TRACE(_T("%s has just connected, Dial Duration was %d\n"), connection.m_sName, connection.m_DialDuration);

  //Inform the notify window of the event
  ASSERT(m_pNotificationWnd);
  ASSERT(m_pNotificationWnd->GetSafeHwnd());
  m_pNotificationWnd->SendMessage(m_nNotifyMessage, RAS_CONNECT_EVENT, (LPARAM) &connection);
}

void CRasMonitor::OnDial(const CRasConnection& connection)
{
  //Display some debug info
  TRACE(_T("%s has just dialled\n"), connection.m_sName);

  //Inform the notify window of the event
  ASSERT(m_pNotificationWnd);
  ASSERT(m_pNotificationWnd->GetSafeHwnd());
  m_pNotificationWnd->SendMessage(m_nNotifyMessage, RAS_DIAL_EVENT, (LPARAM) &connection);
}

void CRasMonitor::OnDisconnect(const CRasConnection& connection)
{
  //Display some debug info
  TRACE(_T("%s has just disconnected, Dial Duration was %d, Connection Time was %d\n"), connection.m_sName, connection.m_DialDuration, connection.m_ConnectDuration);

  //Inform the notify window of the event
  ASSERT(m_pNotificationWnd);
  ASSERT(m_pNotificationWnd->GetSafeHwnd());
  m_pNotificationWnd->SendMessage(m_nNotifyMessage, RAS_DISCONNECT_EVENT, (LPARAM) &connection);
}

void CRasMonitor::OnCheck(BOOL bClosing, RASCONN* pConnections, DWORD dwConnections)
{
	//Iterate through all the previously active connections
	//which has now disappeared and call the virtual OnDisconnect
	//function for the connection
	for (int i=m_Connections.GetUpperBound(); i>=0; i--)
	{
    BOOL bFound = FALSE;
    for (DWORD j=0; j<dwConnections && !bFound; j++)
      bFound = m_Connections.ElementAt(i).m_sName == pConnections[j].szEntryName;

    if (!bFound)
		{
      CRasConnection& connection = m_Connections.ElementAt(i);
			SYSTEMTIME st;
      //If we are dealing with archived data then use the archive time stamp and
      //not the current time
      if (m_bArchivedDataLoaded)
        CopyMemory(&st, &m_archiveTime, sizeof(SYSTEMTIME));
      else  
			  GetLocalTime(&st);
      if (connection.m_bConnected)
        connection.m_ConnectDuration = (CTime(st) - CTime(connection.m_ConnectionTime)).GetTotalSeconds();
      else
        connection.m_DialDuration = (CTime(st) - CTime(connection.m_DialTime)).GetTotalSeconds();
      connection.m_bConnected = FALSE;
      connection.m_HangupTime = st;
      OnDisconnect(connection);
      m_Connections.RemoveAt(i);
		}
	}

  //Iterate through all the current connections
  for (i=0; i<(int)dwConnections; i++)
  {
    int nConnection = GetConnection(pConnections[i].szEntryName);
    if (nConnection == -1)
    {
    	//For any new active connections which have appeared call the 
      //OnDial or the OnConnect function
      CRasConnection newConnection(pConnections[i]);
      if (newConnection.m_bConnected)
      {
        newConnection.GetInitialConnectionDetails();
        OnConnect(newConnection);
      }
      else
        OnDial(newConnection);
      m_Connections.Add(newConnection);
    }
    else
    {
      CRasConnection& connection = m_Connections.ElementAt(nConnection);

      //For existing connections, check to see if their connection state
      //has changed to connected and call the OnConnect function, Also call 
      //the GetInitialConnectionDetails method of CRasConnection
      if (IsConnected(pConnections[i].hrasconn))
      {
        if (!connection.m_bConnected)
        {
			    SYSTEMTIME now;
			    GetLocalTime(&now);
          connection.m_ConnectionTime = now;
          connection.m_DialDuration = (CTime(now) - CTime(connection.m_DialTime)).GetTotalSeconds();
          connection.m_bConnected = TRUE;
          connection.GetInitialConnectionDetails();
          OnConnect(connection); 
        }
        else
          connection.GetCurrentConnectionDetails();
      }
    }

    if (bClosing)
    {
      //Call the Disconnect for all connections as we are about to finish
      //our monitoring
      CRasConnection& connection = m_Connections.ElementAt(i);
		  SYSTEMTIME now;
		  GetLocalTime(&now);
      if (connection.m_bConnected)
        connection.m_ConnectDuration = (CTime(now) - CTime(connection.m_ConnectionTime)).GetTotalSeconds();
      else
        connection.m_DialDuration = (CTime(now) - CTime(connection.m_DialTime)).GetTotalSeconds();
      connection.m_bConnected = FALSE;
      connection.m_HangupTime = now;
      OnDisconnect(connection);
      m_Connections.RemoveAt(i);
    }
  }

  //Now give the notification window a chance of updating ifself
  ASSERT(m_pNotificationWnd);
  ASSERT(m_pNotificationWnd->GetSafeHwnd());
  m_pNotificationWnd->SendMessage(m_nNotifyMessage, RAS_CHECK_EVENT, (LPARAM) &m_Connections);
}

void CRasMonitor::DoCheck(BOOL bClosing)
{
	//First work out how many connections there are currently
	DWORD dwConnections;
	RASCONN rasconn;
	rasconn.dwSize = sizeof(RASCONN);
	DWORD dwSize = rasconn.dwSize;
	DWORD dwSuccess = RasEnumConnections(&rasconn, &dwSize, &dwConnections);

	RASCONN* pRasConn = NULL;
	RASCONN* pActiveConnections = NULL;
	DWORD dwActiveConnections = 0;
	if (dwSuccess == 0)
	{
		if (dwConnections)
		{
			//At this stage we have a single active RASCONN
		  pActiveConnections = &rasconn;
		  dwActiveConnections = dwConnections;
		}
	}
	else if (dwSuccess != ERROR_BUFFER_TOO_SMALL)
	  return;
	else
	{
		//Allocate enough memory to satisy the request
		pRasConn = new RASCONN[dwConnections];
		pRasConn[0].dwSize = sizeof(RASCONN);
		dwSize = dwConnections*sizeof(RASCONN);

		//Now enumerate all the connections
		dwSuccess = RasEnumConnections(pRasConn, &dwSize, &dwConnections);

		//Some unknown error
		if (dwSuccess != 0)
		{
			delete [] pRasConn;
			return;
		}

		//At this stage we have an array of RASCONN which
		//are currently active
		pActiveConnections = pRasConn;
		dwActiveConnections = dwConnections;
	}

	//Call the virtual function to allow client customisation
  OnCheck(bClosing, pActiveConnections, dwActiveConnections);

	//Clean up any heap memory we may have used
	if (pRasConn)
	  delete [] pRasConn;
}

DWORD CRasMonitor::RasEnumConnections(LPRASCONN lprasconn, LPDWORD lpcb, LPDWORD lpcConnections)
{
  //if we are on NT and we cannot get a handle to the SCM or RasMan
  //they proceed no further with out checks
  if (m_bRunningNT && (m_hRasMan == NULL))
  {
		*lpcb = 0;
		*lpcConnections = 0;
		return 0;
  }

  //First do the check on the SCM
	if (m_bRunningNT)
	{
    SERVICE_STATUS stat;
    QueryServiceStatus(m_hRasMan, &stat);
    if (stat.dwCurrentState != SERVICE_RUNNING) // not running?
		{
      //If the RasMan service is not running there is definitely not
      //any RAS connections active. This avoids us having to unnecessarily
      //load up the RASAPI32.DLL under NT. This reduces the working set
      //of any programs which use CRasMonitor by c. 3 MB when on NT when
      //no ras connections are active.
			*lpcb = 0;
			*lpcConnections = 0;
			return 0;
		}
	}

  //Now try RAS directly
	if (!m_hRasApi32)
	{
		m_hRasApi32 = LoadLibrary(_T("RASAPI32.DLL"));
		if (!m_hRasApi32)
		{
			TRACE(_T("CRasMonitor::RasEnumConnections: Can't load RASAPI32.DLL, GetLastError() returns: %d.\n"), GetLastError());
			*lpcb=0;
			*lpcConnections=0;
			return 0;
		}

#ifndef UNICODE
		m_pfnRasEnumConnections = (PFNRASENUMCONNECTIONS) GetProcAddress(m_hRasApi32, "RasEnumConnectionsA");
		m_pfnRasGetConnectStatus = (PFNRASGETCONNECTSTATUS) GetProcAddress(m_hRasApi32, "RasGetConnectStatusA");
#else
		m_pfnRasEnumConnections = (PFNRASENUMCONNECTIONS) GetProcAddress(m_hRasApi32, "RasEnumConnectionsW");
		m_pfnRasGetConnectStatus = (PFNRASGETCONNECTSTATUS) GetProcAddress(m_hRasApi32, "RasGetConnectStatusW");
#endif

    //In the unlikely event that any of the GetProcAddresses fail, Cleanup gracefully
    if (m_pfnRasEnumConnections == NULL || m_pfnRasGetConnectStatus == NULL)
    {
			TRACE(_T("CRasMonitor::RasEnumConnections: Can't get RASAPI32.DLL entry points, GetLastError() returns: %d.\n"), GetLastError());
			*lpcb=0;
			*lpcConnections=0;

      //Release our Rasapi handle
			FreeLibrary(m_hRasApi32);
			m_hRasApi32 = NULL;
      m_pfnRasGetConnectStatus = NULL;
      m_pfnRasEnumConnections = NULL;

			return 0;
    }
	}
  VERIFY(m_pfnRasEnumConnections);
	DWORD dwRet = m_pfnRasEnumConnections(lprasconn, lpcb, lpcConnections);

	return dwRet;
}

DWORD CRasMonitor::RasGetConnectStatus(HRASCONN hrasconn, LPRASCONNSTATUS lprasconnstatus)
{
	if (m_hSCM)
	{
    SERVICE_STATUS stat;
    QueryServiceStatus(m_hRasMan, &stat);
    if (stat.dwCurrentState != SERVICE_RUNNING) // not running?
		{
			ZeroMemory(lprasconnstatus, sizeof(RASCONNSTATUS));
			lprasconnstatus->dwSize = sizeof(RASCONNSTATUS);
			lprasconnstatus->rasconnstate = RASCS_Disconnected;
			return 0;
		}
	}
	if (!m_hRasApi32)
	{
		m_hRasApi32 = LoadLibrary(_T("RASAPI32.DLL"));
		if (!m_hRasApi32)
		{
			TRACE(_T("CRasMonitor::RasGetConnectStatus: Can't load RASAPI32.DLL, GetLastError() returns: %d.\n"), GetLastError());
			ZeroMemory(lprasconnstatus, sizeof(RASCONNSTATUS));
			lprasconnstatus->dwSize=sizeof(RASCONNSTATUS);
			lprasconnstatus->rasconnstate=RASCS_Disconnected;
			return 0;
		}

#ifndef UNICODE
		m_pfnRasEnumConnections = (PFNRASENUMCONNECTIONS) GetProcAddress(m_hRasApi32, "RasEnumConnectionsA");
		m_pfnRasGetConnectStatus = (PFNRASGETCONNECTSTATUS) GetProcAddress(m_hRasApi32, "RasGetConnectStatusA");
#else
		m_pfnRasEnumConnections = (PFNRASENUMCONNECTIONS) GetProcAddress(m_hRasApi32, "RasEnumConnectionsW");
		m_pfnRasGetConnectStatus = (PFNRASGETCONNECTSTATUS) GetProcAddress(m_hRasApi32, "RasGetConnectStatusW");
#endif

    //In the unlikely event that any of the GetProcAddresses fail, Cleanup gracefully
    if (m_pfnRasEnumConnections == NULL || m_pfnRasGetConnectStatus == NULL)
    {
			TRACE(_T("CRasMonitor::RasGetConnectStatus: Can't get RASAPI32.DLL entry points, GetLastError() returns: %d.\n"), GetLastError());
			ZeroMemory(lprasconnstatus, sizeof(RASCONNSTATUS));
			lprasconnstatus->dwSize=sizeof(RASCONNSTATUS);
			lprasconnstatus->rasconnstate=RASCS_Disconnected;

      //Release our Rasapi handle
			FreeLibrary(m_hRasApi32);
			m_hRasApi32 = NULL;
      m_pfnRasGetConnectStatus = NULL;
      m_pfnRasEnumConnections = NULL;

			return 0;
    }
	}

  VERIFY(m_pfnRasGetConnectStatus);
	return m_pfnRasGetConnectStatus(hrasconn, lprasconnstatus);
}

void CRasMonitor::Serialize(CArchive& ar)
{
  if (ar.IsLoading())
  {
    //Version stamp the data
    WORD wVersion;
    ar >> wVersion;

    //the actual data
    int nSize;
    ar >> nSize;
    m_Connections.SetSize(nSize);
    for (int i=0; i<nSize; i++)
    {
      CRasConnection connection;
      connection.Serialize(ar);
      m_Connections.SetAt(i, connection);
    }

    //Don't forget to read in the archive time
    CRasConnection::SerializeTime(ar, m_archiveTime);

    //Call the OnCheck method with the archived data
    m_bArchivedDataLoaded = TRUE;
    OnCheck(FALSE, NULL, 0);
    m_bArchivedDataLoaded = FALSE;
  }
  else
  {
    //Version stamp the data
    WORD wVersion = 0x100;
    ar << wVersion;

    //the actual data
    int nSize = m_Connections.GetSize();
    ar << nSize;
    for (int i=0; i<nSize; i++)
    {
      CRasConnection& connection = m_Connections.ElementAt(i);
      connection.Serialize(ar);
    }

    //Archive out the current time aswell.
 		SYSTEMTIME archiveTime;
		GetLocalTime(&archiveTime);
    CRasConnection::SerializeTime(ar, archiveTime);
  }
}
