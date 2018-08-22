

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



extern "C" void __declspec(dllexport) WINAPI YourFunctionNumberOne();

extern "C" HRESULT __declspec(dllexport) WINAPI DllGetVersion(dllversioninfo* Release);



// MAIN Exports

extern "C" bool __declspec(dllexport) WINAPI Ping(int MethodID, TMemo *Report);






bool Decode_Resp(char * buf, int bytes, struct sockaddr_in * from, TMemo *Report);
void Fill_Icmp_Data(char * icmp_data, int datasize);
USHORT Checksum(USHORT * buffer, int size);


#endif

