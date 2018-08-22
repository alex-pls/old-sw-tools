// IPDetective Project
//
// Status: Aborted
//
// by Alessandro Polo 2002
// eWorld Network :: www.ewgate.net
//------------------------------------------------------------------------------
//                                                                   15/05/2002
#include <vcl.h>
#include <shlwapi.h>
#include <Registry.hpp>
#include <iostream.h>
#include <fstream>
#include "osfunc.h"



/*
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

  */

#include <nb30.h>

using namespace std;


bool GetAdapterInfo(int nAdapterNum, TMemo *Report)
{
    // Reset the LAN adapter so that we can begin querying it
    NCB Ncb;
    memset(&Ncb, 0, sizeof(Ncb));
    Ncb.ncb_command = NCBRESET;
    Ncb.ncb_lana_num = nAdapterNum;
    if (Netbios(&Ncb) != NRC_GOODRET) {
//        char acTemp[80];
//        ostrstream outs(acTemp, sizeof(acTemp));
//        outs << "error " << Ncb.ncb_retcode << " on reset" << ends;
        Report->Lines->Add("Error: " + AnsiString(Ncb.ncb_retcode) + " on reset.");
        return false;
    }
    
    // Prepare to get the adapter status block 
    memset(&Ncb, 0, sizeof(Ncb));
    Ncb.ncb_command = NCBASTAT;
    Ncb.ncb_lana_num = nAdapterNum;
    strcpy((char *) Ncb.ncb_callname, "*");

    struct ASTAT {
        ADAPTER_STATUS adapt;
        NAME_BUFFER NameBuff[30];
    } Adapter;

    memset(&Adapter, 0, sizeof(Adapter));
    Ncb.ncb_buffer = (unsigned char *)&Adapter;
    Ncb.ncb_length = sizeof(Adapter);
    
    // Get the adapter's info and, if this works, return it in standard,
    // colon-delimited form.
    if (Netbios(&Ncb) == 0) {
        Report->Lines->Add(
                AnsiString(Adapter.adapt.adapter_address[0]) + ":" +
                AnsiString(Adapter.adapt.adapter_address[1]) + ":" +
                AnsiString(Adapter.adapt.adapter_address[2]) + ":" +
                AnsiString(Adapter.adapt.adapter_address[3]) + ":" +
                AnsiString(Adapter.adapt.adapter_address[4]) + ":" +
                AnsiString(Adapter.adapt.adapter_address[5]));
/*        char acMAC[18];
        sprintf(acMAC, "%02X:%02X:%02X:%02X:%02X:%02X",
                int (Adapter.adapt.adapter_address[0]),
                int (Adapter.adapt.adapter_address[1]),
                int (Adapter.adapt.adapter_address[2]),
                int (Adapter.adapt.adapter_address[3]),
                int (Adapter.adapt.adapter_address[4]),
                int (Adapter.adapt.adapter_address[5]));
        sMAC = acMAC;
*/        return true;
    }
    else {
//        char acTemp[80];
//        ostrstream outs(acTemp, sizeof(acTemp));
//        outs << "error " << Ncb.ncb_retcode << " on ASTAT" << ends;
//        sMAC = acTemp;
        Report->Lines->Add("Error " + AnsiString(Ncb.ncb_retcode) + " on ASTAT");
        return false;
    }
}

DWORD GetDLLVersion(String dllName)
   {
   DWORD version = 0;
   HINSTANCE hInst = LoadLibrary(dllName.c_str());
   if (hInst)
      {
      DLLGETVERSIONPROC getVersion = (DLLGETVERSIONPROC)GetProcAddress(hInst, "DllGetVersion");
      if (getVersion)
         {
         DLLVERSIONINFO info;
         ZeroMemory(&info, sizeof(info));
         info.cbSize = sizeof(info);
         HRESULT result = (*getVersion)(&info);
         if (SUCCEEDED(result))
            version = PackDLLVersion(info.dwMajorVersion, info.dwMinorVersion);
         }
      FreeLibrary(hInst);
      }
   return(version);
   }



bool OSInfoS(TMemo *Report)
 {
   OSVERSIONINFO info;
   ZeroMemory(&info, sizeof(OSVERSIONINFO));
   info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
   bool success = GetVersionEx(&info);
   if (!success)
      return false;

   DWORD buildNumber = info.dwBuildNumber;
   if (info.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
      buildNumber = LOWORD(buildNumber);

//        Report->Lines->Add((int)info.dwMajorVersion + "." + (int)info.dwMinorVersion +
//                           "  built " + (int)buildNumber);


   if (info.dwPlatformId == VER_PLATFORM_WIN32s)
      Report->Lines->Add("Win32s");
   else if (info.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
      {
      if ((info.dwMajorVersion > 4) || ((info.dwMajorVersion == 4) && (info.dwMinorVersion > 0)))
        Report->Lines->Add("Windows 98");
      else
        Report->Lines->Add("windows 95");
      }
   else if (info.dwPlatformId == VER_PLATFORM_WIN32_NT)
      {
      if (info.dwMajorVersion < 5)
        Report->Lines->Add("Windows NT");
      else if (info.dwMajorVersion < 5)
        Report->Lines->Add("Windows 2000");
      }
   else Report->Lines->Add("/t unknow System.");

        AnsiString csdver  = info.szCSDVersion;
   if (csdver.IsEmpty() && info.dwPlatformId == VER_PLATFORM_WIN32_NT)
        Report->Lines->Add("No Service Pack Installed");
   else Report->Lines->Add(csdver);



///////////////////////////////////////////////////////////////
/*
// READ FROM FILE

        ifstream fp_in;
//Application->GetNamePath()
        fp_in.open(FileName, ios::in);        // | ios::noreplace);
        if (!fp_in) return false;             // controllo validità output

        OSRegInfo *LocalOSKeys[256];
                                                        // carattere di tabulazione = TabChar
//        fp_out.write((char *)(pItem->Name(0)), strlen(pItem->Name(0)));
        int l=0;
        AnsiString key, name, temp;
        while(!fp_in.eof())
                {
//                temp = fp_in.read();
                //parse
                LocalOSKeys[l++] = new OSRegInfo(key, name);
                }
        fp_in.close();
  TRegistry *Registry = new TRegistry;

for (int i=0; i<l; i++)
        {
            Registry->RootKey = LocalOSKeys[i]->RootKey;
            // False because we do not want to create it if it doesn't exist
            Registry->OpenKey(LocalOSKeys[i].Key ,false);
            LocalOSKeys[i].Value = Registry->ReadString(LocalOSKeys[i].Name);
            ////////
            if (LocalOSKeys[i].Value)
                Report->Lines->Add(LocalOSKeys[i].Comment + ":/t" + LocalOSKeys[i].Value);
            ////////
        };

    delete Registry;

 */
//////////////////////////////////////////////////////////////////
      return true;
};


void EnumerateDrives(TMemo *Report)
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
        case DRIVE_RAMDISK:     Rep = DriveLetter + "\t Removable drive";
                                break;
        default:                Rep = DriveLetter + "\t Not mouted";
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
};
