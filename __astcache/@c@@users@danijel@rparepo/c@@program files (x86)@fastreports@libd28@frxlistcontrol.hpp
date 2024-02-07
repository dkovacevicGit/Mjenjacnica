// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxListControl.pas' rev: 35.00 (Windows)

#ifndef FrxlistcontrolHPP
#define FrxlistcontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>
#include <System.Types.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <frxUnicodeUtils.hpp>
#include <System.WideStrings.hpp>
#include <frxClass.hpp>
#include <frxGraphicUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxlistcontrol
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxCustomListControlView;
class DELPHICLASS TfrxRightEdge;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxCustomListControlView : public Frxclass::TfrxView
{
	typedef Frxclass::TfrxView inherited;
	
private:
	bool FAllowExpressions;
	System::UnicodeString FExpressionDelimiters;
	int FItemIndex;
	void __fastcall SetItems(System::Widestrings::TWideStrings* const Value);
	bool __fastcall IsExprDelimitersStored();
	System::WideString __fastcall GetItemsText();
	void __fastcall SetItemsText(const System::WideString Value);
	
protected:
	System::Widestrings::TWideStrings* FItems;
	Frxgraphicutils::TfrxDrawText* FDrawText;
	System::DynamicArray<int> FLineY;
	int FLineSpacing;
	virtual void __fastcall SetItemIndex(const int Value);
	int __fastcall XCorrected(const System::Extended X);
	int __fastcall YCorrected(const System::Extended Y);
	void __fastcall DrawTextInit();
	void __fastcall DrawTextDimensions(System::Extended ScaleX, System::Extended ScaleY, System::Extended OffsetX, System::Extended OffsetY);
	System::Types::TRect __fastcall CalcTextRect(System::Extended OffsetX, System::Extended OffsetY, System::Extended ScaleX, System::Extended ScaleY);
	virtual System::Types::TRect __fastcall NoScrollBar(const System::Types::TRect &Rect);
	void __fastcall LoadFromDataField();
	void __fastcall GetExpressionDelimiters(/* out */ System::WideString &LeftDlm, /* out */ System::WideString &RightDlm);
	bool __fastcall IsPreview(const Frxclass::TfrxInteractiveEventsParams &EventParams);
	bool __fastcall IsLeft(System::Uitypes::TMouseButton Button);
	virtual void __fastcall FillMemoText(Frxclass::TfrxCustomMemoView* Memo) = 0 ;
	__property bool AllowExpressions = {read=FAllowExpressions, write=FAllowExpressions, default=1};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, nodefault};
	__property System::WideString ItemsText = {read=GetItemsText, write=SetItemsText};
	
public:
	__fastcall virtual TfrxCustomListControlView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxCustomListControlView();
	virtual void __fastcall GetData();
	void __fastcall FillMemo(Frxclass::TfrxCustomMemoView* Memo);
	__property System::Widestrings::TWideStrings* Items = {read=FItems, write=SetItems};
	__property System::UnicodeString ExpressionDelimiters = {read=FExpressionDelimiters, write=FExpressionDelimiters, stored=IsExprDelimitersStored};
public:
	/* TfrxComponent.DesignCreate */ inline __fastcall virtual TfrxCustomListControlView(System::Classes::TComponent* AOwner, System::Word Flags) : Frxclass::TfrxView(AOwner, Flags) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxRightEdge : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::Types::TRect FRect;
	bool __fastcall IsInside(int X, int Y);
	
public:
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* Canvas, System::Extended ScaleX, System::Extended ScaleY);
	void __fastcall Init(const System::Types::TRect &Rect);
public:
	/* TObject.Create */ inline __fastcall TfrxRightEdge() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxRightEdge() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define DefaultExpressionDelimiters L"[,]"
}	/* namespace Frxlistcontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXLISTCONTROL)
using namespace Frxlistcontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxlistcontrolHPP
