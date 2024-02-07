//---------------------------------------------------------------------------

#ifndef UnitKontrolaH
#define UnitKontrolaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include "frxClass.hpp"
#include "frxListBox.hpp"
//---------------------------------------------------------------------------
class TFormKontrola : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *ButtonOtkup;
	TButton *ButtonProdaja;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditBlagajnik;
	TEdit *EditSredTecaj;
	TEdit *EditOtkup;
	TComboBox *ComboBox2;
	TListView *ListView1;
	TLabel *Label5;
	TLabel *Label6;
	TButton *ButtonDelete;
	TButton *ButtonEdit;
	TPanel *Panel2;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TXMLDocument *XMLDocument1;
	TPanel *Panel3;
	TLabel *Label13;
	TLabel *Label14;
	TButton *ButtonExit;
	TLabel *Label11;
	TLabel *Label12;
	TButton *ButtonDeleteRowXml;
	void __fastcall ComboBox2Select(TObject *Sender);
	void __fastcall ButtonOtkupClick(TObject *Sender);
	void __fastcall ButtonProdajaClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall EditOtkupEnter(TObject *Sender);
	void __fastcall EditSredTecajEnter(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonEditClick(TObject *Sender);
	void __fastcall ListView1Change(TObject *Sender, TListItem *Item, TItemChange Change);
	void __fastcall EditSredTecajExit(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall ButtonDeleteRowXmlClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormKontrola(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormKontrola *FormKontrola;
//---------------------------------------------------------------------------
#endif
