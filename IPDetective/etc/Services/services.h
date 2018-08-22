#include <vcl.h>
#include <windows.h>
#include <string>
#include <shlwapi.h>

class ServiceDLL {
 private:
        AnsiString FileName;
        AnsiString defFileName;
        AnsiString Description;
        AnsiString Version;
        HINSTANCE hLibrary;
        bool Loaded;
 public:
        ServiceDLL(AnsiString newFileName, bool LoadNow, AnsiString newDescription = "");
        ~ServiceDLL();
        bool Load();
        AnsiString GetVersion(){return Version;};
        HINSTANCE GetIstance(){return hLibrary;};
        AnsiString GetDescription(){return Description;};
        bool SetFileName(AnsiString newFileName);
        AnsiString GetFileName(){return FileName;};
        AnsiString GetdefFileName(){return defFileName;};
        bool Status(){return (this->Loaded);}
 };



ServiceDLL Ping("pinger.dll", false, "Ping");
ServiceDLL Finger("finger.dll", false, "Finger");
ServiceDLL PortScanner("pscanner.dll", false, "Port Scanner");
ServiceDLL TraceRoute("tracer.dll", false, "TraceRoute");
ServiceDLL WhoIs("whois.dll", false, "WhoIs");
ServiceDLL OSFinger("osfinger.dll", false, "OS Detection");
ServiceDLL EmailServ("emails.dll", false, "Email Services");
ServiceDLL SimpleServ("simples.dll", false, "Simple Services");
ServiceDLL WWWServ("wwwserv.dll", false, "WWW Services");
ServiceDLL TrScanner("trscanner.dll", false, "Trojan Scanner");
ServiceDLL LANServ("lannfo.dll", false, "LAN Service");
ServiceDLL ICQServ("base.dll", true, "ICQ Service");
ServiceDLL ICQMAPI("ICQMAPI.dll", true, "ICQ MAPI");

ServiceDLL AttackFunctions("bonus.dll", true, "AttackFunctions");


ServiceDLL LServEcho("s_echo.dll", true, "Echo Server");

ServiceDLL SysInfoServ("sysinfos.dll", true, "System Infos Loader");


ServiceDLL PROVA("base.dll", true, "PROVA");



 ServiceDLL *AllServices[] = {&Ping ,
                             &Finger ,
                             &PortScanner ,
                             &TraceRoute ,
                             &WhoIs ,
                             &OSFinger ,
                             &EmailServ ,
                             &SimpleServ ,
                             &WWWServ ,
                             &TrScanner ,
                             &LANServ ,
                             &ICQServ ,
                             &ICQMAPI    };     // Services must be in the same
                                                //  order as in the treeview list

const int ServiceCount = 13;

ServiceDLL *AllServers[]  = {&LServEcho
                                         };


  HRESULT (PASCAL FAR * lpfn_getVersion)(DLLVERSIONINFO *Release);



//WhoIs
  bool (PASCAL FAR * lpfn_WhoIs)(AnsiString server, AnsiString ip, TMemo* Report);
  bool (PASCAL FAR * lpfn_WhoIsValidate)(AnsiString ip, int port, TMemo* Report);

//LANinfo

  bool (PASCAL FAR * lpfn_LAN_EnumNetwork)(DWORD dwLevel, LPNETRESOURCE lpNet, TMemo* Report);
  bool (PASCAL FAR * lpfn_LAN_EnumDrives)(TMemo* Report);
  bool (PASCAL FAR * lpfn_GetMACAdapters)(int nGetWay, TMemo *Report);

  bool (PASCAL FAR * lpfn_LAN_EnumNetHandler)(DWORD dwLevel, LPNETRESOURCE lpNet, TMemo* Report);
  bool (PASCAL FAR * lpfn_LAN_EnumerateServerDisks)(AnsiString Server, TMemo *Report);
  bool (PASCAL FAR * lpfn_LAN_EnumerateUsers)(AnsiString Server, TMemo* Report);
  bool (PASCAL FAR * lpfn_LAN_EnumerateGroups)(AnsiString Server, TMemo *Report);
  bool (PASCAL FAR * lpfn_LAN_EnumerateServers)(AnsiString Server, AnsiString Domain, TMemo *Report);
  bool (PASCAL FAR * lpfn_LAN_GetDCName)(AnsiString Server, AnsiString Domain, TMemo *Report);;


class __declspec(dllimport) Computer
{
 private:
        AnsiString Server;
        AnsiString Domain;
        TMemo *Report;

 public:
        Computer();
        Computer(AnsiString newServer, TMemo *newReport);
        Computer(AnsiString newServer, AnsiString newDomain, TMemo *newReport);
//        ~Computer();

        bool EnumDrives();
        bool EnumServerDisks();
        bool EnumUsers();
        bool EnumGroups();
        bool EnumServers();

        bool GetDCName();

        bool EnumNetHandler(DWORD dwLevel, LPNETRESOURCE lpNet, TMemo* Report);
        bool GetMACAdapters(int nGetWay);

};


//Simple Services
  AnsiString (PASCAL FAR * lpfn_SimpleSEnum)(int ServiceID);
  AnsiString (PASCAL FAR * lpfn_GetSServiceDesc)(int ServiceID);
  bool (PASCAL FAR * lpfn_CallService)(int ServiceID, AnsiString ip, int port, int proto, TMemo* Report);
  int  (PASCAL FAR * lpfn_GetSServicePort)(int ServiceID);


//Pinger
  bool (PASCAL FAR * lpfn_Ping_Lame)(AnsiString ip, unsigned int PingTimes, unsigned int PacketSize, TMemo *Report);


//Port Scanner
//  bool (PASCAL FAR * lpfn_PS_LameScan(AnsiString strHostOrIP, LIVE_PORTS *pPorts, unsigned int nPort, TMemo *Report);


//Finger
  bool (PASCAL FAR * lpfn_Finger_Lame)(AnsiString ip, int port, AnsiString user, TMemo* Report);

// ICQ MAPI  TEMPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP

  bool (PASCAL FAR * lpfn_ICQAPICall_SetLicenseKey)(char *pszName, char *pszPassword, char *pszLicense);
