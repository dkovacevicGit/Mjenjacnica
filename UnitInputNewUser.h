//---------------------------------------------------------------------------

#ifndef UnitInputNewUserH
#define UnitInputNewUserH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.ControlList.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.ControlList.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.JumpList.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormInputNewUser : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit1Oib;
	TEdit *Edit2FirstName;
	TEdit *Edit3LastName;
	TEdit *Edit4Username;
	TEdit *Edit5Password;
	TEdit *Edit6ConfPassword;
	TEdit *Edit7RoleID;
	TEdit *Edit8OfficeID;
	TButton *ButtonNewUserSave;
	TButton *ButtonNewUserCancel;
	TLabel *Label9;
	TDateTimePicker *DateTimePicker1;
	TButton *ButtonOibProvjera;

	void __fastcall ButtonNewUserSaveClick(TObject *Sender);
	void __fastcall ButtonNewUserCancelClick(TObject *Sender);
	void __fastcall Edit1OibExit(TObject *Sender);
	void __fastcall Edit5PasswordExit(TObject *Sender);
	void __fastcall ButtonOibProvjeraClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormInputNewUser(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormInputNewUser *FormInputNewUser;
//---------------------------------------------------------------------------
#endif
