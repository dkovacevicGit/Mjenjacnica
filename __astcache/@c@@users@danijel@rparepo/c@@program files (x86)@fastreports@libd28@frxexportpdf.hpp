// CodeGear C++Builder
// Copyright (c) 1995, 2022 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportPDF.pas' rev: 35.00 (Windows)

#ifndef FrxexportpdfHPP
#define FrxexportpdfHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Classes.hpp>
#include <System.Win.ComObj.hpp>
#include <Vcl.Printers.hpp>
#include <System.Variants.hpp>
#include <System.Contnrs.hpp>
#include <frxPictureGraphics.hpp>
#include <frxExportBaseDialog.hpp>
#include <frxClass.hpp>
#include <frxExportPDFHelpers.hpp>
#include <frxVectorCanvas.hpp>
#include <frxHelpers.hpp>
#include <System.WideStrings.hpp>
#include <System.AnsiStrings.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------
#pragma link "usp10.lib"

namespace Frxexportpdf
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxPDFPage;
class DELPHICLASS TfrxPDFAnnot;
class DELPHICLASS TfrxPDFEngineState;
struct TSignatureData;
class DELPHICLASS TSignatureInfo;
class DELPHICLASS TSignatureInfoList;
class DELPHICLASS TfrxPDFExport;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TfrxPDFEncBit : unsigned char { ePrint, eModify, eCopy, eAnnot };

typedef System::Set<TfrxPDFEncBit, TfrxPDFEncBit::ePrint, TfrxPDFEncBit::eAnnot> TfrxPDFEncBits;

class PASCALIMPLEMENTATION TfrxPDFPage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FBackPictureVisible;
	bool FBackPictureStretched;
	double FHeight;
	
public:
	__fastcall TfrxPDFPage(Frxclass::TfrxReportPage* Page);
	__property double Height = {read=FHeight};
	__property bool BackPictureVisible = {read=FBackPictureVisible, nodefault};
	__property bool BackPictureStretched = {read=FBackPictureStretched, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxPDFPage() { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxPDFAnnot : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int Number;
	System::UnicodeString Rect;
	System::UnicodeString Hyperlink;
	int DestPage;
	int DestY;
public:
	/* TObject.Create */ inline __fastcall TfrxPDFAnnot() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxPDFAnnot() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TfrxPDFEngineState : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TfrxPDFExport* FExport;
	System::Extended FHeight;
	System::Extended FMarginTop;
	System::Extended FMarginLeft;
	
public:
	__fastcall TfrxPDFEngineState(TfrxPDFExport* AExport);
	__fastcall virtual ~TfrxPDFEngineState();
	void __fastcall BeginBBoxMode(System::Extended Height);
	void __fastcall RestoreState();
};


enum DECLSPEC_DENUM TEmbeddedRelation : unsigned char { erData, erSource, erAlternative, erSupplement, erUnspecified };

enum DECLSPEC_DENUM TZUGFeRD_ConformanceLevel : unsigned char { clMINIMUM, clBASIC, clCOMFORT, clEXTENDED };

typedef System::Set<Frxclass::TPDFSignatureKind, Frxclass::TPDFSignatureKind::skInvisible, Frxclass::TPDFSignatureKind::skEmpty> TSignatureKindSet;

enum DECLSPEC_DENUM TSignatureErrorHandling : unsigned char { seShowDialog, seCancelExport, seIgnoreCertificate };

struct DECLSPEC_DRECORD TSignatureData
{
public:
	System::Classes::TComponentName Name;
	System::WideString Description;
	Frxclass::TPDFSignatureKind Kind;
	System::WideString Location;
	System::WideString Reason;
	System::WideString ContactInfo;
	System::WideString CertificatePath;
	System::AnsiString CertificatePassword;
	bool Used;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSignatureInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TSignatureData FData;
	
protected:
	virtual void __fastcall AssignTo(System::Classes::TPersistent* Dest);
	
public:
	__fastcall TSignatureInfo(Frxclass::TfrxDigitalSignatureView* DigitalSignatureView);
	__fastcall TSignatureInfo(TfrxPDFExport* PDFExport, System::Classes::TComponentName AName);
	__fastcall TSignatureInfo(const TSignatureData &SD);
	__property TSignatureData Data = {read=FData, write=FData};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSignatureInfo() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TSignatureInfoList : public Frxhelpers::TOwnObjList
{
	typedef Frxhelpers::TOwnObjList inherited;
	
private:
	TSignatureData __fastcall GetData(int Index);
	void __fastcall SetData(int Index, const TSignatureData &Value);
	
protected:
	TfrxPDFExport* FPDFExport;
	
public:
	__fastcall TSignatureInfoList(TfrxPDFExport* APDFExport);
	void __fastcall Init();
	bool __fastcall IsFind(System::Classes::TComponentName Name, /* out */ int &Index);
	bool __fastcall IsContain(System::Classes::TComponentName Name);
	void __fastcall AddDefault();
	void __fastcall AddData(const TSignatureData &SD);
	void __fastcall GetOldDigitalSignDataFromExport();
	void __fastcall SetOldDigitalSignDataToExport();
	__property TSignatureData Data[int Index] = {read=GetData, write=SetData};
	__property TfrxPDFExport* PDFExport = {write=FPDFExport};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TSignatureInfoList() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TfrxPDFExport : public Frxexportbasedialog::TfrxBaseDialogExportFilter
{
	typedef Frxexportbasedialog::TfrxBaseDialogExportFilter inherited;
	
private:
	bool FCompressed;
	bool FEmbeddedFonts;
	bool FEmbedProt;
	bool FPrintOpt;
	System::Classes::TList* FPages;
	bool FOutline;
	int FQuality;
	Frxclass::TfrxCustomOutline* FPreviewOutline;
	System::WideString FSubject;
	System::WideString FAuthor;
	bool FBackground;
	System::WideString FCreator;
	bool FTags;
	bool FProtection;
	System::AnsiString FUserPassword;
	System::AnsiString FOwnerPassword;
	TfrxPDFEncBits FProtectionFlags;
	System::WideString FKeywords;
	System::WideString FTitle;
	System::WideString FProducer;
	bool FPrintScaling;
	bool FFitWindow;
	bool FHideMenubar;
	bool FCenterWindow;
	bool FHideWindowUI;
	bool FHideToolbar;
	bool FTransparency;
	bool FSaveOriginalImages;
	System::Classes::TStream* pdf;
	int FStartXRef;
	int FSignatureIndex;
	int FPageTreeNo;
	Frxexportpdfhelpers::TPDFObjectsHelper* FPOH;
	System::Extended FWidth;
	System::Extended FHeight;
	System::Extended FMarginLeft;
	System::Extended FMarginTop;
	System::AnsiString FEncKey;
	System::AnsiString FOPass;
	System::AnsiString FUPass;
	unsigned FEncBits;
	System::AnsiString FFileID;
	System::Uitypes::TColor FLastColor;
	System::UnicodeString FLastColorResult;
	System::Classes::TMemoryStream* OutStream;
	Frxexportpdfhelpers::TReferenceArray* FPageAnnots;
	Frxexportpdfhelpers::TPageByPageReferenceArray* FPageAnnotsArray;
	System::Classes::TList* FAnnots;
	Frxexportpdfhelpers::TfrxPDFXObjectArray* FXObjects;
	Frxexportpdfhelpers::TReferenceArray* FPageXObjects;
	Frxexportpdfhelpers::TPageByPageReferenceArray* FPageXObjectsArray;
	Frxexportpdfhelpers::TPDFGLobalFonts* FFonts;
	Frxexportpdfhelpers::TReferenceArray* FPageFonts;
	Frxexportpdfhelpers::TPageByPageReferenceArray* FPageFontsArray;
	Frxexportpdfhelpers::TReferenceArray* FPagesRef;
	Frxexportpdfhelpers::TReferenceArray* FAcroFormsRefs;
	int FMetaFileId;
	int FStructId;
	int FColorProfileId;
	int FAttachmentsNamesId;
	int FAttachmentsListId;
	int FPDFviaEMF;
	bool FPdfA;
	Frxexportpdfhelpers::TPDFStandard FPDFStandard;
	Frxexportpdfhelpers::TPDFVersion FPDFVersion;
	bool FUsePNGAlpha;
	int FPictureDPI;
	bool FInteractiveForms;
	TfrxPDFEngineState* FPDFState;
	System::WideString FInteractiveFormsFontSubset;
	Frxpicturegraphics::TfrxCustomGraphicFormatClass FGraphicHelper;
	Frxpicturegraphics::TfrxCustomGraphicFormatClass FAlphaGraphicHelper;
	__int64 FContentPosition;
	__int64 FContentEndPosition;
	__int64 FByteRangeIndex;
	System::WideString FDigitalSignLocation;
	System::WideString FDigitalSignReason;
	System::WideString FDigitalSignContactInfo;
	System::WideString FDigitalSignCertificatePath;
	System::AnsiString FDigitalSignCertificatePassword;
	TSignatureErrorHandling FSignErrorHandling;
	TfrxPDFExport* FIncrementalExport;
	int FFirstNextId;
	TSignatureData FSignatureData;
	int FCurvePrecision;
	int __fastcall AddSignatureDict();
	void __fastcall AddSignatureAppearence(int sigObjNo);
	void __fastcall AddSignature();
	void __fastcall AddAcroForm();
	System::UnicodeString __fastcall GetPDFDash(const Frxclass::TfrxFrameStyle LineStyle, System::Extended Width);
	System::AnsiString __fastcall GetID();
	System::AnsiString __fastcall CryptStr(System::AnsiString Source, int id, bool IsEscapeSpecialChar = true);
	System::AnsiString __fastcall CryptToHex(System::AnsiString Source, int id);
	System::AnsiString __fastcall PrepareStr(const System::WideString Text, int Id);
	System::AnsiString __fastcall PrepareAnsiStr(const System::AnsiString Text, int Id);
	System::AnsiString __fastcall PrepareCreationDate(int Id);
	System::AnsiString __fastcall EscapeSpecialChar(System::AnsiString TextStr);
	System::AnsiString __fastcall StrToUTF16(const System::WideString Value);
	System::AnsiString __fastcall StrToUTF16H(const System::WideString Value);
	System::AnsiString __fastcall PMD52Str(void * p);
	System::AnsiString __fastcall PadPassword(System::AnsiString Password);
	void __fastcall PrepareKeys();
	void __fastcall SetProtectionFlags(const TfrxPDFEncBits Value);
	void __fastcall Clear();
	void __fastcall WriteFont(Frxexportpdfhelpers::TfrxPDFFont* pdfFont);
	void __fastcall AddObject(Frxclass::TfrxView* const Obj);
	System::Extended __fastcall AddMemo(Frxclass::TfrxCustomMemoView* const Memo, bool IsInteractive = false, int SelectedLine = 0xffffffff);
	void __fastcall AddMemoField(Frxclass::TfrxCustomMemoView* const Memo, bool ViaEMF);
	void __fastcall AddCheckBox(Frxclass::TfrxView* const Obj, bool IsInteractiveCB = false);
	void __fastcall AddCheckBoxField(Frxclass::TfrxView* const Obj, bool ViaEMF);
	void __fastcall AddComboBox(Frxclass::TfrxView* const Obj, bool IsInteractive = false);
	void __fastcall AddListBox(Frxclass::TfrxView* const Obj, bool IsInteractive = false);
	void __fastcall AddListControlField(Frxclass::TfrxView* const Obj);
	void __fastcall AddPictureField(Frxclass::TfrxView* const Obj);
	void __fastcall AddLine(Frxclass::TfrxCustomLineView* const Line);
	void __fastcall AddShape(Frxclass::TfrxShapeView* const Shape);
	void __fastcall AddDigitalSignature(Frxclass::TfrxDigitalSignatureView* const Obj);
	void __fastcall AddViaEMF(Frxclass::TfrxView* const Obj, bool IsInBBOX = false);
	int __fastcall AddAsPicture(Frxclass::TfrxView* const Obj);
	void __fastcall CreateAlphaFromColorMask(System::Uitypes::TColor TransparentColorMask, Vcl::Graphics::TBitmap* SourceGraphic, Frxexportpdfhelpers::TMaskArray &MaskBytes);
	void __fastcall CreateAlphaMask(Frxpicturegraphics::TfrxCustomGraphicFormatClass GHelper, Vcl::Graphics::TBitmap* SourceGraphic, Frxexportpdfhelpers::TMaskArray &MaskBytes);
	System::UnicodeString __fastcall GetPDFColor(const System::Uitypes::TColor Color);
	void __fastcall AddAttachments();
	void __fastcall AddEmbeddedFileItem(System::TObject* EmbeddedFile);
	void __fastcall AddStructure();
	void __fastcall AddMetaData();
	void __fastcall AddColorProfile();
	void __fastcall WritePDFStream(System::Classes::TStream* Target, System::Classes::TStream* Source, int id, bool Compressed, bool Encrypted, bool startingBrackets, bool endingBrackets, bool enableLength2);
	void __fastcall SetEmbeddedFonts(const bool Value);
	Frxclass::TfrxRect __fastcall GetRect(Frxclass::TfrxView* Obj);
	Frxclass::TfrxRect __fastcall GetClipRect(Frxclass::TfrxView* Obj, bool Internal = false);
	Frxclass::TfrxRect __fastcall GetDMPRect(const Frxclass::TfrxRect &R);
	void __fastcall Cmd(const System::UnicodeString Args);
	void __fastcall Cmd_ObjPath(Frxclass::TfrxView* Obj);
	void __fastcall Cmd_RoundRectanglePath(Frxclass::TfrxShapeView* RoundedRect);
	void __fastcall Cmd_EllipsePath(Frxclass::TfrxShapeView* Ellipse);
	void __fastcall Cmd_TrianglePath(Frxclass::TfrxShapeView* Triangle);
	void __fastcall Cmd_DiamondPath(Frxclass::TfrxShapeView* Diamond);
	void __fastcall Cmd_ClipObj(Frxclass::TfrxView* Obj);
	void __fastcall Cmd_FillObj(Frxclass::TfrxView* Obj, System::Uitypes::TColor Color);
	void __fastcall Cmd_FillBrush(Frxclass::TfrxView* Obj, Frxclass::TfrxBrushFill* BrushFill);
	void __fastcall Cmd_FillGlass(Frxclass::TfrxView* Obj, Frxclass::TfrxGlassFill* GlassFill);
	void __fastcall Cmd_FillGradient(Frxclass::TfrxView* Obj, Frxclass::TfrxGradientFill* GradientFill);
	void __fastcall Cmd_Hatch(Frxclass::TfrxView* Obj, System::Uitypes::TColor Color, Vcl::Graphics::TBrushStyle Style);
	void __fastcall Cmd_ClipRect(Frxclass::TfrxView* Obj);
	Frxexportpdfhelpers::TfrxPDFFont* __fastcall Cmd_Font(Frxclass::TfrxView* Obj)/* overload */;
	Frxexportpdfhelpers::TfrxPDFFont* __fastcall Cmd_Font(Vcl::Graphics::TFont* Font)/* overload */;
	void __fastcall CmdMoveTo(System::Extended x, System::Extended y);
	void __fastcall CmdLineTo(System::Extended x, System::Extended y);
	void __fastcall CmdCurveTo(System::Extended x1, System::Extended y1, System::Extended x2, System::Extended y2, System::Extended x3, System::Extended y3);
	void __fastcall CmdFillColor(System::Uitypes::TColor Color);
	void __fastcall CmdStrokeColor(System::Uitypes::TColor Color);
	void __fastcall CmdStroke();
	void __fastcall CmdLineWidth(System::Extended Value);
	bool __fastcall IsInteractiveField(Frxclass::TfrxView* Obj);
	System::Extended __fastcall pdfX(System::Extended x);
	System::Extended __fastcall pdfY(System::Extended y);
	System::Extended __fastcall pdfSize(System::Extended Size);
	Frxclass::TfrxPoint __fastcall pdfPoint(System::Extended x, System::Extended y);
	void __fastcall StartBBoxMode(Frxclass::TfrxView* const Obj);
	System::UnicodeString __fastcall EndBBoxMode();
	void __fastcall SetPDFStandard(const Frxexportpdfhelpers::TPDFStandard Value);
	void __fastcall SetPDFVersion(const Frxexportpdfhelpers::TPDFVersion Value);
	void __fastcall SetTransparency(const bool Value);
	void __fastcall SetPdfA(const bool Value);
	void __fastcall SetPictureDPI(const int Value);
	void __fastcall SetSaveOriginalImages(const bool Value);
	void __fastcall SetInteractiveForms(const bool Value);
	void __fastcall SetQuality(const int Value);
	void __fastcall SetCurvePrecision(const int Value);
	
protected:
	Frxclass::TfrxRect FPageRect;
	System::UnicodeString stLeft;
	System::UnicodeString stRight;
	System::UnicodeString stTop;
	System::UnicodeString stBottom;
	System::UnicodeString stRect;
	System::Contnrs::TObjectList* FEmbeddedFiles;
	System::UnicodeString FZUGFeRDDescription;
	System::UnicodeString FCreationDateTime;
	System::UnicodeString FCreationDateTimeMeta;
	bool FDebugDateTimeID;
	System::AnsiString FSignRect;
	bool FSignatureExists;
	TSignatureInfoList* FSignatureInfoList;
	int FCurrentPageNo;
	int FCurrentPageIndex;
	int FSignaturePageIndex;
	TfrxPDFExport* FRoot;
	TfrxPDFExport* FParent;
	int FInformationDictionaryNo;
	int FInteractiveFormDictionaryNo;
	int FCatalogDictionaryNo;
	int FEncryptNo;
	System::TDateTime FDateTime;
	System::AnsiString FID;
	bool __fastcall IsAddViaEMF(Frxclass::TfrxView* const Obj);
	void __fastcall AddAsPictureOld(Frxclass::TfrxView* const Obj);
	void __fastcall DoFill(Frxclass::TfrxView* const Obj);
	void __fastcall DoFrame(Frxclass::TfrxFrame* const aFrame, const Frxclass::TfrxRect &aRect);
	System::UnicodeString __fastcall STpdfPoint(System::Extended x, System::Extended y);
	System::UnicodeString __fastcall STpdfSize(System::Extended Size);
	System::UnicodeString __fastcall STpdfRect(System::Extended x, System::Extended y, System::Extended Width, System::Extended Height);
	void __fastcall ExportViaVector(Frxclass::TfrxCustomMemoView* const Memo);
	void __fastcall Vector_ExtTextOut(Frxclass::TfrxCustomMemoView* Memo, Frxvectorcanvas::TVector_ExtTextOut* Vector);
	void __fastcall WritePageTree();
	void __fastcall WriteInformationDictionary();
	void __fastcall WriteCatalogDictionary(int OutlineObjNo);
	void __fastcall OutUsedXObjects();
	bool __fastcall IsRoot();
	__property TfrxPDFExport* Root = {read=FRoot};
	__property TfrxPDFExport* Parent = {read=FParent};
	
public:
	__property TSignatureInfoList* SignatureInfoList = {read=FSignatureInfoList};
	__fastcall virtual TfrxPDFExport(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxPDFExport();
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	__classmethod virtual Frxexportbasedialog::TfrxBaseExportDialogClass __fastcall ExportDialogClass();
	virtual bool __fastcall Start();
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	virtual void __fastcall Finish();
	void __fastcall ExecuteIncremental();
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall BeginClip(Frxclass::TfrxView* Obj);
	virtual void __fastcall EndClip();
	void __fastcall AddEmbeddedFile(System::UnicodeString Name, System::UnicodeString Description, System::TDateTime ModDate, TEmbeddedRelation Relation, System::UnicodeString MIME, System::Classes::TStream* FileStream);
	void __fastcall AddEmbeddedXML(System::UnicodeString Name, System::UnicodeString Description, System::TDateTime ModDate, System::Classes::TStream* FileStream, TZUGFeRD_ConformanceLevel ZUGFeRDLevel = (TZUGFeRD_ConformanceLevel)(0x1), const System::UnicodeString ZUGFeRDDescription = System::UnicodeString());
	bool __fastcall IsPDFA();
	bool __fastcall IsPDFA_1();
	bool __fastcall IsSignatureExists(TSignatureKindSet SignatureKindSet = (TSignatureKindSet() << Frxclass::TPDFSignatureKind::skInvisible << Frxclass::TPDFSignatureKind::skVisible << Frxclass::TPDFSignatureKind::skEmpty ));
	void __fastcall FillSignatureInfoList(TSignatureInfoList* SIL);
	__property bool SaveOriginalImages = {read=FSaveOriginalImages, write=SetSaveOriginalImages, nodefault};
	__property int PictureDPI = {read=FPictureDPI, write=SetPictureDPI, nodefault};
	__property int CurvePrecision = {read=FCurvePrecision, write=SetCurvePrecision, nodefault};
	__property bool UsePNGAlpha = {read=FUsePNGAlpha, write=FUsePNGAlpha, nodefault};
	__property System::WideString DigitalSignLocation = {read=FDigitalSignLocation, write=FDigitalSignLocation};
	__property System::WideString DigitalSignReason = {read=FDigitalSignReason, write=FDigitalSignReason};
	__property System::WideString DigitalSignContactInfo = {read=FDigitalSignContactInfo, write=FDigitalSignContactInfo};
	__property System::WideString DigitalSignCertificatePath = {read=FDigitalSignCertificatePath, write=FDigitalSignCertificatePath};
	__property System::AnsiString DigitalSignCertificatePassword = {read=FDigitalSignCertificatePassword, write=FDigitalSignCertificatePassword};
	__property TSignatureErrorHandling SignErrorHandling = {read=FSignErrorHandling, write=FSignErrorHandling, default=0};
	__property TfrxPDFExport* IncrementalExport = {read=FIncrementalExport};
	
__published:
	__property bool Compressed = {read=FCompressed, write=FCompressed, default=1};
	__property bool EmbeddedFonts = {read=FEmbeddedFonts, write=SetEmbeddedFonts, default=0};
	__property bool EmbedFontsIfProtected = {read=FEmbedProt, write=FEmbedProt, default=1};
	__property bool InteractiveForms = {read=FInteractiveForms, write=SetInteractiveForms, default=0};
	__property System::WideString InteractiveFormsFontSubset = {read=FInteractiveFormsFontSubset, write=FInteractiveFormsFontSubset};
	__property OpenAfterExport;
	__property bool PrintOptimized = {read=FPrintOpt, write=FPrintOpt, nodefault};
	__property bool Outline = {read=FOutline, write=FOutline, nodefault};
	__property bool Background = {read=FBackground, write=FBackground, nodefault};
	__property bool HTMLTags = {read=FTags, write=FTags, nodefault};
	__property OverwritePrompt;
	__property int Quality = {read=FQuality, write=SetQuality, nodefault};
	__property bool Transparency = {read=FTransparency, write=SetTransparency, default=1};
	__property System::WideString Title = {read=FTitle, write=FTitle};
	__property System::WideString Author = {read=FAuthor, write=FAuthor};
	__property System::WideString Subject = {read=FSubject, write=FSubject};
	__property System::WideString Keywords = {read=FKeywords, write=FKeywords};
	__property System::WideString Creator = {read=FCreator, write=FCreator};
	__property System::WideString Producer = {read=FProducer, write=FProducer};
	__property System::AnsiString UserPassword = {read=FUserPassword, write=FUserPassword};
	__property System::AnsiString OwnerPassword = {read=FOwnerPassword, write=FOwnerPassword};
	__property TfrxPDFEncBits ProtectionFlags = {read=FProtectionFlags, write=SetProtectionFlags, nodefault};
	__property bool HideToolbar = {read=FHideToolbar, write=FHideToolbar, nodefault};
	__property bool HideMenubar = {read=FHideMenubar, write=FHideMenubar, nodefault};
	__property bool HideWindowUI = {read=FHideWindowUI, write=FHideWindowUI, nodefault};
	__property bool FitWindow = {read=FFitWindow, write=FFitWindow, nodefault};
	__property bool CenterWindow = {read=FCenterWindow, write=FCenterWindow, nodefault};
	__property bool PrintScaling = {read=FPrintScaling, write=FPrintScaling, nodefault};
	__property bool PdfA = {read=FPdfA, write=SetPdfA, nodefault};
	__property Frxexportpdfhelpers::TPDFStandard PDFStandard = {read=FPDFStandard, write=SetPDFStandard, nodefault};
	__property Frxexportpdfhelpers::TPDFVersion PDFVersion = {read=FPDFVersion, write=SetPDFVersion, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxPDFExport() : Frxexportbasedialog::TfrxBaseDialogExportFilter() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 DefaultSignatureIndex = System::Int8(0x0);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfSetLineColor(System::Uitypes::TColor Color);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfSetLineWidth(double Width);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfStrokeRect(const Frxclass::TfrxRect &R, System::Uitypes::TColor Color, System::Extended LineWidth);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfFillRect(const Frxclass::TfrxRect &R, System::Uitypes::TColor Color);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfSetColor(System::Uitypes::TColor Color);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfStroke(void);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfFill(void);
extern DELPHI_PACKAGE System::AnsiString __fastcall pdfPoint(double x, double y);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfLine(double x, double y);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfMove(double x, double y);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfColor(System::Uitypes::TColor Color);
extern DELPHI_PACKAGE System::AnsiString __fastcall PdfString(const System::WideString Str);
}	/* namespace Frxexportpdf */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTPDF)
using namespace Frxexportpdf;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportpdfHPP
