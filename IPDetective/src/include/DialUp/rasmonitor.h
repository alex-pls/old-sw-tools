/*
Module : RASMONITOR.H
Purpose: Defines the interface for a number of wrapper classes for 
         monitoring Ras connections 

Copyright (c) 1998 - 2000 by PJ Naughter.  
All rights reserved.

*/

#ifndef __RASMONITOR_H__
#define __RASMONITOR_H__
                      
#ifndef __AFXTEMPL_H__
#pragma message("RAS classes require afxtempl.h in your PCH")                                                                                
#endif

#ifndef _WINSVC_
#pragma message("RAS classes require winsvc.h in your PCH")                                                                                
#endif

//Function pointer typedefs used internally by CRasMonitor class
typedef DWORD (__stdcall *PFNRASENUMCONNECTIONS)(LPRASCONN, LPDWORD, LPDWORD);
typedef DWORD (__stdcall *PFNRASGETCONNECTSTATUS)(HRASCONN, LPRASCONNSTATUS);


///////////////////// Includes //////////////////////////////////////
#include "cpdh.h"     //my own wrapper class for performance data on NT
#include <pdhmsg.h>


//A class represeing a Dial-Up Networking connection
class CRasConnection
{
public:
//Constructors / Destructors
  CRasConnection();
	CRasConnection(const RASCONN& Connection);
  ~CRasConnection();

//Methods
  void Serialize(CArchive& ar);
  static void SerializeTime(CArchive& ar, SYSTEMTIME& st);
  void GetInitialConnectionDetails();
  void GetCurrentConnectionDetails();

//Serialized Data
  CString    m_sName;             //Name of the connection
	CString    m_sDeviceName;       //Name of the Device this connection is using
	CString    m_sDeviceType;       //Name of the Device Type this connection is using
  SYSTEMTIME m_ConnectionTime;    //The local time when the connection was started
  SYSTEMTIME m_DialTime;          //The local time when the connection was dialled
  BOOL       m_bConnected;        //True if currently connected, FALSE during the dialing
                                  //stage of a connection
  DWORD      m_ConnectDuration;   //how long the connection was made (in Seconds)
  DWORD      m_DialDuration;      //how long the connection took to be made (in Seconds)
  SYSTEMTIME m_HangupTime;        //The local time when the connection was closed
  DWORD      m_dwBytesReceived;   //The total number of bytes received
  DWORD      m_dwBytesSent;       //The number of bytes sent
  DWORD      m_dwConnectionSpeed; //The connection speed

protected:
//Temporary Data
  DWORD       m_dwInitialBytesReceived; //The total number of bytes received when connection is made
  DWORD       m_dwInitialBytesSent;     //The number of bytes sent received when connection is made
  CPdhCounter m_NTcounterR;             //NT performance counter for bytes received
  CPdhCounter m_NTcounterT;             //NT performance counter for bytes transmitted
  CPdhQuery   m_NTquery;                //NT performance query 
};


//Wparam which is used in notification message
const WPARAM RAS_DIAL_EVENT = 1;
const WPARAM RAS_CONNECT_EVENT = 2;
const WPARAM RAS_DISCONNECT_EVENT = 3;
const WPARAM RAS_CHECK_EVENT = 4;


//The Ras Monitor class which client applications should 
//derive from and override the virtual functions to perform
//whatever application specific behaviour they want
class CRasMonitor : public CWnd
{
public:
//Constructors / Destructors
  CRasMonitor();
  virtual ~CRasMonitor();

//Methods
	//Start monitoring ras connections
  BOOL Start(CWnd* pNotifyWnd, UINT nNotifyMessage);

	//Stop monitoring ras connections.
  BOOL Stop();

  //Determines if a ras connection handle is currently connected
  static BOOL IsConnected(HRASCONN hConnection);

  //Serializes the current state of the connections to and from disk
  void Serialize(CArchive& ar);

  //Accessors
  int NumberOfConnections() const { return m_Connections.GetSize(); };

protected:
//Data
  CArray<CRasConnection, CRasConnection&> m_Connections;
  UINT m_nTimerID;
  CWnd* m_pNotificationWnd;
  UINT m_nNotifyMessage;
  BOOL m_bStarted;
  BOOL m_bArchivedDataLoaded;
  SYSTEMTIME m_archiveTime;

//Methods
	BOOL ConnectionExists(const CString& sName);
  int GetConnection(const CString& sName);
	void DoCheck(BOOL bClosing);
  void OnDial(const CRasConnection& connection);
  void OnConnect(const CRasConnection& connection);
  void OnDisconnect(const CRasConnection& connection);
  void OnCheck(BOOL bClosing, RASCONN* pConnections, DWORD dwConnections);

//Static Methods
  static DWORD RasEnumConnections(LPRASCONN lprasconn, LPDWORD lpcb, LPDWORD lpcConnections); 
  static DWORD RasGetConnectStatus(HRASCONN hrasconn, LPRASCONNSTATUS lprasconnstatus);

//Static Data
  static SC_HANDLE m_hSCM;
  static SC_HANDLE m_hRasMan;
  static PFNRASENUMCONNECTIONS m_pfnRasEnumConnections;
  static PFNRASGETCONNECTSTATUS m_pfnRasGetConnectStatus;
  static HINSTANCE m_hRasApi32;
  static BOOL m_bRunningNT;

	//{{AFX_MSG(CRasMonitor)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
  DECLARE_MESSAGE_MAP()

  DECLARE_DYNAMIC(CRasMonitor)

  friend class CRasConnection;
};

#endif //__RASMONITOR_H__