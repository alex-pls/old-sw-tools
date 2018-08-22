/*
........eWorld ReSearch 2004
........Alessandro Polo
........http://www.ewgate.net
........=====================
........This software is freeware. Source code is Open Source.
........Keep Author's Credits if you use any part of this software.
........=====================
........Project State: Completed
........Project Date:  27/2/2004
*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "data.h"
#include "main.h"
#include "about.h"

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
void __fastcall TmainFrm::Exit1Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TmainFrm::MacBoxKeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        if (MyData->GetMac(MacBox2->Text))
                Button8Click(Sender);

}
//---------------------------------------------------------------------------
void __fastcall TmainFrm::MatBoxKeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        {
        //ricerca catalogo
        if (MyData->GetMac(MacBox2->Text))
                {
                CatBox->Text = MyData->GetMac(MacBox2->Text)->SearchMat(MatBox->Text.ToDouble());
                }

        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::FormShow(TObject *Sender)
{

MyData = new AllData();
datafile = "data.txt";
InfoText2->Caption = "Database vuoto. Nessun file caricato.";
if (FileExists(ExtractFilePath(Application->ExeName) + datafile))
        {
        MyData->LoadFromFile(datafile);
        Button5Click(Sender);
        };

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::OpenDataFile1Click(TObject *Sender)
{
OpenDialog->Title = "Open DataFile..";
OpenDialog->DefaultExt = "TXT";
OpenDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
OpenDialog->Options.Clear();
OpenDialog->Options << ofFileMustExist << ofPathMustExist;
if (OpenDialog->Execute())
        {
        datafile = OpenDialog->FileName;
        MyData->LoadFromFile(datafile);
        Button5Click(Sender);
        }
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ViewDataFile1Click(TObject *Sender)
{
ShellExecute(NULL, "open", "notepad.exe", datafile.c_str(), "", SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::SaveData1Click(TObject *Sender)
{
 mainFrm->SaveDialog->Title = "Save Data File..";
 mainFrm->SaveDialog->DefaultExt = "txt";
 mainFrm->SaveDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
 mainFrm->SaveDialog->Options.Clear();
 mainFrm->SaveDialog->Options << ofPathMustExist;

 if (mainFrm->SaveDialog->Execute())
        {
        datafile = mainFrm->SaveDialog->FileName;
        if (MyData->SaveToFile(datafile))
                ShowMessage("All done. Data Saved.");
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button1Click(TObject *Sender)
{
//MyData->ListMac(MacBox->Items->Strings);
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::Button6Click(TObject *Sender)
{

if (!EditMac->Text.IsEmpty())
        {
        MyData->AddMac(EditMac->Text);
        Button5Click(Sender);
        EditMac->Text = "";
        };

}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::Button5Click(TObject *Sender)
{
MacInfo->Caption = "";
if (!MyData->GetMacNumber())
        {
        StaticMacN->Caption = "Nessuna Macc.";
        ListMacs->Items->Clear();
        ShowMessage("Nessuna macchina presente del database.");
        MacBox->Text = "";
        MacBox->Items->Clear();
        MacBox2->Text = "";
        MacBox2->Items->Clear();
        MatBox->Text = "";
        CatBox->Text = "";
        CatBox->Items->Clear();
        InfoText1->Caption = "Database vuoto, nessuna macchina presente.";
        InfoText2->Caption = "Caricare un file di dati. [File->Open]";
        return;
        };
StaticMacN->Caption = AnsiString(MyData->GetMacNumber()) + " macchine";
MyData->ListMac(ListMacs->Items);
MyData->ListMac(MacBox->Items);
MyData->ListMac(MacBox2->Items);
InfoText1->Caption = AnsiString(MyData->GetMacNumber()) + " Macchine presenti, per un totale di " + AnsiString(MyData->GetTotCatNumber()) + " cataloghi.";
InfoText2->Caption = "Database operativo, File dati: " + datafile;
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button3Click(TObject *Sender)
{
if ((ListMacs->ItemIndex != -1)&&(Application->MessageBoxA("Rimuovere la macchina selezionata?", "Comferma Rimozione..", MB_YESNO) == IDOK ) )
        {
        MyData->RemMac(ListMacs->Items->Strings[ListMacs->ItemIndex]);
        Button5Click(Sender);
        InfoText2->Caption = "Database Modificato. Salvare prima di uscire.";
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button4Click(TObject *Sender)
{
 SaveDialog->Title = "Esporta Lista Macchine..";
 SaveDialog->DefaultExt = "txt";
 SaveDialog->Filter = "Text files (*.txt)|*.TXT|All files (*.*)|*.*";
 SaveDialog->Options.Clear();
 SaveDialog->Options << ofPathMustExist;

 if (mainFrm->SaveDialog->Execute())
        {
        if (MyData->ExportMacs(SaveDialog->FileName))
                ShowMessage("All done. Data Saved.");
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button7Click(TObject *Sender)
{
if ((ListCats->ItemIndex != -1)&&(MyData->GetMac(MacBox2->Text)))
        {
        if (Application->MessageBoxA("Rumuovere?", "Comferma Rimozione..", MB_YESNO) == IDOK )
                {
                MyData->GetMac(MacBox2->Text)->RemCat(ListCats->Items->Strings[ListCats->ItemIndex]);
                Button8Click(Sender);
                };
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button9Click(TObject *Sender)
{
if ((ListCats->ItemIndex != -1)&&(!EditCat1->Text.IsEmpty())&&(!EditCat2->Text.IsEmpty()))
        {
        MyData->GetMac(MacBox2->Text)->GetCat(ListCats->Items->Strings[ListCats->ItemIndex])->SetRange(EditCat1->Text.ToDouble(), EditCat2->Text.ToDouble() );
        Button8Click(Sender);
        InfoText2->Caption = "Database Modificato. Salvare prima di uscire.";
        };
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::Button8Click(TObject *Sender)
{
if (Sender == MacBox)
        MacBox2->Text = MacBox->Text;
else
        MacBox->Text = MacBox2->Text;

if (MyData->GetMac(MacBox2->Text))
        {
        MyData->GetMac(MacBox2->Text)->ListCat(ListCats->Items);
        MyData->GetMac(MacBox2->Text)->ListCat(CatBox->Items);
        InfoText2->Caption = "Database Modificato. Salvare prima di uscire.";

        }
else
        {
        ListCats->Items->Clear();
        CatBox->Text = "";
        CatBox->Items->Clear();
        };
EditCat1->Text = "";
EditCat2->Text = "";
EditAddCat->Text = "";
EditAddCat1->Text = "";
EditAddCat2->Text = "";
MatBox->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Button10Click(TObject *Sender)
{
if (MyData->GetMac(MacBox2->Text))
        {
        double tmp;
        if (EditAddCat2->Text.IsEmpty())
                tmp = 0;
        else
                tmp = EditAddCat2->Text.ToDouble();

        MyData->GetMac(MacBox2->Text)->AddCat(EditAddCat->Text, EditAddCat1->Text.ToDouble(), tmp);
        Button8Click(Sender);
        ListCats->ItemIndex = ListCats->Items->Count-1;
        ListCatsClick(Sender); 
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ListCatsClick(TObject *Sender)
{
if (MyData->GetMac(MacBox2->Text))
        {
        EditCat1->Text = MyData->GetMac(MacBox2->Text)->GetCat(ListCats->Items->Strings[ListCats->ItemIndex])->GetStart();
        EditCat2->Text = MyData->GetMac(MacBox2->Text)->GetCat(ListCats->Items->Strings[ListCats->ItemIndex])->GetEnd();
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::A1Click(TObject *Sender)
{
AboutBox->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TmainFrm::CatBoxChange(TObject *Sender)
{
if (MyData->GetMac(MacBox->Text))
        {
        if (MyData->GetMac(MacBox->Text)->GetCat(CatBox->Text)->GetEnd() == 0)
                MatBox->Text = "dalla " + AnsiString(MyData->GetMac(MacBox->Text)->GetCat(CatBox->Text)->GetStart()) +  " in poi (current p.)";
        else
                MatBox->Text = "dalla " + AnsiString(MyData->GetMac(MacBox->Text)->GetCat(CatBox->Text)->GetStart()) +  " alla " + AnsiString(MyData->GetMac(MacBox->Text)->GetCat(CatBox->Text)->GetEnd());
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::ListMacsClick(TObject *Sender)
{
if (ListMacs->ItemIndex != -1)
        {
        if (MyData->GetMac(ListMacs->Items->Strings[ListMacs->ItemIndex]))
               MacInfo->Caption = ListMacs->Items->Strings[ListMacs->ItemIndex] + " comprende " + AnsiString(MyData->GetMac(ListMacs->Items->Strings[ListMacs->ItemIndex])->GetNumCat()) + " cataloghi.";
        MacBox->Text = ListMacs->Items->Strings[ListMacs->ItemIndex];
        MacBox2->Text = ListMacs->Items->Strings[ListMacs->ItemIndex];
        Button8Click(Sender);
        };

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::RicaricaDati1Click(TObject *Sender)
{
        MyData->LoadFromFile(datafile);
        Button5Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::Save1Click(TObject *Sender)
{
        MyData->SaveToFile(datafile);
        Button5Click(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::FormClose(TObject *Sender, TCloseAction &Action)
{
if (InfoText2->Caption == "Database Modificato. Salvare prima di uscire.")
        {
        if (Application->MessageBoxA("Il Database è stato modificato, è necessario salvare per non perdere le modifiche. Salvare i dati?", "Salva Database..", MB_YESNO) == IDOK )
                MyData->SaveToFile(datafile);
        };
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::MatBoxClick(TObject *Sender)
{
if (MatBox->Text.SubString(1, 5) == "dalla")
        MatBox->Text = "";
        
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::EditMacKeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        {
        Button6Click(Sender);
        EditMac->Text = "";
        }
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::EditCatKeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        Button9Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TmainFrm::EditAddCat2KeyPress(TObject *Sender, char &Key)
{
if (Key == VK_RETURN)
        Button10Click(Sender);
}
//---------------------------------------------------------------------------


