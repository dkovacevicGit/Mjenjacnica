// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxPictureCache.pas' rev: 35.00 (Windows)

#ifndef FrxpicturecacheHPP
#define FrxpicturecacheHPP

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
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <frxXML.hpp>
#include <frxBaseGraphicsTypes.hpp>
#include <System.SyncObjs.hpp>
#include <System.Variants.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxpicturecache
{
//-- forward type declarations -----------------------------------------------
struct TfrxCacheItem;
class DELPHICLASS TfrxCacheList;
class DELPHICLASS TfrxFileStream;
class DELPHICLASS TfrxMemoryStream;
class DELPHICLASS TfrxInternalPictureCache;
class DELPHICLASS TfrxThumbnailThread;
class DELPHICLASS TfrxPictureCache;
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD TfrxCacheItem
{
public:
	int Segment;
	int Offset;
	int Loading;
	int Width;
	int Height;
};
#pragma pack(pop)


enum DECLSPEC_DENUM TfrxThumbnailsUpdateState : unsigned char { tusAdded, tusClear };

typedef TfrxCacheItem *PfrxCacheItem;

typedef void __fastcall (__closure *TfrxThumbnailsUpdate)(System::TObject* Sender, TfrxThumbnailsUpdateState UpdateState);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxCacheList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	PfrxCacheItem operator[](int Index) { return this->Items[Index]; }
	
private:
	PfrxCacheItem __fastcall Get(int Index);
	
protected:
	System::Classes::TList* FItems;
	void __fastcall Clear();
	
public:
	__fastcall TfrxCacheList();
	__fastcall virtual ~TfrxCacheList();
	PfrxCacheItem __fastcall Add();
	int __fastcall Count();
	System::Types::TSize __fastcall GetSize(const int Index);
	__property PfrxCacheItem Items[int Index] = {read=Get/*, default*/};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxFileStream : public System::Classes::TFileStream
{
	typedef System::Classes::TFileStream inherited;
	
private:
	unsigned FSz;
	
public:
	virtual int __fastcall Seek(int Offset, System::Word Origin)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
public:
	/* TFileStream.Create */ inline __fastcall TfrxFileStream(const System::UnicodeString AFileName, System::Word Mode)/* overload */ : System::Classes::TFileStream(AFileName, Mode) { }
	/* TFileStream.Create */ inline __fastcall TfrxFileStream(const System::UnicodeString AFileName, System::Word Mode, unsigned Rights)/* overload */ : System::Classes::TFileStream(AFileName, Mode, Rights) { }
	/* TFileStream.Destroy */ inline __fastcall virtual ~TfrxFileStream() { }
	
	/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxMemoryStream : public System::Classes::TMemoryStream
{
	typedef System::Classes::TMemoryStream inherited;
	
private:
	unsigned FSz;
	
public:
	virtual int __fastcall Seek(int Offset, System::Word Origin)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin)/* overload */;
public:
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TfrxMemoryStream() { }
	
public:
	/* TObject.Create */ inline __fastcall TfrxMemoryStream() : System::Classes::TMemoryStream() { }
	
	/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Word Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxInternalPictureCache : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TfrxCacheList* FItems;
	System::Classes::TList* FCacheStreamList;
	System::Classes::TStringList* FTempFile;
	System::UnicodeString FTempDir;
	bool FUseFileCache;
	System::Syncobjs::TCriticalSection* FCrit;
	PfrxCacheItem __fastcall Add();
	void __fastcall SetTempDir(const System::UnicodeString Value);
	void __fastcall SetUseFileCache(const bool Value);
	void __fastcall AddSegment();
	Vcl::Graphics::TGraphic* __fastcall InternalGetPicture(Vcl::Graphics::TPicture* APicture, Vcl::Graphics::TGraphic* aGraphic, int ImageIndex);
	
protected:
	int __fastcall Count();
	
public:
	__fastcall TfrxInternalPictureCache();
	__fastcall virtual ~TfrxInternalPictureCache();
	void __fastcall Clear();
	int __fastcall AddPicture(Vcl::Graphics::TGraphic* aGraphic);
	void __fastcall GetPicture(Vcl::Graphics::TGraphic* aGraphic, int ImageIndex)/* overload */;
	void __fastcall GetPicture(Vcl::Graphics::TPicture* Picture, int ImageIndex)/* overload */;
	Vcl::Graphics::TGraphic* __fastcall GetPicture(const int ImageIndex)/* overload */;
	System::Types::TSize __fastcall GetSize(const int ImageIndex);
	void __fastcall SetSize(const int ImageIndex, int Width, int Height);
	bool __fastcall IsExist(const int ImageIndex);
	void __fastcall SaveToXML(Frxxml::TfrxXMLItem* Item);
	void __fastcall LoadFromXML(Frxxml::TfrxXMLItem* Item);
	__property bool UseFileCache = {read=FUseFileCache, write=SetUseFileCache, nodefault};
	__property System::UnicodeString TempDir = {read=FTempDir, write=SetTempDir};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TfrxThumbnailThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	TfrxPictureCache* FCache;
	void __fastcall DoUpdate();
	
public:
	__fastcall TfrxThumbnailThread(TfrxPictureCache* ACache);
	__fastcall virtual ~TfrxThumbnailThread();
	virtual void __fastcall Execute();
};


class PASCALIMPLEMENTATION TfrxPictureCache : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	TfrxInternalPictureCache* FPictureCache;
	TfrxInternalPictureCache* FThumbnailCache;
	System::Classes::TStringList* FCahcedBitmap;
	TfrxThumbnailsUpdate FOnThumbnailUpdated;
	bool FIsUpdating;
	Frxbasegraphicstypes::TfrxPictureCacheOptions* FPictureCacheOptions;
	System::UnicodeString __fastcall GetTempDir();
	bool __fastcall GetUseFileCache();
	void __fastcall SetTempDir(const System::UnicodeString Value);
	void __fastcall SetUseFileCache(const bool Value);
	Vcl::Graphics::TGraphic* __fastcall GetPicture(const int ImageIndex, const Frxbasegraphicstypes::TfrxCachedGraphicType CacheType)/* overload */;
	void __fastcall BuildThumbnailFromCache();
	void __fastcall StartThumbnailThread();
	void __fastcall FreeThumbnailThread();
	System::Types::TSize __fastcall CalcThumbnailSize(const int Width, const int Height, const Frxbasegraphicstypes::TfrxCachedGraphicType CacheType);
	void __fastcall ThumbnailUpdate(TfrxThumbnailsUpdateState State);
	void __fastcall SetPictureCacheOptions(Frxbasegraphicstypes::TfrxPictureCacheOptions* const Value);
	int __fastcall AddPictureTo(Vcl::Graphics::TGraphic* aGraphic, TfrxInternalPictureCache* InternalCache);
	bool __fastcall IsAutoRefMode();
	System::Types::TSize __fastcall GetSize(const Frxbasegraphicstypes::TfrxCachedGraphicType CacheType, const int ImageIndex);
	
public:
	__fastcall TfrxPictureCache();
	__fastcall virtual ~TfrxPictureCache();
	void __fastcall Clear();
	void __fastcall BuildFinished();
	int __fastcall AddPicture(Vcl::Graphics::TGraphic* aGraphic);
	void __fastcall GetGraphic(Vcl::Graphics::TGraphic* aGraphic, int ImageIndex)/* overload */;
	void __fastcall GetPicture(Vcl::Graphics::TPicture* APicture, int ImageIndex)/* overload */;
	Vcl::Graphics::TGraphic* __fastcall GetGraphic(int ImageIndex)/* overload */;
	Frxbasegraphicstypes::_di_IfrxCachedGraphic __fastcall GetCachedBitmap(Frxbasegraphicstypes::TfrxCachedGraphicType CacheType, int ImageIndex);
	Vcl::Graphics::TGraphic* __fastcall GetPictureTo(Vcl::Graphics::TPicture* APicture, Vcl::Graphics::TGraphic* aGraphic, int ImageIndex)/* overload */;
	void __fastcall SaveToXML(Frxxml::TfrxXMLItem* Item);
	void __fastcall LoadFromXML(Frxxml::TfrxXMLItem* Item);
	__property bool UseFileCache = {read=GetUseFileCache, write=SetUseFileCache, nodefault};
	__property System::UnicodeString TempDir = {read=GetTempDir, write=SetTempDir};
	__property Frxbasegraphicstypes::TfrxPictureCacheOptions* PictureCacheOptions = {read=FPictureCacheOptions, write=SetPictureCacheOptions};
	__property TfrxThumbnailsUpdate OnThumbnailUpdated = {read=FOnThumbnailUpdated, write=FOnThumbnailUpdated};
private:
	void *__IfrxPictureCache;	// Frxbasegraphicstypes::IfrxPictureCache 
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {06FD066C-726D-4BC0-811D-94150807E798}
	operator Frxbasegraphicstypes::_di_IfrxPictureCache()
	{
		Frxbasegraphicstypes::_di_IfrxPictureCache intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator Frxbasegraphicstypes::IfrxPictureCache*(void) { return (Frxbasegraphicstypes::IfrxPictureCache*)&__IfrxPictureCache; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxpicturecache */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXPICTURECACHE)
using namespace Frxpicturecache;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxpicturecacheHPP
