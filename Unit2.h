#ifndef COLECTION_H
#define COLECTION_H

#include "File2.h"
#include <Grids.hpp>
#include <list>

using namespace std;

class CColection
{
private:
   list <CResidentialPremises> ListR;
   list <CNonResidentialPremises> ListN;
public:
   void vReadFile(TStringGrid *sg);
   char chRead(char *pTemporaryArray, ifstream &fin,int j);
   void vCreateObjects(TStringGrid *sg);
   void vSearchMaxSquare(TStringGrid *sg);
   void vSearchMinSquare(TStringGrid *sg);
   void vSearchMaxSquareRP(TStringGrid *sg);
   void vSearchMinSquareRP(TStringGrid *sg);
   void vSearchMaxSquareNRP(TStringGrid *sg);
   void vSearchMinSquareNRP(TStringGrid *sg);
   void vAddObjects(TStringGrid *sg);
   void vPrintObjects(TStringGrid *sg);
   void vDeleteAllObjects(TEdit *ed);
   void vSearchOwnerWith2(TStringGrid *sg);
   void vDeleteChooseObject(TStringGrid *sg, TEdit *ed);
   void vSaveToFile();
   string toString(int _nValue);
   bool isSeachByParametr(int _nCheckSearch, TEdit *ed, TStringGrid *sg);
   void vSortingPurpose(TStringGrid *sg);
   void vSortingAddress(TStringGrid *sg);
   void vSortingNumberRooms(TStringGrid *sg);
   friend bool isUint(const string &);
};

#endif
