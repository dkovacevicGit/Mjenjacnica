//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitLangSelect.h"
#include "UnitPocetna.h"
#include "Dictionary.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxGIFGraphic"
#pragma resource "*.dfm"
TFormLangSelect *FormLangSelect;
//---------------------------------------------------------------------------

__fastcall TFormLangSelect::TFormLangSelect(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormLangSelect::Image1Click(TObject *Sender)
{
	ShowMessage("Odabrali ste hrvatski jezik");  //Prikaz poruke
	Prevoditelj::Hrvatski();  //Pozivanje funkcije Hrvatski() iz klase Prevoditelj
	Close(); //Zatvaranje dijaloga
}

void __fastcall TFormLangSelect::Image2Click(TObject *Sender)
{
	ShowMessage("English language selected!");
	Prevoditelj::Engleski();
	Close();
}

void __fastcall TFormLangSelect::Image3Click(TObject *Sender)
{
	ShowMessage("Sie haben die deutsche Sprache ausgewählt!");
	Prevoditelj::Njemacki();
	Close();
}
//---------------------------------------------------------------------------

