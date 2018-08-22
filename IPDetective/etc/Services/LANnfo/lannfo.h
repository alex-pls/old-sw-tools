

#ifdef __BUILDING_THE_DLL

#define __EXPORT_TYPE __export
	#else
	#define __EXPORT_TYPE __import
	#endif

#ifndef _MYDLL_H
#define _MYDLL_H


typedef struct _dllversioninfo
{
    DWORD dwmajorversion;
    DWORD dwminorversion;
    DWORD dwbuildnumber;
    DWORD dwplatformid;
}dllversioninfo;

typedef LONG		HRESULT;

typedef bool(WINAPI * pSnmpExtensionInit) (
        IN DWORD dwTimeZeroReference,
        OUT HANDLE * hPollForTrapEvent,
        OUT AsnObjectIdentifier * supportedView);

typedef bool(WINAPI * pSnmpExtensionTrap) (
        OUT AsnObjectIdentifier * enterprise,
        OUT AsnInteger * genericTrap,
        OUT AsnInteger * specificTrap,
        OUT AsnTimeticks * timeStamp,
        OUT RFC1157VarBindList * variableBindings);

typedef bool(WINAPI * pSnmpExtensionQuery) (
        IN BYTE requestType,
        IN OUT RFC1157VarBindList * variableBindings,
        OUT AsnInteger * errorStatus,
        OUT AsnInteger * errorIndex);

typedef bool(WINAPI * pSnmpExtensionInitEx) (
        OUT AsnObjectIdentifier * supportedView);


extern "C" void __declspec(dllexport) WINAPI YourFunctionNumberOne();
extern "C" HRESULT __declspec(dllexport) WINAPI DllGetVersion(dllversioninfo* Release);


class __declspec(dllexport) Computer
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


#endif

