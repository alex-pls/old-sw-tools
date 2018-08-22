//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "shortcuts.h"
//#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TShortCutsFrm *ShortCutsFrm;
//---------------------------------------------------------------------------
__fastcall TShortCutsFrm::TShortCutsFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TShortCutsFrm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//mainFrm->WinShortcuts_Mnu->Checked = false;
}
//---------------------------------------------------------------------------

