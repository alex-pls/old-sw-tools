// IPDetective Project
//
// Status: Aborted
//
// by Alessandro Polo 2002
// eWorld Network :: www.ewgate.net
//------------------------------------------------------------------------------
//                                                                    15/05/2002
#ifndef osinfoH
#define osinfoH
//==============================================================================

const char *FileName = "oskeys.dat";

class OSRegInfo {
public:
        AnsiString RootKey;
        AnsiString Path;
        AnsiString Value;
        AnsiString Name;
        AnsiString Comment;
        OSRegInfo();
        OSRegInfo(AnsiString SetKey, AnsiString SetName)
                {
//                Key = SetKey;
// PARSE
                Name = SetName;
                };
};
bool GetAdapterInfo(int nAdapterNum, TMemo *Report);
void EnumerateDrives(TMemo *Report);
bool OSInfoS(TMemo *Report);
inline DWORD PackDLLVersion(DWORD major, DWORD minor)
   {
   return((major << 16) + minor);
   }

DWORD GetDLLVersion(String dllName);



              

//==============================================================================
#endif


/*

HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\UNIMODEM\DeviceSpecific
        first sub folder is modem name

HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Setup
        \BootDir


HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon
        AltDefaultDomainName
        AltDefaultUserName
        AutoAdminLogon           0 o 1
        Shell

HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\NetworkCards
        1    \Description
        2


HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Updates
         win2000 updates


HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion
         SystemRoot

         RegisteredOwner
         RegisteredOrganization
         ProductName
         ProductID
         CurrentVersion
         CurrentType
         CurrentBuildNumber
         CSDVersion
*/
