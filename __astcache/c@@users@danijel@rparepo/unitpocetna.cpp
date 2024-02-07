//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitPocetna.h"
#include "UnitKontrola.h"
#include "UnitPostavke.h"
#include "UnitTecajnaLista.h"
#include "UnitTransakcije.h"
#include "UnitAdminLogin.h"
#include "UnitShiftLogin.h"
#include "UnitSuperLogin.h"
#include "UnitLangSelect.h"
#include <iniFiles.hpp>
#include <registry.hpp>
#include "Dictionary.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPocetna *FormPocetna;
//---------------------------------------------------------------------------
__fastcall TFormPocetna::TFormPocetna(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormPocetna::FormActivate(TObject *Sender)
{
	FormLangSelect -> ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPocetna::ButtonExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormPocetna::ButtonSettingsClick(TObject *Sender)
{
	FormAdminLogin -> ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPocetna::ButtonCurrencyListClick(TObject *Sender)
{
    FormTecajnaLista -> ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPocetna::ButtonTransactionsClick(TObject *Sender)
{
    FormShiftLogin -> ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPocetna::ButtonSupervisorsClick(TObject *Sender)
{
	FormSuperLogin -> ShowModal();
}
//---------------------------------------------------------------------------

//void __fastcall TFormPocetna::FormCreate(TObject *Sender)
//{
//	TIniFile *iniFile;
//	iniFile = new TIniFile(GetCurrentDir() + "\\aaa.ini");
//	iniFile->WriteString("FormPocetna", "Naslov", Caption);
//	delete iniFile;
//
//}

//---------------------------------------------------------------------------

void __fastcall TFormPocetna::FormClose(TObject *Sender, TCloseAction &Action)
{
	TIniFile *iniFile;
	iniFile = new TIniFile(GetCurrentDir() + "\\postavke.ini");
	iniFile->WriteString("FormPocetna", "Naslov", Caption);
	delete iniFile;
}
//---------------------------------------------------------------------------

void __fastcall TFormPocetna::HrvatskiClick(TObject *Sender)
{
	//ShowMessage("Odabrali ste hrvatski jezik");
	Prevoditelj::Hrvatski();
}
//---------------------------------------------------------------------------

void __fastcall TFormPocetna::EngleskiClick(TObject *Sender)
{
	//ShowMessage("English language selected!");
	Prevoditelj::Engleski();
}
//---------------------------------------------------------------------------

void __fastcall TFormPocetna::NjemackiClick(TObject *Sender)
{
	//ShowMessage("Sie haben die deutsche Sprache ausgewählt!");
	Prevoditelj::Njemacki();
}
//---------------------------------------------------------------------------

