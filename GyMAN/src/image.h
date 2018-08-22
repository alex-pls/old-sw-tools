//---------------------------------------------------------------------------

#ifndef imageH
#define imageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TImageFrm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image;
        void __fastcall ImageClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TImageFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TImageFrm *ImageFrm;
//---------------------------------------------------------------------------
#endif
