

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


bool AOLCrash (struct sockaddr_in &target, int proto, TMemo* Report);
bool IGMPWinDOS (struct sockaddr_in &target, int proto, TMemo* Report);
bool DOSNuke (struct sockaddr_in &target, int proto, TMemo* Report);



extern "C" HRESULT __declspec(dllexport) WINAPI DllGetVersion(dllversioninfo* Release);



// MAIN Exports

extern "C" AnsiString __declspec(dllexport) WINAPI EnumServices(int ServiceID);
extern "C" AnsiString __declspec(dllexport) WINAPI GetServiceDesc(int ServiceID);
extern "C" int __declspec(dllexport) WINAPI GetServicePort(int ServiceID);
extern "C" bool __declspec(dllexport) WINAPI CallService(int ServiceID, AnsiString ip, int port, int proto, TMemo* Report);

#endif

