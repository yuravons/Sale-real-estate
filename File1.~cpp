#include "File2.h"
#include <vcl.h>
#include <fstream>
#include <iostream>
#include <cctype>
#include <sstream>
#include <map>
#include "Unit2.h"

using namespace std;

//встановлення кількості кімнат
void CRealEstate :: vSetNumbersRooms(int _nNumbersRooms)
{
   m_nNumbersRooms = _nNumbersRooms;
}

//встановлення загальної площі
void CRealEstate :: vSetTotalArea(int _nTotalArea)
{
   m_nTotalArea = _nTotalArea;
}

//встановлення ціни
void CRealEstate :: vSetPrice(int _nPrice)
{
   m_nPrice = _nPrice;
}

//встановлення типу
void CRealEstate :: vSetType(string _sType)
{
   m_sType = _sType;
}

//встановлення адреси
void CRealEstate :: vSetAddress(string _sAddress)
{
   m_sAddress = _sAddress;
}

//встановлення імені власника
void CRealEstate :: vSetOwner(string _sOwner)
{
   m_sOwner = _sOwner;
}

//повернення типу
string CRealEstate :: sGetType()const
{
   return m_sType;
}

//повернення адреси
string CRealEstate :: sGetAddress()const
{
   return m_sAddress;
}

//повернення імені власника
string CRealEstate :: sGetOwner()const
{
   return m_sOwner;
}

//поверення кількості кімнат
int CRealEstate :: nGetNumberRooms()const
{
   return m_nNumbersRooms;
}

//поверення загальної площі
int CRealEstate :: nGetTotalArea()const
{
   return m_nTotalArea;
}

//поверення загальної ціни
int CRealEstate :: nGetPrice()const
{
   return m_nPrice;
}

//конструктор дочірнього класу без параметрів
CResidentialPremises :: CResidentialPremises()
{
   m_sType = "";
   m_sAddress = "";
   m_sOwner = "";
   m_nNumbersRooms = 0;
   m_nTotalArea = 0;
   m_nKitchenArea = 0;
   m_nRoomsArea = 0;
   m_sRepairCondition = "";
   m_nPrice = 0;
}

//конструктор дочірнього класу із параметрами
CResidentialPremises :: CResidentialPremises(string _sType,string _sAddress,string _sOwner,int _nNumberRooms,
int _nTotalArea, int _nKitchenArea, int _nRoomsArea,string _sRepairCondition,int _nPrice)
{
   m_sType = _sType;
   m_sAddress = _sAddress;
   m_sOwner = _sOwner;
   m_nNumbersRooms = _nNumberRooms;
   m_nTotalArea = _nTotalArea;
   m_nKitchenArea = _nKitchenArea;
   m_nRoomsArea = _nRoomsArea;
   m_sRepairCondition = _sRepairCondition;
   m_nPrice = _nPrice;
}

//встановлення цільового призначення
void CResidentialPremises :: vSetRepairCondition(string _sRepairCondition)
{
   m_sRepairCondition = _sRepairCondition;
}

//встановлення площі кухні
void CResidentialPremises :: vSetKitchenArea(int _nKitchenArea)
{
   m_nKitchenArea = _nKitchenArea ;
}

//встановлення площі кімнат
void CResidentialPremises :: vSetRoomsArea(int _nRoomsArea)
{
   m_nRoomsArea = _nRoomsArea ;
}

//повернення площі кухні
int CResidentialPremises :: nGetKitchenArea()const
{
   return m_nKitchenArea;
}

//повернення площі кімнат
int CResidentialPremises :: nGetRoomsArea()const
{
   return m_nRoomsArea;
}

//повернення цільового призначення
string CResidentialPremises :: sGetRepairCondition()const
{
    return m_sRepairCondition;
}

//перевірка знайденої максимальної площі
bool CResidentialPremises :: isDefinitionSquareMax(const CResidentialPremises &obj)
{
   bool isReplace;
   if(m_nTotalArea > obj.m_nTotalArea)
      isReplace = true;
   return isReplace;
}

