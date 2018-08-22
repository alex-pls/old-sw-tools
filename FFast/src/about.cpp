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
void __fastcall TAboutBox::CommentsClick(TObject *Sender)
{
 ShellExecute(Handle, "open", "http://www.ewgate.net/research/", NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

