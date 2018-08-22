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

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "image.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TImageFrm *ImageFrm;
//---------------------------------------------------------------------------
__fastcall TImageFrm::TImageFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TImageFrm::ImageClick(TObject *Sender)
{
ImageFrm->Close();
}
//---------------------------------------------------------------------------

