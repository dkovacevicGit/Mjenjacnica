//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("UnitShiftLogin.cpp", FormShiftLogin);
USEFORM("UnitPostavke.cpp", FormPostavke);
USEFORM("UnitPocetna.cpp", FormPocetna);
USEFORM("UnitTransakcije.cpp", FormTransakcije);
USEFORM("UnitTecajnaLista.cpp", FormTecajnaLista);
USEFORM("UnitSuperLogin.cpp", FormSuperLogin);
USEFORM("UnitKontrola.cpp", FormKontrola);
USEFORM("UnitInputNewUser.cpp", FormInputNewUser);
USEFORM("UnitAdminLogin.cpp", FormAdminLogin);
USEFORM("UnitLangSelect.cpp", FormLangSelect);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormPocetna), &FormPocetna);
		Application->CreateForm(__classid(TFormTecajnaLista), &FormTecajnaLista);
		Application->CreateForm(__classid(TFormTransakcije), &FormTransakcije);
		Application->CreateForm(__classid(TFormKontrola), &FormKontrola);
		Application->CreateForm(__classid(TFormPostavke), &FormPostavke);
		Application->CreateForm(__classid(TFormAdminLogin), &FormAdminLogin);
		Application->CreateForm(__classid(TFormSuperLogin), &FormSuperLogin);
		Application->CreateForm(__classid(TFormShiftLogin), &FormShiftLogin);
		Application->CreateForm(__classid(TFormInputNewUser), &FormInputNewUser);
		Application->CreateForm(__classid(TFormLangSelect), &FormLangSelect);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
