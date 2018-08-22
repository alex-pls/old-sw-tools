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
#pragma hdrstop

#include "options.h"
#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOptionsFrm *OptionsFrm;
//---------------------------------------------------------------------------
__fastcall TOptionsFrm::TOptionsFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOptionsFrm::Panel2Click(TObject *Sender)
{
mainFrm->ColorDialog->Color = Panel2->Color;
if (mainFrm->ColorDialog->Execute())
  Panel2->Color = mainFrm->ColorDialog->Color;
}
//---------------------------------------------------------------------------
void __fastcall TOptionsFrm::Panel3Click(TObject *Sender)
{
mainFrm->FontDialog->Font = Panel3->Font;
if (mainFrm->FontDialog->Execute())
        Panel3->Font = mainFrm->FontDialog->Font;
}
//---------------------------------------------------------------------------
void __fastcall TOptionsFrm::Button2Click(TObject *Sender)
{
 mainFrm->DBGrid->Color = Panel2->Color;
 mainFrm->DBGrid->Font =  Panel3->Font;

 HKEY	hkey;
 LONG lnRes;
 lnRes = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\eWorld\\GyMan\\", 0L,KEY_ALL_ACCESS, &hkey);

 if(ERROR_SUCCESS == lnRes )
        {
         int value = 1;
         long MyColor;
         DWORD dwType, dwSize;
         DWORD dwTypeS, dwSizeS;
         dwType = REG_DWORD;
         dwSize = sizeof(REG_DWORD);
         dwTypeS = REG_SZ;

         RegSetValueEx(hkey, TEXT("TableFileName"), 0, dwTypeS, (unsigned char*)Edit1->Text.c_str(), Edit1->Text.Length());

         MyColor = (long)Panel2->Color;
         RegSetValueEx(hkey, TEXT("TableColor"), 0, dwType, (unsigned char*)(&MyColor), dwSize);

         MyColor = (long)Panel3->Font->Color;
         RegSetValueEx(hkey, TEXT("TableFontColor"), 0, dwType, (unsigned char*)(&MyColor), dwSize);

         value = (int)CheckBox1->Checked;
         RegSetValueEx(hkey, TEXT("LoadDatabase"), 0, dwType, (unsigned char*)(&value), dwSize);

         value = (int)CheckBox3->Checked;
         RegSetValueEx(hkey, TEXT("SaveLastUsed"), 0, dwType, (unsigned char*)(&value), dwSize);

         value = (int)CheckBox2->Checked;
         RegSetValueEx(hkey, TEXT("SaveOptions"), 0, dwType, (unsigned char*)(&value), dwSize);

         value = (int)CheckBox5->Checked;
         RegSetValueEx(hkey, TEXT("SaveColDim"), 0, dwType, (unsigned char*)(&value), dwSize);

        if (CheckBox5->Checked)
                {
                value = mainFrm->ExpiredList->ColWidths[0];
                RegSetValueEx(hkey, TEXT("ColDimExpList1"), 0, dwType, (unsigned char*)(&value), dwSize);
                value = mainFrm->ExpiringList->ColWidths[0];
                RegSetValueEx(hkey, TEXT("ColDimExpList2"), 0, dwType, (unsigned char*)(&value), dwSize);

                for (int i = 0; i <  9; i++)
                        {
                        if (i < mainFrm->DBGrid->Columns->Count)
                                {
                                mainFrm->ColDimTable[i] = mainFrm->DBGrid->Columns->Items[i]->Width;
                                RegSetValueEx(hkey, TEXT(AnsiString("ColDimTable" + AnsiString(i)).c_str()), 0, dwType, (unsigned char*)(&(mainFrm->ColDimTable[i])), dwSize);
                                };
                        };

                };

         RegCloseKey(hkey);
        }
 else
        ShowMessage("I/O Error saving data in the Registry!");

}
//---------------------------------------------------------------------------


