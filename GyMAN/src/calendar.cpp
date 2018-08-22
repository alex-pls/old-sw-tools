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

#include "calendar.h"
#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCalendarFrm *CalendarFrm;
//---------------------------------------------------------------------------
__fastcall TCalendarFrm::TCalendarFrm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCalendarFrm::MonthCalendarDblClick(TObject *Sender)
{
/*
 if (!mainFrm->DBEdit2->SelText.IsEmpty())
        mainFrm->DBEdit2->Text = DateToStr(MonthCalendar->Date);
 else if (!mainFrm->DBEdit3->SelText.IsEmpty())
        mainFrm->DBEdit3->Text = DateToStr(MonthCalendar->Date);
 else if (!mainFrm->DBEdit4->SelText.IsEmpty())
        mainFrm->DBEdit4->Text = DateToStr(MonthCalendar->Date);
*/
}
//---------------------------------------------------------------------------


