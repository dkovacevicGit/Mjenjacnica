
// **************************************************** //
//                                                    
//                  XML Data Binding                  
//                                                    
//         Generated on: 16.10.2023. 20:50:59         
//       Generated from: C:\RPA projekt\NoviXML.xml   
//   Settings stored in: C:\RPA projekt\NoviXML.xdb   
//                                                    
// **************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "NoviXML.h"


// Global Functions 

_di_IXMLsaldoType __fastcall Getsaldo(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLsaldoType) Doc->GetDocBinding("saldo", __classid(TXMLsaldoType), TargetNamespace);
};

_di_IXMLsaldoType __fastcall Getsaldo(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getsaldo(DocIntf);
};

_di_IXMLsaldoType __fastcall Loadsaldo(const System::UnicodeString& FileName)
{
  return (_di_IXMLsaldoType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("saldo", __classid(TXMLsaldoType), TargetNamespace);
};

_di_IXMLsaldoType __fastcall  Newsaldo()
{
  return (_di_IXMLsaldoType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("saldo", __classid(TXMLsaldoType), TargetNamespace);
};

// TXMLsaldoType 

void __fastcall TXMLsaldoType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("transaction"), __classid(TXMLtransactionType));
  ItemTag = "transaction";
  ItemInterface = __uuidof(IXMLtransactionType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLtransactionType __fastcall TXMLsaldoType::Get_transaction(const int Index)
{
  return (_di_IXMLtransactionType) List->Nodes[Index];
};

_di_IXMLtransactionType __fastcall TXMLsaldoType::Add()
{
  return (_di_IXMLtransactionType) AddItem(-1);
};

_di_IXMLtransactionType __fastcall TXMLsaldoType::Insert(const int Index)
{
  return (_di_IXMLtransactionType) AddItem(Index);
};

// TXMLtransactionType 

System::UnicodeString __fastcall TXMLtransactionType::Get_Blagajnik()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Blagajnik")]->Text;
};

void __fastcall TXMLtransactionType::Set_Blagajnik(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Blagajnik")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLtransactionType::Get_Valuta()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Valuta")]->Text;
};

void __fastcall TXMLtransactionType::Set_Valuta(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Valuta")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLtransactionType::Get_Srednji_tecaj()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Srednji_tecaj")]->Text;
};

void __fastcall TXMLtransactionType::Set_Srednji_tecaj(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Srednji_tecaj")]->NodeValue = Value;
};

float __fastcall TXMLtransactionType::Get_Ulaz_EUR()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("Ulaz_EUR")]->Text);
};

void __fastcall TXMLtransactionType::Set_Ulaz_EUR(const float Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Ulaz_EUR")]->NodeValue = Value;
};

float __fastcall TXMLtransactionType::Get_Izlaz_EUR()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("Izlaz_EUR")]->Text);
};

void __fastcall TXMLtransactionType::Set_Izlaz_EUR(const float Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Izlaz_EUR")]->NodeValue = Value;
};
