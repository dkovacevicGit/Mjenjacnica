// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportPDFHelpers.pas' rev: 35.00 (Windows)

#ifndef FrxexportpdfhelpersHPP
#define FrxexportpdfhelpersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <frxRC4.hpp>
#include <frxTrueTypeCollection.hpp>
#include <System.Contnrs.hpp>
#include <frxBaseGraphicsTypes.hpp>
#include <frxPictureGraphics.hpp>
#include <frxEMFAbstractExport.hpp>
#include <frxClass.hpp>
#include <frxEMFFormat.hpp>
#include <frxUtils.hpp>
#include <System.AnsiStrings.hpp>
#include <System.UITypes.hpp>
#include <frxAnaliticGeometry.hpp>
#include <frxExportHelpers.hpp>
#include <frxHelpers.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexportpdfhelpers
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxPDFFont;
class DELPHICLASS TfrxPDFXObjectArray;
struct TCrossReferenceSubsection;
class DELPHICLASS TReferenceArray;
class DELPHICLASS TPageByPageReferenceArray;
class DELPHICLASS TCrossReferenceSection;
class DELPHICLASS TPDFGLobalFonts;
class DELPHICLASS TPDFObjectsHelper;
struct TViewSizes;
struct TRGBAWord;
class DELPHICLASS TInt64List;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxPDFFont : public Frxexporthelpers::TfrxExportFont
{
	typedef Frxexporthelpers::TfrxExportFont inherited;
	
private:
	System::Uitypes::TColor FColor;
	System::AnsiString FFontName;
	System::Extended FSize;
	
protected:
	bool FSaved;
	void __fastcall FillOutlineTextMetrix();
	
public:
	System::AnsiString Name;
	int Reference;
	__fastcall TfrxPDFFont(Vcl::Graphics::TFont* Font);
	void __fastcall Save(int AReference);
	void __fastcall PackTTFFont();
	System::AnsiString __fastcall GetFontName();
	System::Extended __fastcall SpaceAdjustment(const Frxexporthelpers::TRemapedString &RS, System::Extended TextWidth, System::Extended FontSize);
	double __fastcall FontHeightToPointSizeFactor();
	void __fastcall Update(TfrxPDFFont* const SourcePDFFont, Vcl::Graphics::TFont* const SourceFont);
	__property System::AnsiString FontName = {read=FFontName, write=FFontName};
	__property System::Extended Size = {read=FSize, write=FSize};
	__property System::Uitypes::TColor Color = {read=FColor, write=FColor, nodefault};
	__property bool Saved = {read=FSaved, nodefault};
public:
	/* TfrxExportFont.Destroy */ inline __fastcall virtual ~TfrxPDFFont() { }
	
};


typedef System::StaticArray<System::Byte, 16> TfrxPDFXObjectHash;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxPDFXObjectArray : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<int> _TfrxPDFXObjectArray__1;
	
	typedef System::DynamicArray<TfrxPDFXObjectHash> _TfrxPDFXObjectArray__2;
	
	
private:
	int FCount;
	_TfrxPDFXObjectArray__1 FObjId;
	_TfrxPDFXObjectArray__2 FHash;
	int __fastcall GetId(int Index);
	
protected:
	void __fastcall SureIndex(int Index);
	