//перевірка знайденої мінімальної площі
bool CResidentialPremises :: isDefinitionSquareMin(const CResidentialPremises &obj)
{
   bool isReplace;
   if(m_nTotalArea < obj.m_nTotalArea)
      isReplace = true;
   return isReplace;
}

//вивід об'єкта у StringGrid
void CResidentialPremises :: vPrintRPInForm(int _nRows, TStringGrid *sg)
{
   sg->Cells[0][_nRows+1] = m_sType.c_str();
   sg->Cells[1][_nRows+1] = m_sAddress.c_str();
   sg->Cells[2][_nRows+1] = m_sOwner.c_str();
   sg->Cells[3][_nRows+1] = IntToStr(m_nNumbersRooms);
   sg->Cells[4][_nRows+1] = IntToStr(m_nTotalArea);
   sg->Cells[5][_nRows+1] = IntToStr(m_nKitchenArea);
   sg->Cells[6][_nRows+1] = IntToStr(m_nRoomsArea);
   sg->Cells[7][_nRows+1] = m_sRepairCondition.c_str();
   sg->Cells[9][_nRows+1] = IntToStr(m_nPrice);
}

//порівняння об'єктів за адресою
bool isSortAddressR(const CResidentialPremises &obj1,const CResidentialPremises &obj2)
{
   return obj1.sGetAddress() < obj2.sGetAddress();
}

//порівняння об'єктів за кількістю кімнат
bool isSortNumberRoomsR(const CResidentialPremises &obj1,const CResidentialPremises &obj2)
{
   return obj1.nGetNumberRooms() < obj2.nGetNumberRooms();
}

//деструктор дочірнього класу
CResidentialPremises :: ~CResidentialPremises()
{

}

//конструктор дочірнього класу без параметрів
CNonResidentialPremises :: CNonResidentialPremises()
{
   m_sType = "";
   m_sAddress = "";
   m_sOwner = "";
   m_nNumbersRooms = 0;
   m_nTotalArea = 0;
   m_sPurpose = "";
   m_nPrice = 0;
}

//конструктор дочірнього класу із параметрами
CNonResidentialPremises :: CNonResidentialPremises(string _sType,string _sAddress,string _sOwner,int _nNumberRooms,
int _nTotalArea, string _sPurpose,int _nPrice)
{
   m_sType = _sType;
   m_sAddress = _sAddress;
   m_sOwner = _sOwner;
   m_nNumbersRooms = _nNumberRooms;
   m_nTotalArea = _nTotalArea;
   m_sPurpose = _sPurpose;
   m_nPrice = _nPrice;
}

//встановлення цільового призначення
void CNonResidentialPremises :: vSetPurpose(string _sPurpose)
{
   m_sPurpose = _sPurpose;
}

//повернення цільового призначення
string CNonResidentialPremises :: sGetPurpose()const
{
   return m_sPurpose;
}

//перевірка знайденої максимальної площі
bool CNonResidentialPremises :: isDefinitionSquareMax(const CNonResidentialPremises &obj)
{
   bool isReplace;
   if(m_nTotalArea > obj.m_nTotalArea)
      isReplace = true;
   return isReplace;
}

//перевірка знайденої мінімальної площі
bool CNonResidentialPremises :: isDefinitionSquareMin(const CNonResidentialPremises &obj)
{
   bool isReplace;
   if(m_nTotalArea < obj.m_nTotalArea)
      isReplace = true;
   return isReplace;
}

//порівняння об'єктів за цільовим призначенням
bool isSortPurpose(const CNonResidentialPremises &obj1,const CNonResidentialPremises &obj2)
{
  return obj1.sGetPurpose() < obj2.sGetPurpose();
}

//порівняння об'єктів за адресою
bool isSortAddressN(const CNonResidentialPremises &obj1,const CNonResidentialPremises &obj2)
{
   return obj1.sGetAddress() < obj2.sGetAddress();
}

//порівняння об'єктів за кількістю кімнат
bool isSortNumberRoomsN(const CNonResidentialPremises &obj1,const CNonResidentialPremises &obj2)
{
   return obj1.nGetNumberRooms() < obj2.nGetNumberRooms();
}

