// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxListBox.pas' rev: 35.00 (Windows)

#ifndef FrxlistboxHPP
#define FrxlistboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Types.hpp>
#include <Vcl.Controls.hpp>
#include <frxClass.hpp>
#include <frxListControl.hpp>
#include <System.UITypes.hpp>
#include <System.WideStrings.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxlistbox
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxVerticalScrollBar;
class DELPHICLASS TfrxListBoxObject;
class DELPHICLASS TfrxListBoxView;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TScrollBoxMousePlace : unsigned char { cpAbove, cpCenter, cpBelow };

class PASCALIMPLEMENTATION TfrxVerticalScrollBar : public Frxlistcontrol::TfrxRightEdge
{
	typedef Frxlistcontrol::TfrxRightEdge inherited;
	
private:
	System::Extended FContentHeight;
	System::Extended FControlHeight;
	int FContentLineCount;
	int FTopLineIndex;
	int FDownTopLineIndex;
	bool FMouseCaptured;
	TScrollBoxMousePlace FDownPlace;
	int FDownY;
	int FCurrentY;
	System::Extended FScrollBoxTop;
	System::Extended FScrollBoxBottom;
	System::Extended FScrollBoxStep;
	int FMaxTopLineIndex;
	int FWheelStepNumber;
	bool FInitialized;
	void __fastcall SetTopLineIndex(const int Value);
	
protected:
	TScrollBoxMousePlace __fastcall CalcPlace(int Y);
	void __fastcall SquareLineTo(Vcl::Graphics::TCanvas* Canvas, int X, int Y);
	System::Uitypes::TColor __fastcall MixColor(System::Uitypes::TColor C1, System::Uitypes::TColor C2);
	
public:
	HIDESBASE void __fastcall Init(System::Extended AContentHeight, System::Extended AControlHeight, const System::Types::TRect &Rect, int AContentLineCount);
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* Canvas, System::Extended ScaleX, System::Extended ScaleY);
	bool __fastcall IsVisible();
	bool __fastcall DoMouseDown(int X, int Y);
	void __fastcall DoMouseUp();
	void __fastcall DoMouseMove(int X, int Y);
	bool __fastcall DoMouseWheel(int WheelDelta);
	__property bool MouseCaptured = {read=FMouseCaptured, nodefault};
	__property int TopLineIndex = {read=FTopLineIndex, write=SetTopLineIndex, nodefault};
	__property bool Initialized = {read=FInitialized, nodefault};
public:
	/* TObject.Create */ inline __fastcall TfrxVerticalScrollBar() : Frxlistcontrol::TfrxRightEdge() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxVerticalScrollBar() { }
	
};


class PASCALIMPLEMENTATION TfrxListBoxObject : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
public:
	/* TComponent.Create */ inline __fastcall virtual TfrxListBoxObject(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TfrxListBoxObject() { }
	
};


class PASCALIMPLEMENTATION TfrxListBoxView : public Frxlistcontrol::TfrxCustomListControlView
{
	typedef Frxlistcontrol::TfrxCustomListControlView inherited;
	
private:
	int __fastcall GetTopLineIndex();
	
protected:
	System::Extended FContentHeight;
	bool FMouseCaptured;
	TfrxVerticalScrollBar* FScrollBar;
	bool __fastcall IsChangeItemIndex(const int Y);
	bool __fastcall IsScrollBarAllowed();
	virtual System::Types::TRect __fastcall NoScrollBar(const System::Types::TRect &Rect);
	void __fastcall DrawText();
	void __fastcall SetDrawParams(Vcl::Graphics::TCanvas* Canvas, System::Extended ScaleX, System::Extended ScaleY, System::Extended OffsetX, System::Extended OffsetY);
	virtual void __fastcall FillMemoText(Frxclass::TfrxCustomMemoView* Memo);
	virtual bool __fastcall DoMouseDown(int X, int Y, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, Frxclass::TfrxInteractiveEventsParams &EventParams);
	virtual void __fastcall DoMouseUp(int X, int Y, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, Frxclass::TfrxInteractiveEventsParams &EventParams);
	virtual void __fastcall DoMouseMove(int X, int Y, System::Classes::TShiftState Shift, Frxclass::TfrxInteractiveEventsParams &EventParams);
	virtual bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos, Frxclass::TfrxInteractiveEventsParams &EventParams);
	
public:
	__fastcall virtual TfrxListBoxView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxListBoxView();
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* Canvas, System::Extended ScaleX, System::Extended ScaleY, System::Extended OffsetX, System::Extended OffsetY);
	__property int TopLineIndex = {read=GetTopLineIndex, nodefault};
	
__published:
	__property AllowExpressions = {default=1};
	__property BrushStyle;
	__property Color;
	__property Cursor = {default=0};
	__property DataField = {default=0};
	__property DataSet;
	__property DataSetName = {default=0};
	__property Editable = {default=1};
	__property ExpressionDelimiters = {default=0};
	__property Font;
	__property Frame;
	__property FillType = {default=0};
	__property Fill;
	__property ItemIndex;
	__property Items;
	__property ItemsText = {default=0};
	__property ParentFont = {default=1};
	__property TagStr = {default=0};
public:
	/* TfrxComponent.DesignCreate */ inline __fastcall virtual TfrxListBoxView(System::Classes::TComponent* AOwner, System::Word Flags) : Frxlistcontrol::TfrxCustomListControlView(AOwner, Flags) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxlistbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXLISTBOX)
using namespace Frxlistbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxlistboxHPP
