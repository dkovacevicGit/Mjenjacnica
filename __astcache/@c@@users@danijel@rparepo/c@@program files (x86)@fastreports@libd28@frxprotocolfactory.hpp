// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxProtocolFactory.pas' rev: 35.00 (Windows)

#ifndef FrxprotocolfactoryHPP
#define FrxprotocolfactoryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.SyncObjs.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxprotocolfactory
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IfrxDataLinkObject;
typedef System::DelphiInterface<IfrxDataLinkObject> _di_IfrxDataLinkObject;
class DELPHICLASS TfrxCustomDatalinkProtocol;
class DELPHICLASS TfrxProtocolItem;
class DELPHICLASS TfrxDataLinkProtocols;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TfrxDataLinkLoadMethod : unsigned char { dlmGetLink, dlmOnGetData, dlmOnLoading };

__interface  INTERFACE_UUID("{83CD083D-0399-44F2-B0F7-3A3F8109EE0E}") IfrxDataLinkObject  : public System::IInterface 
{
	virtual bool __fastcall LoadDataStream(System::Classes::TStream* Stream, const System::UnicodeString NewLink) = 0 ;
	virtual System::UnicodeString __fastcall GetLink(TfrxDataLinkLoadMethod LoadMethod) = 0 ;
	virtual bool __fastcall IsExpressionLink() = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxCustomDatalinkProtocol : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod virtual bool __fastcall LoadBy(System::UnicodeString &Link, System::Classes::TStream* Stream, System::TObject* BoundData = (System::TObject*)(0x0));
public:
	/* TObject.Create */ inline __fastcall TfrxCustomDatalinkProtocol() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxCustomDatalinkProtocol() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TfrxCustomDatalinkProtocolClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxProtocolItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FProtocolName;
	TfrxCustomDatalinkProtocolClass FProtocol;
	System::TObject* FData;
	
public:
	__property System::UnicodeString ProtocolName = {read=FProtocolName, write=FProtocolName};
	__property System::TObject* Data = {read=FData, write=FData};
	__property TfrxCustomDatalinkProtocolClass Protocol = {read=FProtocol, write=FProtocol};
public:
	/* TObject.Create */ inline __fastcall TfrxProtocolItem() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxProtocolItem() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxDataLinkProtocols : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TfrxProtocolItem* operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Syncobjs::TCriticalSection* FListCS;
	System::Classes::TList* FList;
	bool FWriteLock;
	int FReadLockCounter;
	TfrxProtocolItem* __fastcall GetItem(int Index);
	int __fastcall IndexOf(const System::UnicodeString ProtocolName);
	void __fastcall Lock(bool IsWriting = false);
	void __fastcall Unlock(bool IsWriting = false);
	void __fastcall Clear();
	void __fastcall ParseLink(System::UnicodeString &Protocol, System::UnicodeString &Link);
	
public:
	__fastcall TfrxDataLinkProtocols();
	__fastcall virtual ~TfrxDataLinkProtocols();
	void __fastcall Register(TfrxCustomDatalinkProtocolClass AClass, const System::UnicodeString ProtocolName, System::TObject* BoundData = (System::TObject*)(0x0));
	void __fastcall Unregister(const System::UnicodeString ProtocolName);
	bool __fastcall LoadByLink(System::UnicodeString &Link, System::Classes::TStream* Stream);
	bool __fastcall LoadToObject(System::UnicodeString &Link, _di_IfrxDataLinkObject DataLinkObject);
	TfrxCustomDatalinkProtocolClass __fastcall GetProtocol(const System::UnicodeString Link);
	TfrxProtocolItem* __fastcall GetProtocolItem(const System::UnicodeString Link);
	__property TfrxProtocolItem* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE TfrxDataLinkProtocols* __fastcall frxDataProtocols(void);
}	/* namespace Frxprotocolfactory */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXPROTOCOLFACTORY)
using namespace Frxprotocolfactory;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxprotocolfactoryHPP
