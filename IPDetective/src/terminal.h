//---------------------------------------------------------------------------

#ifndef terminalH
#define terminalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TTerminalFrm : public TForm
{
__published:	// IDE-managed Components

        TMemo *TConsole_Memo;
        TPanel *Panel;
        TComboBox *TConsole_cmb;
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall TConsole_cmbKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        TComboBox *TConsoleApp_cmb;
        TMemo *TConsoleApp_Memo;
        TMenuItem *CloseCall;
        __fastcall TTerminalFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTerminalFrm *TerminalFrm;
//---------------------------------------------------------------------------
#endif
