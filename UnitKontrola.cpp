//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitKontrola.h"
#include "UnitSuperLogin.h"
#include "NoviXML.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxListBox"
#pragma resource "*.dfm"
TFormKontrola *FormKontrola;
//---------------------------------------------------------------------------
class Valuta {
public:
    AnsiString naziv;
	float srednjiTecaj;
	float prodajni;
	float otkupni;

	Valuta(const AnsiString& naziv, float srednjiTecaj) : naziv(naziv), srednjiTecaj(srednjiTecaj) {}

	float izracunProdajni() {
		prodajni = srednjiTecaj * 0.9;
		return prodajni;
    }

	float izracunOtkupni() {
		otkupni = srednjiTecaj * 1.1;
		return otkupni;
		}
};

class Blagajnik {
public:
	int temp;
	float total1, total2, saldo;

	Blagajnik(float saldo) : saldo(saldo) {}

	void OtkupStraneValute(Valuta valuta, float iznos) {
		saldo = 0;
		saldo = valuta.izracunProdajni() * iznos;
		total1 = saldo * 100;
		//ShowMessage(total1);
		}

	void ProdajaStraneValute(Valuta valuta, float iznos) {
		saldo = 0;
		saldo = valuta.izracunOtkupni() * iznos;
		total2 = saldo * 100;
		//ShowMessage(total2);
		}


	float getTotal(){
		float total = 0;
		total = abs(total2 - total1);
		return total/100;
	}
};

//---------------------------------------------------------------------------
__fastcall TFormKontrola::TFormKontrola(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TFormKontrola::FormCreate(TObject *Sender)  //Učitavanje liste prilikom otvaranja Forme
{
	_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);

	ListView1->Items->Clear();
	for(int i = 0; i < SaldoList->Count; i++){
		ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption = SaldoList->transaction[i]->Get_Blagajnik();
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Valuta());
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Srednji_tecaj());
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Ulaz_EUR());
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Izlaz_EUR());
		}

}

 //---------------------------------------------------------------------------

void __fastcall TFormKontrola::ComboBox2Select(TObject *Sender)
{
	Label6->Caption = ComboBox2->Text;    //Prikaz odabrane valute u labeli
	ButtonOtkup->Caption = "Otkupi  " + ComboBox2->Text;    //Prikaz odabrane valute u Btn-u
	ButtonProdaja->Caption = "Prodaj  " + ComboBox2->Text;   //Prikaz odabrane valute u Btn-u
}
//---------------------------------------------------------------------------

void __fastcall TFormKontrola::EditSredTecajExit(TObject *Sender) //Prikaz prod i otkup tečaja ispod btn-a
{
	Label11->Caption = EditSredTecaj->Text * 0.9;
	Label12->Caption = EditSredTecaj->Text * 1.1;
}
//---------------------------------------------------------------------------

void __fastcall TFormKontrola::ButtonOtkupClick(TObject *Sender)  //Tipka za OTKUP
{
	AnsiString nazivValute = ComboBox2->Text;
	float srednjiTecaj = StrToFloat(EditSredTecaj->Text);
	float iznosOtkupa = StrToFloat(EditOtkup->Text);
	float n;

	Valuta valuta(nazivValute, srednjiTecaj);
	Blagajnik blag(0.0);
	blag.OtkupStraneValute(valuta, iznosOtkupa);

	n = blag.getTotal();
	//LabelSaldo->Caption = FloatToStr(n/100.0);    //Prikaz u labeli - obrisano

	// Upisivanje u XML
	_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);
	_di_IXMLtransactionType Trans = SaldoList->Add();

	Trans->Blagajnik = EditBlagajnik->Text;
	Trans->Valuta = ComboBox2->Text;
	Trans->Srednji_tecaj = EditSredTecaj->Text;
	Trans->Ulaz_EUR = StrToFloat("0");
	Trans->Izlaz_EUR = n;
	XMLDocument1->SaveToFile(XMLDocument1->FileName);

	int ok = Application->MessageBox(L"Otkup evidentiran!", L"Info", MB_OK);
	if (ok==IDOK) {
		_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);

		// Čitanje iz XML-a
		ListView1->Items->Clear();
		for(int i = 0; i < SaldoList->Count; i++){
			ListView1->Items->Add();
			ListView1->Items->Item[i]->Caption = SaldoList->transaction[i]->Get_Blagajnik();
			ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Valuta());
			ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Srednji_tecaj());
			ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Ulaz_EUR());
			ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Izlaz_EUR());
		}
	}


}
//---------------------------------------------------------------------------

