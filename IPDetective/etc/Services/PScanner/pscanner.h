

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

////////////////////////////////////////////////////////////// Lame Scan
typedef struct tagLIVE_PORTS
{
	AnsiString      strName;
	AnsiString      strAliases;
	short           s_port;
        AnsiString      strProto;
}LIVE_PORTS;
////////////////////////////////////////////////////////////// Lame Scan


extern "C" void __declspec(dllexport) WINAPI YourFunctionNumberOne();

extern "C" HRESULT __declspec(dllexport) WINAPI DllGetVersion(dllversioninfo* Release);



// MAIN Exports
extern "C" bool __declspec(dllexport) WINAPI Scan(int MethodID, TMemo *Report);

extern "C" bool __declspec(dllexport) WINAPI LameScan(AnsiString strHostOrIP, LIVE_PORTS *pPorts, unsigned int nPort, TMemo *Report);




AnsiString InterpretError(unsigned int nErrCode);

#endif

