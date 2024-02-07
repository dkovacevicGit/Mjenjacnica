// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxGif2.pas' rev: 35.00 (Windows)

#ifndef Frxgif2HPP
#define Frxgif2HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.MMSystem.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <frxGif1.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxgif2
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxGIFFrame;
class DELPHICLASS TfrxGIFFrameList;
class DELPHICLASS TfrxGIFImage;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxGIFFrame : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int frLeft;
	int frTop;
	int frWidth;
	int frHeight;
	bool TheEnd;
	
public:
	__fastcall TfrxGIFFrame(TfrxGIFFrame* Item);
public:
	/* TObject.Create */ inline __fastcall TfrxGIFFrame() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxGIFFrame() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxGIFFrameList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TfrxGIFFrame* operator[](int I) { return this->Frames[I]; }
	
private:
	TfrxGIFFrame* __fastcall GetFrame(int I);
	
public:
	__property TfrxGIFFrame* Frames[int I] = {read=GetFrame/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TfrxGIFFrameList() { }
	
public:
	/* TObject.Create */ inline __fastcall TfrxGIFFrameList() : System::Classes::TList() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TfrxGIFImage : public Frxgif1::TfrxHtBitmap
{
	typedef Frxgif1::TfrxHtBitmap inherited;
	
private:
	Frxgif1::TGif* FGif;
	int FImageWidth;
	int FImageHeight;
	int FNumFrames;
	bool FTransparent;
	bool FVisible;
	Frxgif1::TfrxHtBitmap* Strip;
	TfrxGIFFrameList* Frames;
	HIDESBASE void __fastcall SetTransparent(bool AValue);
	
public:
	__fastcall virtual TfrxGIFImage()/* overload */;
	__fastcall TfrxGIFImage(TfrxGIFImage* Item);
	__fastcall virtual ~TfrxGIFImage();
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &ARect);
	HIDESBASE System::Uitypes::TColor __fastcall TransparentColor();
	__property bool IsTransparent = {read=FTransparent, write=SetTransparent, nodefault};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
	__property int NumFrames = {read=FNumFrames, nodefault};
public:
	/* TfrxHtBitmap.Create */ inline __fastcall TfrxGIFImage(bool WithTransparentMask)/* overload */ : Frxgif1::TfrxHtBitmap(WithTransparentMask) { }
	
public:
	/* TBitmap.Create */ inline __fastcall TfrxGIFImage(int AWidth, int AHeight)/* overload */ : Frxgif1::TfrxHtBitmap(AWidth, AHeight) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxgif2 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXGIF2)
using namespace Frxgif2;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Frxgif2HPP
