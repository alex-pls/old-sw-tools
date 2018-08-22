
#include "services.h"

ServiceDLL::ServiceDLL(AnsiString newFileName, bool LoadNow, AnsiString newDescription)
 {
 this->Loaded = false;

 this->defFileName = newFileName;
 this->Description = newDescription;
 this->Version = "";

 if (!SetFileName(newFileName)) return;

 if (LoadNow)
        {
         this->hLibrary = LoadLibrary(this->FileName.c_str());
         if (this->hLibrary)
                {
                this->Loaded = true;

                (FARPROC) lpfn_getVersion = GetProcAddress (this->hLibrary, "DllGetVersion");
//                DLLGETVERSIONPROC getVersion = (DLLGETVERSIONPROC)GetProcAddress(this->hLibrary, "DllGetVersion");
                if (lpfn_getVersion)
                        {
ShowMessage("ciao bambo");
                        DLLVERSIONINFO info;
                        ZeroMemory(&info, sizeof(info));
                        info.cbSize = sizeof(info);
                        HRESULT result = (lpfn_getVersion)(&info);
// BUG    -> SUCCEEDED(x)   x TO BE OK ?????????????????
                        if (result)
                                this->Version = AnsiString(info.dwMajorVersion) + "." + AnsiString(info.dwMinorVersion)  + " (built " + AnsiString(info.dwBuildNumber) + ") [" + AnsiString(info.dwPlatformID) + "]";
                        else
                                ShowMessage("ciao bambo!!");
                        };
                };
        };
 }

bool ServiceDLL::Load()
 {
 if (this->Loaded) return true;
 if (this->FileName == "ERROR - File not Found") return false;

 this->hLibrary = LoadLibrary(this->FileName.c_str());
 if (this->hLibrary)
        {
        this->Loaded = true;
        return true;
        }
 return false;
 }

bool ServiceDLL::SetFileName(AnsiString newFileName)
 {
    if (FileExists(newFileName))
        {
        this->FileName = newFileName;
        return true;
        }
    this->FileName = "ERROR - File not Found";
    this->Loaded = false;
    return false;
 }

ServiceDLL::~ServiceDLL()
 {
 FreeLibrary(this->hLibrary);
 }


