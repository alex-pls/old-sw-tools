//---------------------------------------------------------------------------

#ifndef calendarH
#define calendarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TCalendarFrm : public TForm
{
__published:	// IDE-managed Components
        TMonthCalendar *MonthCalendar;
        void __fastcall MonthCalendarDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCalendarFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCalendarFrm *CalendarFrm;
//---------------------------------------------------------------------------
#endif