void __fastcall TOptionsFrm::Button1Click(TObject *Sender)
{
 HKEY	hkey;
 LONG lnRes;
 lnRes = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "Software\\eWorld\\GyMan\\", 0L,KEY_ALL_ACCESS, &hkey);

 if(ERROR_SUCCESS == lnRes )
        {
         int result = 0;
         long MyColor;
         DWORD dwType, dwSize;
         dwType = REG_DWORD;
         dwSize = sizeof(DWORD);
         AnsiString tmp;

        result = 1;
        RegQueryValueEx(hkey, TEXT("SaveColDim"), NULL, &dwType, (PBYTE)&result, &dwSize);
        CheckBox5->Checked = (int)result;

        if (CheckBox5->Checked)
                {
                result = mainFrm->ExpiredList->ColWidths[0];
                RegQueryValueEx(hkey, TEXT("ColDimExpList1"), NULL, &dwType, (PBYTE)&result, &dwSize);
                mainFrm->ExpiredList->ColWidths[0] =  result;

                result = mainFrm->ExpiringList->ColWidths[0];
                RegQueryValueEx(hkey, TEXT("ColDimExpList2"), NULL, &dwType, (PBYTE)&result, &dwSize);
                mainFrm->ExpiringList->ColWidths[0] = result;

                for (int i = 0; i <  9; i++)
                        {
                        tmp = AnsiString("ColDimTable" + AnsiString(i));
                        result = (int)mainFrm->ColDimTable[i];
                        if (RegQueryValueEx(hkey, TEXT(tmp.c_str()), NULL, &dwType, (PBYTE)&result, &dwSize) == ERROR_SUCCESS )
                                mainFrm->ColDimTable[i] = result;
                        };

                };

        result = 1;
        RegQueryValueEx(hkey, TEXT("LoadDatabase"), NULL, &dwType, (PBYTE)&result, &dwSize);
        CheckBox1->Checked = (int)result;

        result = 1;
        RegQueryValueEx(hkey, TEXT("SaveLastUsed"), NULL, &dwType, (PBYTE)&result, &dwSize);
        CheckBox3->Checked = (int)result;

        result = 1;
        RegQueryValueEx(hkey, TEXT("SaveOptions"), NULL, &dwType, (PBYTE)&result, &dwSize);
        CheckBox2->Checked = (int)result;

        char buffer[128]="";
        DWORD DataCount=sizeof(buffer);
        DWORD DataType;
        buffer[0]='\0';
        if (RegQueryValueEx( hkey, "TableFileName", 0, &DataType, (unsigned char*)buffer, &DataCount ) == ERROR_SUCCESS )
                {
                Edit1->Text = AnsiString(buffer);
                mainFrm->defdatafile = AnsiString(buffer);
                };

        buffer[0]='\0';
        if (RegQueryValueEx( hkey, "TableFontName", 0, &DataType, (unsigned char*)buffer, &DataCount ) == ERROR_SUCCESS )
                Panel3->Font->Name = AnsiString(buffer);

        result = Panel3->Font->Size;
        RegQueryValueEx(hkey, TEXT("TableFontSize"), NULL, &dwType, (PBYTE)&result, &dwSize);
        Panel3->Font->Size = (int)result;

        MyColor = (long)Panel2->Color;
        RegQueryValueEx(hkey, TEXT("TableColor"), NULL, &dwType, (PBYTE)&MyColor, &dwSize);
        Panel2->Color = (long)MyColor;

        MyColor = (long)Panel2->Font->Color;
        RegQueryValueEx(hkey, TEXT("TableFontColor"), NULL, &dwType, (PBYTE)&MyColor, &dwSize);
        Panel3->Font->Color = (long)MyColor;

        mainFrm->DBGrid->Color = Panel2->Color;
        mainFrm->DBGrid->Font = Panel3->Font;

        RegCloseKey(hkey);
        }
 else
        {
        //Probably first execution on this System, Registry is empty
        //save current options
        DWORD	dwDisposition;
        lnRes = RegCreateKeyEx(HKEY_LOCAL_MACHINE, "Software\\eWorld\\GyMan\\", 0, NULL, 0, 0, NULL, &hkey, &dwDisposition);
         if( ERROR_SUCCESS != lnRes )
                ShowMessage("I/O Error creating Key in the Registry!");
         else
                {
                RegCloseKey(hkey);
                Button3Click(Sender);
                Button2Click(Sender);
                };
        };

}
//---------------------------------------------------------------------------

void __fastcall TOptionsFrm::Button3Click(TObject *Sender)
{
CheckBox1->Checked = true;
CheckBox2->Checked = true;
CheckBox3->Checked = true;
CheckBox5->Checked = true;
Edit1->Text = "Esempio.dbf";
Panel2->Color = clMoneyGreen;
Panel3->Color = clCream;
Panel3->Font->Color = clWindowText;
Panel3->Font->Size = 8;
Panel3->Font->Name = "MS Sans Serif";
Panel3->Font->Style.Clear();
mainFrm->ExpiredList->ColWidths[0] = 215;
mainFrm->ExpiringList->ColWidths[0] = 215;
mainFrm->ColDimTable[0] = 200;
mainFrm->ColDimTable[1] = 100;
mainFrm->ColDimTable[2] = 100;
mainFrm->ColDimTable[3] = 70;
mainFrm->ColDimTable[4] = 100;
mainFrm->ColDimTable[5] = 50;
mainFrm->ColDimTable[6] = 70;
mainFrm->ColDimTable[7] = 50;
mainFrm->ColDimTable[8] = 50;

Button2Click(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TOptionsFrm::Image1Click(TObject *Sender)
{
mainFrm->OpenDialog->Title = "Carica Database predefinito..";
mainFrm->OpenDialog->DefaultExt = "DBF";
mainFrm->OpenDialog->Filter = "DBase (*.dbf)|*.DBF| Paradox (*.db)|*.DB";
mainFrm->OpenDialog->Options.Clear();
mainFrm->OpenDialog->Options << ofFileMustExist << ofPathMustExist;
if (mainFrm->OpenDialog->Execute())
        {
        Edit1->Text = mainFrm->OpenDialog->FileName;
        CheckBox3->Checked = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TOptionsFrm::Panel2DblClick(TObject *Sender)
{
Panel2->Color = clMoneyGreen;
}
//---------------------------------------------------------------------------

void __fastcall TOptionsFrm::Panel3DblClick(TObject *Sender)
{
Panel3->Color = clCream;
Panel3->Font->Name = "MS Sans Serif";
Panel3->Font->Size = 8;
Panel3->Font->Color = clWindowText;
}
//---------------------------------------------------------------------------

void __fastcall TOptionsFrm::FormShow(TObject *Sender)
{
Panel2->Color = mainFrm->DBGrid->Color;
Panel3->Font = mainFrm->DBGrid->Font;

}
//---------------------------------------------------------------------------

