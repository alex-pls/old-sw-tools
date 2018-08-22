/*
........eWorld ReSearch 2004
........Alessandro Polo
........http://www.ewgate.net
........=====================
........This software is freeware. Source code is Open Source.
........Keep Author's Credits if you use any part of this software.
........=====================
........Project State: Completed
........Project Date:  28/2/2004
*/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("main.cpp", mainFrm);
USEFORM("options.cpp", OptionsFrm);
USEFORM("about.cpp", AboutBox);
USEFORM("calendar.cpp", CalendarFrm);
USEFORM("image.cpp", ImageFrm);
USEFORM("imageed.cpp", ImageEditorFrm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, int)
{
        Application->Title = "eWorld Testing Instance System";
        HWND hPrevApp;
        hPrevApp = ::FindWindow("TApplication", "GyManager 1.02");
        if ((hPrevApp)&&( hInstance != hPrevApp))
                {
                PostMessage(hPrevApp, WM_SYSCOMMAND, SC_RESTORE, 0);
                return 0;
                };

    try {
                 Application->Initialize();
                 Application->Title = "GyManager 1.02";
                 Application->CreateForm(__classid(TmainFrm), &mainFrm);
                 Application->CreateForm(__classid(TOptionsFrm), &OptionsFrm);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TCalendarFrm), &CalendarFrm);
                 Application->CreateForm(__classid(TImageFrm), &ImageFrm);
                 Application->CreateForm(__classid(TImageEditorFrm), &ImageEditorFrm);
                 Application->Run();


        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