public:
	__fastcall TfrxPDFXObjectArray();
	int __fastcall Add(int AId, const TfrxPDFXObjectHash &Hash);
	void __fastcall Clear();
	int __fastcall Find(const TfrxPDFXObjectHash &Hash);
	__property int Id[int Index] = {read=GetId};
	__property int Count = {read=FCount, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxPDFXObjectArray() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TCrossReferenceSubsection
{
public:
	bool Start;
	int Length;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TReferenceArray : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<int> _TReferenceArray__1;
	
	
private:
	int FCount;
	_TReferenceArray__1 FData;
	System::UnicodeString __fastcall GetRef(int Index);
	int __fastcall GetNo(int Index);
	
public:
	__fastcall TReferenceArray();
	void __fastcall Add(int ObjNo);
	void __fastcall WriteToStream(System::Classes::TStream* Stream, System::UnicodeString Caption);
	void __fastcall Clear();
	__property int Count = {read=FCount, nodefault};
	__property System::UnicodeString Ref[int Index] = {read=GetRef};
	__property int No[int Index] = {read=GetNo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TReferenceArray() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPageByPageReferenceArray : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TReferenceArray*> _TPageByPageReferenceArray__1;
	
	typedef System::DynamicArray<int> _TPageByPageReferenceArray__2;
	
	
public:
	TReferenceArray* operator[](int Index) { return this->Data[Index]; }
	
private:
	_TPageByPageReferenceArray__1 FData;
	_TPageByPageReferenceArray__2 FContents;
	TReferenceArray* __fastcall GetData(int Index);
	void __fastcall SetData(int Index, TReferenceArray* const Value);
	int __fastcall GetContents(int Index);
	void __fastcall SetContents(int Index, const int Value);
	
protected:
	void __fastcall SureIndex(int Index);
	
public:
	__fastcall TPageByPageReferenceArray();
	__fastcall virtual ~TPageByPageReferenceArray();
	__property TReferenceArray* Data[int Index] = {read=GetData, write=SetData/*, default*/};
	__property int Contents[int Index] = {read=GetContents, write=SetContents};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TCrossReferenceSection : public Frxhelpers::TOwnObjList
{
	typedef Frxhelpers::TOwnObjList inherited;
	
private:
	bool FSingleCharacterEOL;
	int FSectionOffset;
	int FNextId;
	
protected:
	int __fastcall IndexOfId(int Id);
	
public:
	__fastcall TCrossReferenceSection(bool ASingleCharacterEOL);
	virtual void __fastcall Clear();
	void __fastcall Init();
	void __fastcall AddId(int Id, int Offset = 0x0);
	int __fastcall AddNext(int Offset = 0x0);
	void __fastcall SetOffset(int Id, int Offset);
	void __fastcall PrepareToOut();
	bool __fastcall IsSubsection(int Index, /* out */ System::UnicodeString &SubsectionStr);
	System::UnicodeString __fastcall OutLine(int Index);
	__property int NextId = {read=FNextId, write=FNextId, nodefault};
	__property int SectionOffset = {write=FSectionOffset, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TCrossReferenceSection() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPDFGLobalFonts : public Frxhelpers::TOwnObjList
{
	typedef Frxhelpers::TOwnObjList inherited;
	
public:
	TfrxPDFFont* operator[](int Index) { return this->Items[Index]; }
	
protected:
	HIDESBASE TfrxPDFFont* __fastcall Get(int Index);
	
public:
	int __fastcall AddFont(Vcl::Graphics::TFont* const Font, const System::UnicodeString OSFontName);
	int __fastcall IndexOfFont(System::UnicodeString Name, System::Uitypes::TFontStyles Style);
	int __fastcall IndexByReference(int No);
	__property TfrxPDFFont* Items[int Index] = {read=Get/*, default*/};
public:
	/* TOwnObjList.Create */ inline __fastcall TPDFGLobalFonts(bool AOwnsObjects) : Frxhelpers::TOwnObjList(AOwnsObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TPDFGLobalFonts() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPDFObjectsHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TPDFGLobalFonts* FFonts;
	System::Classes::TList* FAcroFonts;
	System::Classes::TList* FBBoxFonts;
	TReferenceArray* FPageFonts;
	TCrossReferenceSection* FCRS;
	System::Classes::TStream* FpdfStream;
	bool FProtection;
	System::AnsiString FEncKey;
	bool FEmbedded;
	int FQuality;
	TfrxPDFXObjectArray* FXObjects;
	TReferenceArray* FPageXObjects;
	bool FIsBBoxReleative;
	int FLastRequestedXRef;
	Frxpicturegraphics::TfrxCustomGraphicFormatClass FGraphicHelper;
	TfrxPDFFont* __fastcall GetAcroFonts(int Index);
	int __fastcall GetAcroFontsCount();
	TfrxPDFFont* __fastcall GetBBoxFonts(int Index);
	int __fastcall GetBBoxFontsCount();
	int __fastcall GetLastObjectXRefID();
	
protected:
	System::UnicodeString __fastcall GetOSFontName(Vcl::Graphics::TFont* const Font);
	bool __fastcall IsFontNameAndStyle(Vcl::Graphics::TFont* const Font, System::UnicodeString Name, System::Uitypes::TFontStyles Style);
	TfrxPDFFont* __fastcall GetGlobalFont(Vcl::Graphics::TFont* const Font, const System::UnicodeString OSFontName);
	
public:
	__fastcall TPDFObjectsHelper();
	__fastcall virtual ~TPDFObjectsHelper();
	void __fastcall Clear();
	TfrxPDFFont* __fastcall GetAcroFont(Vcl::Graphics::TFont* const Font);
	int __fastcall GetObjFontNumber(Vcl::Graphics::TFont* const Font);
	void __fastcall OutPageFonts();
	int __fastcall FindXObject(const TfrxPDFXObjectHash &Hash);
	int __fastcall OutXObjectImage(const TfrxPDFXObjectHash &XObjectHash, Vcl::Graphics::TGraphic* Image, System::Classes::TStream* XObjectStream, bool IsTransparent = false, int MaskId = 0x0);
	int __fastcall OutTransparentGraphic(Vcl::Graphics::TGraphic* Graphic, const System::Types::TSize &Size);
	int __fastcall UpdateXRef();
	void __fastcall StartBBox();
	void __fastcall EndBBox();
	__property TfrxPDFFont* AcroFonts[int Index] = {read=GetAcroFonts};
	__property int AcroFontsCount = {read=GetAcroFontsCount, nodefault};
	__property TfrxPDFFont* BBoxFonts[int Index] = {read=GetBBoxFonts};
	__property int BBoxFontsCount = {read=GetBBoxFontsCount, nodefault};
	__property TPDFGLobalFonts* Fonts = {read=FFonts, write=FFonts};
	__property TfrxPDFXObjectArray* XObjects = {read=FXObjects, write=FXObjects};
	__property TReferenceArray* PageXObjects = {read=FPageXObjects, write=FPageXObjects};
	__property TReferenceArray* PageFonts = {read=FPageFonts, write=FPageFonts};
	__property System::Classes::TStream* pdfStream = {write=FpdfStream};
	__property TCrossReferenceSection* CRS = {read=FCRS};
	__property int LastObjectXRefID = {read=GetLastObjectXRefID, nodefault};
	__property bool Protection = {write=FProtection, nodefault};
	__property System::AnsiString EncKey = {write=FEncKey};
	__property bool EmbeddedFonts = {read=FEmbedded, write=FEmbedded, default=0};
	__property bool IsBBox = {read=FIsBBoxReleative, nodefault};
	__property int Quality = {read=FQuality, write=FQuality, nodefault};
};

#pragma pack(pop)

typedef System::DynamicArray<System::Byte> TMaskArray;

typedef System::Set<Frxclass::TfrxShapeKind, Frxclass::TfrxShapeKind::skRectangle, Frxclass::TfrxShapeKind::skDiagonal2> TfrxShapeKindSet;

struct DECLSPEC_DRECORD TViewSizes
{
public:
	System::Extended l;
	System::Extended t;
	System::Extended w;
	System::Extended h;
	System::Extended r;
	System::Extended b;
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TRGBAWord
{
public:
	System::Byte Blue;
	System::Byte Green;
	System::Byte Red;
	System::Byte Alpha;
};
#pragma pack(pop)


typedef System::StaticArray<TRGBAWord, 4096> TRGBAWordArray;

typedef TRGBAWordArray *PRGBAWord;

enum DECLSPEC_DENUM TPDFStandard : unsigned char { psNone, psPDFA_1a, psPDFA_1b, psPDFA_2a, psPDFA_2b, psPDFA_3a, psPDFA_3b };

enum DECLSPEC_DENUM TPDFVersion : unsigned char { pv14, pv15, pv16, pv17 };

typedef System::StaticArray<System::UnicodeString, 7> Frxexportpdfhelpers__8;

typedef System::StaticArray<System::UnicodeString, 7> Frxexportpdfhelpers__9;

typedef System::StaticArray<System::UnicodeString, 7> Frxexportpdfhelpers__01;

typedef System::StaticArray<System::UnicodeString, 4> Frxexportpdfhelpers__11;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TInt64List : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__int64 operator[](int Index) { return this->Items[Index]; }
	
private:
	__int64 __fastcall GetItem(int Index);
	void __fastcall Setitem(int Index, const __int64 Value);
	int __fastcall GetCount();
	
protected:
	System::Contnrs::TObjectList* FObjectList;
	
public:
	__fastcall TInt64List();
	__fastcall virtual ~TInt64List();
	void __fastcall Add(__int64 Value);
	void __fastcall Clear();
	__property __int64 Items[int Index] = {read=GetItem, write=Setitem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define PDF_DIVIDER  (7.500000E-01)
extern DELPHI_PACKAGE Frxexportpdfhelpers__8 PDFStandardName;
extern DELPHI_PACKAGE Frxexportpdfhelpers__9 PDFPartName;
extern DELPHI_PACKAGE Frxexportpdfhelpers__01 PDFConformanceName;
extern DELPHI_PACKAGE Frxexportpdfhelpers__11 PDFVersionName;
static const System::Extended tpPt = 3.527778E-03;
#define UnderlineShift  (-1.200000E-01)
#define StrikeOutShift  (2.800000E-01)
#define UnderlineWidth  (8.000000E-02)
static const System::Extended StrikeOutWidth = 5.656908E-02;
extern DELPHI_PACKAGE void __fastcall DisableTpPtCorrection(void);
extern DELPHI_PACKAGE void __fastcall EnableTpPtCorrection(void);
extern DELPHI_PACKAGE void __fastcall StretchFont(System::Uitypes::TFontName FontName, int FontSize, double Factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall StretchFont(System::Uitypes::TFontName FontName, float Factor)/* overload */;
extern DELPHI_PACKAGE void __fastcall ClearStretchedFont(System::Uitypes::TFontName FontName);
extern DELPHI_PACKAGE System::Extended __fastcall PDFFontSize(Vcl::Graphics::TFont* Font);
extern DELPHI_PACKAGE System::Extended __fastcall EMFPDFFontSize(Vcl::Graphics::TFont* Font);
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall CreateBitmap(Vcl::Graphics::TPixelFormat PixelFormat, int Width, int Height)/* overload */;
extern DELPHI_PACKAGE Vcl::Graphics::TBitmap* __fastcall CreateBitmap(Vcl::Graphics::TPixelFormat PixelFormat, Vcl::Graphics::TBitmap* SizeBitmap)/* overload */;
extern DELPHI_PACKAGE int __fastcall BitmapPixelSize(Vcl::Graphics::TBitmap* Bitmap);
extern DELPHI_PACKAGE void __fastcall SaveMask(System::Classes::TStream* pdf, System::Classes::TStream* XObjectStream, TMaskArray MaskBytes, TPDFObjectsHelper* FPOH, Vcl::Graphics::TBitmap* TempBitmap, bool FProtection, System::AnsiString FEncKey, /* out */ TfrxPDFXObjectHash &XObjectHash, /* out */ int &XMaskId, /* out */ int &PicIndex);
extern DELPHI_PACKAGE void __fastcall CreateMask(Vcl::Graphics::TBitmap* Bitmap, TMaskArray &Mask);
extern DELPHI_PACKAGE bool __fastcall IsVersionByStandard(TPDFStandard ps, TPDFVersion &pv);
extern DELPHI_PACKAGE bool __fastcall IsPDFA_1(TPDFStandard ps);
extern DELPHI_PACKAGE bool __fastcall IsPDFA(TPDFStandard ps);
extern DELPHI_PACKAGE TPDFVersion __fastcall PDFVersionByName(System::UnicodeString VersionName);
extern DELPHI_PACKAGE TPDFStandard __fastcall PDFStandardByName(System::UnicodeString StandardName);
extern DELPHI_PACKAGE TViewSizes __fastcall ShadowlessSizes(Frxclass::TfrxView* Obj);
extern DELPHI_PACKAGE bool __fastcall Is2DShape(Frxclass::TfrxView* Obj);
extern DELPHI_PACKAGE bool __fastcall IsShape(Frxclass::TfrxView* Obj, TfrxShapeKindSet ShapeKindSet);
extern DELPHI_PACKAGE void __fastcall Write(System::Classes::TStream* Stream, const System::AnsiString S)/* overload */;
extern DELPHI_PACKAGE void __fastcall WriteLn(System::Classes::TStream* Stream, const System::AnsiString S)/* overload */;
extern DELPHI_PACKAGE void __fastcall WriteLn(System::Classes::TStream* Stream, const System::UnicodeString S)/* overload */;
extern DELPHI_PACKAGE void __fastcall Write(System::Classes::TStream* Stream, const System::UnicodeString S)/* overload */;
extern DELPHI_PACKAGE void __fastcall GetStreamHash(/* out */ TfrxPDFXObjectHash &Hash, System::Classes::TStream* S);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ObjNumber(int FNumber);
extern DELPHI_PACKAGE System::UnicodeString __fastcall ObjNumberRef(int FNumber);
extern DELPHI_PACKAGE System::UnicodeString __fastcall PrepXRefPos(int Index);
extern DELPHI_PACKAGE System::AnsiString __fastcall CryptStream(System::Classes::TStream* Source, System::Classes::TStream* Target, System::AnsiString Key, int id);
extern DELPHI_PACKAGE void __fastcall AddStyleSimulation(System::UnicodeString FontName, System::Uitypes::TFontStyles FontStyles);
extern DELPHI_PACKAGE void __fastcall DeleteStyleSimulation(System::UnicodeString FontName);
extern DELPHI_PACKAGE bool __fastcall IsNeedsBoldSimulation(Vcl::Graphics::TFont* Font, /* out */ System::UnicodeString &Simulation);
extern DELPHI_PACKAGE bool __fastcall IsNeedsItalicSimulation(Vcl::Graphics::TFont* Font, /* out */ System::UnicodeString &Simulation);
extern DELPHI_PACKAGE System::UnicodeString __fastcall Color2Str(System::Uitypes::TColor Color);
extern DELPHI_PACKAGE System::UnicodeString __fastcall frxRect2Str(const Frxclass::TfrxRect &DR, const int Prec = 0x3);
extern DELPHI_PACKAGE Frxclass::TfrxPoint __fastcall frxPointSum(const Frxclass::TfrxPoint &P1, const Frxclass::TfrxPoint &P2);
extern DELPHI_PACKAGE Frxclass::TfrxPoint __fastcall frxPointMult(const Frxclass::TfrxPoint &P, System::Extended Factor);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrToHex(const System::WideString Value);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrToHexDx(const Frxexporthelpers::TRemapedString &RS, Frxanaliticgeometry::TDoubleArray pdfDX, bool AverageDx);
extern DELPHI_PACKAGE System::AnsiString __fastcall StrToHexSp(const System::WideString Value, System::Extended SpaceAdjustment);
}	/* namespace Frxexportpdfhelpers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTPDFHELPERS)
using namespace Frxexportpdfhelpers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportpdfhelpersHPP
