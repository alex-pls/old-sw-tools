

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




class SystemInfos
 {
 private:

 public:
        SystemSoftware Software;
        SystemHardware Hardware;
        SystemNetwork Network;

//        SystemInfos();
//        ~SystemInfos();

 };

#endif

