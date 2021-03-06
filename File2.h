#ifndef HEADER
#define HEADER

#include <string>
#include <Grids.hpp>
#include <list>

using namespace std;

class CRealEstate
{
protected:
   int m_nNumbersRooms;
   int m_nTotalArea;
   int m_nPrice;
   string m_sType;
   string m_sAddress;
   string m_sOwner;
public:
   void vSetNumbersRooms(int _nNumbersRooms);
   void vSetTotalArea(int _nTotalArea);
   void vSetPrice(int _nPrice);
   void vSetType(string _sType);
   void vSetAddress(string _sAddress);
   void vSetOwner(string _sOwner);

   string sGetOwner()const;
   string sGetType()const;
   string sGetAddress()const;
   int nGetNumberRooms()const;
   int nGetTotalArea()const;
   int nGetPrice()const;
};

class CResidentialPremises : public CRealEstate
{
private:
   int m_nKitchenArea;
   int m_nRoomsArea;
   string m_sRepairCondition;
public:
   CResidentialPremises();
   CResidentialPremises(string, string, string, int, int, int, int, string, int);
   void vSetRepairCondition(string _sRepairCondition);
   void vSetKitchenArea(int _nKitchenArea);
   void vSetRoomsArea(int _nRoomsArea);
   int nGetKitchenArea()const;
   int nGetRoomsArea()const;
   string sGetRepairCondition()const;

   bool isDefinitionSquareMax(const CResidentialPremises &obj);
   bool isDefinitionSquareMin(const CResidentialPremises &obj);

   friend bool isSortAddressR(const CResidentialPremises &obj1, const CResidentialPremises &obj2);
   friend bool isSortNumberRoomsR(const CResidentialPremises &obj1, const CResidentialPremises &obj2);

   void vPrintRPInForm(int _nRows, TStringGrid *sg);

   ~CResidentialPremises();
};

class CNonResidentialPremises : public CRealEstate
{
private:
   string m_sPurpose;
public:
   CNonResidentialPremises();
   CNonResidentialPremises(string, string, string, int, int, string, int);
   void vSetPurpose(string _sPurpose);
   string sGetPurpose()const;

   friend bool isSortPurpose(const CNonResidentialPremises &obj1,const CNonResidentialPremises &obj2);
   friend bool isSortAddressN(const CNonResidentialPremises &obj1,const CNonResidentialPremises &obj2);
   friend bool isSortNumberRoomsN(const CNonResidentialPremises &obj1,const CNonResidentialPremises &obj2);

   bool isDefinitionSquareMax(const CNonResidentialPremises &obj);
   bool isDefinitionSquareMin(const CNonResidentialPremises &obj);

   void vPrintNRPInForm(int _nRows, TStringGrid *sg);

   ~CNonResidentialPremises();
};

class CSummator
{
   int sum ;
public:
   int operator()(const CResidentialPremises &obj);
   int operator()(const CNonResidentialPremises &obj);
   int operator()(list <CResidentialPremises> l1, list <CNonResidentialPremises> l2);
};

class Exception1
{
protected:
   int nNumberOfProblem;
   string sProblem;

public:
   virtual void vvDisplay() = 0;
};

class ReadFileException : public Exception1
{
   int nProblemRow;
public:
   ReadFileException(int , char * , int );
   void vvDisplay();
};

class AddInFormException : public Exception1
{
public:
   AddInFormException(int , char *);
   void vvDisplay();
};

class SearchInFormException : public Exception1
{
public:
   SearchInFormException(int , char *);
   void vvDisplay();
};

class DefinitionException : public Exception1
{
public:
   DefinitionException(int , char * );
   void vvDisplay();
};

class OtherException : public Exception1
{
public:
   OtherException(int , char * );
   void vvDisplay();
};

#endif
