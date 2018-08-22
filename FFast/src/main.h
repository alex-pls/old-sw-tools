//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TmainFrm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Edit1;
        TMenuItem *A1;
        TMenuItem *N1;
        TMenuItem *Exit1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TBevel *Bevel1;
        TComboBox *MacBox;
        TLabel *Label1;
        TComboBox *CatBox;
        TBevel *Bevel2;
        TLabel *Label2;
        TBevel *Bevel3;
        TLabel *Label3;
        TEdit *MatBox;
        TMenuItem *OpenDataFile1;
        TSaveDialog *SaveDialog;
        TOpenDialog *OpenDialog;
        TMenuItem *ViewDataFile1;
        TMenuItem *SaveData1;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TGroupBox *GroupBox1;
        TEdit *EditMac;
        TGroupBox *GroupBox2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TLabel *Label4;
        TListBox *ListMacs;
        TStaticText *StaticMacN;
        TComboBox *MacBox2;
        TBevel *Bevel4;
        TLabel *Label6;
        TListBox *ListCats;
        TButton *Button7;
        TButton *Button8;
        TPanel *Panel1;
        TLabel *Label8;
        TLabel *Label9;
        TEdit *EditCat1;
        TEdit *EditCat2;
        TButton *Button9;
        TGroupBox *GroupBox3;
        TButton *Button10;
        TLabel *Label7;
        TEdit *EditAddCat;
        TEdit *EditAddCat2;
        TEdit *EditAddCat1;
        TLabel *Label10;
        TLabel *Label11;
        TMenuItem *N2;
        TMenuItem *EsportaListaMacchine1;
        TLabel *Label12;
        TStaticText *MacInfo;
        TMenuItem *Aggiorna1;
        TStaticText *InfoText1;
        TStaticText *InfoText2;
        TMenuItem *RicaricaDati1;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *Save1;
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall MacBoxKeyPress(TObject *Sender, char &Key);
        void __fastcall MatBoxKeyPress(TObject *Sender, char &Key);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall OpenDataFile1Click(TObject *Sender);
        void __fastcall ViewDataFile1Click(TObject *Sender);
        void __fastcall SaveData1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall ListCatsClick(TObject *Sender);
        void __fastcall A1Click(TObject *Sender);
        void __fastcall CatBoxChange(TObject *Sender);
        void __fastcall ListMacsClick(TObject *Sender);
        void __fastcall RicaricaDati1Click(TObject *Sender);
        void __fastcall Save1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall MatBoxClick(TObject *Sender);
        void __fastcall EditMacKeyPress(TObject *Sender, char &Key);
        void __fastcall EditCatKeyPress(TObject *Sender, char &Key);
        void __fastcall EditAddCat2KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TmainFrm(TComponent* Owner);

        AllData* MyData;
        AnsiString datafile;
};
//---------------------------------------------------------------------------
extern PACKAGE TmainFrm *mainFrm;
//---------------------------------------------------------------------------
#endif
