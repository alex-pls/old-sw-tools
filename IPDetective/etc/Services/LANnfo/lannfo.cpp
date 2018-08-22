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

#include <nb30.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <objbase.h>
#include <snmp.h>

#include <lmaccess.h> //
#include <lmapibuf.h> //
#include <lmwksta.h> //
#include <lmserver.h> //
#define LM20_WORKSTATION_STATISTICS
#include <lmstats.h> //


#include "lannfo.h"
#pragma hdtstop         //Added
#pragma argsused

using namespace std;
#define bzero(thing,sz) memset(thing,0,sz)


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


Computer::Computer(AnsiString newServer, TMemo *newReport)
 {
 Server = newServer;
 Domain = NULL;
 Report = newReport;
 };

Computer::Computer(AnsiString newServer, AnsiString newDomain, TMemo *newReport)
 {
 Server = newServer;
 Domain = newDomain;
 Report = newReport;
 };

bool Computer::EnumNetHandler(DWORD dwLevel, LPNETRESOURCE lpNet, TMemo* Report)
{
   DWORD dwStatus, dwSize, dwEntries, i, j;
   HANDLE hMem, hStr;
   LPSTR lpStr;
   LPNETRESOURCE lpNewNet;
   HANDLE hEnum;

   dwStatus = WNetOpenEnum( RESOURCE_GLOBALNET,          //  Look for the works
                            RESOURCETYPE_ANY,                  //  when opening
                            0, lpNet, &hEnum );
   if( dwStatus != NO_ERROR )
      return( FALSE );                       //  If there's an error, just exit
                                //  Allocate buffer space for a mess of objects
   hMem = GlobalAlloc( GHND, sizeof(NETRESOURCE) * 128 );
   if( ! hMem )
      return( FALSE );

   lpNewNet = (LPNETRESOURCE)GlobalLock( hMem );           //  Ready the buffer

   dwEntries = 128;                         //  We can handle up to 128 entries
   dwSize = sizeof(NETRESOURCE) * 128;
                                                  //  Enumerate into the buffer
   dwStatus = WNetEnumResource( hEnum, &dwEntries, (LPVOID)lpNewNet, &dwSize );

   if( dwStatus != NO_ERROR )            //  Rats...error, free memory and exit
   {
      WNetCloseEnum( hEnum );
      GlobalUnlock( hMem );
      GlobalFree( hMem );
      return( FALSE );
   }
   WNetCloseEnum( hEnum );                  //  Done with the handle...close it

   hStr = GlobalAlloc( GHND, 512 );              //  Allocate some string space
   lpStr = (char *)GlobalLock( hStr );

   for( i = 0; i < dwEntries; i++ )                 //  Loop through each entry
   {
      if( lpNewNet[ i ].lpRemoteName )                     //  Is there a name?
      {
         if( lpNewNet[ i ].dwDisplayType == RESOURCEDISPLAYTYPE_DOMAIN )
            strcpy( lpStr, "Domain..." );

         else if( lpNewNet[ i ].dwDisplayType == RESOURCEDISPLAYTYPE_GENERIC )
            strcpy( lpStr, "Generic.." );

         else if( lpNewNet[ i ].dwDisplayType == RESOURCEDISPLAYTYPE_SERVER )
            strcpy( lpStr, "Server..." );

         else if( lpNewNet[ i ].dwDisplayType == RESOURCEDISPLAYTYPE_SHARE )
            strcpy( lpStr, "Share...." );
            
         for( j = 0; j < dwLevel; j++ )    //  Indent levels deeper with spaces
            strcat( lpStr, "......" );
                                               //  Add name and send to listbox
         strcat( lpStr, lpNewNet[ i ].lpRemoteName );


         Report->Lines->Add(lpStr);		// NEED VCL.h TO RUN


      }                                           //  Call again for each entry

      EnumNetHandler(dwLevel + 1, lpNewNet + i, Report);
   }

   GlobalUnlock( hStr );                           //  Free memory when leaving
   GlobalFree( hStr );
   GlobalUnlock( hMem );
   GlobalFree( hMem );

   return( TRUE );
}



