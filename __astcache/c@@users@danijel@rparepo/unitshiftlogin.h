//---------------------------------------------------------------------------

#ifndef UnitShiftLoginH
#define UnitShiftLoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormShiftLogin : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditUsernameShift;
	TEdit *EditPasswordShift;
	TButton *BtLoginShiftOk;
	TButton *BtLoginShiftCancel;
	void __fastcall BtLoginShiftCancelClick(TObject *Sender);
	void __fastcall BtLoginShiftOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormShiftLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormShiftLogin *FormShiftLogin;
//---------------------------------------------------------------------------
#endif
