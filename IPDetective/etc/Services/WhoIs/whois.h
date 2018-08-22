

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




class __declspec(dllexport) ServerSocket
{
 private:
	 int MemberOne;
//         String hostname;
         bool enable;
 public:
	 static int MemberTwo;
         int FunctionGetMemberOne ();
         bool Enable() { return this->enable;};
//         String GetHostName() { return this->hostname};
 };


extern "C" bool __declspec(dllexport) WINAPI  WhoIs(AnsiString server, AnsiString ip, TMemo* Report);
extern "C" bool __declspec(dllexport) WINAPI  ValidateServer(AnsiString ip, int port, TMemo* Report);


#endif

