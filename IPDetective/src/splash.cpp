//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSplashFrm *SplashFrm;
//---------------------------------------------------------------------------
__fastcall TSplashFrm::TSplashFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSplashFrm::FormCreate(TObject *Sender)
{
//AppVersion_Lbl->Caption = "version " + VERSION;
//CompileTime_Lbl->Caption = "compiled on " + FILEDATE;
}
//---------------------------------------------------------------------------
