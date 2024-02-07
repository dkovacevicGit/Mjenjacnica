//---------------------------------------------------------------------------

#ifndef UnitAdminLoginH
#define UnitAdminLoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
//---------------------------------------------------------------------------
class TFormAdminLogin : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelUsername;
	TLabel *LabelPassword;
	TEdit *EditUsernameAdmin;
	TEdit *EditPasswordAdmin;
	TButton *BtLoginAdminOk;
	TButton *BtLoginAdminCancel;
	void __fastcall BtLoginAdminCancelClick(TObject *Sender);
	void __fastcall BtLoginAdminOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAdminLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAdminLogin *FormAdminLogin;
//---------------------------------------------------------------------------
#endif
