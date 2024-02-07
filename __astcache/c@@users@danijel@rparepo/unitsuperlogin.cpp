//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitSuperLogin.h"
#include "UnitKontrola.h"
#include "UnitPocetna.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSuperLogin *FormSuperLogin;
//---------------------------------------------------------------------------
__fastcall TFormSuperLogin::TFormSuperLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormSuperLogin::BtLoginSuperCancelClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormSuperLogin::BtLoginSuperOkClick(TObject *Sender)
{
	String username = EditUsernameSuper->Text;
	String password = EditPasswordSuper->Text;

	TFDQuery *query = new TFDQuery(NULL);
	query->Connection = FormPocetna->FDConnection1;

query->SQL->Text = "SELECT * FROM users u1 WHERE u1.Username = :username AND u1.Password = :password AND u1.RoleIdent = 2";
	query->ParamByName("username")->AsString = username;
	query->ParamByName("password")->AsString = password;

    query->Open();
	if (!query->Eof) {
    	FormKontrola->ShowModal();
		Close();
		//ShowMessage("Login successful!");
	} else {
		Application->MessageBox(L"Invalid username or password or you don't have permission to access!", L"Login faild!", MB_ICONSTOP);
	}

	EditUsernameSuper->Text="";
	EditPasswordSuper->Text="";

    query->Close();
	delete query;
}
//---------------------------------------------------------------------------

