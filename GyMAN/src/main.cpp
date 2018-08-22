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
#include <DateUtils.hpp>
#include <Clipbrd.hpp>

#include "ShellAPI.h"

#pragma hdrstop

#include "main.h"
#include "options.h"
#include "calendar.h"
#include "image.h"
#include "imageed.h"
#include "about.h"
#include "twaini.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainFrm *mainFrm;

//---------------------------------------------------------------------------
__fastcall TmainFrm::TmainFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TmainFrm::Opzioni1Click(TObject *Sender)
{
OptionsFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::exit1Click(TObject *Sender)
{
FormClose(Sender, caFree);
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SalvaconNome1Click(TObject *Sender)
{
 SaveDialog->Title = "Salva Database con nome..";
 SaveDialog->DefaultExt = "DBF";
 SaveDialog->Filter = "DBase (*.dbf)|*.DBF";
 SaveDialog->Options.Clear();
 SaveDialog->Options << ofPathMustExist;

 if (SaveDialog->Execute())
        {
        expTable->Close();
        expTable->Exclusive = true;
        expTable->DatabaseName = "";
        expTable->TableName = SaveDialog->FileName;
        expTable->TableType = ttDBase;
        expTable->FieldDefs->Clear();
        expTable->FieldDefs->Add("name", ftString, 32, true);
        expTable->FieldDefs->Add("expdate", ftDate);
        expTable->FieldDefs->Add("subdate", ftDate);
        expTable->FieldDefs->Add("birthdate", ftDate);
        expTable->FieldDefs->Add("notes", ftString, 128);
        expTable->FieldDefs->Add("phone", ftString, 32);
        expTable->FieldDefs->Add("address", ftString, 64);
        expTable->FieldDefs->Add("image", ftGraphic);
        expTable->FieldDefs->Add("cert", ftBoolean);
        expTable->IndexDefs->Clear();
        expTable->IndexDefs->Add("","name", TIndexOptions() <<ixPrimary << ixUnique);
        expTable->IndexDefs->Add("expdate","expdate", TIndexOptions());
        expTable->IndexDefs->Add("subdate","subdate", TIndexOptions());
        expTable->IndexDefs->Add("birthdate","birthdate", TIndexOptions());
        expTable->CreateTable();
        expTable->Open();
        expTable->BatchMove(Table, batAppend);
        expTable->Close();

        if (FileExists(SaveDialog->FileName))
                {
                AnsiString tmpmsg, basefile;
                basefile = SaveDialog->FileName.SubString(1, SaveDialog->FileName.LowerCase().AnsiPos(".dbf")-1);
                tmpmsg = "Il database è stato esportato. Mantenere la copia per sicurezza. \n\n";
                tmpmsg += "Nota: I file dati sono i seguenti: \n";
                tmpmsg += "\t - " + basefile + ".DBF";
                tmpmsg += "\n\t - " + basefile + ".DBT";
                tmpmsg += "\n\t - " + basefile + ".MDX";
                tmpmsg += "\n\nNon rinominare i file e non separarli.";
                ShowMessage(tmpmsg);
                }
        else
                ShowMessage("ERRORE: Il database non è stato salvato.");

        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::GyMan1Click(TObject *Sender)
{
AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button1Click(TObject *Sender)
{
ImageEditorFrm->Image->AutoSize = true;
ImageEditorFrm->Image->Stretch = false;
ImageEditorFrm->Image->Picture->Assign(DBImage1->Picture);
ImageEditorFrm->HSizeEdit->Text = ImageEditorFrm->Image->Picture->Height;
ImageEditorFrm->WSizeEdit->Text = ImageEditorFrm->Image->Picture->Width;
ImageEditorFrm->Image->AutoSize = false;
ImageEditorFrm->Button4Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SvuotaDatabaseClick(TObject *Sender)
{
if (Table->Active)
        if (Application->MessageBoxA("Tutti i dati dei Clienti vengono persi irrimediabilmente.", "Svuotare il Database?", MB_YESNO) == IDYES)
                Table->EmptyTable();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Modifica2Click(TObject *Sender)
{
if (Table->Active)
        {
        if (!PageControl->ActivePage->TabIndex)
                PageControl->ActivePageIndex = 2;
        Table->Edit();
        if (PageControl->ActivePage->TabIndex == 2)
                DBEdit4->SetFocus();
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Elimina1Click(TObject *Sender)
{
if (Table->Exists)
        if (Application->MessageBoxA("Eliminare il Cliente selezionato?", "Conferma rimozione..", MB_YESNO) == IDOK)
                Table->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Aggiungi1Click(TObject *Sender)
{
if (Table->Active)
        {
        if (!PageControl->ActivePage->TabIndex)
                PageControl->ActivePageIndex = 2;
        Table->Last();
        Table->Append();
        if (PageControl->ActivePage->TabIndex == 2)
                DBEdit1->SetFocus();
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Nome1Click(TObject *Sender)
{
Nome1->Checked = true;
Scadenza1->Checked = false;
Iscrizione1->Checked = false;
Datadinascita1->Checked = false;

Table->DisableControls();
Table->Active = false;
Table->Exclusive = true;
Table->IndexFieldNames = "name";
Table->IndexDefs->Update();
Table->Exclusive = false;
Table->Active = true;
Table->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Scadenza1Click(TObject *Sender)
{
Nome1->Checked = false;
Scadenza1->Checked = true;
Iscrizione1->Checked = false;
Datadinascita1->Checked = false;

Table->DisableControls();
Table->Active = false;
Table->Exclusive = true;
Table->IndexFieldNames = "expdate";
Table->IndexDefs->Update();
Table->Exclusive = false;
Table->Active = true;
Table->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Iscrizione1Click(TObject *Sender)
{
Nome1->Checked = false;
Scadenza1->Checked = false;
Iscrizione1->Checked = true;
Datadinascita1->Checked = false;

Table->DisableControls();
Table->Active = false;
Table->Exclusive = true;
Table->IndexFieldNames = "subdate";
Table->IndexDefs->Update();
Table->Exclusive = false;
Table->Active = true;
Table->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Datadinascita1Click(TObject *Sender)
{
Nome1->Checked = false;
Scadenza1->Checked = false;
Iscrizione1->Checked = false;
Datadinascita1->Checked = true;

Table->DisableControls();
Table->Active = false;
Table->Exclusive = true;
Table->IndexFieldNames = "birthdate";
Table->IndexDefs->Update();
Table->Exclusive = false;
Table->Active = true;
Table->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::FormShow(TObject *Sender)
{
//                      set default values
ImageH = 240;
ImageW = 200;
ColDimTable[0] = 200;
ColDimTable[1] = 100;
ColDimTable[2] = 100;
ColDimTable[3] = 100;
ColDimTable[4] = 100;
ColDimTable[5] = 70;
ColDimTable[6] = 70;
ColDimTable[7] = 50;
ColDimTable[8] = 50;


defStatusMsg = "Database non caricato. Aprire un file dal Menu.";
defdatafile = OptionsFrm->Edit1->Text;

OptionsFrm->Button1Click(Sender); //load options

bool erstate = true;
if ((OptionsFrm->CheckBox1->Checked)&&(FileExists(defdatafile)))
        {
        Table->Close();
        Table->DatabaseName = "";
        Table->Exclusive = true;
        Table->IndexFieldNames = "";
        Table->IndexDefs->Clear();
        Table->TableName = defdatafile;
        Table->TableType = ttDefault;

        try
                {
                Table->Exclusive;
                Table->Open();
                erstate = false;
                }
        catch (EDBEngineError* dbError)
                {
                ShowMessage(dbError[0].Message);
                };
        };

 if (!erstate)
        {
        if ((Table->Fields->Count > 8) && (Table->FieldList->Strings[0] == "name") && (Table->FieldList->Strings[1] == "expdate") && (Table->FieldList->Strings[2] == "subdate") && (Table->FieldList->Strings[3] == "birthdate") && (Table->FieldList->Strings[4] == "notes") && (Table->FieldList->Strings[5] == "phone") && (Table->FieldList->Strings[6] == "address") && (Table->FieldList->Strings[7] == "image") && (Table->FieldList->Strings[8] == "cert"))
                {
                DBEdit1->DataField = Table->FieldList->Strings[0];
                DBEdit2->DataField = Table->FieldList->Strings[1];
                DBEdit3->DataField = Table->FieldList->Strings[2];
                DBEdit4->DataField = Table->FieldList->Strings[3];
                DBMemo1->DataField = Table->FieldList->Strings[4];
                DBEdit5->DataField = Table->FieldList->Strings[5];
                DBEdit6->DataField = Table->FieldList->Strings[6];
                DBImage1->DataField = Table->FieldList->Strings[7];
                DBCheckBox1->DataField = Table->FieldList->Strings[8];

                Aggiorna1Click(Sender);
                Scadenza1Click(Sender); //ordinamento predefinito

                DBGrid->Columns->Items[0]->Title->Caption = "Nome Cliente";
                DBGrid->Columns->Items[1]->Title->Caption = "Data Scadenza";
                DBGrid->Columns->Items[2]->Title->Caption = "Data Iscrizione";
                DBGrid->Columns->Items[3]->Title->Caption = "Data di Nascita";
                DBGrid->Columns->Items[4]->Title->Caption = "Note";
                DBGrid->Columns->Items[5]->Title->Caption = "Telefono";
                DBGrid->Columns->Items[6]->Title->Caption = "Indirizzo";
                DBGrid->Columns->Items[7]->Title->Caption = "Immagine";
                DBGrid->Columns->Items[8]->Title->Caption = "Certificato";

                if (OptionsFrm->CheckBox5->Checked)
                        for (int i = 0; i <  9; i++)
                                if (ColDimTable[i])
                                        DBGrid->Columns->Items[i]->Width = ColDimTable[i];

                }
        else
                if (Application->MessageBoxA("Il file Database non sembra corretto! Creare un Nuovo database?", "Impossibile caricare il database", MB_YESNO) == IDYES)
                        Nuovodatabase1Click(Sender);

        PageControl->ActivePageIndex = 0;
        }
 else
        if (Application->MessageBoxA("Il database predefinito non esiste. Creare un Nuovo database?", "Impossibile caricare il database", MB_YESNO) == IDYES)
                Nuovodatabase1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::CaricaFile1Click(TObject *Sender)
{
OpenDialog->Title = "Carica Database Clienti..";
OpenDialog->DefaultExt = "DBF";
OpenDialog->Filter = "DBase (*.dbf)|*.DBF";
OpenDialog->Options.Clear();
OpenDialog->Options << ofFileMustExist << ofPathMustExist;
if (OpenDialog->Execute())
        {
        bool erstate = false;
        Table->Close();
        Table->DatabaseName = "";
        Table->Exclusive = true;
        Table->IndexFieldNames = "";
        Table->IndexDefs->Clear();
        Table->TableName = OpenDialog->FileName;
        Table->TableType = ttDefault;

        try
                {
                Table->Exclusive;
                Table->Open();
                }
        catch (EDBEngineError* dbError)
                {
                ShowMessage(dbError[0].Message);
                erstate = true;
                }

        if (!erstate)
                {
                if ((Table->Fields->Count > 8) && (Table->FieldList->Strings[0] == "name") && (Table->FieldList->Strings[1] == "expdate") && (Table->FieldList->Strings[2] == "subdate") && (Table->FieldList->Strings[3] == "birthdate") && (Table->FieldList->Strings[4] == "notes") && (Table->FieldList->Strings[5] == "phone") && (Table->FieldList->Strings[6] == "address") && (Table->FieldList->Strings[7] == "image") && (Table->FieldList->Strings[8] == "cert"))
                        {
                        DBEdit1->DataField = Table->FieldList->Strings[0];
                        DBEdit2->DataField = Table->FieldList->Strings[1];
                        DBEdit3->DataField = Table->FieldList->Strings[2];
                        DBEdit4->DataField = Table->FieldList->Strings[3];
                        DBMemo1->DataField = Table->FieldList->Strings[4];
                        DBEdit5->DataField = Table->FieldList->Strings[5];
                        DBEdit6->DataField = Table->FieldList->Strings[6];
                        DBImage1->DataField = Table->FieldList->Strings[7];
                        DBCheckBox1->DataField = Table->FieldList->Strings[8];

                        Aggiorna1Click(Sender);
                        Scadenza1Click(Sender); //ordinamento predefinito

                        DBGrid->Columns->Items[0]->Title->Caption = "Nome Cliente";
                        DBGrid->Columns->Items[1]->Title->Caption = "Data Scadenza";
                        DBGrid->Columns->Items[2]->Title->Caption = "Data Iscrizione";
                        DBGrid->Columns->Items[3]->Title->Caption = "Data di Nascita";
                        DBGrid->Columns->Items[4]->Title->Caption = "Note";
                        DBGrid->Columns->Items[5]->Title->Caption = "Telefono";
                        DBGrid->Columns->Items[6]->Title->Caption = "Indirizzo";
                        DBGrid->Columns->Items[7]->Title->Caption = "Immagine";
                        DBGrid->Columns->Items[8]->Title->Caption = "Certificato";

                        if (OptionsFrm->CheckBox5->Checked)
                                for (int i = 0; i <  9; i++)
                                        if (ColDimTable[i])
                                                DBGrid->Columns->Items[i]->Width = ColDimTable[i];
                        }
                else
                        {
                        ShowMessage("ERRORE: Il File dati non sembra corretto.");
                        Table->Close();
                        Aggiorna1Click(Sender);
                        };
                PageControl->ActivePageIndex = 1;
                }
        else
                {
                ShowMessage("Impossibile caricare il file.");
                Aggiorna1Click(Sender);
                }
        };
}

//---------------------------------------------------------------------------

void __fastcall TmainFrm::DBEditKeyPress(TObject *Sender, char &Key)
{
StatusBar->Panels->Items[1]->Text = "Database Modificato. Salvare premendo Invio o cliccando il Visto.";

if (Key == VK_RETURN)
        if ((Table->Active) && (Table->Exists))
                if (DBEdit1->Text.IsEmpty())
                        ShowMessage("Inserire un nome valido!");
                else
                        Table->Post();
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Aggiorna1Click(TObject *Sender)
{
StatusBar->Panels->Items[0]->Text = "Oggi " + DateToStr(Date());
ExpiredList->Strings->Clear();
ExpiringList->Strings->Clear();
CalendarFrm->MonthCalendar->Date = Date();;
ImageS->Picture->Assign(NULL);

if (!Table->Exists)
        {
        defStatusMsg = "Database non caricato. Aprire o creare un nuovo database dal Menu File.";
        StatusBar->Panels->Items[1]->Text = defStatusMsg;
        return;
        };

Table->DisableControls();
Table->First();
TDate tmpdate;
while (!Table->Eof)
        {
        if (!TryStrToDate(Table->FieldByName("expdate")->AsString, tmpdate))
                ExpiredList->InsertRow(Table->FieldByName("name")->AsString, "Scadenza non impostata!", 1);
        else if (CompareDate(Date(), tmpdate) >= 0)
                {
                if (IsSameDay(tmpdate, Date()))
                        ExpiredList->InsertRow(Table->FieldByName("name")->AsString, AnsiString(DateToStr(tmpdate) + " (oggi)"), 1);
                else if (DaysBetween(tmpdate, Date()) == 1)
                        ExpiredList->InsertRow(Table->FieldByName("name")->AsString, AnsiString(DateToStr(tmpdate) + " (ieri)"), 1);
                else  if (DaysBetween(tmpdate, Date()) <= cmb_dayscad->Text.ToIntDef(5))
                        ExpiredList->InsertRow(Table->FieldByName("name")->AsString, AnsiString(DateToStr(tmpdate) + " (" + AnsiString(DaysBetween(tmpdate, Date())) + " giorni fa)"), 1);
                };
        Table->Next();
        }

Table->First();
while (!Table->Eof)
        {
        if (TryStrToDate(Table->FieldByName("expdate")->AsString, tmpdate))
                if (CompareDate(tmpdate, Date()) > 0)
                        {
                        if (DaysBetween(tmpdate, Date()) == 1)
                                ExpiringList->InsertRow(Table->FieldByName("name")->AsString, AnsiString(DateToStr(tmpdate) + " (domani)"), 1);
                        else if (DaysBetween(tmpdate, Date()) <= cmb_dayspan->Text.ToIntDef(5))
                                ExpiringList->InsertRow(Table->FieldByName("name")->AsString, AnsiString(DateToStr(tmpdate) + " (tra " + AnsiString(DaysBetween(tmpdate, Date())) + " giorni)"), 1);
                        };
        Table->Next();
        };
Table->EnableControls();
defStatusMsg = "Database operativo. " + AnsiString(Table->RecordCount) + " clienti.";


if ((ExpiredList->RowCount==2)&&(!ExpiredList->Keys[1].IsEmpty()))
        defStatusMsg += " Una tessera scaduta.";
else if (ExpiredList->RowCount == 2)
        defStatusMsg += " Nessuna tessera scaduta.";
else if (ExpiredList->RowCount>2)
        defStatusMsg += " " + AnsiString(ExpiredList->RowCount-1) + " tessere scadute.";

if ((ExpiringList->RowCount==2)&&(!ExpiringList->Keys[1].IsEmpty()))
        defStatusMsg += " Una tessera in scadenza.";
else if (ExpiringList->RowCount == 2)
        defStatusMsg += " Nessuna tessera in scadenza.";
else if (ExpiringList->RowCount>2)
        defStatusMsg += " " + AnsiString(ExpiringList->RowCount-1) + " tessere in scadenza.";

defStatusMsg += " [file: " +  ExtractFileName(Table->TableName) + "]";
StatusBar->Panels->Items[1]->Text = defStatusMsg;

ExpiringListClick(Sender);
ExpiredListClick(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::Button3Click(TObject *Sender)
{
if (Table->Exists)
        {
        Table->DisableControls();
        Table->Edit();
        Table->Fields->FieldByName("subdate")->AsString = Date();
        Table->Post();
        Table->EnableControls();
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button4Click(TObject *Sender)
{
if (Table->Exists)
        {
        Table->DisableControls();
        Table->Edit();
        Table->Fields->FieldByName("expdate")->Value = IncMonth(Date());
        Table->Post();
        Table->EnableControls();
        };
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::Button5Click(TObject *Sender)
{
if (Table->Exists)
        {
        Table->DisableControls();
        ExpiringListClick(Sender);
        if (Table->FieldByName("name")->AsString == ExpiringList->Keys[ExpiringList->Row])
                {
                Table->Edit();
                Table->FieldByName("expdate")->Value = IncMonth(Date());
                Table->Post();
                };
        Table->EnableControls();
        PageControl->ActivePageIndex = 2;
        DBEdit2->SetFocus();
        }
else
        ShowMessage("E' necessario aprire o creare un nuovo database.");
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::Calendario1Click(TObject *Sender)
{
CalendarFrm->Visible = !CalendarFrm->Visible;
Calendario1->Checked = !Calendario1->Checked;
CalendarFrm->MonthCalendar->Date = MonthCalendar->Date;
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::FotoTessera1Click(TObject *Sender)
{
ImageFrm->Visible = !ImageFrm->Visible;
FotoTessera1->Checked = !FotoTessera1->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::cmb_dayspanKeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        {
        cmb_dayspan->Text = cmb_dayspan->Text.ToIntDef(5);
        Aggiorna1Click(Sender);
        }
}
//---------------------------------------------------------------------------



void __fastcall TmainFrm::TableAfterPost(TDataSet *DataSet)
{
defStatusMsg = "Database Operativo. Tutti i dati sono stati salvati. [" + AnsiString(Table->RecordCount) + " clienti]";
StatusBar->Panels->Items[1]->Text = defStatusMsg;
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button8Click(TObject *Sender)
{
if (Table->Exists)
        {
        Table->DisableControls();
        ExpiredListClick(Sender);
        if (Table->FieldByName("name")->AsString == ExpiredList->Keys[ExpiredList->Row])
                {
                Table->Edit();
                Table->FieldByName("expdate")->Value = IncMonth(Date());
                Table->Post();
                }
        Table->EnableControls();
        PageControl->ActivePageIndex = 2;
        DBEdit2->SetFocus();
        }
else
        ShowMessage("E' necessario aprire o creare un nuovo database.");
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button7Click(TObject *Sender)
{
if (Table->Exists)
        {
        ExpiredListClick(Sender);
        PageControl->ActivePageIndex = 2;
        Table->Edit();
        DBEdit2->SetFocus();
        }
else
        ShowMessage("E' necessario aprire o creare un nuovo database.");
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::Button6Click(TObject *Sender)
{
if (Table->Exists)
        {
        ExpiringListClick(Sender);
        PageControl->ActivePageIndex = 2;
        Table->Edit();
        DBEdit2->SetFocus();
        }
else
        ShowMessage("E' necessario aprire o creare un nuovo database.");
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ExpiringListClick(TObject *Sender)
{
if ((ExpiringList->Row < ExpiringList->RowCount)&&(Table->Exists))
        {
        TDate tmpdate = Date();
        Table->First();
        while (!Table->Eof)
                {
                if (Table->FieldByName("name")->AsString == ExpiringList->Keys[ExpiringList->Row])
                        {
                        TryStrToDate(Table->FieldByName("expdate")->AsString, tmpdate);
                        MonthCalendar->Date = tmpdate;
                        CalendarFrm->MonthCalendar->Date = tmpdate;
                        ImageS->Picture->Assign(DBImage1->Picture);
                        ImageFrm->Image->Picture->Assign(DBImage1->Picture);
                        break;
                        };
                Table->Next();
                }
        Table->EnableControls();
        }
else
        {
        CalendarFrm->MonthCalendar->Date = Date();;
        ImageS->Picture->Assign(NULL);
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ExpiredListClick(TObject *Sender)
{
if ((ExpiredList->Row < ExpiredList->RowCount)&&(Table->Exists))
        {
        TDate tmpdate = Date();
        Table->DisableControls();
        Table->First();
        while (!Table->Eof)
                {
                if (Table->FieldByName("name")->AsString == ExpiredList->Keys[ExpiredList->Row])
                        {
                        TryStrToDate(Table->FieldByName("expdate")->AsString, tmpdate);
                        MonthCalendar->Date = tmpdate;
                        CalendarFrm->MonthCalendar->Date = tmpdate;
                        ImageS->Picture->Assign(DBImage1->Picture);
                        ImageS->Hint = Table->FieldByName("notes")->AsString;
                        ImageFrm->Image->Picture->Assign(DBImage1->Picture);
                        break;
                        };
                Table->Next();
                }
        Table->EnableControls();
        }
else
        {
        CalendarFrm->MonthCalendar->Date = Date();;
        ImageS->Picture->Assign(NULL);
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::DBEditDateClick(TObject *Sender)
{
if (Table->Exists)
        {
        TDBEdit* TheSender = (TDBEdit*)Sender;
        TDate tmpdate = CalendarFrm->MonthCalendar->Date;
        TryStrToDate(TheSender->EditText, tmpdate);
        CalendarFrm->MonthCalendar->Date = tmpdate;
        };
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::eWorldReSearch1Click(TObject *Sender)
{
 ShellExecute(Handle, "open", "http://www.ewgate.net/research/", NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TmainFrm::Button11Click(TObject *Sender)
{
if (Table->Exists)
        {
        ImageEditorFrm->Button3Click(Sender);
        Table->Edit();
        mainFrm->DBImage1->Picture->Graphic->Assign(ImageEditorFrm->Image->Picture->Graphic);
        Table->Post();
        if ((ImageEditorFrm->Image->Picture->Height > ImageH) || (ImageEditorFrm->Image->Picture->Width > ImageW))
                if (Application->MessageBoxA("L'immagine è più grande del necessario. Modificarla?", "Aprire Editor Immagini?", MB_YESNO) == IDYES)
                        ImageEditorFrm->ShowModal();
        }
else
        ShowMessage("E' necessario aprire o creare un nuovo database.");
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Aquisisci1Click(TObject *Sender)
{
 if (TwainExists())
  {
     HANDLE dib = TwainGetImage( Handle );

     if ( dib == 0 )
             return;

     LPBITMAPINFO bmi = (LPBITMAPINFO)::GlobalLock(dib);

     ImageEditorFrm->Image->AutoSize = true;
     ImageEditorFrm->Image->Stretch = false;
     ImageEditorFrm->Image->Picture->Bitmap->Height = bmi->bmiHeader.biHeight;
     ImageEditorFrm->Image->Picture->Bitmap->Width = bmi->bmiHeader.biWidth;
     SetDIBits( ImageEditorFrm->Image->Picture->Bitmap->Canvas->Handle, ImageEditorFrm->Image->Picture->Bitmap->Handle, 0,
                        (UINT) bmi->bmiHeader.biHeight,
			(Byte*)((Byte*)bmi + sizeof(BITMAPINFOHEADER)),
                        bmi, DIB_RGB_COLORS );

     ::GlobalUnlock( dib );
     ::GlobalFree( dib );

     ImageEditorFrm->HSizeEdit->Text = ImageEditorFrm->Image->Picture->Height;
     ImageEditorFrm->WSizeEdit->Text = ImageEditorFrm->Image->Picture->Width;
     ImageEditorFrm->Image->Height = ImageEditorFrm->Image->Picture->Height;
     ImageEditorFrm->Image->Width = ImageEditorFrm->Image->Picture->Width;
     ImageEditorFrm->Image->AutoSize = false;

  };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::FormClose(TObject *Sender, TCloseAction &Action)
{
 if ((OptionsFrm->CheckBox3->Checked)&&(Table->Exists))
        OptionsFrm->Edit1->Text = Table->TableName;

 if (OptionsFrm->CheckBox2->Checked)
        OptionsFrm->Button2Click(Sender);

 if (Table->Exists)
        Table->Close();

 FreeLibrary( TwainInst );
}
//---------------------------------------------------------------------------



void __fastcall TmainFrm::EsportaListaNomi1Click(TObject *Sender)
{
if ((Table->Exists)&&(Table->RecordCount))
 {
 SaveDialog->Title = "Esporta Lista Nomi Clienti..";
 SaveDialog->DefaultExt = "txt";
 SaveDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
 SaveDialog->Options.Clear();
 SaveDialog->Options << ofPathMustExist;

 if (SaveDialog->Execute())
        {
        TStringList *expfile;
        expfile = new TStringList;
        expfile->Clear();
        expfile->Add("#                   GyManager 1.01");
        expfile->Add("# ================================");
        expfile->Add("# Lista Nomi Clienti\t" + AnsiString(Date()));
        expfile->Add("");
        expfile->Add("");
        expfile->Add("Nome Cliente\t\tTelefono\tIndirizzo");

        Table->DisableControls();
        Table->First();
        while (!Table->Eof)
                {
                expfile->Add(Table->FieldByName("name")->AsString + "\t\t" + Table->FieldByName("phone")->AsString + "\t" + Table->FieldByName("address")->AsString);
                Table->Next();
                }
        Table->EnableControls();

        expfile->SaveToFile(SaveDialog->FileName);
        delete expfile;
        ShellExecute(NULL, "open", "notepad.exe", SaveDialog->FileName.c_str(), "", SW_SHOWDEFAULT);

        };
 };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::EsportaListaCompleta1Click(TObject *Sender)
{
if ((Table->Exists)&&(Table->RecordCount))
 {
 SaveDialog->Title = "Esporta Lista Nomi Clienti..";
 SaveDialog->DefaultExt = "txt";
 SaveDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
 SaveDialog->Options.Clear();
 SaveDialog->Options << ofPathMustExist;

 if (SaveDialog->Execute())
        {
        TStringList *expfile;
        expfile = new TStringList;
        expfile->Clear();
        expfile->Add("#                   GyManager 1.01");
        expfile->Add("# ================================");
        expfile->Add("# Lista Clienti    \t" + AnsiString(Date()));
        expfile->Add("");
        expfile->Add("");
        expfile->Add("# Nome Cliente\t\tScadenza\tIscrizione");
        expfile->Add("");

        Table->DisableControls();
        Table->First();
        while (!Table->Eof)
                {
                expfile->Add(Table->FieldByName("name")->AsString + "\t\t" + Table->FieldByName("expdate")->AsString + "\t" + Table->FieldByName("subdate")->AsString);
                Table->Next();
                }
        Table->EnableControls();

        expfile->SaveToFile(SaveDialog->FileName);
        delete expfile;
        ShellExecute(NULL, "open", "notepad.exe", SaveDialog->FileName.c_str(), "", SW_SHOWDEFAULT);
        };
 };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Nuovodatabase1Click(TObject *Sender)
{
 SaveDialog->Title = "Nuovo Database Clienti..";
 SaveDialog->DefaultExt = "DBF";
 SaveDialog->Filter = "DBase (*.dbf)|*.DBF";
 SaveDialog->Options.Clear();
 SaveDialog->Options << ofPathMustExist;

 if (SaveDialog->Execute())
        {
        Table->Close();
        Table->Exclusive = true;
        Table->DatabaseName = "";
        Table->TableName = SaveDialog->FileName;
        Table->TableType = ttDBase;
        Table->FieldDefs->Clear();
        Table->FieldDefs->Add("name", ftString, 32, true);
        Table->FieldDefs->Add("expdate", ftDate);
        Table->FieldDefs->Add("subdate", ftDate);
        Table->FieldDefs->Add("birthdate", ftDate);
        Table->FieldDefs->Add("notes", ftString, 128);
        Table->FieldDefs->Add("phone", ftString, 32);
        Table->FieldDefs->Add("address", ftString, 64);
        Table->FieldDefs->Add("image", ftGraphic);
        Table->FieldDefs->Add("cert", ftBoolean);

        Table->IndexDefs->Clear();
        Table->IndexDefs->Add("","name", TIndexOptions() <<ixPrimary << ixUnique);
        Table->IndexDefs->Add("expdate","expdate", TIndexOptions());
        Table->IndexDefs->Add("subdate","subdate", TIndexOptions());
        Table->IndexDefs->Add("birthdate","birthdate", TIndexOptions());

        Table->CreateTable();
        Table->Open();

        DBEdit1->DataField = Table->FieldList->Strings[0];
        DBEdit2->DataField = Table->FieldList->Strings[1];
        DBEdit3->DataField = Table->FieldList->Strings[2];
        DBEdit4->DataField = Table->FieldList->Strings[3];
        DBMemo1->DataField = Table->FieldList->Strings[4];
        DBEdit5->DataField = Table->FieldList->Strings[5];
        DBEdit6->DataField = Table->FieldList->Strings[6];
        DBImage1->DataField = Table->FieldList->Strings[7];
        DBCheckBox1->DataField = Table->FieldList->Strings[8];

        ColDimTable[0] = 200;
        ColDimTable[1] = 100;
        ColDimTable[2] = 100;
        ColDimTable[3] = 100;
        ColDimTable[4] = 100;
        ColDimTable[5] = 70;
        ColDimTable[6] = 70;
        ColDimTable[7] = 50;
        ColDimTable[8] = 20;

        Aggiorna1Click(Sender);
        Scadenza1Click(Sender); //ordinamento predefinito

        DBGrid->Columns->Items[0]->Title->Caption = "Nome Cliente";
        DBGrid->Columns->Items[1]->Title->Caption = "Data Scadenza";
        DBGrid->Columns->Items[2]->Title->Caption = "Data Iscrizione";
        DBGrid->Columns->Items[3]->Title->Caption = "Data di Nascita";
        DBGrid->Columns->Items[4]->Title->Caption = "Note";
        DBGrid->Columns->Items[5]->Title->Caption = "Telefono";
        DBGrid->Columns->Items[6]->Title->Caption = "Indirizzo";
        DBGrid->Columns->Items[7]->Title->Caption = "Immagine";
        DBGrid->Columns->Items[8]->Title->Caption = "Certificato";

        for (int i = 0; i <  9; i++)
                DBGrid->Columns->Items[i]->Width = ColDimTable[i];

        PageControl->ActivePageIndex = 1;
        };
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::EditorImmagini1Click(TObject *Sender)
{
ImageEditorFrm->Image->AutoSize = true;
ImageEditorFrm->Image->Stretch = false;
ImageEditorFrm->Image->Picture->Assign(DBImage1->Picture);
ImageEditorFrm->HSizeEdit->Text = ImageEditorFrm->Image->Picture->Height;
ImageEditorFrm->WSizeEdit->Text = ImageEditorFrm->Image->Picture->Width;
ImageEditorFrm->Image->AutoSize = false;
ImageEditorFrm->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::ImageSClick(TObject *Sender)
{
if (!ImageS->Picture->Graphic->Empty)
        {
        ImageFrm->Image->Picture->Assign(ImageS->Picture);
        ImageFrm->Width = ImageFrm->Image->Picture->Width;
        ImageFrm->Height = ImageFrm->Image->Picture->Height;
        FotoTessera1Click(Sender);
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button2Click(TObject *Sender)
{
Aquisisci1Click(Sender);
ImageEditorFrm->Button2Click(Sender);
if ((ImageEditorFrm->Image->Picture->Height > ImageH) || (ImageEditorFrm->Image->Picture->Width > ImageW))
        if (Application->MessageBoxA("L'immagine è più grande del necessario. Modificarla?", "Aprire Editor Immagini?", MB_YESNO) == IDYES)
                ImageEditorFrm->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button10Click(TObject *Sender)
{
if (Table->Exists)
        {
        Table->Edit();
        Table->Append();
        PageControl->ActivePageIndex = 2;
        DBEdit1->SetFocus();
        }
else
        ShowMessage("E' necessario aprire o creare un nuovo database.");

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button12Click(TObject *Sender)
{
if (Table->Exists)
        {
        Scadenza1Click(Sender);
        PageControl->ActivePageIndex = 1;
        }
else
        ShowMessage("E' necessario aprire o creare un nuovo database.");
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::ClientisenzaCertificato1Click(TObject *Sender)
{
if (Table->Exists)
        {
        AnsiString list;
        Table->First();
        while (!Table->Eof)
                {
                if (!DBCheckBox1->Checked)
                        {
                        list += "\t - " + Table->FieldByName("name")->AsString + "\n";
                        };
                Table->Next();
                }
        ShowMessage("I Seguenti Clienti non hanno ancora consegnato il certificato medico. \n\n" + list);
        }
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::cmb_dayscadKeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        {
        cmb_dayscad->Text = cmb_dayscad->Text.ToIntDef(10);
        Aggiorna1Click(Sender);
        }
}
//---------------------------------------------------------------------------