//вивід нежитлового об'єкта у StringGrid
void CNonResidentialPremises :: vPrintNRPInForm(int _nRows, TStringGrid *sg)
{
   sg->Cells[0][_nRows+1] = m_sType.c_str();
   sg->Cells[1][_nRows+1] = m_sAddress.c_str();
   sg->Cells[2][_nRows+1] = m_sOwner.c_str();
   sg->Cells[3][_nRows+1] = IntToStr(m_nNumbersRooms);
   sg->Cells[4][_nRows+1] = IntToStr(m_nTotalArea);
   sg->Cells[8][_nRows+1] = m_sPurpose.c_str();
   sg->Cells[9][_nRows+1] = IntToStr(m_nPrice);
}

//деструктор дочірнього класу
CNonResidentialPremises :: ~CNonResidentialPremises()
{

}

//перевизначення оператора для житлових об'єктів
int CSummator :: operator()(const CResidentialPremises &obj)
{
   sum = obj.nGetPrice();
   return sum;
}

//перевизначення оператора для нежитлових об'єктів
int CSummator :: operator()(const CNonResidentialPremises &obj)
{
   sum = obj.nGetPrice();
   return sum;
}

//перевизначення оператора для усіх об'єктів
int CSummator ::  operator()(list <CResidentialPremises> l1, list <CNonResidentialPremises> l2)
{
   sum = 0;
   for (list <CResidentialPremises> :: iterator it1 = l1.begin(); it1 != l1.end(); ++it1)
      sum += it1->nGetPrice();
   for (list <CNonResidentialPremises> :: iterator it2 = l2.begin(); it2 != l2.end(); ++it2)
      sum += it2->nGetPrice();
   return sum;
}

//констуктор класу обробки виключень зчитування із файлу
ReadFileException :: ReadFileException(int nNumberOfProblem, char * sProblem, int nProblemRow)
{
   this->nNumberOfProblem = nNumberOfProblem;
   this->sProblem = sProblem;
   this->nProblemRow = nProblemRow;
}

//вивід виключень для зчитування із файлу
void ReadFileException :: vvDisplay()
{
   ShowMessage("Problem " + IntToStr(nNumberOfProblem) + " in " + IntToStr(nProblemRow)+
    " row: " + sProblem.c_str());
}

//констуктор класу обробки виключень додавання елементу
AddInFormException :: AddInFormException(int nNumberOfProblem, char * sProblem)
{
   this->nNumberOfProblem = nNumberOfProblem;
   this->sProblem = sProblem;
}

//вивід виключень для додавання елементу
void AddInFormException :: vvDisplay()
{
   ShowMessage("Problem " + IntToStr(nNumberOfProblem) +  ": "+ sProblem.c_str());
}

//констуктор класу обробки виключень пошуку елементу
SearchInFormException :: SearchInFormException(int nNumberOfProblem, char * sProblem)
{
   this->nNumberOfProblem = nNumberOfProblem;
   this->sProblem = sProblem;
}

//вивід виключень для пошуку елементу
void SearchInFormException :: vvDisplay()
{
   ShowMessage("Problem " + IntToStr(nNumberOfProblem) +  ": "+ sProblem.c_str());
}

//констуктор класу обробки виключень всіх інших функцій
OtherException :: OtherException(int nNumberOfProblem, char * sProblem)
{
   this->nNumberOfProblem = nNumberOfProblem;
   this->sProblem = sProblem;
}

//вивід виключень для всіх інших
void OtherException :: vvDisplay()
{
   ShowMessage("Problem " + IntToStr(nNumberOfProblem) +
    " : " + sProblem.c_str());
}

//констуктор класу обробки виключень всіх інших функцій
DefinitionException :: DefinitionException(int nNumberOfProblem, char * sProblem)
{
   this->nNumberOfProblem = nNumberOfProblem;
   this->sProblem = sProblem;
}

//вивід виключень для всіх інших
void DefinitionException :: vvDisplay()
{
   ShowMessage("Problem " + IntToStr(nNumberOfProblem) +
    " : " + sProblem.c_str());
}




























