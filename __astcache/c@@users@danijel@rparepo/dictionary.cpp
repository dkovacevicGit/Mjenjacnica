//---------------------------------------------------------------------------

#pragma hdrstop

#include "Dictionary.h"
#include "UnitPocetna.h"
#include "UnitLangSelect.h"
#include "UnitAdminLogin.h"
#include "UnitInputNewUser.h"
#include "UnitKontrola.h"
#include "UnitPostavke.h"
#include "UnitShiftLogin.h"
#include "UnitSuperLogin.h"
#include "UnitTecajnaLista.h"
#include "UnitTransakcije.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

void Prevoditelj::Hrvatski()
{
	FormPocetna->Caption = "Mjenjačnica";
	FormPocetna->ButtonCurrencyList->Caption = "Tečajna lista";
	FormPocetna->ButtonTransactions->Caption = "Transakcije";
	FormPocetna->ButtonSupervisors->Caption = "Kontrola";
	FormPocetna->ButtonSettings->Caption = "Postavke";
	FormPocetna->ButtonExit->Caption = "Izlaz";
	FormPocetna->MainMenu1->Items[0].Items[0]->Caption = "Jezik";
	FormPocetna->MainMenu1->Items[0].Items[1]->Caption = "Pomoć";
	FormPocetna->MainMenu1->Items[0].Items[2]->Caption = "O programu";

	FormAdminLogin->Caption = "Admin prijava";
	FormAdminLogin->LabelUsername->Caption = "Korisničko ime:";
	FormAdminLogin->LabelPassword->Caption = "Lozinka:";
	FormAdminLogin->BtLoginAdminOk->Caption = "Prijava";
	FormAdminLogin->BtLoginAdminCancel->Caption = "Odbaci";

	FormShiftLogin->Caption = "Blagajnik prijava";
	FormShiftLogin->Label1->Caption = "Korisničko ime:";
	FormShiftLogin->Label2->Caption = "Lozinka:";
	FormShiftLogin->BtLoginShiftOk->Caption = "Prijava";
	FormShiftLogin->BtLoginShiftCancel->Caption = "Odbaci";

	FormSuperLogin->Caption = "Kontrolor prijava";
	FormSuperLogin->Label1->Caption = "Korisničko ime:";
	FormSuperLogin->Label2->Caption = "Lozinka:";
	FormSuperLogin->BtLoginSuperOk->Caption = "Prijava";
	FormSuperLogin->BtLoginSuperCancel->Caption = "Odbaci";

	FormTecajnaLista->Caption = "Tečajna lista";

	FormTransakcije->Caption = "Otkup i prodaja";

	FormKontrola->Caption = "Kontrola";
	FormKontrola->Label1->Caption = "Valuta:";
	FormKontrola->Label2->Caption = "Tečaj:";
	FormKontrola->Label3->Caption = "Iznos:";
	FormKontrola->Label4->Caption = "Blagajnik:";
	FormKontrola->Label5->Caption = "EUR";
	FormKontrola->ButtonOtkup->Caption = "Otkupi";
	FormKontrola->ButtonProdaja->Caption = "Predaj";
	FormKontrola->ButtonDelete->Caption = "Obriši listu";
	FormKontrola->ButtonEdit->Caption = "Uredi označeno";
	FormKontrola->Label7->Caption = "EUR ulaz:";
	FormKontrola->Label9->Caption = "EUR izlaz:";
	FormKontrola->Label13->Caption = "Iznos gotovine:";
	FormKontrola->ButtonExit->Caption = "Izlaz";
	FormKontrola->ButtonDeleteRowXml->Caption = "Obriši označeno";


	FormPostavke->Caption = "Postavke";
	FormPostavke->Label3->Caption = "Administracija korisnika";
	FormPostavke->Label4->Caption = "Detalji";
	FormPostavke->Label5->Caption = "(unesi OIB, ime ili prezime)";
	FormPostavke->Label6->Caption = "Pretraži";
	FormPostavke->Label7->Caption = "Prodajno mjesto";
	FormPostavke->Label1->Caption = "Detalji:";
	FormPostavke->Label2->Caption = "Prava korisnika";
	FormPostavke->Button4UploadPic->Caption = "Unos identifikacijskog dokumenta";
	FormPostavke->Button1Search->Caption = "Traži";
	FormPostavke->Button2NewUser->Caption = "Novi korisnik";
	FormPostavke->Button3DelUser->Caption = "Obriši korisnika";
	FormPostavke->Button2->Caption = "Uvezi iz datoteke";
	FormPostavke->Button3->Caption = "Izvezi u datoteku";
	FormPostavke->ButtonExpToPdf->Caption = "Kreiraj izvještaj";
	FormPostavke->ButtonExit->Caption = "Izlaz";
}

