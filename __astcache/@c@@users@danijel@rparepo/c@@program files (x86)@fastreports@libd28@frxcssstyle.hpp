// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxCSSStyle.pas' rev: 35.00 (Windows)

#ifndef FrxcssstyleHPP
#define FrxcssstyleHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <frxHelpers.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxcssstyle
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxCSSStyle;
class DELPHICLASS TfrxCSSList;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxCSSStyle : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	System::UnicodeString operator[](const System::UnicodeString Key) { return this->Style[Key]; }
	
private:
	System::Classes::TStrings* FKeys;
	System::Classes::TStrings* FValues;
	System::UnicodeString FName;
	System::UnicodeString __fastcall GetStyle(const System::UnicodeString Key);
	void __fastcall SetStyle(const System::UnicodeString Key, const System::UnicodeString Value);
	void __fastcall SetPrefixStyle(System::UnicodeString Index, const System::UnicodeString Value);
	
public:
	__fastcall TfrxCSSStyle();
	__fastcall virtual ~TfrxCSSStyle();
	TfrxCSSStyle* __fastcall This();
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	void __fastcall Clear();
	void __fastcall SetValuesFromText(const System::UnicodeString Text);
	bool __fastcall IsHasKey(System::UnicodeString Key);
	int __fastcall Count();
	System::UnicodeString __fastcall Text(bool Formatted = false);
	__property System::UnicodeString Style[const System::UnicodeString Key] = {read=GetStyle, write=SetStyle/*, default*/};
	__property System::UnicodeString PrefixStyle[System::UnicodeString Index] = {write=SetPrefixStyle};
	__property System::UnicodeString Name = {read=FName, write=FName};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxCSSList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FStyles;
	int __fastcall GetCount();
	
public:
	__fastcall TfrxCSSList();
	__fastcall virtual ~TfrxCSSList();
	void __fastcall Clear();
	void __fastcall Assign(TfrxCSSList* SourceStyleList);
	void __fastcall Save(System::Classes::TStream* Stream, bool Formatted);
	System::UnicodeString __fastcall AddStyle(TfrxCSSStyle* Style);
	TfrxCSSStyle* __fastcall AddName(const System::UnicodeString Name, System::UnicodeString Values = System::UnicodeString());
	int __fastcall AddText(const System::UnicodeString AStyle);
	TfrxCSSStyle* __fastcall GetStyle(const int Index);
	TfrxCSSStyle* __fastcall GetStyleByName(const System::UnicodeString Name);
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxcssstyle */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXCSSSTYLE)
using namespace Frxcssstyle;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxcssstyleHPP
