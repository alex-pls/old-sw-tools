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

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
#include <ValEdit.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TmainFrm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Modifica1;
        TMenuItem *Abotu1;
        TMenuItem *N1;
        TMenuItem *Aggiorna1;
        TMenuItem *CaricaFile1;
        TMenuItem *SalvaconNome1;
        TMenuItem *N2;
        TMenuItem *exit1;
        TMenuItem *GyMan1;
        TMenuItem *eWorldReSearch1;
        TPageControl *PageControl;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TStatusBar *StatusBar;
        TDataSource *DataSource;
        TDBGrid *DBGrid;
        TDBNavigator *DBNavigator1;
        TMenuItem *Opzioni1;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TOpenPictureDialog *OpenPictureDialog;
        TSavePictureDialog *SavePictureDialog;
        TFontDialog *FontDialog;
        TColorDialog *ColorDialog;
        TGroupBox *GroupBox1;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TLabel *Label1;
        TGroupBox *GroupBox2;
        TLabel *Label2;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TStaticText *StaticText5;
        TGroupBox *GroupBox3;
        TButton *Button1;
        TTable *Table;
        TMenuItem *N3;
        TMenuItem *SvuotaDatabase;
        TDBEdit *DBEdit1;
        TDBNavigator *DBNavigator2;
        TButton *Button3;
        TButton *Button4;
        TDBMemo *DBMemo1;
        TMenuItem *Ordinaper1;
        TMenuItem *Nome1;
        TMenuItem *Scadenza1;
        TMenuItem *Iscrizione1;
        TMenuItem *Datadinascita1;
        TPanel *Panel1;
        TGroupBox *GroupBox4;
        TMonthCalendar *MonthCalendar;
        TGroupBox *GroupBox5;
        TValueListEditor *ExpiredList;
        TValueListEditor *ExpiringList;
        TStaticText *StaticText6;
        TComboBox *cmb_dayspan;
        TLabel *Label3;
        TMenuItem *Visualizza1;
        TMenuItem *Calendario1;
        TMenuItem *FotoTessera1;
        TButton *Button5;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
        TDBEdit *DBEdit4;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TDBImage *DBImage1;
        TButton *Button11;
        TImageList *ImageList;
        TMenuItem *Aquisisci1;
        TImage *ImageS;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *EsportaListaNomi1;
        TMenuItem *N6;
        TMenuItem *EsportaListaCompleta1;
        TMenuItem *Nuovodatabase1;
        TMenuItem *EditorImmagini1;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TButton *Button2;
        TButton *Button9;
        TButton *Button10;
        TButton *Button12;
        TTable *expTable;
        TStaticText *StaticText7;
        TDBEdit *DBEdit5;
        TStaticText *StaticText8;
        TDBEdit *DBEdit6;
        TDBCheckBox *DBCheckBox1;
        TStaticText *StaticText9;
        TMenuItem *N10;
        TMenuItem *ClientisenzaCertificato1;
        TStaticText *StaticText10;
        TLabel *Label4;
        TComboBox *cmb_dayscad;
        void __fastcall Opzioni1Click(TObject *Sender);
        void __fastcall exit1Click(TObject *Sender);
        void __fastcall CaricaFile1Click(TObject *Sender);
        void __fastcall SalvaconNome1Click(TObject *Sender);
        void __fastcall GyMan1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall SvuotaDatabaseClick(TObject *Sender);
        void __fastcall Modifica2Click(TObject *Sender);
        void __fastcall Elimina1Click(TObject *Sender);
        void __fastcall Aggiungi1Click(TObject *Sender);
        void __fastcall Nome1Click(TObject *Sender);
        void __fastcall Scadenza1Click(TObject *Sender);
        void __fastcall Iscrizione1Click(TObject *Sender);
        void __fastcall Datadinascita1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall DBEditKeyPress(TObject *Sender, char &Key);
        void __fastcall Aggiorna1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Calendario1Click(TObject *Sender);
        void __fastcall FotoTessera1Click(TObject *Sender);
        void __fastcall cmb_dayspanKeyPress(TObject *Sender, char &Key);
        void __fastcall TableAfterPost(TDataSet *DataSet);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall ExpiringListClick(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall ExpiredListClick(TObject *Sender);
        void __fastcall DBEditDateClick(TObject *Sender);
        void __fastcall eWorldReSearch1Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Aquisisci1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall EsportaListaNomi1Click(TObject *Sender);
        void __fastcall EsportaListaCompleta1Click(TObject *Sender);
        void __fastcall Nuovodatabase1Click(TObject *Sender);
        void __fastcall EditorImmagini1Click(TObject *Sender);
        void __fastcall ImageSClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall ClientisenzaCertificato1Click(TObject *Sender);
        void __fastcall cmb_dayscadKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TmainFrm(TComponent* Owner);

        AnsiString defdatafile;
        AnsiString defStatusMsg;
        int ColDimTable[9];
        int ImageH;
        int ImageW;

};
//---------------------------------------------------------------------------
extern PACKAGE TmainFrm *mainFrm;

extern HANDLE TwainInst;


//---------------------------------------------------------------------------
#endif
