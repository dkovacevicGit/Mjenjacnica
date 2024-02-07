// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxHelpers.pas' rev: 35.00 (Windows)

#ifndef FrxhelpersHPP
#define FrxhelpersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <frxXML.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxhelpers
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TOwnObjList;
class DELPHICLASS TfrxValuedXMLReader;
class DELPHICLASS TfrxValuedXMLDocument;
class DELPHICLASS ESignException;
class DELPHICLASS TLogList;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TOwnObjList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	System::TObject* operator[](int Index) { return this->Items[Index]; }
	
private:
	bool FOwnsObjects;
	
protected:
	System::TObject* __fastcall GetItem(int Index);
	
public:
	__fastcall TOwnObjList(bool AOwnsObjects);
	virtual void __fastcall Clear();
	void __fastcall AddNonZero(void * Item);
	HIDESBASE void __fastcall Assign(System::Classes::TList* SourceList);
	__property System::TObject* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TOwnObjList() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TValueDlm : unsigned char { vdUnknown, vdApostrophe, vdQuote };

class PASCALIMPLEMENTATION TfrxValuedXMLReader : public Frxxml::TfrxXMLReader
{
	typedef Frxxml::TfrxXMLReader inherited;
	
protected:
	bool __fastcall IsLastSlash(const System::UnicodeString InSt);
	bool __fastcall IsFirstSlash(const System::UnicodeString InSt);
	bool __fastcall IsFirstNumberSign(const System::UnicodeString InSt);
	virtual void __fastcall ReadValuedItem(/* out */ System::UnicodeString &NameS, /* out */ System::UnicodeString &ValueS, /* out */ System::UnicodeString &Text);
	virtual void __fastcall ProcessSecondLeftBrocket() = 0 ;
	virtual Frxxml::TfrxXMLItem* __fastcall CreateItem();
	void __fastcall AddChar(System::AnsiString &st, int &stPos, char ch);
	
public:
	bool __fastcall IsReadValuedXMLRootItem(Frxxml::TfrxXMLItem* Item);
	bool __fastcall IsReadValuedXMLItem(Frxxml::TfrxXMLItem* Item);
public:
	/* TfrxXMLReader.Create */ inline __fastcall TfrxValuedXMLReader(System::Classes::TStream* Stream) : Frxxml::TfrxXMLReader(Stream) { }
	/* TfrxXMLReader.Destroy */ inline __fastcall virtual ~TfrxValuedXMLReader() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxValuedXMLDocument : public Frxxml::TfrxXMLDocument
{
	typedef Frxxml::TfrxXMLDocument inherited;
	
protected:
	System::Classes::TStream* FValuedXMLStream;
	TfrxValuedXMLReader* FValuedXMLStreamReader;
	virtual void __fastcall ReadXMLHeader() = 0 ;
	virtual TfrxValuedXMLReader* __fastcall CreateReader() = 0 ;
	
public:
	void __fastcall InitValuedXMLFile(const System::UnicodeString FileName);
	void __fastcall DoneValuedXMLFile();
	bool __fastcall IsReadItem(Frxxml::TfrxXMLItem* Item);
public:
	/* TfrxXMLDocument.Create */ inline __fastcall TfrxValuedXMLDocument() : Frxxml::TfrxXMLDocument() { }
	/* TfrxXMLDocument.Destroy */ inline __fastcall virtual ~TfrxValuedXMLDocument() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION ESignException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall ESignException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ESignException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall ESignException(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ESignException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ESignException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall ESignException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall ESignException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ESignException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ESignException(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ESignException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ESignException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ESignException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ESignException() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TLogList : public System::Classes::TStringList
{
	typedef System::Classes::TStringList inherited;
	
public:
	void __fastcall Save(System::Sysutils::TFileName FileName);
	void __fastcall SaveAppend(System::Sysutils::TFileName FileName);
public:
	/* TStringList.Create */ inline __fastcall TLogList()/* overload */ : System::Classes::TStringList() { }
	/* TStringList.Create */ inline __fastcall TLogList(bool OwnsObjects)/* overload */ : System::Classes::TStringList(OwnsObjects) { }
	/* TStringList.Create */ inline __fastcall TLogList(System::WideChar QuoteChar, System::WideChar Delimiter)/* overload */ : System::Classes::TStringList(QuoteChar, Delimiter) { }
	/* TStringList.Create */ inline __fastcall TLogList(System::WideChar QuoteChar, System::WideChar Delimiter, System::Classes::TStringsOptions Options)/* overload */ : System::Classes::TStringList(QuoteChar, Delimiter, Options) { }
	/* TStringList.Create */ inline __fastcall TLogList(System::Types::TDuplicates Duplicates, bool Sorted, bool CaseSensitive)/* overload */ : System::Classes::TStringList(Duplicates, Sorted, CaseSensitive) { }
	/* TStringList.Destroy */ inline __fastcall virtual ~TLogList() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::WideString __fastcall ReadWideStringFromStream(System::Classes::TStream* Stream);
extern DELPHI_PACKAGE void __fastcall WriteWideStringToStream(System::Classes::TStream* Stream, const System::WideString ws);
extern DELPHI_PACKAGE System::Extended __fastcall ReadExtended16(System::Classes::TStream* Stream);
extern DELPHI_PACKAGE System::Extended __fastcall ReadExtended8(System::Classes::TStream* Stream);
extern DELPHI_PACKAGE System::Extended __fastcall ReadExtended10(System::Classes::TStream* Stream);
extern DELPHI_PACKAGE double __fastcall Limit(const double Value, const double MinValue, const double MaxValue)/* overload */;
extern DELPHI_PACKAGE float __fastcall Limit(const float Value, const float MinValue, const float MaxValue)/* overload */;
extern DELPHI_PACKAGE int __fastcall Limit(const int Value, const int MinValue, const int MaxValue)/* overload */;
extern DELPHI_PACKAGE System::UnicodeString __fastcall NormalizeScientificNotation(const System::UnicodeString S);
extern DELPHI_PACKAGE System::Classes::TStrings* __fastcall ToStringList(const System::UnicodeString S, const System::WideChar Delimiter);
extern DELPHI_PACKAGE System::AnsiString __fastcall AnsiStringOfChar(char ACh, int Count);
extern DELPHI_PACKAGE unsigned __fastcall ByteSwap(int Value)/* overload */;
extern DELPHI_PACKAGE unsigned __fastcall ByteSwap(unsigned Value)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall ByteSwap(__int64 Value)/* overload */;
extern DELPHI_PACKAGE System::AnsiString __fastcall BufferToHex(void * Buffer, unsigned Len, bool UpCase = true);
extern DELPHI_PACKAGE System::AnsiString __fastcall AnsiToHex(System::AnsiString st, bool UpCase = true);
extern DELPHI_PACKAGE System::Word __fastcall ROR16(const System::Word Value, const System::Byte Bits);
extern DELPHI_PACKAGE System::Word __fastcall ROL16(const System::Word Value, const System::Byte Bits);
extern DELPHI_PACKAGE unsigned __fastcall ROL(const unsigned Value, const System::Byte Bits);
extern DELPHI_PACKAGE System::AnsiString __fastcall IntToAnsiStr(int Value);
extern DELPHI_PACKAGE void * __fastcall IncPointer(void * P, unsigned Offset);
}	/* namespace Frxhelpers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXHELPERS)
using namespace Frxhelpers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxhelpersHPP
