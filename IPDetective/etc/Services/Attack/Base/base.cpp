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

#include <winsock2.h>

#include "base.h"
#pragma hdtstop         //Added
#pragma argsused

using namespace std;


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

extern "C" AnsiString __declspec(dllexport) WINAPI EnumServices(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return "";
        case 1: return "";
       default: return "";
        };
 }

extern "C" AnsiString __declspec(dllexport) WINAPI GetServiceDesc(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return "";
        case 1: return "";
       default: return "";
        };
 }

extern "C" int __declspec(dllexport) WINAPI GetServicePort(int ServiceID)
{
switch (ServiceID)
        {
        case 0: return 0;
        case 1: return 0;
       default: return 0;
        };
 }

extern "C" bool __declspec(dllexport) WINAPI CallService(int ServiceID, AnsiString ip, int port, int proto, TMemo* Report)
{
        WSADATA wsad;
        if( WSAStartup( 0x0101, &wsad ) )          //  Initialize sockets here
                {
                Report->Lines->Add("ERROR|\tWSAStartup(0x0101) failed:" + AnsiString(WSAGetLastError()));
                return false;
                };


switch (ServiceID)
        {
        case 0: return (ip, port, proto, Report);
        case 1: return (ip, port, proto, Report);
       default: return false;
        };
 }

bool (AnsiString ip, int port, int proto, TMemo* Report)
 {
        return true;
 };


bool (AnsiString ip, int port, int proto, TMemo* Report)
 {
     return true;
 };

