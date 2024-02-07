//---------------------------------------------------------------------------

#ifndef UnitLangSelectH
#define UnitLangSelectH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "frxGIFGraphic.hpp"
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormLangSelect : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
   	__fastcall TFormLangSelect(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLangSelect *FormLangSelect;
//---------------------------------------------------------------------------
#endif
