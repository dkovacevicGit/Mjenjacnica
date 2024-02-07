// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxGif1.pas' rev: 35.00 (Windows)

#ifndef Frxgif1HPP
#define Frxgif1HPP

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
#include <System.Math.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxgif1
{
//-- forward type declarations -----------------------------------------------
struct TRGBQUAD;
struct TGifDataBlock;
struct TGifSignature;
struct TGifExtensionGraphic;
struct TGifExtensionComment;
struct TGifExtensionText;
struct TGifExtensionApplication;
struct TGifExtension;
struct TGifScreenDescriptor;
struct TGifColorTable;
struct TGifImageDescriptor;
struct TGifZip;
class DELPHICLASS TfrxHtBitmap;
class DELPHICLASS TGif;
//-- type declarations -------------------------------------------------------
typedef NativeInt PtrInt;

typedef NativeUInt PtrUInt;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TRGBQUAD
{
public:
	System::Byte rgbBlue;
	System::Byte rgbGreen;
	System::Byte rgbRed;
	System::Byte rgbReserved;
};
#pragma pack(pop)


typedef TGifDataBlock *PGifDataBlock;

struct DECLSPEC_DRECORD TGifDataBlock
{
public:
	int rSize;
	System::StaticArray<System::Byte, 255> rData;
};


typedef TGifSignature *PGifSignature;

struct DECLSPEC_DRECORD TGifSignature
{
public:
	System::StaticArray<char, 6> rSignature;
};


typedef TGifExtensionGraphic *PGifExtensionGraphic;

struct DECLSPEC_DRECORD TGifExtensionGraphic
{
public:
	int rBlockSize;
	int rDisposal;
	bool rUserInputValid;
	bool rTransparentValid;
	int rDelayTime;
	int rTransparentIndex;
};


typedef TGifExtensionComment *PGifExtensionComment;

struct DECLSPEC_DRECORD TGifExtensionComment
{
public:
	System::Classes::TList* rDataBlockList;
};


typedef TGifExtensionText *PGifExtensionText;

struct DECLSPEC_DRECORD TGifExtensionText
{
public:
	int rBlockSize;
	int rGridLeft;
	int rGridTop;
	int rGridWidth;
	int rGridHeight;
	int rCellWidth;
	int rCellHeight;
	int rForegroundIndex;
	int rBackgroundIndex;
	System::Classes::TList* rDataBlockList;
};


typedef TGifExtensionApplication *PGifExtensionApplication;

struct DECLSPEC_DRECORD TGifExtensionApplication
{
public:
	int rBlockSize;
	System::StaticArray<char, 8> rIdentifier;
	System::StaticArray<char, 3> rAuthentication;
	System::Classes::TList* rDataBlockList;
};


typedef TGifExtension *PGifExtension;

struct DECLSPEC_DRECORD TGifExtension
{
	
public:
	System::Byte rLabel;
	union
	{
		struct 
		{
			int rDummy;
		};
		struct 
		{
			TGifExtensionApplication rApp;
		};
		struct 
		{
			TGifExtensionText rText;
		};
		struct 
		{
			TGifExtensionComment rComment;
		};
		struct 
		{
			TGifExtensionGraphic rGraphic;
		};
		
	};
};


typedef TGifScreenDescriptor *PGifScreenDescriptor;

struct DECLSPEC_DRECORD TGifScreenDescriptor
{
public:
	int rWidth;
	int rHeight;
	bool rGlobalColorValid;
	int rColorResolution;
	bool rSorted;
	int rGlobalColorSize;
	int rBackgroundIndex;
	int rAspectRatio;
	int rGlobalColorTable;
};


typedef TGifColorTable *PGifColorTable;

struct DECLSPEC_DRECORD TGifColorTable
{
public:
	int rSize;
	System::StaticArray<System::Uitypes::TColor, 256> rColors;
};


typedef TGifImageDescriptor *PGifImageDescriptor;

struct DECLSPEC_DRECORD TGifImageDescriptor
{
public:
	int rIndex;
	int rLeft;
	int rTop;
	int rWidth;
	int rHeight;
	bool rLocalColorValid;
	bool rInterlaced;
	bool rSorted;
	int rLocalColorSize;
	int rLocalColorTable;
	int rLZWSize;
	System::Classes::TList* rExtensionList;
	System::Byte *rPixelList;
	int rPixelCount;
	Vcl::Graphics::TBitmap* rBitmap;
};


typedef TGifZip *PGifZip;

struct DECLSPEC_DRECORD TGifZip
{
public:
	TGifImageDescriptor *rID;
	TGifColorTable *rCT;
	System::StaticArray<int, 4096> rPrefix;
	System::StaticArray<int, 4096> rSuffix;
	System::StaticArray<System::Byte, 4096> rCodeStack;
	int rSP;
	int rClearCode;
	int rEndCode;
	int rHighCode;
	int rCurSize;
	int rBitString;
	int rBits;
	int rCurSlot;
	int rTopSlot;
	bool rMaxVal;
	int rCurX;
	int rCurY;
	int rCurPass;
	int rFirstSlot;
	int rNextSlot;
	int rCount;
	int rLast;
	bool rUnget;
};


class PASCALIMPLEMENTATION TfrxHtBitmap : public Vcl::Graphics::TBitmap
{
	typedef Vcl::Graphics::TBitmap inherited;
	
private:
	void __fastcall SetMask(Vcl::Graphics::TBitmap* AValue);
	Vcl::Graphics::TBitmap* __fastcall GetMask();
	void __fastcall SetTransparentMask(bool AValue);
	
protected:
	Vcl::Graphics::TBitmap* FMask;
	bool FTransparentMask;
	__property bool TransparentMask = {read=FTransparentMask, write=SetTransparentMask, nodefault};
	
public:
	__fastcall TfrxHtBitmap(bool WithTransparentMask)/* overload */;
	__fastcall virtual ~TfrxHtBitmap();
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Rect);
	void __fastcall StretchDraw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &DestRect, const System::Types::TRect &SrcRect);
	__property Vcl::Graphics::TBitmap* BitmapMask = {read=GetMask, write=SetMask};