bool Computer::EnumDrives()
{
  AnsiString Rep;
  char Buff[256];
  DWORD Size = sizeof(Buff);  // Enumerate the drives starting with D:
  char i;
  for (i='C';i<'Z';i++) {
    Rep = "";
    String DriveLetter = String(i) + ":";
    // Find out the drive type. if (it's a hardware drive) continue looking.
    int DriveType = GetDriveType(DriveLetter.c_str());

    switch (DriveType)
        {
        case DRIVE_FIXED:       Rep = DriveLetter + "\t Fixed drive";
                                break;
        case DRIVE_CDROM:       Rep = DriveLetter + "\t CD-ROM drive";
                                break;
        case DRIVE_RAMDISK:     Rep = DriveLetter + "\t RAM drive";
                                break;
        case DRIVE_REMOVABLE:   Rep = DriveLetter + "\t Removable drive";
                                break;
        case DRIVE_REMOTE:      Rep = DriveLetter + "\t Remote (network) drive";
                                break;
        case 1:                 Rep = DriveLetter + "\t Not mounted.";
                                break;
        case 0:
        default:                Rep = DriveLetter + "\t The drive type cannot be determined.";
                                break;
        };

    if ((DriveType==0)||(DriveType==1))
        {
        Report->Lines->Add(Rep);
        continue;
        };

    DWORD Res = WNetGetConnection(DriveLetter.c_str(), Buff, &Size);
    switch (Res)
        {
        case 0:                         Rep = Rep + "\tConnected to " + String(Buff);
                                        break;
        case ERROR_NOT_CONNECTED:       Rep = Rep + "\tAvailable for connecting.";
                                        break;
        case ERROR_CONNECTION_UNAVAIL:  Rep = Rep + "\tRemembered but not connected (" + String(Buff) + ")";
                                        break;
        default:                        Rep = Rep + "\tUnknown network status.";
        };
    Report->Lines->Add(Rep);
    };
    return true;
};


// get shared disks

bool Computer::EnumServerDisks()
{
        DWORD			dwTotalEntries;
        DWORD			dwEntriesRead;
        DWORD			dwPrefmaxlen	= 600;
        SERVER_INFO_100 *	theEntries	= new SERVER_INFO_100[600];
        LPTSTR servername;

        if ((Server == NULL) || (Server == "")) servername = NULL;
         else strcpy(servername, Server.c_str());

        // lists information about all servers of the domain
        if (0 != NetServerDiskEnum((wchar_t*)servername, 0, /*out*/(LPBYTE*)&theEntries , dwPrefmaxlen,
	           /*out*/&dwEntriesRead, /*out*/ &dwTotalEntries, /*resumehandle*/ NULL))
          {
                Report->Lines->Add("");
                Report->Lines->Add("ERROR|\tShared Disks Listing Falied.");
                Report->Lines->Add("");
                return false;
          };
        Report->Lines->Add("");
        Report->Lines->Add("Listing Shared Disks:");
        Report->Lines->Add("");
          for (int i=0; i< dwEntriesRead; i++)
                {
                Report->Lines->Add("\t" + AnsiString(theEntries[i].sv100_name));

                };
       NetApiBufferFree (theEntries);
       return true;
 };


 bool GetAdapterInfo(int adapter_num, string &mac_addr)
{
    // Reset the LAN adapter so that we can begin querying it
  NCB Ncb;
  memset(&Ncb, 0, sizeof(Ncb));
  Ncb.ncb_command = NCBRESET;
  Ncb.ncb_lana_num = adapter_num;
  if (Netbios(&Ncb) != NRC_GOODRET) {
    mac_addr = "bad (NCBRESET): ";
    mac_addr += AnsiString(Ncb.ncb_retcode).c_str();
    return false;
  }

  // Prepare to get the adapter status block
  bzero(&Ncb,sizeof(Ncb));
  Ncb.ncb_command = NCBASTAT;
  Ncb.ncb_lana_num = adapter_num;
  strcpy((char *) Ncb.ncb_callname, "*");
  struct ASTAT
  {
    ADAPTER_STATUS adapt;
    NAME_BUFFER NameBuff[30];
  } Adapter;
  bzero(&Adapter,sizeof(Adapter));
  Ncb.ncb_buffer = (unsigned char *)&Adapter;
  Ncb.ncb_length = sizeof(Adapter);

  // Get the adapter's info and, if this works, return it in standard,
  // colon-delimited form.
  if (Netbios(&Ncb) == 0)
  {
    char acMAC[18];
    sprintf(acMAC, "%02X:%02X:%02X:%02X:%02X:%02X",
            int (Adapter.adapt.adapter_address[0]),
            int (Adapter.adapt.adapter_address[1]),
            int (Adapter.adapt.adapter_address[2]),
            int (Adapter.adapt.adapter_address[3]),
            int (Adapter.adapt.adapter_address[4]),
            int (Adapter.adapt.adapter_address[5]));
    mac_addr = acMAC;
    return true;
  }
  else
  {
    mac_addr = "bad (NCBASTAT): ";
    mac_addr += AnsiString(Ncb.ncb_retcode).c_str();
    return false;
  }
}


bool Computer::GetMACAdapters(int nGetWay)
{
switch (nGetWay)
  {
  case 0:       // NETBIOS WAY
        {
        // Get adapter list
          LANA_ENUM AdapterList;
          NCB Ncb;
          memset(&Ncb, 0, sizeof(NCB));
          Ncb.ncb_command = NCBENUM;
          Ncb.ncb_buffer = (unsigned char *)&AdapterList;
          Ncb.ncb_length = sizeof(AdapterList);
          Netbios(&Ncb);
          // Get all of the local ethernet addresses
          string mac_addr;
          for (int i = 0; i < AdapterList.length - 1; ++i)
                {
                if (GetAdapterInfo(AdapterList.lana[i], mac_addr))
                    Report->Lines->Add("Adapter " + IntToStr (AdapterList.lana[i]) +
                                       "\tMAC is " + AnsiString(mac_addr.c_str()) );
                else
                    {
                    Report->Lines->Add("Failed to get MAC address! Do you have the NetBIOS protocol installed?");
                    return false;
                    };
                }
         };
         break;
  case 1:       // COM GUID API
        {
        // Ask COM to create a UUID for us.  If this machine has an Ethernet
        // adapter, the last six bytes of the UUID (bytes 2-7 inclusive in
        // the Data4 element) should be the MAC address of the local Ethernet adapter.
            GUID uuid;
            CoCreateGuid(&uuid);
            // Spit the address out
            char mac_addr[18];
            sprintf(mac_addr,"%02X:%02X:%02X:%02X:%02X:%02X",
                    uuid.Data4[2],uuid.Data4[3],uuid.Data4[4],
                    uuid.Data4[5],uuid.Data4[6],uuid.Data4[7]);

            Report->Lines->Add(mac_addr);
        };
        break;
//  case 2:       // SNMP Extension API

  };
  return true;
}


bool Computer::EnumUsers()
{
        DWORD			dwTotalEntries;
        DWORD			dwEntriesRead;
        DWORD			dwPrefmaxlen	= 600;
        USER_INFO_0 *	        theEntries	= new USER_INFO_0[600];
        USER_INFO_0 *	        theInfos	= new USER_INFO_0;
        WKSTA_USER_INFO_0 *	currLoggedUser	= new WKSTA_USER_INFO_0;
        LPTSTR servername;

        if ((Server == NULL) || (Server == "")) servername = NULL;
         else strcpy(servername, Server.c_str());

        // information about the currently logged-on use
        if (!NetWkstaUserGetInfo(NULL,0,(LPBYTE*)&currLoggedUser))
                Report->Lines->Add("Current logged User:\t" + AnsiString(currLoggedUser->wkui0_username));
         else
                Report->Lines->Add("ERROR|\tCan't read current Logged UserName.");

        // lists information about all users currently logged on to the workstation
        if (0 != NetWkstaUserEnum((wchar_t*)servername, 0, (LPBYTE*)&theEntries, dwPrefmaxlen, &dwEntriesRead, &dwTotalEntries, NULL))
                {
                Report->Lines->Add("");
                Report->Lines->Add("Listing Current logged Users");
                Report->Lines->Add("");
                  for (int i=0; i< dwEntriesRead; i++)
                        {
                        Report->Lines->Add("\t\t" + AnsiString(theEntries[i].usri0_name));
                        };
                Report->Lines->Add("");
                }
         else
                Report->Lines->Add("ERROR|\tCan't read current Logged Users.");

        // lists information about all users on to the workstation
        if (0 != NetUserEnum((wchar_t*)servername, 0, 0, /*out*/ (LPBYTE*)&theEntries , dwPrefmaxlen,
	           /*out*/&dwEntriesRead, /*out*/ &dwTotalEntries, /*out resumehandle*/ NULL))
          {
                Report->Lines->Add("");
                Report->Lines->Add("ERROR|\tUsers Listing Falied.");
                Report->Lines->Add("");
                return false;
          };
        Report->Lines->Add("");
        Report->Lines->Add("Listing Users:");
        Report->Lines->Add("");
          for (int i=0; i< dwEntriesRead; i++)
                {
                Report->Lines->Add("\t\t" + AnsiString(theEntries[i].usri0_name));
                NetUserGetInfo((wchar_t*)servername, theEntries[i].usri0_name, 0, (LPBYTE*)theInfos);
                Report->Lines->Add("\t" + AnsiString(theInfos->usri0_name));
                };
       NetApiBufferFree (theEntries);
       NetApiBufferFree (currLoggedUser);        // clean allocated API buffers
       return true;
 };


