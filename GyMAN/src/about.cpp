/*
........eWorld ReSearch 2004
........Alessandro Polo
........http://www.ewgate.net
........=====================
........This software is freeware. Project is Open Source.
........Keep Author's Credits if you use any part of this software.
........=====================
........Project State: Completed
........Project Date:  09/3/2004
*/
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "about.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::Label2Click(TObject *Sender)
{
 ShellExecute(Handle, "open", "http://www.ewgate.net/research/", NULL,NULL,SW_SHOWDEFAULT);
        
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Label1Click(TObject *Sender)
{
 ShellExecute(Handle, "open", "http://www.twain.org/", NULL,NULL,SW_SHOWDEFAULT);

}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Label3Click(TObject *Sender)
{
        ShellExecute(NULL, "open", "notepad.exe", "ReadMe.txt", "", SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

