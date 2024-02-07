//---------------------------------------------------------------------------

#ifndef UnitSuperLoginH
#define UnitSuperLoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormSuperLogin : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TButton *BtLoginSuperOk;
	TButton *BtLoginSuperCancel;
	TEdit *EditPasswordSuper;
	TEdit *EditUsernameSuper;
	void __fastcall BtLoginSuperCancelClick(TObject *Sender);
	void __fastcall BtLoginSuperOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSuperLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSuperLogin *FormSuperLogin;
//---------------------------------------------------------------------------
#endif