bool Computer::EnumGroups()
{
        DWORD			dwTotalEntries;
        DWORD			dwEntriesRead;
        DWORD			dwPrefmaxlen	= 600;
        GROUP_INFO_0 *	        theEntries	= new GROUP_INFO_0[600];
        GROUP_INFO_0 *	        theInfos	= new GROUP_INFO_0;
        LPTSTR servername;


        if ((Server == NULL) || (Server == "")) servername = NULL;
         else strcpy(servername, Server.c_str());

        // lists information about all goups on to the workstation
        if (0 != NetGroupEnum((wchar_t*)servername, 0, /*out*/(LPBYTE*)&theEntries , dwPrefmaxlen,
	           /*out*/&dwEntriesRead, /*out*/ &dwTotalEntries, /*out resumehandle*/ NULL))
          {
                Report->Lines->Add("");
                Report->Lines->Add("ERROR|\tGroups Listing Falied.");
                Report->Lines->Add("");
                return false;
          };
        Report->Lines->Add("");
        Report->Lines->Add("Listing Groups:");
        Report->Lines->Add("");
          for (int i=0; i< dwEntriesRead; i++)
                {
                Report->Lines->Add("\t" + AnsiString(theEntries[i].grpi0_name));
                NetGroupGetInfo((wchar_t*)servername, theEntries[i].grpi0_name, 0, (LPBYTE*)theInfos);
                Report->Lines->Add("\t\t" + AnsiString(theInfos->grpi0_name));

                };
       NetApiBufferFree (theInfos);
       NetApiBufferFree (theEntries);
       return true;
 };



bool Computer::EnumServers()
{
        DWORD			dwTotalEntries;
        DWORD			dwEntriesRead;
        DWORD			dwPrefmaxlen	= 600;
        SERVER_INFO_100 *	theEntries	= new SERVER_INFO_100[600];
        SERVER_INFO_100 *	theInfos	= new SERVER_INFO_100;
        LPTSTR servername;
        LPTSTR domainname;

        if ((Server == NULL) || (Server == "")) servername = NULL;
         else strcpy(servername, Server.c_str());

        if ((Domain == NULL) || (Domain == "")) domainname = NULL;
         else strcpy(domainname, Domain.c_str());

        // lists information about all servers of the domain
        if (0 != NetServerEnum((wchar_t*)servername, 0, /*out*/(LPBYTE*)&theEntries , dwPrefmaxlen,
	           /*out*/&dwEntriesRead, /*out*/ &dwTotalEntries, SV_TYPE_ALL, (wchar_t*)domainname, /*resumehandle*/ NULL))
          {
                Report->Lines->Add("");
                Report->Lines->Add("ERROR|\tServers Listing Falied.");
                Report->Lines->Add("");
                return false;
          };
        Report->Lines->Add("");
        Report->Lines->Add("Listing Groups:");
        Report->Lines->Add("");
          for (int i=0; i< dwEntriesRead; i++)
                {
                Report->Lines->Add("\t" + AnsiString(theEntries[i].sv100_name));
                NetServerGetInfo(theEntries[i].sv100_name, 0, (LPBYTE*)theInfos);
                Report->Lines->Add("\t\t" + AnsiString(theInfos->sv100_platform_id));

                };
       NetApiBufferFree (theInfos);
       NetApiBufferFree (theEntries);
       return true;
 };


 // domain controller
bool Computer::GetDCName()
{
        LPTSTR servername;
        LPTSTR domainname;
        char *DCName;

        if ((Server == NULL) || (Server == "")) servername = NULL;
         else strcpy(servername, Server.c_str());

        if ((Domain == NULL) || (Domain == "")) domainname = NULL;
         else strcpy(domainname, Domain.c_str());


        if (0 != NetGetAnyDCName((wchar_t*)servername, (wchar_t*)domainname, (LPBYTE*)DCName))
                {
                Report->Lines->Add("Domain Controller Name: " + AnsiString(DCName));
                Report->Lines->Add("\t\t");
                return false;
                }
        else
                {
                Report->Lines->Add("ERROR|\tFalied to get Domain Controller name.");
                Report->Lines->Add("");
                };

        NetApiBufferFree (DCName);        // clean allocated API buffers
        return true;
};

