/*
........eWorld ReSearch 2004
........Alessandro Polo
........http://www.ewgate.net
........=====================
........This software is freeware. Source code is Open Source.
........Keep Author's Credits if you use any part of this software.
........=====================
........Project State: Completed
........Project Date:  27/2/2004
*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("main.cpp", mainFrm);
USEFORM("about.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Fast Catalog Manager 1.0";
                 Application->CreateForm(__classid(TmainFrm), &mainFrm);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
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
