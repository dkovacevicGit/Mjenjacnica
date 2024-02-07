//---------------------------------------------------------------------------

#ifndef UnitPostavkeH
#define UnitPostavkeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Datasnap.DBClient.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportBaseDialog.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
#include "frxExportHTML.hpp"
//---------------------------------------------------------------------------
class TFormPostavke : public TForm
{
__published:	// IDE-managed Components
	TFDTable *FDTable1users;
	TFDTable *FDTable2rules;
	TFDTable *FDTable3pos;
	TDataSource *DataSource1users;
	TDataSource *DataSource2rules;
	TDataSource *DataSource3pos;
	TStringField *FDTable1usersOIB;
	TStringField *FDTable1usersFirstName;
	TStringField *FDTable1usersLastName;
	TStringField *FDTable1usersUsername;
	TStringField *FDTable1usersPassword;
	TBlobField *FDTable1usersIdDoc;
	TIntegerField *FDTable1usersRoleIdent;
	TIntegerField *FDTable1usersPosID;
	TFDAutoIncField *FDTable1usersUserID;
	TDBGrid *DBGrid1users;
	TStringField *FDTable1usersOffice;
	TStringField *FDTable1usersRoleName;
	TPanel *Panel1;
	TDBImage *DBImage2;
	TDBGrid *DBGrid1;
	TLabel *Label1;
	TLabel *Label2;
	TDBGrid *DBGrid2;
	TLabel *Label3;
	TLabel *Label4;
	TDBNavigator *DBNavigator1;
	TButton *Button1Search;
	TEdit *Edit1Search;
	TButton *Button2NewUser;
	TButton *Button3DelUser;
	TLabel *Label5;
	TLabel *Label6;
	TPanel *Panel2;
	TButton *Button2;
	TButton *Button3;
	TStatusBar *StatusBar1;
	TLabel *Label7;
	TButton *Button4UploadPic;
	TOpenDialog *OpenDialog1;
	TButton *ButtonExpToPdf;
	TfrxReport *frxReport1;
	TfrxDBDataset *frxDBDataset1;
	TfrxDBDataset *frxDBDataset2;
	TfrxPDFExport *frxPDFExport1;
	TfrxRTFExport *frxRTFExport1;
	TfrxDBDataset *frxDBDataset3;
	TButton *ButtonExit;
	TfrxHTMLExport *frxHTMLExport1;
	void __fastcall Button2NewUserClick(TObject *Sender);
	void __fastcall Button3DelUserClick(TObject *Sender);
	void __fastcall Button1SearchClick(TObject *Sender);
	void __fastcall Button4UploadPicClick(TObject *Sender);
	void __fastcall ButtonExpToPdfClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFormPostavke(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPostavke *FormPostavke;
//---------------------------------------------------------------------------
#endif
