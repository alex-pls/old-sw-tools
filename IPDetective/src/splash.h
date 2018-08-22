//---------------------------------------------------------------------------

#ifndef splashH
#define splashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TSplashFrm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TLabel *Label1;
        TLabel *AppVersion_Lbl;
        TPanel *Panel3;
        TLabel *Label3;
        TLabel *CompileTime_Lbl;
        TPanel *Panel4;
        TImage *Image1;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSplashFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSplashFrm *SplashFrm;
//---------------------------------------------------------------------------
#endif
