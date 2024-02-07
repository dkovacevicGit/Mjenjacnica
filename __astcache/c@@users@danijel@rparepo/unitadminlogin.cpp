//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAdminLogin.h"
#include "UnitPocetna.h"
#include "UnitPostavke.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAdminLogin *FormAdminLogin;
//---------------------------------------------------------------------------
__fastcall TFormAdminLogin::TFormAdminLogin(TComponent* Owner)
	: TForm(Owner)
	{
	}

//---------------------------------------------------------------------------
void __fastcall TFormAdminLogin::BtLoginAdminOkClick(TObject *Sender)
{
	String username = EditUsernameAdmin->Text;
	String password = EditPasswordAdmin->Text;

	TFDQuery *query = new TFDQuery(NULL);
	query->Connection = FormPocetna->FDConnection1;

	query->SQL->Text = "SELECT * FROM users u1 WHERE u1.Username = :username AND"
						" u1.Password = :password AND u1.RoleIdent = 1";

	query->ParamByName("username")->AsString = username;
	query->ParamByName("password")->AsString = password;

	query->Open();
	if (!query->Eof) {
		FormPostavke->ShowModal();
		Close();
		//ShowMessage("Login successful!");
	} else {
		Application->MessageBox(L"Invalid username or password or you don't have permission to access!", L"Login faild!", MB_ICONSTOP);
	}

	EditUsernameAdmin->Text="";
	EditPasswordAdmin->Text="";

    query->Close();
	delete query;

}
//---------------------------------------------------------------------------
void __fastcall TFormAdminLogin::BtLoginAdminCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------