void Prevoditelj::Engleski()
{
	FormPocetna->Caption = "Currency Exchange";
	FormPocetna->ButtonCurrencyList->Caption = "Currency list";
	FormPocetna->ButtonTransactions->Caption = "Transactions";
	FormPocetna->ButtonSupervisors->Caption = "Supervisors";
	FormPocetna->ButtonSettings->Caption = "Settings";
	FormPocetna->ButtonExit->Caption = "Exit";
	FormPocetna->MainMenu1->Items[0].Items[0]->Caption = "Language";
	FormPocetna->MainMenu1->Items[0].Items[1]->Caption = "Help";
	FormPocetna->MainMenu1->Items[0].Items[2]->Caption = "About";

	FormAdminLogin->Caption = "Admin Login";
	FormAdminLogin->LabelUsername->Caption = "Username:";
	FormAdminLogin->LabelPassword->Caption = "Password:";
	FormAdminLogin->BtLoginAdminOk->Caption = "Login";
	FormAdminLogin->BtLoginAdminCancel->Caption = "Cancel";

	FormShiftLogin->Caption = "Shift Login";
	FormShiftLogin->Label1->Caption = "Username:";
	FormShiftLogin->Label2->Caption = "Password:";
	FormShiftLogin->BtLoginShiftOk->Caption = "Login";
	FormShiftLogin->BtLoginShiftCancel->Caption = "Cancel";

	FormSuperLogin->Caption = "Super Login";
	FormSuperLogin->Label1->Caption = "Username:";
	FormSuperLogin->Label2->Caption = "Password:";
	FormSuperLogin->BtLoginSuperOk->Caption = "Login";
	FormSuperLogin->BtLoginSuperCancel->Caption = "Cancel";

	FormTecajnaLista->Caption = "Currency list";

	FormTransakcije->Caption = "Transactions";

	FormKontrola->Caption = "Supervisor control";
	FormKontrola->Label1->Caption = "Currency:";
	FormKontrola->Label2->Caption = "Exchange ratio:";
	FormKontrola->Label3->Caption = "Amount:";
	FormKontrola->Label4->Caption = "Seller name:";
	FormKontrola->Label5->Caption = "EUR";
	FormKontrola->ButtonOtkup->Caption = "Buy";
	FormKontrola->ButtonProdaja->Caption = "Sell";
	FormKontrola->ButtonDelete->Caption = "Delete list";
	FormKontrola->ButtonEdit->Caption = "Edit row";
	FormKontrola->Label7->Caption = "EUR inflow:";
	FormKontrola->Label9->Caption = "EUR exit:";
	FormKontrola->Label13->Caption = "Cash saldo:";
	FormKontrola->ButtonExit->Caption = "Exit";
	FormKontrola->ButtonDeleteRowXml->Caption = "Delete selected";


	FormPostavke->Caption = "Settings";
	FormPostavke->Label3->Caption = "User administration";
	FormPostavke->Label4->Caption = "User details";
	FormPostavke->Label5->Caption = "(type OIB, First name or Last name)";
	FormPostavke->Label6->Caption = "Search user";
	FormPostavke->Label7->Caption = "Company office administration";
	FormPostavke->Label1->Caption = "Office details:";
	FormPostavke->Label2->Caption = "Role description";
	FormPostavke->Button4UploadPic->Caption = "Import identification document";
	FormPostavke->Button1Search->Caption = "Search";
	FormPostavke->Button2NewUser->Caption = "New user";
	FormPostavke->Button3DelUser->Caption = "Delete selected user";
	FormPostavke->Button2->Caption = "Import from file";
	FormPostavke->Button3->Caption = "Export to file";
	FormPostavke->ButtonExpToPdf->Caption = "Create report";
	FormPostavke->ButtonExit->Caption = "Exit";
}

void Prevoditelj::Njemacki()
{

}


