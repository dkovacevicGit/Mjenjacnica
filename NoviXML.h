
// **************************************************** //
//                                                    
//                  XML Data Binding                  
//                                                    
//         Generated on: 16.10.2023. 20:50:59         
//       Generated from: C:\RPA projekt\NoviXML.xml   
//   Settings stored in: C:\RPA projekt\NoviXML.xdb   
//                                                    
// **************************************************** //

#ifndef   NoviXMLH
#define   NoviXMLH

#include <System.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLsaldoType;
typedef System::DelphiInterface<IXMLsaldoType> _di_IXMLsaldoType;
__interface IXMLtransactionType;
typedef System::DelphiInterface<IXMLtransactionType> _di_IXMLtransactionType;

// IXMLsaldoType 

__interface INTERFACE_UUID("{A5F0FEAA-B77D-48FA-9E83-0614F213D8AC}") IXMLsaldoType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLtransactionType __fastcall Get_transaction(const int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLtransactionType __fastcall Add() = 0;
  virtual _di_IXMLtransactionType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLtransactionType transaction[const int Index] = { read=Get_transaction };/* default */
};

// IXMLtransactionType 

__interface INTERFACE_UUID("{9F636BB6-C78E-4140-84C1-D64A3C0338C1}") IXMLtransactionType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_Blagajnik() = 0;
  virtual System::UnicodeString __fastcall Get_Valuta() = 0;
  virtual System::UnicodeString __fastcall Get_Srednji_tecaj() = 0;
  virtual float __fastcall Get_Ulaz_EUR() = 0;
  virtual float __fastcall Get_Izlaz_EUR() = 0;
  virtual void __fastcall Set_Blagajnik(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_Valuta(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_Srednji_tecaj(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_Ulaz_EUR(const float Value) = 0;
  virtual void __fastcall Set_Izlaz_EUR(const float Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString Blagajnik = { read=Get_Blagajnik, write=Set_Blagajnik };
  __property System::UnicodeString Valuta = { read=Get_Valuta, write=Set_Valuta };
  __property System::UnicodeString Srednji_tecaj = { read=Get_Srednji_tecaj, write=Set_Srednji_tecaj };
  __property float Ulaz_EUR = { read=Get_Ulaz_EUR, write=Set_Ulaz_EUR };
  __property float Izlaz_EUR = { read=Get_Izlaz_EUR, write=Set_Izlaz_EUR };
};

// Forward Decls 

class TXMLsaldoType;
class TXMLtransactionType;

// TXMLsaldoType 

class TXMLsaldoType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLsaldoType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLsaldoType 
  virtual _di_IXMLtransactionType __fastcall Get_transaction(const int Index);
  virtual _di_IXMLtransactionType __fastcall Add();
  virtual _di_IXMLtransactionType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLtransactionType 

class TXMLtransactionType : public Xml::Xmldoc::TXMLNode, public IXMLtransactionType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLtransactionType 
  virtual System::UnicodeString __fastcall Get_Blagajnik();
  virtual System::UnicodeString __fastcall Get_Valuta();
  virtual System::UnicodeString __fastcall Get_Srednji_tecaj();
  virtual float __fastcall Get_Ulaz_EUR();
  virtual float __fastcall Get_Izlaz_EUR();
  virtual void __fastcall Set_Blagajnik(const System::UnicodeString Value);
  virtual void __fastcall Set_Valuta(const System::UnicodeString Value);
  virtual void __fastcall Set_Srednji_tecaj(const System::UnicodeString Value);
  virtual void __fastcall Set_Ulaz_EUR(const float Value);
  virtual void __fastcall Set_Izlaz_EUR(const float Value);
};

// Global Functions 

_di_IXMLsaldoType __fastcall Getsaldo(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLsaldoType __fastcall Getsaldo(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLsaldoType __fastcall Loadsaldo(const System::UnicodeString& FileName);
_di_IXMLsaldoType __fastcall  Newsaldo();

#define TargetNamespace ""

#endif