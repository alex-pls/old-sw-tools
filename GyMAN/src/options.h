//---------------------------------------------------------------------------

#ifndef optionsH
#define optionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TOptionsFrm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TGroupBox *GroupBox3;
        TPanel *Panel2;
        TPanel *Panel3;
        TGroupBox *GroupBox1;
        TCheckBox *CheckBox1;
        TEdit *Edit1;
        TCheckBox *CheckBox2;
        TImage *Image1;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox3;
        void __fastcall Panel2Click(TObject *Sender);
        void __fastcall Panel3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Panel2DblClick(TObject *Sender);
        void __fastcall Panel3DblClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOptionsFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionsFrm *OptionsFrm;
//---------------------------------------------------------------------------
#endif