/*
// operating statistics for a service.

extern "C" bool __declspec(dllexport) WINAPI GetServiceStats(AnsiString Server, bool Service, TMemo *Report)
{
        STAT_WORKSTATION_0 *	theEntry	= new STAT_WORKSTATION_0;
        LPTSTR servername;
        LPTSTR servicename;

        if ((Server == NULL) || (Server == "")) servername = NULL;
         else strcpy(servername, Server.c_str());

        if (Service) servicename = "WORKSTATION";
         else servicename = "SERVER";

        // lists information about all servers of the domain
        if (0 != NetStatisticsGet((wchar_t*)servername, (wchar_t*)servicename, 0, 0, (LPBYTE*)theEntry))
          {
                Report->Lines->Add("");
                Report->Lines->Add("ERROR|\tCan't get Server Statistics.");
                Report->Lines->Add("");
                return false;
          };
        Report->Lines->Add("");
        Report->Lines->Add("_____________Server Statistics:");
        Report->Lines->Add("");
        Report->Lines->Add("Network control blocks:");
        Report->Lines->Add(" Issued by the server:\t" + AnsiString(theEntry->stw0_numNCB_s));
        Report->Lines->Add(" Issued by applications:\t" + AnsiString(theEntry->stw0_numNCB_a));
        Report->Lines->Add("");
        Report->Lines->Add("Falied Network control blocks:");
        Report->Lines->Add(" Issued by the server:\t" + AnsiString(theEntry->stw0_fiNCB_s));
        Report->Lines->Add(" Issued by applications:\t" + AnsiString(theEntry->stw0_fiNCB_a));
        Report->Lines->Add(" Issued by the redirector:\t" + AnsiString(theEntry->stw0_fiNCB_r));
        Report->Lines->Add("");
        Report->Lines->Add("Network control blocks falied before completion:");
        Report->Lines->Add(" Issued by the server:\t" + AnsiString(theEntry->stw0_fcNCB_s));
        Report->Lines->Add(" Issued by applications:\t" + AnsiString(theEntry->stw0_fcNCB_a));
        Report->Lines->Add(" Issued by the redirector:\t" + AnsiString(theEntry->stw0_fcNCB_r));

        Report->Lines->Add("");
        Report->Lines->Add("Number of workstation Sessions:");
        Report->Lines->Add(" Started:\t" + AnsiString(theEntry->stw0_sesstart));
        Report->Lines->Add(" Falied:\t" + AnsiString(theEntry->stw0_sessfailcon));
        Report->Lines->Add(" Failed after the session was established:");
        Report->Lines->Add("         \t" + AnsiString(theEntry->stw0_sessbroke));
        Report->Lines->Add("");
        Report->Lines->Add("Number of workstation use failures:\t" + AnsiString(theEntry->stw0_autorec));
        Report->Lines->Add("");
        Report->Lines->Add("Number of workstation bytes:");
        Report->Lines->Add(" Sent to the network:\t" + AnsiString(theEntry->stw0_bytessent_r_hi));
        Report->Lines->Add(" Received from the network:\t" + AnsiString(theEntry->stw0_bytesrcvd_r_hi));
        Report->Lines->Add("");
        Report->Lines->Add("Number of server bytes:");
        Report->Lines->Add(" Sent to the network:\t" + AnsiString(theEntry->stw0_bytessent_s_hi));
        Report->Lines->Add(" Received from the network:\t" + AnsiString(theEntry->stw0_bytesrcvd_s_hi));
        Report->Lines->Add("");
        Report->Lines->Add("Number of application bytes:");
        Report->Lines->Add(" Sent to the network:\t" + AnsiString(theEntry->stw0_bytessent_a_hi));
        Report->Lines->Add(" Received from the network:\t" + AnsiString(theEntry->stw0_bytesrcvd_a_hi));
        Report->Lines->Add("");
        Report->Lines->Add("Buffer Failures");
        Report->Lines->Add(" Failed to allocate one:\t" + AnsiString(theEntry->stw0_reqbufneed));
        Report->Lines->Add(" Failed to allocate big one:\t" + AnsiString(theEntry->stw0_bigbufneed));
       NetApiBufferFree (theEntry);
       return true;
 };
*/

/*







// transports that are managed by the server

NET_API_STATUS NetServerTransportEnum(

    LPTSTR servername,	
    DWORD level,	
    LPBYTE *bufptr,	
    DWORD prefmaxlen,	
    LPDWORD entriesread,
    LPDWORD totalentries,	
    LPDWORD resumehandle 	
   );	


// information about the configuration elements for a workstation.

NET_API_STATUS NetWkstaGetInfo(

    LPTSTR servername,	
    DWORD level,	
    LPBYTE *bufptr	
   );	


*/
