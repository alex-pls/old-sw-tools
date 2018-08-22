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
#include <jpeg.hpp>

#pragma hdrstop

#include "imageed.h"
#include "main.h"

#include "twaini.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TImageEditorFrm *ImageEditorFrm;
//---------------------------------------------------------------------------
__fastcall TImageEditorFrm::TImageEditorFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Button2Click(TObject *Sender)
{
if ((!Image->Picture->Graphic->Empty)&&(mainFrm->Table->Exists))
        {
        mainFrm->Table->Edit();
// DA CONTROLLARE
        mainFrm->DBImage1->Picture->Graphic->Assign(Image->Picture->Graphic);
        mainFrm->Table->Post();
        };
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Button3Click(TObject *Sender)
{
mainFrm->OpenPictureDialog->Title = "Carica FotoTessera..";
mainFrm->OpenPictureDialog->DefaultExt = "JPG";
mainFrm->OpenPictureDialog->Filter = "JPEG Images (*.jpg)|*.jpg| Bitmap Images (*.bmp)|*.BMP";
mainFrm->OpenPictureDialog->Options.Clear();
mainFrm->OpenPictureDialog->Options << ofFileMustExist << ofHideReadOnly;
if (mainFrm->OpenPictureDialog->Execute())
        {
        Image->AutoSize = true;
        Image->Stretch = false;
        if (mainFrm->OpenPictureDialog->FileName.SubString(mainFrm->OpenPictureDialog->FileName.Length()-2, 3).LowerCase() == "jpg")
                {
                ImageEditorFrm->Image->Picture->LoadFromFile(mainFrm->OpenPictureDialog->FileName);
                Graphics::TBitmap *bmp = new Graphics::TBitmap();
                bmp->Width = Image->Picture->Width;
                bmp->Height = Image->Picture->Height;
                bmp->Canvas->StretchDraw(bmp->Canvas->ClipRect, Image->Picture->Graphic);
                Image->Picture->Bitmap->Assign(bmp);
                delete bmp;
                }
        else
                {

                Image->Picture->LoadFromFile(mainFrm->OpenPictureDialog->FileName);
                };
        HSizeEdit->Text = Image->Picture->Height;
        WSizeEdit->Text = Image->Picture->Width;
        Image->AutoSize = false;
        };
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Button1Click(TObject *Sender)
{
mainFrm->Aquisisci1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Button4Click(TObject *Sender)
{
mainFrm->SavePictureDialog->Title = "Salva Immagine con nome..";
mainFrm->SavePictureDialog->DefaultExt = "JPG";
mainFrm->SavePictureDialog->Filter = "JPEG Images (*.jpg)|*.jpg| Bitmap Images (*.bmp)|*.BMP";
mainFrm->SavePictureDialog->Options.Clear();
if (mainFrm->SavePictureDialog->Execute())
        {
        if (mainFrm->SavePictureDialog->FileName.SubString(mainFrm->SavePictureDialog->FileName.Length()-2, 3).LowerCase() == "jpg")
                {
                TJPEGImage *jp = new TJPEGImage();
                try
                        {
                        jp->Assign(Image->Picture->Bitmap);
                        jp->SaveToFile(mainFrm->SavePictureDialog->FileName);
                        }
                __finally
                        {
                        delete jp;
                        };
                }
        else
                Image->Picture->Bitmap->SaveToFile(mainFrm->SavePictureDialog->FileName);
        };
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Button5Click(TObject *Sender)
{
Graphics::TBitmap *bmp = new Graphics::TBitmap();
bmp->Width = WSizeEdit->Text.ToIntDef(Image->Picture->Width);
bmp->Height = HSizeEdit->Text.ToIntDef(Image->Picture->Height);
bmp->Canvas->StretchDraw(bmp->Canvas->ClipRect, Image->Picture->Graphic);
Image->Picture->Bitmap->Assign(bmp);
delete bmp;
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Panel3Click(TObject *Sender)
{
if (Panel3->BevelOuter == bvRaised)
        Panel3->BevelOuter = bvLowered;
else
        Panel3->BevelOuter = bvRaised;

}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Panel1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
if ((SelectorBox->ItemIndex == 1)&&(Panel3->BevelOuter == bvLowered))
        {
        HSizeEdit1->Text = AnsiString(Y);
        WSizeEdit1->Text = AnsiString(X);
        }
else if ((SelectorBox->ItemIndex == 0)&&(Panel4->BevelOuter == bvLowered))
        {
        HSizeEdit->Text = AnsiString(Y);
        WSizeEdit->Text = AnsiString(X);
        };

}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::SelectorBoxChange(TObject *Sender)
{
EditBox1->Visible = false;
EditBox2->Visible = false;

switch (SelectorBox->ItemIndex)
        {
        case 0:
                EditBox1->Visible = true;
                break;
        case 1:
                EditBox2->Visible = true;
                break;
        };


}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Panel4Click(TObject *Sender)
{
if (Panel4->BevelOuter == bvRaised)
        Panel4->BevelOuter = bvLowered;
else
        Panel4->BevelOuter = bvRaised;

}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Button6Click(TObject *Sender)
{
Image->Stretch = false;
Image->Picture->Graphic->Height = HSizeEdit1->Text.ToIntDef(Image->Picture->Height);
Image->Picture->Graphic->Width =  WSizeEdit1->Text.ToIntDef(Image->Picture->Width);
Image->Height = Image->Picture->Graphic->Height;
Image->Width = Image->Picture->Graphic->Width;
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Panel1Click(TObject *Sender)
{
Panel3->BevelOuter = bvRaised;
Panel4->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::Button7Click(TObject *Sender)
{
 double ratio, defratio;
 ratio = (double)Image->Picture->Height / (double)Image->Picture->Width;
 defratio = (double)mainFrm->ImageH / (double)mainFrm->ImageW;
 CheckBox1->Checked = false;
 if (ratio < defratio)// => width is max
        {
        WSizeEdit->Text = mainFrm->ImageW;
        ratio = (double)Image->Picture->Width / (double)Image->Picture->Height; // for rounding
        HSizeEdit->Text = AnsiString((int)((double)mainFrm->ImageW / ratio));
        }
 else
        {
        HSizeEdit->Text = mainFrm->ImageH;
        WSizeEdit->Text = AnsiString((int)((double)mainFrm->ImageH / ratio));
        };
Button5Click(Sender);
}
//---------------------------------------------------------------------------



void __fastcall TImageEditorFrm::WSizeEditKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if ((CheckBox1->Checked)&&(WSizeEdit->Text.ToIntDef(0)))
        {
        double ratio;
        ratio = (double)Image->Picture->Width / (double)Image->Picture->Height;
        HSizeEdit->Text = AnsiString((int)(WSizeEdit->Text.ToDouble() / ratio));
        };
        
}
//---------------------------------------------------------------------------

void __fastcall TImageEditorFrm::HSizeEditKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if ((CheckBox1->Checked)&&(HSizeEdit->Text.ToIntDef(0)))
        {
        double ratio;
        ratio = (double)Image->Picture->Height / (double)Image->Picture->Width;
        WSizeEdit->Text = AnsiString((int)(HSizeEdit->Text.ToDouble() / ratio));
        };
        
}
//---------------------------------------------------------------------------


