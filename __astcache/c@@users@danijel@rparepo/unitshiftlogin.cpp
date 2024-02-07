//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitShiftLogin.h"
#include "UnitPocetna.h"
#include "UnitTransakcije.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormShiftLogin *FormShiftLogin;
//---------------------------------------------------------------------------
__fastcall TFormShiftLogin::TFormShiftLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormShiftLogin::BtLoginShiftCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormShiftLogin::BtLoginShiftOkClick(TObject *Sender)
{
	String username = EditUsernameShift->Text;
	String password = EditPasswordShift->Text;

	TFDQuery *query = new TFDQuery(NULL);
	query->Connection = FormPocetna->FDConnection1;

	query->SQL->Text = "SELECT * FROM users u1 WHERE u1.Username = :username AND u1.Password = :password AND u1.RoleIdent = 3";
	query->ParamByName("username")->AsString = username;
	query->ParamByName("password")->AsString = password;

	query->Open();
	if (!query->Eof) {
		FormTransakcije->ShowModal();
		Close();
		//ShowMessage("Login successful!");
	} else {
		//ShowMessage("Login failed. Invalid username or password or you don't have permission");
		Application->MessageBox(L"Invalid username or password or you don't have permission to access!", L"Login faild!", MB_ICONSTOP);
	}

	EditUsernameShift->Text="";
	EditPasswordShift->Text="";

    query->Close();
	delete query;
}
//---------------------------------------------------------------------------

