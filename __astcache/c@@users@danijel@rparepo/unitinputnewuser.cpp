//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <string>
#pragma hdrstop

#include "UnitInputNewUser.h"
#include "UnitPostavke.h"
#include "UnitPocetna.h"
#include <System.SysUtils.hpp>
#include <System.Character.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormInputNewUser *FormInputNewUser;

double Sum (double a, double b);

//---------------------------------------------------------------------------
_fastcall TFormInputNewUser::TFormInputNewUser(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormInputNewUser::ButtonNewUserSaveClick(TObject *Sender)
{
	String oib = Edit1Oib->Text;
	String firstName = Edit2FirstName->Text;
	String lastName = Edit3LastName->Text;
	String username = Edit4Username->Text;
	String password = Edit5Password->Text;
	String password2 = Edit6ConfPassword->Text;
	String roleID = Edit7RoleID->Text;
	String officeID = Edit8OfficeID->Text;
	String employDate = DateToStr(DateTimePicker1->Date);

	// Provjera password i confirm password

	if(password!=password2){
		ShowMessage("Password and confirmed password are not equal!");
		}

	else{

		// Otvaranje konekcije

		TFDQuery *query = new TFDQuery(NULL);
		query->Connection = FormPocetna->FDConnection1;

		query->SQL->Text = 	"INSERT INTO users (OIB, FirstName, LastName, Username, Password, EmployDate, RoleIdent, PosID) "
							"VALUES (:oib, :firstName, :lastName, :username, :password, :employDate, :roleID, :officeID)";

		// Parametri
		query->ParamByName("oib")->AsString = oib;
		query->ParamByName("firstName")->AsString = firstName;
		query->ParamByName("lastName")->AsString = lastName;
		query->ParamByName("username")->AsString = username;
		query->ParamByName("password")->AsString = password;
		query->ParamByName("employDate")->AsString = employDate;
		query->ParamByName("roleID")->AsInteger = StrToInt(roleID);
		query->ParamByName("officeID")->AsInteger = StrToInt(officeID);

		// Izvršimo upit
		query->ExecSQL();
		FormPostavke->FDTable1users->Refresh();
		query->Close();
		delete query;

		// Brisanje polja
		Edit1Oib->Text = "";
		Edit2FirstName->Text = "";
		Edit3LastName->Text = "";
		Edit4Username->Text = "";
		Edit5Password->Text = "";
		Edit6ConfPassword->Text = "";
		Edit7RoleID->Text = "";
		Edit8OfficeID->Text = "";

		ShowMessage("New user created!");

		Close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormInputNewUser::ButtonNewUserCancelClick(TObject *Sender)
{
	Edit1Oib->Text = "";
	Edit2FirstName->Text = "";
	Edit3LastName->Text = "";
	Edit4Username->Text = "";
	Edit5Password->Text = "";
	Edit6ConfPassword->Text = "";
	Edit7RoleID->Text = "";
	Edit8OfficeID->Text = "";

	Close();
}

//---------------------------------------------------------------------------

void __fastcall TFormInputNewUser::Edit1OibExit(TObject *Sender)
{
	String oib = Edit1Oib->Text;

	if (oib.Length() != 11) { ShowMessage("OIB must contain 11 characters and only numbers!"); }

}
//---------------------------------------------------------------------------

/*int strongPassword(const AnsiString& password) {

	if (password.Length() < 8) {
		ShowMessage("Too short password!");
	}

	int imaVelikoSlovo = 0;
	int imaMaloSlovo = 0;
	int imaBroj = 0;
	int imaSpecZnak = 0;
	int passOK = 1;

	for (int i = 1; i <= password.Length(); i++) {
        char c = password[i];

		if (IsUpper(c)) {
			imaVelikoSlovo++;
		} else if (IsLower(c)) {
			imaMaloSlovo++;
		} else if (IsDigit(c)) {
			imaBroj++;
		} else {
			String specialChars = "!@#$%^&*()_-+=<>?";

			if (specialChars.Pos(c) != 0) {
				imaSpecZnak++;
            }
        }
	}

	if(imaVelikoSlovo == 0 && imaMaloSlovo == 0 && imaBroj == 0 && imaSpecZnak == 0){

		passOK =1;
	}

	return passOK;
}  */

void __fastcall TFormInputNewUser::Edit5PasswordExit(TObject *Sender)
{
	String password = Edit5Password->Text;
	if (password.Length() < 8) {
			ShowMessage("Password must contain minimum 8 characters");
		}

	/*AnsiString password = Edit5Password->Text;
	if (strongPassword(passOK)==1) {
		// Lozinka je jaka
		ShowMessage("Lozinka je jaka.");
	} else {
		// Lozinka nije jaka
		ShowMessage("Lozinka nije jaka.");
	} */

}
//---------------------------------------------------------------------------

void __fastcall TFormInputNewUser::ButtonOibProvjeraClick(TObject *Sender)
{
	String oib = Edit1Oib->Text;

	int numArray[11]; // Deklaracija niza integera

	for (int i = 0; i < 10; i++) {
		numArray[i] = StrToInt(oib[i]); // Pretvorba karaktera u integer
    }

	ShowMessage(numArray[0] + 100);
}

//---------------------------------------------------------------------------