public:
	/* TBitmap.Create */ inline __fastcall virtual TfrxHtBitmap()/* overload */ : Vcl::Graphics::TBitmap() { }
	/* TBitmap.Create */ inline __fastcall TfrxHtBitmap(int AWidth, int AHeight)/* overload */ : Vcl::Graphics::TBitmap(AWidth, AHeight) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGif : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TMemoryStream* fIOStream;
	System::Classes::TMemoryStream* fDataStream;
	System::Classes::TList* fExtension;
	TGifSignature *fSignature;
	TGifScreenDescriptor *fScreenDescriptor;
	System::Classes::TList* fImageDescriptorList;
	System::Classes::TList* fColorTableList;
	System::Classes::TList* fPaletteList;
	TGifZip *fZipData;
	int FLoopCount;
	
protected:
	int __fastcall GetHeight();
	int __fastcall GetWidth();
	bool __fastcall GetTransparent();
	
private:
	void __fastcall ReadSignature();
	void __fastcall ReadScreenDescriptor();
	void __fastcall ReadColorTable(int Size, /* out */ int &Table);
	void __fastcall ReadImageDescriptor();
	void __fastcall ReadDataBlockList(System::Classes::TList* List);
	void __fastcall ReadExtension(bool &Done);
	void __fastcall ReadSourceInteger(int size, /* out */ int &value);
	void __fastcall WriteSignature();
	void __fastcall WriteScreenDescriptor();
	void __fastcall WriteColorTable(int Table);
	void __fastcall WriteExtension(PGifExtension eb);
	void __fastcall WriteDataBlockList(System::Classes::TList* List);
	void __fastcall WriteImageDescriptor(PGifImageDescriptor id);
	void __fastcall WriteSourceInteger(int size, int &value);
	void __fastcall LZWDecode(PGifImageDescriptor pID);
	void __fastcall LZWEncode(PGifImageDescriptor pID);
	void __fastcall LZWInit(PGifImageDescriptor pID);
	void __fastcall LZWFinit();
	void __fastcall LZWReset();
	int __fastcall LZWGetCode();
	void __fastcall LZWSaveCode(int Code);
	void __fastcall LZWDecodeCode(int &Code);
	void __fastcall LZWSaveSlot(int Prefix, int Suffix);
	void __fastcall LZWIncrPosition();
	void __fastcall LZWCheckSlot();
	void __fastcall LZWWriteBitmap();
	void __fastcall LZWPutCode(int code);
	void __fastcall LZWPutClear();
	int __fastcall LZWReadBitmap();
	System::AnsiString __fastcall GetSignature();
	PGifScreenDescriptor __fastcall GetScreenDescriptor();
	int __fastcall GetImageCount();
	PGifImageDescriptor __fastcall GetImageDescriptor(int image);
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(int image);
	int __fastcall GetColorTableCount();
	PGifColorTable __fastcall GetColorTable(int table);
	int __fastcall GetImageDelay(int Image);
	int __fastcall GetImageDisposal(int Image);
	int __fastcall GetColorIndex(int image, int x, int y);
	int __fastcall GetTransparentIndex(int image);
	System::Uitypes::TColor __fastcall GetTransparentColor();
	int __fastcall GetImageLeft(int image);
	int __fastcall GetImageTop(int image);
	int __fastcall GetImageWidth(int image);
	int __fastcall GetImageHeight(int image);
	int __fastcall GetImageDepth(int image);
	void __fastcall FreeDataBlockList(System::Classes::TList* &list);
	void __fastcall FreeExtensionList(System::Classes::TList* &list);
	void __fastcall MakeBitmaps();
	PGifExtensionGraphic __fastcall FindGraphicExtension(int image);
	int __fastcall FindColorIndex(System::Uitypes::TColor c, PGifColorTable ct);
	void __fastcall ExtractLoopCount(System::Classes::TList* List);
	
