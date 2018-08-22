//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("IPDetec.res");
USEFORM("main.cpp", mainFrm);
USEUNIT("OSfunc.cpp");
USEFORM("about.cpp", AboutBox);
USEFORM("splash.cpp", SplashFrm);
USEFORM("shortcuts.cpp", ShortCutsFrm);
USEFORM("terminal.cpp", TerminalFrm);
USEUNIT("Services\services.cpp");
USEUNIT("include\SerialPort\comm.cpp");
USEUNIT("include\SerialPort\BackgroundCommThread.cpp");
//---------------------------------------------------------------------------
HINSTANCE g_hinst;              // used for TrayIcon
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE hInstance, LPSTR, int)
{
    // Search for a previous instances using the caption of the
    // the hidden application window. In order to do this, we
    // must temporarily change our caption so that FindWindow
    // doesn't find us (the hidden application window has
    // already been created before WinMain runs)
    Application->Title = "";
    HWND hPrevApp = ::FindWindow(NULL, "IP Detective 2002");

    // FindWindow returns a non-zero HWND if it finds the window
    // If the window was found, restore it and return without running
    if(hPrevApp)
    {
        PostMessage(hPrevApp, WM_SYSCOMMAND, SC_RESTORE, 0);
        return 0;
    }
    // else: other instance not found, restore the title and continue
    else
        Application->Title = "IP Detective 2002";


        try
        {
                 Application->Initialize();
                 Application->Title = "IP Detective 2002";
                 g_hinst = hInstance;   // used for TrayIcon
                 Application->CreateForm(__classid(TmainFrm), &mainFrm);
                 Application->CreateForm(__classid(TSplashFrm), &SplashFrm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
