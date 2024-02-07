//---------------------------------------------------------------------------

#ifndef UnitPocetnaH
#define UnitPocetnaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "UnitLangSelect.h"
//---------------------------------------------------------------------------
class TFormPocetna : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonCurrencyList;
	TButton *ButtonTransactions;
	TButton *ButtonSupervisors;
	TButton *ButtonSettings;
	TButton *ButtonExit;
	TStatusBar *StatusBar1;
	TFDConnection *FDConnection1;
	TPanel *Panel1;
	TMainMenu *MainMenu1;
	TMenuItem *Croatian2;
	TMenuItem *About1;
	TMenuItem *Language;
	TMenuItem *Hrvatski;
	TMenuItem *Engleski;
	TMenuItem *Njemacki;
	TMenuItem *About2;
	TMenuItem *About3;
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall ButtonSettingsClick(TObject *Sender);
	void __fastcall ButtonCurrencyListClick(TObject *Sender);
	void __fastcall ButtonTransactionsClick(TObject *Sender);
	void __fastcall ButtonSupervisorsClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall HrvatskiClick(TObject *Sender);
	void __fastcall EngleskiClick(TObject *Sender);
	void __fastcall NjemackiClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormPocetna(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPocetna *FormPocetna;
//---------------------------------------------------------------------------
#endif
