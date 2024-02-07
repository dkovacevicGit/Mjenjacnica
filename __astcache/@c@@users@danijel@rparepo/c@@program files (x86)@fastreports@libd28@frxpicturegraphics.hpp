// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxPictureGraphics.pas' rev: 35.00 (Windows)

#ifndef FrxpicturegraphicsHPP
#define FrxpicturegraphicsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Variants.hpp>
#include <frxBaseGraphicsTypes.hpp>
#include <System.Types.hpp>
#include <System.SyncObjs.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxpicturegraphics
{
//-- forward type declarations -----------------------------------------------
struct TfrxGraphicProps;
struct TfrxDrawGraphicExt;
class DELPHICLASS EAbstractGraphicFormatException;
class DELPHICLASS TfrxCustomGraphicFormat;
class DELPHICLASS TfrxFullAbilitiesGraphicFormat;
class DELPHICLASS TfrxCustomVectorGraphicFormat;
class DELPHICLASS TfrxGraphicCanvasHelper;
class DELPHICLASS TfrxBitmapCanvasHelper;
class DELPHICLASS TfrxBitmapGraphicFormat;
class DELPHICLASS TfrxDefaultGraphicFormat;
class DELPHICLASS TfrxGraphicFormats;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TfrxGraphicFormatCap : unsigned char { gcSaveTo, gcLoadFrom, gcGetCanvas, gcDraw, gcConvert, gcConvertToBitmap };

enum DECLSPEC_DENUM TfrxGraphicStringType : unsigned char { stClassName, stName, stExtension, stMime };

typedef System::Set<TfrxGraphicFormatCap, TfrxGraphicFormatCap::gcSaveTo, TfrxGraphicFormatCap::gcConvertToBitmap> TfrxGraphicFormatCaps;

typedef System::TMetaClass* TfrxGraphicCanvasHelperClass;

typedef System::TMetaClass* TfrxCanvasClass;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TfrxGraphicProps
{
public:
	bool HasAlpha;
	bool Transparent;
	System::Uitypes::TColor TransparentColor;
	int Quality;
	Vcl::Graphics::TPixelFormat PixelFormat;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TfrxDrawGraphicExt
{
public:
	Frxbasegraphicstypes::TfrxGraphicDrawProps DrawProps;
	System::Uitypes::TColor TransparentColor;
	Frxbasegraphicstypes::TfrxGraphicQuality Quality;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION EAbstractGraphicFormatException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EAbstractGraphicFormatException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EAbstractGraphicFormatException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EAbstractGraphicFormatException(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EAbstractGraphicFormatException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EAbstractGraphicFormatException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EAbstractGraphicFormatException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EAbstractGraphicFormatException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EAbstractGraphicFormatException(const System::UnicodeString Msg, const System::TVarRec *Args, const int Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EAbstractGraphicFormatException(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EAbstractGraphicFormatException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EAbstractGraphicFormatException(System::PResStringRec ResStringRec, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EAbstractGraphicFormatException(NativeUInt Ident, const System::TVarRec *Args, const int Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EAbstractGraphicFormatException() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxCustomGraphicFormat : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual TfrxGraphicCanvasHelperClass __fastcall GetCanvasHelperClass();
	__classmethod virtual void __fastcall DoDrawExt(const TfrxDrawGraphicExt &GProps, Vcl::Graphics::TCanvas* Canvas, Vcl::Graphics::TGraphic* AGraphic, const System::Types::TRect &Area, double ScaleX, double ScaleY);
	
public:
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall ConvertFrom(Vcl::Graphics::TGraphic* Graphic, Vcl::Graphics::TPixelFormat DestPixelFormat, int DestQuality = 0x64);
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall ConvertToBitmap(Vcl::Graphics::TGraphic* Graphic, Vcl::Graphics::TPixelFormat DestPixelFormat);
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall ConvertToMaskedBitmap(Vcl::Graphics::TGraphic* Graphic, Vcl::Graphics::TPixelFormat DestPixelFormat, System::Uitypes::TColor TransparentMask);
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall CreateNew(int Width, int Height, Vcl::Graphics::TPixelFormat PixelFormat, bool Transparent, int Quality = 0x64);
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall CreateFromStream(System::Classes::TStream* const Stream);
	__classmethod virtual TfrxGraphicCanvasHelper* __fastcall CreateCanvasHelper(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual void __fastcall ScaleGraphic(Vcl::Graphics::TGraphic* Graphic, int NewWidth, int NewHeight);
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall ScaleGraphicToNew(Vcl::Graphics::TGraphic* Graphic, int NewWidth, int NewHeight);
	__classmethod virtual void __fastcall Draw(Vcl::Graphics::TCanvas* Canvas, Vcl::Graphics::TGraphic* AGraphic, const System::Types::TRect &Area, Frxbasegraphicstypes::TfrxGraphicQuality Quality);
	__classmethod virtual void __fastcall DrawTransparent(Vcl::Graphics::TCanvas* Canvas, Vcl::Graphics::TGraphic* AGraphic, const System::Types::TRect &Area, System::Uitypes::TColor MaskColor, Frxbasegraphicstypes::TfrxGraphicQuality Quality);
	__classmethod virtual void __fastcall DrawExt(const TfrxDrawGraphicExt &GProps, Vcl::Graphics::TCanvas* Canvas, Vcl::Graphics::TGraphic* AGraphic, const System::Types::TRect &Area, double ScaleX, double ScaleY);
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicMime();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicName();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicExt();
	__classmethod virtual int __fastcall GetGraphicConst();
	__classmethod virtual TfrxGraphicProps __fastcall GetGraphicProps(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual TfrxGraphicFormatCaps __fastcall GetFormatCapabilities();
	__classmethod virtual Vcl::Graphics::TBitmap* __fastcall GetAlphaBitmap(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual Vcl::Graphics::TBitmap* __fastcall GetMaskBitmap(Vcl::Graphics::TGraphic* Graphic, System::Uitypes::TColor TransparentMask);
	__classmethod virtual bool __fastcall HasAlphaChanel(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual bool __fastcall HasMaskColor(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual bool __fastcall IsTransparent(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual bool __fastcall IsSupportedFormat(System::Classes::TStream* const Stream);
	__classmethod virtual bool __fastcall IsVector();
	__classmethod virtual bool __fastcall LoadFromStream(Vcl::Graphics::TPicture* const aPictire, System::Classes::TStream* Stream);
	__classmethod virtual void __fastcall SetTransparent(Vcl::Graphics::TGraphic* Graphic, bool Transparent);
	__classmethod virtual void __fastcall SetTransparentColor(Vcl::Graphics::TGraphic* Graphic, System::Uitypes::TColor Color);
	__classmethod virtual System::Uitypes::TColor __fastcall GetTransparentColor(Vcl::Graphics::TGraphic* Graphic);
public:
	/* TObject.Create */ inline __fastcall TfrxCustomGraphicFormat() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxCustomGraphicFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxFullAbilitiesGraphicFormat : public TfrxCustomGraphicFormat
{
	typedef TfrxCustomGraphicFormat inherited;
	
public:
	__classmethod virtual TfrxGraphicFormatCaps __fastcall GetFormatCapabilities();
public:
	/* TObject.Create */ inline __fastcall TfrxFullAbilitiesGraphicFormat() : TfrxCustomGraphicFormat() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxFullAbilitiesGraphicFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxCustomVectorGraphicFormat : public TfrxFullAbilitiesGraphicFormat
{
	typedef TfrxFullAbilitiesGraphicFormat inherited;
	
public:
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall ConvertToBitmap(Vcl::Graphics::TGraphic* Graphic, Vcl::Graphics::TPixelFormat DestPixelFormat);
	__classmethod virtual bool __fastcall HasAlphaChanel(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual Vcl::Graphics::TBitmap* __fastcall GetAlphaBitmap(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual bool __fastcall IsVector();
public:
	/* TObject.Create */ inline __fastcall TfrxCustomVectorGraphicFormat() : TfrxFullAbilitiesGraphicFormat() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxCustomVectorGraphicFormat() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TfrxCustomGraphicFormatClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxGraphicCanvasHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TfrxCustomGraphicFormatClass FFormatClass;
	
protected:
	Vcl::Graphics::TGraphic* FGraphic;
	virtual Vcl::Graphics::TCanvas* __fastcall GetCanvas();
	virtual Vcl::Graphics::TGraphic* __fastcall GetCanvasGraphic();
	
public:
	__fastcall virtual TfrxGraphicCanvasHelper(Vcl::Graphics::TGraphic* Graphic, TfrxCustomGraphicFormatClass FormatClass);
	__fastcall virtual ~TfrxGraphicCanvasHelper();
	virtual void __fastcall ReleaseCanvas();
	__property Vcl::Graphics::TCanvas* Canvas = {read=GetCanvas};
	__property Vcl::Graphics::TGraphic* CanvasGraphic = {read=GetCanvasGraphic};
	__property TfrxCustomGraphicFormatClass GraphicHelper = {read=FFormatClass};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxBitmapCanvasHelper : public TfrxGraphicCanvasHelper
{
	typedef TfrxGraphicCanvasHelper inherited;
	
protected:
	virtual Vcl::Graphics::TCanvas* __fastcall GetCanvas();
public:
	/* TfrxGraphicCanvasHelper.Create */ inline __fastcall virtual TfrxBitmapCanvasHelper(Vcl::Graphics::TGraphic* Graphic, TfrxCustomGraphicFormatClass FormatClass) : TfrxGraphicCanvasHelper(Graphic, FormatClass) { }
	/* TfrxGraphicCanvasHelper.Destroy */ inline __fastcall virtual ~TfrxBitmapCanvasHelper() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxBitmapGraphicFormat : public TfrxFullAbilitiesGraphicFormat
{
	typedef TfrxFullAbilitiesGraphicFormat inherited;
	
protected:
	__classmethod virtual TfrxGraphicCanvasHelperClass __fastcall GetCanvasHelperClass();
	__classmethod virtual void __fastcall DoDrawExt(const TfrxDrawGraphicExt &GProps, Vcl::Graphics::TCanvas* Canvas, Vcl::Graphics::TGraphic* AGraphic, const System::Types::TRect &Area, double ScaleX, double ScaleY);
	
public:
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall ConvertFrom(Vcl::Graphics::TGraphic* Graphic, Vcl::Graphics::TPixelFormat DestPixelFormat, int DestQuality = 0x64);
	__classmethod virtual Vcl::Graphics::TGraphic* __fastcall CreateNew(int Width, int Height, Vcl::Graphics::TPixelFormat PixelFormat, bool Transparent, int Quality = 0x64);
	__classmethod virtual bool __fastcall HasAlphaChanel(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicMime();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicName();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicExt();
	__classmethod virtual int __fastcall GetGraphicConst();
	__classmethod virtual TfrxGraphicProps __fastcall GetGraphicProps(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual bool __fastcall IsSupportedFormat(System::Classes::TStream* const Stream);
	__classmethod virtual void __fastcall SetTransparent(Vcl::Graphics::TGraphic* Graphic, bool Transparent);
	__classmethod virtual void __fastcall SetTransparentColor(Vcl::Graphics::TGraphic* Graphic, System::Uitypes::TColor Color);
	__classmethod virtual System::Uitypes::TColor __fastcall GetTransparentColor(Vcl::Graphics::TGraphic* Graphic);
	__classmethod virtual Vcl::Graphics::TBitmap* __fastcall GetAlphaBitmap(Vcl::Graphics::TGraphic* Graphic);
public:
	/* TObject.Create */ inline __fastcall TfrxBitmapGraphicFormat() : TfrxFullAbilitiesGraphicFormat() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxBitmapGraphicFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxDefaultGraphicFormat : public TfrxCustomGraphicFormat
{
	typedef TfrxCustomGraphicFormat inherited;
	
public:
	__classmethod virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicMime();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicName();
	__classmethod virtual System::UnicodeString __fastcall GetGraphicExt();
	__classmethod virtual int __fastcall GetGraphicConst();
	__classmethod virtual TfrxGraphicFormatCaps __fastcall GetFormatCapabilities();
public:
	/* TObject.Create */ inline __fastcall TfrxDefaultGraphicFormat() : TfrxCustomGraphicFormat() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxDefaultGraphicFormat() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxGraphicFormats : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TfrxCustomGraphicFormatClass operator[](int Index) { return this->Items[Index]; }
	
private:
	System::Syncobjs::TCriticalSection* FGFormatsCS;
	TfrxCustomGraphicFormatClass __fastcall GetItem(int Index);
	void __fastcall PutItem(int Index, const TfrxCustomGraphicFormatClass Value);
	bool __fastcall IsCapsSupported(TfrxGraphicFormatCaps ReqCaps, TfrxGraphicFormatCaps SourceCaps);
	
public:
	__fastcall TfrxGraphicFormats();
	__fastcall virtual ~TfrxGraphicFormats();
	System::UnicodeString __fastcall BuildFormatsString(TfrxGraphicStringType stType, const System::UnicodeString Separator = L" ", TfrxGraphicFormatCaps RequiredCaps = TfrxGraphicFormatCaps() );
	System::Classes::TStringList* __fastcall BuildFormatsStrings(TfrxGraphicStringType stType, TfrxGraphicFormatCaps RequiredCaps = TfrxGraphicFormatCaps() );
	Vcl::Graphics::TGraphic* __fastcall Convert(Vcl::Graphics::TGraphic* SourceGraphic, const System::UnicodeString DestFormat, Vcl::Graphics::TPixelFormat DestPixelFormat, int DestQuality = 0x64);
	Vcl::Graphics::TGraphic* __fastcall ConvertToBitmap(Vcl::Graphics::TGraphic* SourceGraphic, Vcl::Graphics::TPixelFormat DestPixelFormat);
	void __fastcall Draw(Vcl::Graphics::TCanvas* Canvas, Vcl::Graphics::TGraphic* AGraphic, const System::Types::TRect &Area, Frxbasegraphicstypes::TfrxGraphicQuality Quality);
	void __fastcall DrawExt(const TfrxDrawGraphicExt &GProps, Vcl::Graphics::TCanvas* Canvas, Vcl::Graphics::TGraphic* AGraphic, const System::Types::TRect &Area, double ScaleX, double ScaleY);
	TfrxCustomGraphicFormatClass __fastcall FindByGraphic(Vcl::Graphics::TGraphicClass GraphicClass, TfrxGraphicFormatCaps RequiredCaps = TfrxGraphicFormatCaps() );
	TfrxCustomGraphicFormatClass __fastcall FindByExt(const System::UnicodeString Ext, TfrxGraphicFormatCaps RequiredCaps = TfrxGraphicFormatCaps() );
	TfrxCustomGraphicFormatClass __fastcall FindByFormat(System::Classes::TStream* Stream, TfrxGraphicFormatCaps RequiredCaps = TfrxGraphicFormatCaps() );
	TfrxCustomGraphicFormatClass __fastcall FindByConst(const int Index, TfrxGraphicFormatCaps RequiredCaps = TfrxGraphicFormatCaps() );
	TfrxCustomGraphicFormatClass __fastcall FindByName(const System::UnicodeString Name, TfrxGraphicFormatCaps RequiredCaps = TfrxGraphicFormatCaps() );
	TfrxCustomGraphicFormatClass __fastcall GetDefault();
	bool __fastcall HasAlphaChanel(Vcl::Graphics::TGraphic* Graphic);
	bool __fastcall IsTransparent(Vcl::Graphics::TGraphic* Graphic);
	bool __fastcall LoadFromStream(Vcl::Graphics::TPicture* const aPictire, System::Classes::TStream* Stream)/* overload */;
	Vcl::Graphics::TGraphic* __fastcall LoadFromStream(System::Classes::TStream* Stream)/* overload */;
	void __fastcall ScaleGraphic(Vcl::Graphics::TGraphic* Graphic, int NewWidth, int NewHeight);
	Vcl::Graphics::TGraphic* __fastcall ScaleGraphicToNew(Vcl::Graphics::TGraphic* Graphic, int NewWidth, int NewHeight);
	void __fastcall RegisterFormat(TfrxCustomGraphicFormatClass AClass);
	void __fastcall UnregisterFormat(TfrxCustomGraphicFormatClass AClass);
	__property TfrxCustomGraphicFormatClass Items[int Index] = {read=GetItem, write=PutItem/*, default*/};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 frxBitmapFileFormat = System::Int8(0x0);
extern DELPHI_PACKAGE TfrxCanvasClass frxDefaultMetaCanvasClass;
extern DELPHI_PACKAGE TfrxGraphicFormats* __fastcall GetGraphicFormats(void);
}	/* namespace Frxpicturegraphics */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXPICTUREGRAPHICS)
using namespace Frxpicturegraphics;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxpicturegraphicsHPP
