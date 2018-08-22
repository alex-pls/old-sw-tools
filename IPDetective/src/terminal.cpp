//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "terminal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTerminalFrm *TerminalFrm;


//---------------------------------------------------------------------------
__fastcall TTerminalFrm::TTerminalFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTerminalFrm::FormPaint(TObject *Sender)
{
        TConsole_cmb->Width = TConsole_Memo->Width;
}
//---------------------------------------------------------------------------
void __fastcall TTerminalFrm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        CloseCall->Checked = false;
}
//---------------------------------------------------------------------------


void __fastcall TTerminalFrm::TConsole_cmbKeyPress(TObject *Sender,
      char &Key)
{
    TConsoleApp_cmb->Text = TConsole_cmb->Text;
    if (Key == VK_RETURN)
        {
//SEND  TConsole_cmb->Text
        TConsole_Memo->Lines->Add("£ocal:\t" + TConsole_cmb->Text);
        TConsoleApp_Memo->Lines->Add("£ocal:\t" + TConsole_cmb->Text);
        TConsole_cmb->Clear();
        TConsoleApp_cmb->Clear();
        };

}
//---------------------------------------------------------------------------

