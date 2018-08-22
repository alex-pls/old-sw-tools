//---------------------------------------------------------------------------

#ifndef shortcutsH
#define shortcutsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TShortCutsFrm : public TForm
{
__published:	// IDE-managed Components
        TListView *ShortCutsListView;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TShortCutsFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TShortCutsFrm *ShortCutsFrm;
//---------------------------------------------------------------------------
#endif
