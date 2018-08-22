//---------------------------------------------------------------------------

#ifndef imageedH
#define imageedH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TImageEditorFrm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TButton *Button1;
        TImage *Image;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TGroupBox *EditBox1;
        TEdit *HSizeEdit;
        TEdit *WSizeEdit;
        TCheckBox *CheckBox1;
        TButton *Button5;
        TComboBox *SelectorBox;
        TLabel *Label1;
        TLabel *Label2;
        TGroupBox *EditBox2;
        TLabel *Label3;
        TEdit *HSizeEdit1;
        TLabel *Label4;
        TEdit *WSizeEdit1;
        TButton *Button6;
        TPanel *Panel3;
        TPanel *Panel4;
        TButton *Button7;
        TPanel *Panel5;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Panel3Click(TObject *Sender);
        void __fastcall Panel1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall SelectorBoxChange(TObject *Sender);
        void __fastcall Panel4Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall WSizeEditKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall HSizeEditKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TImageEditorFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TImageEditorFrm *ImageEditorFrm;
//---------------------------------------------------------------------------
#endif