public:
	__fastcall TGif();
	__fastcall TGif(TGif* AGif);
	__fastcall virtual ~TGif();
	void __fastcall FreeImage();
	void __fastcall SaveToStream(System::Classes::TStream* Destination);
	void __fastcall LoadFromStream(System::Classes::TStream* Source);
	TfrxHtBitmap* __fastcall GetStripBitmap();
	__property System::AnsiString Signature = {read=GetSignature};
	__property PGifScreenDescriptor ScreenDescriptor = {read=GetScreenDescriptor};
	__property int ImageCount = {read=GetImageCount, nodefault};
	__property PGifImageDescriptor ImageDescriptor[int Image] = {read=GetImageDescriptor};
	__property Vcl::Graphics::TBitmap* Bitmap[int Image] = {read=GetBitmap};
	__property int ColorTableCount = {read=GetColorTableCount, nodefault};
	__property PGifColorTable ColorTable[int Table] = {read=GetColorTable};
	__property int Height = {read=GetHeight, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	__property int ImageDelay[int Image] = {read=GetImageDelay};
	__property int ImageDisposal[int Image] = {read=GetImageDisposal};
	__property bool Transparent = {read=GetTransparent, nodefault};
	__property int TransparentIndex[int Image] = {read=GetTransparentIndex};
	__property System::Uitypes::TColor TransparentColor = {read=GetTransparentColor, nodefault};
	__property int ImageLeft[int Image] = {read=GetImageLeft};
	__property int ImageTop[int Image] = {read=GetImageTop};
	__property int ImageWidth[int Image] = {read=GetImageWidth};
	__property int ImageHeight[int Image] = {read=GetImageHeight};
	__property int ImageDepth[int Image] = {read=GetImageDepth};
	__property int LoopCount = {read=FLoopCount, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Word kGifCodeTableSize = System::Word(0x1000);
}	/* namespace Frxgif1 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXGIF1)
using namespace Frxgif1;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Frxgif1HPP
