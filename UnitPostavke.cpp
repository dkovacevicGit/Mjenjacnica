//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitPostavke.h"
#include "UnitPocetna.h"
#include <jpeg.hpp>
#include <pngimage.hpp>
#include "UnitInputNewUser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma link "frxExportHTML"
#pragma resource "*.dfm"
TFormPostavke *FormPostavke;
//---------------------------------------------------------------------------
__fastcall TFormPostavke::TFormPostavke(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::Button2NewUserClick(TObject *Sender)
{
	FormInputNewUser->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::Button3DelUserClick(TObject *Sender)
{
	if(Application->MessageBox(L"Are you sure?", L"Warning!", MB_YESNO | MB_DEFBUTTON2 | MB_ICONWARNING)==IDYES){
		FDTable1users->Delete();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::Button1SearchClick(TObject *Sender)
{
	TLocateOptions SearchOptions;
	SearchOptions.Clear();
	SearchOptions << loPartialKey;

	if(FDTable1users->Locate("OIB", Edit1Search->Text, SearchOptions)){
		ShowMessage("Found user by OIB: " + Edit1Search->Text);
		Edit1Search->Text="";
		return;
	}
	if(FDTable1users->Locate("FirstName", Edit1Search->Text, SearchOptions)){
		ShowMessage("Found user: " + UpperCase(Edit1Search->Text));
		Edit1Search->Text="";
	return;
	}
	if(FDTable1users->Locate("LastName", Edit1Search->Text, SearchOptions)){
		ShowMessage("Found user: " + UpperCase(Edit1Search->Text));
		Edit1Search->Text="";
    }
	else{
		ShowMessage("User not found");
		Edit1Search->Text="";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::Button4UploadPicClick(TObject *Sender)
{
	if(OpenDialog1->Execute()){
		FDTable1users->Edit();
		static_cast<TBlobField*>(FDTable1users->FieldByName("IdDoc"))->LoadFromFile(OpenDialog1->FileName);
		FDTable1users->Post();
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::ButtonExpToPdfClick(TObject *Sender) //Kreiranje izvještaja
{
    frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

void __fastcall TFormPostavke::ButtonExitClick(TObject *Sender) //Izlaz iz forme
{
    Close();
}
//---------------------------------------------------------------------------