void __fastcall TFormKontrola::ButtonProdajaClick(TObject *Sender)  // Tipka za PRODAJU
{
	AnsiString nazivValute = ComboBox2->Text;
	float srednjiTecaj = StrToFloat(EditSredTecaj->Text);
	float iznosProdaje = StrToFloat(EditOtkup->Text);
	float n;

	Valuta valuta(nazivValute, srednjiTecaj);
    Blagajnik blag(0.0);
	blag.ProdajaStraneValute(valuta, iznosProdaje);

	n = blag.getTotal();
	//LabelSaldo->Caption = FloatToStr(n/100.0);    //Prikaz u labeli - obrisano

	// Upisivanje u XML
	_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);
	_di_IXMLtransactionType Trans = SaldoList->Add();

	Trans->Blagajnik = EditBlagajnik->Text;
	Trans->Valuta = ComboBox2->Text;
	Trans->Srednji_tecaj = EditSredTecaj->Text;
	Trans->Ulaz_EUR = n;
	Trans->Izlaz_EUR = StrToFloat("0");
	XMLDocument1->SaveToFile(XMLDocument1->FileName);

	int ok = Application->MessageBox(L"Prodaja evidentirana!", L"Info", MB_OK);
	if (ok==IDOK) {
		_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);

		// Čitanje iz XML-a
		ListView1->Items->Clear();
		for(int i = 0; i < SaldoList->Count; i++){
			ListView1->Items->Add();
			ListView1->Items->Item[i]->Caption = SaldoList->transaction[i]->Get_Blagajnik();
			ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Valuta());
			ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Srednji_tecaj());
			ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Ulaz_EUR());
			ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Izlaz_EUR());
		}
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TFormKontrola::EditOtkupEnter(TObject *Sender)
{
	EditOtkup->Text = "";   // Brisanje teksta nakon klika na TEdit
}
//---------------------------------------------------------------------------

void __fastcall TFormKontrola::EditSredTecajEnter(TObject *Sender)
{
	EditSredTecaj->Text = "";   // Brisanje teksta nakon klika na TEdit
}
//---------------------------------------------------------------------------

void __fastcall TFormKontrola::ButtonDeleteClick(TObject *Sender)
{
	_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);

	SaldoList->Clear();
	XMLDocument1->SaveToFile(XMLDocument1->FileName);

	// Čitanje iz XML-a
	ListView1->Items->Clear();
	for(int i = 0; i < SaldoList->Count; i++){
		ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption = SaldoList->transaction[i]->Blagajnik;
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Valuta);
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Srednji_tecaj);
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Ulaz_EUR());
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Izlaz_EUR());
	}

	Label8->Caption = "0.00";
	Label10->Caption = "0.00";
	Label14->Caption = "0.00";
}
//---------------------------------------------------------------------------

void __fastcall TFormKontrola::ButtonEditClick(TObject *Sender) //Editiranje redka u XML-u
{
	// Prekini ukoliko niti jedan kontakt u komponenti ListView1 nije označen
	if(ListView1->ItemIndex == -1)
	return;

	// Ako je označen, editiraj označeni kontakt
	_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);
	_di_IXMLtransactionType Trans = SaldoList->transaction[ListView1->ItemIndex];

	Trans->Blagajnik = EditBlagajnik->Text;
	Trans->Valuta = ComboBox2->Text;
	Trans->Srednji_tecaj = EditSredTecaj->Text;
	Trans->Ulaz_EUR = StrToFloat(EditOtkup->Text);
	XMLDocument1->SaveToFile(XMLDocument1->FileName);

	// Čitanje iz XML-a
	ListView1->Items->Clear();
	for(int i = 0; i < SaldoList->Count; i++){
		ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption = SaldoList->transaction[i]->Blagajnik;
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Valuta);
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Srednji_tecaj);
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Ulaz_EUR());
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Izlaz_EUR());
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormKontrola::ListView1Change(TObject *Sender, TListItem *Item, TItemChange Change)

{
 //--------Metoda za prikaz Otkupljeno, Prodano i Saldo u Labelama

	float nekaVar1, nekaVar2;

	_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);

	for(int i = 0; i < SaldoList->Count; i++){
		nekaVar1 += SaldoList->transaction[i]->Get_Izlaz_EUR();
		nekaVar2 += SaldoList->transaction[i]->Get_Ulaz_EUR();
		}

		float razlika = nekaVar2 - nekaVar1;
		Label8->Caption = nekaVar2;
		Label10->Caption = nekaVar1;
		Label14->Caption = razlika;
		if(razlika<0){
			Label14->Font->Color = clRed;
			Label14->Font->Style = TFontStyles()<<fsBold;
		}
		else{
			Label14->Font->Color = clWindowText;
		}
 }
//---------------------------------------------------------------------------

void __fastcall TFormKontrola::ButtonExitClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormKontrola::ButtonDeleteRowXmlClick(TObject *Sender) //Brisanje reda u XML-u
{
	if (ListView1->ItemIndex == -1)
		return;

	_di_IXMLsaldoType SaldoList = Getsaldo(XMLDocument1);

	SaldoList->Delete(ListView1->ItemIndex);
	XMLDocument1->SaveToFile(XMLDocument1->FileName);

	ListView1->Items->Clear();
	for(int i = 0; i < SaldoList->Count; i++){
		ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption = SaldoList->transaction[i]->Blagajnik;
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Valuta);
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Srednji_tecaj);
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Ulaz_EUR());
		ListView1->Items->Item[i]->SubItems->Add(SaldoList->transaction[i]->Get_Izlaz_EUR());
	}
}
//---------------------------------------------------------------------------
