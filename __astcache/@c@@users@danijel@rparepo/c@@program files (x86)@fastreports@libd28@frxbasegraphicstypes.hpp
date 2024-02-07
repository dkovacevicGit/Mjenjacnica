// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxBaseGraphicsTypes.pas' rev: 35.00 (Windows)

#ifndef FrxbasegraphicstypesHPP
#define FrxbasegraphicstypesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxbasegraphicstypes
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IfrxCachedGraphic;
typedef System::DelphiInterface<IfrxCachedGraphic> _di_IfrxCachedGraphic;
__interface DELPHIINTERFACE IfrxPictureCache;
typedef System::DelphiInterface<IfrxPictureCache> _di_IfrxPictureCache;
__interface DELPHIINTERFACE IfrxCachedView;
typedef System::DelphiInterface<IfrxCachedView> _di_IfrxCachedView;
class DELPHICLASS TfrxPictureConverterOptions;
class DELPHICLASS TfrxPictureCacheOptions;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TfrxGraphicQuality : unsigned char { gqDefault, gqFast, gqHiQuality, gqPrint };

enum DECLSPEC_DENUM TfrxGraphicDrawProp : unsigned char { fgdAutoSize, fgdCenter, fgdKeepAspectRatio, fgdStretch, fgdTransparent, fgdClip, fgdDefaultMaskColor, fgdHiQuality };

typedef System::Set<TfrxGraphicDrawProp, TfrxGraphicDrawProp::fgdAutoSize, TfrxGraphicDrawProp::fgdHiQuality> TfrxGraphicDrawProps;

enum DECLSPEC_DENUM TfrxThumbnailBuildType : unsigned char { tbtNone, tbtOriginal, tbtAtPrepare, tbtAtSave, tbtAtPreview };

typedef System::Int8 TfrxPercentage;

enum DECLSPEC_DENUM TfrxCachedGraphicType : unsigned char { cgNone, cgOriginal, cgThumbnail };

typedef Vcl::Graphics::TGraphic* __fastcall (__closure *TfrxLoadPictureToMethod)(Vcl::Graphics::TPicture* APicture, Vcl::Graphics::TGraphic* aGraphic, int ImageIndex);

__interface  INTERFACE_UUID("{13DA72E5-E8D1-4DEA-931A-8A729CB877E1}") IfrxCachedGraphic  : public System::IInterface 
{
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* Canvas, int X, int Y, int X1, int Y1) = 0 ;
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(TfrxCachedGraphicType CacheType) = 0 ;
	virtual TfrxCachedGraphicType __fastcall GetCacheType() = 0 ;
	virtual void __fastcall SetCacheType(TfrxCachedGraphicType CacheType) = 0 ;
	virtual System::Types::TSize __fastcall GetOriginalSize() = 0 ;
};

__interface  INTERFACE_UUID("{06FD066C-726D-4BC0-811D-94150807E798}") IfrxPictureCache  : public System::IInterface 
{
	virtual int __fastcall AddPicture(Vcl::Graphics::TGraphic* aGraphic) = 0 ;
	virtual void __fastcall GetGraphic(Vcl::Graphics::TGraphic* aGraphic, int ImageIndex) = 0 /* overload */;
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(int ImageIndex) = 0 /* overload */;
	virtual void __fastcall GetPicture(Vcl::Graphics::TPicture* APicture, int ImageIndex) = 0 ;
	virtual _di_IfrxCachedGraphic __fastcall GetCachedBitmap(TfrxCachedGraphicType CacheType, int ImageIndex) = 0 ;
	virtual bool __fastcall IsAutoRefMode() = 0 ;
	virtual System::Types::TSize __fastcall GetSize(const TfrxCachedGraphicType CacheType, const int ImageIndex) = 0 ;
};

__interface  INTERFACE_UUID("{1E87267F-436A-4BFF-A6E9-0D03DD69F56C}") IfrxCachedView  : public System::IInterface 
{
	virtual void __fastcall SetCachedGraphic(const _di_IfrxPictureCache PictureCache) = 0 ;
	virtual void __fastcall GetCachedGraphic(TfrxCachedGraphicType ACacheType, const _di_IfrxPictureCache PictureCache) = 0 ;
	virtual bool __fastcall IsUpdateRequired(TfrxCachedGraphicType NewCacheType) = 0 ;
	virtual void __fastcall ReleaseCachedGraphic() = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxPictureConverterOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TfrxPercentage FReducePercent;
	int FMinHeight;
	int FMaxWidth;
	int FMinWidth;
	int FMaxHeight;
	void __fastcall SetMinHeight(const int Value);
	void __fastcall SetMinWidth(const int Value);
	
public:
	__fastcall TfrxPictureConverterOptions();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=32};
	__property int MaxWidth = {read=FMaxWidth, write=FMaxWidth, default=2147483647};
	__property int MinHeight = {read=FMinHeight, write=SetMinHeight, default=32};
	__property int MaxHeight = {read=FMaxHeight, write=FMaxHeight, default=2147483647};
	__property TfrxPercentage ReducePercent = {read=FReducePercent, write=FReducePercent, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TfrxPictureConverterOptions() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxPictureCacheOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TfrxThumbnailBuildType FCachedImagesBuildType;
	TfrxPictureConverterOptions* FThumbnailQualityReducer;
	TfrxPictureConverterOptions* FOriginalQualityReducer;
	void __fastcall SetOriginalQualityReducer(TfrxPictureConverterOptions* const Value);
	void __fastcall SetThumbnailQualityReducer(TfrxPictureConverterOptions* const Value);
	
public:
	__fastcall TfrxPictureCacheOptions();
	__fastcall virtual ~TfrxPictureCacheOptions();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TfrxPercentage __fastcall GetPercentFor(const TfrxCachedGraphicType CacheType, const int Width, const int Height);
	
__published:
	__property TfrxPictureConverterOptions* OriginalQualityReducer = {read=FOriginalQualityReducer, write=SetOriginalQualityReducer};
	__property TfrxThumbnailBuildType CachedImagesBuildType = {read=FCachedImagesBuildType, write=FCachedImagesBuildType, default=0};
	__property TfrxPictureConverterOptions* ThumbnailQualityReducer = {read=FThumbnailQualityReducer, write=SetThumbnailQualityReducer};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxbasegraphicstypes */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXBASEGRAPHICSTYPES)
using namespace Frxbasegraphicstypes;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxbasegraphicstypesHPP
