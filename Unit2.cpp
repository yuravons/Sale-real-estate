#pragma hdrstop

#include "Unit2.h"
#pragma package(smart_init)
#include <fstream>
#include <map>
#include <sstream>
using namespace std;

//перевірка чи стрічка є числом
bool isUint(const string &s)
{
    return s.find_first_not_of("0123456789") == string::npos;
}

//приведення до типу string
string CColection :: toString(int _nValue)
{
    ostringstream oss;
    oss << _nValue;
    return oss.str();
}

//зчитування слова із файлу
char CColection :: chRead(char *pTemporaryArray, ifstream &fin,int j)
{
   int i = 0;
   char ch;
   while ((ch = fin.get()) != '|'){
      if(isdigit(ch))
         throw ReadFileException(3, "You entered a digit instead word!", j + 1);
      if (i < 10 && !isspace(ch))
      {
         pTemporaryArray[i] = ch;
         ++i;
         pTemporaryArray[i] = '\0';
      }
      else
         continue;
   }
   return *pTemporaryArray;
}

//функція зчитування із файлу та записування у StringGrid
void CColection :: vReadFile(TStringGrid *sg)
{
   ifstream fin1("Read.txt");
      if (!fin1)
         throw OtherException(1, "No file in folder!");
      else if(fin1.peek() == EOF)
         throw OtherException(2, "File is empty!");
      fin1.close();
      ifstream fin("Read.txt");
      char chInformation[200];
      bool isInfo = true;
      if(isInfo){
         isInfo = false;
         fin.getline(chInformation,200) ;
      }
      int c = 0, count , j = 0;
      while(1){
         if(sg->Cells[0][j+1] == "")
            break;
         ++j;
      }
      bool isFlag;
      char *pTemporaryArray;
      do{
         if (fin.eof())
            break;
         c = 0;
         while((fin.get())!='|');

         //Type
         pTemporaryArray = new char[10];
         *pTemporaryArray = chRead(pTemporaryArray, fin, j);
         sg->Cells[c][j+1] = pTemporaryArray;
         ++c;
         delete []pTemporaryArray;
         if (sg->Cells[0][j+1] == "RP")
            isFlag = true;
         else if (sg->Cells[0][j+1] == "NRP")
            isFlag = false;
         //address
         pTemporaryArray = new char[10];
         *pTemporaryArray = chRead(pTemporaryArray, fin, j);
         sg->Cells[c][j+1] = pTemporaryArray;
         ++c;
         delete []pTemporaryArray;

         //Owner
         pTemporaryArray = new char[10];
         *pTemporaryArray = chRead(pTemporaryArray, fin, j);
         sg->Cells[c][j+1] = pTemporaryArray;
         ++c;
         delete []pTemporaryArray;

         //NumbersRooms
         fin >> count;
         if (fin.fail())
            throw ReadFileException(4, "You don`t entered digit!",j+1);
         sg->Cells[c][j+1] = IntToStr(count);
         if(IntToStr(count) < 0)
            throw ReadFileException(5, "You entered a negative number!",j+1);
         ++c;
         while((fin.get())!='|');

         //TotalArea
         fin >> count;
         if (fin.fail())
            throw ReadFileException(4, "You don`t entered digit!",j+1);
         sg->Cells[c][j+1] = IntToStr(count);
         if(IntToStr(count) < 0)
            throw ReadFileException(5, "You entered a negative number!",j+1);
         ++c;
         while((fin.get())!='|');

         if(isFlag){
            //kitchenArea
            fin >> count ;
            if (fin.fail())
               throw ReadFileException(4, "You don`t entered digit!", j+1);
            sg->Cells[c][j+1] = IntToStr(count);
            if(IntToStr(count) < 0)
               throw ReadFileException(5, "You entered a negative number!",j+1);
            ++c;
            while((fin.get())!='|') ;

            //Rooms area
            fin >> count ;
            if (fin.fail())
               throw ReadFileException(4, "You don`t entered digit!",j+1);
            sg->Cells[c][j+1] = IntToStr(count);
            if(IntToStr(count) < 0)
               throw ReadFileException(5, "You entered a negative number!",j+1);
            ++c;
            while((fin.get())!='|');
         }
         else{
            ++c;
            while((fin.get())!='|') ;
            ++c;
            while((fin.get())!='|');
         }
         if(isFlag){
            //RepairCondition
            pTemporaryArray = new char[10];
            *pTemporaryArray = chRead(pTemporaryArray, fin,j);
            sg->Cells[c][j+1] = pTemporaryArray;
            ++c;
            delete []pTemporaryArray;
         }
         else{
            while((fin.get())!='|');
            ++c;
         }
         if(!isFlag){
            //Purpose
            pTemporaryArray = new char[10];
            *pTemporaryArray = chRead(pTemporaryArray, fin,j);
            sg->Cells[c][j+1] = pTemporaryArray;
            ++c;

            delete [] pTemporaryArray;
         }
         else{
            while ((fin.get()) != '|');
            ++c;
         }
         fin >> count;
         if (fin.fail())
            throw ReadFileException(4, "You don`t entered digit!",j+1);
         while((fin.get())!='|');
         sg->Cells[c][j+1] = IntToStr(count);
         if(IntToStr(count) < 0)
            throw ReadFileException(5, "You entered a negative number!",j+1);
         ++j;
         fin.getline(chInformation,200) ;
      }while(1);
   fin.close();
}

//створення об'єктів
void CColection :: vCreateObjects(TStringGrid *sg)
{
   int i = 0;
   while(1){
      if(sg->Cells[0][i+1] == ""){
         break;
      }
      else if(sg->Cells[0][i+1]=="RP"){
         CResidentialPremises *objR = new CResidentialPremises;
         objR->vSetType((sg->Cells[0][i+1]).c_str());
         objR->vSetAddress((sg->Cells[1][i+1]).c_str());
         objR->vSetOwner((sg->Cells[2][i+1]).c_str());
         objR->vSetNumbersRooms(StrToInt(sg->Cells[3][i+1]));
         objR->vSetTotalArea(StrToInt(sg->Cells[4][i+1]));
         objR->vSetKitchenArea(StrToInt(sg->Cells[5][i+1]));
         objR->vSetRoomsArea(StrToInt(sg->Cells[6][i+1]));
         objR->vSetRepairCondition((sg->Cells[7][i+1]).c_str());
         objR->vSetPrice(StrToInt(sg->Cells[9][i+1]));
         ListR.push_back(*objR);
         delete objR;
      }
      else if(sg->Cells[0][i+1]=="NRP"){
         CNonResidentialPremises *objN = new CNonResidentialPremises;
         objN->vSetType((sg->Cells[0][i+1]).c_str());
         objN->vSetAddress((sg->Cells[1][i+1]).c_str());
         objN->vSetOwner((sg->Cells[2][i+1]).c_str());
         objN->vSetNumbersRooms(StrToInt(sg->Cells[3][i+1]));
         objN->vSetTotalArea(StrToInt(sg->Cells[4][i+1]));
         objN->vSetPurpose((sg->Cells[8][i+1]).c_str());
         objN->vSetPrice(StrToInt(sg->Cells[9][i+1]));
         ListN.push_back(*objN);
         delete objN;
      }
      ++i;
   }
}

//пошук найбільшої площі з усіх
void CColection :: vSearchMaxSquare(TStringGrid *sg)
{
   try
   {
      if(ListR.size() == 0 && ListN.size() == 0)
         throw DefinitionException(6,"There are not elements!");
      if(ListR.size() == 0)
         throw DefinitionException(7,"There are not RP elements, please choose Definition only for NRP!");
      if(ListN.size() == 0)
         throw DefinitionException(8,"There are not NRP elements, please choose Definition only for RP!");
      int k = 0;
      CResidentialPremises *obj1 = new CResidentialPremises;
      *obj1 = ListR.back();
      for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR !=  ListR.end();++itR)
         if(itR->isDefinitionSquareMax(*obj1))
            *obj1 = *itR;
      CNonResidentialPremises *obj2 = new CNonResidentialPremises;
      *obj2 = ListN.back();
      for(list <CNonResidentialPremises> :: iterator itN = ListN.begin();itN != ListN.end();++itN)
         if(itN->isDefinitionSquareMax(*obj2))
            *obj2 = *itN;
      if(obj1->nGetTotalArea() >= obj2->nGetTotalArea()){
         for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR){
            if(itR->nGetTotalArea() == obj1->nGetTotalArea()){
               itR->vPrintRPInForm(k, sg);
               ++k;
            }
         }
         for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN){
            if(itN->nGetTotalArea() == obj1->nGetTotalArea()){
               itN->vPrintNRPInForm(k, sg);
               ++k;
            }
         }
      }
      else{
         for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR){
            if(itR->nGetTotalArea() == obj2->nGetTotalArea()){
               itR->vPrintRPInForm(k, sg);
               ++k;
            }
         }
         for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN){
            if(itN->nGetTotalArea() == obj2->nGetTotalArea()){
               itN->vPrintNRPInForm(k, sg);
               ++k;
            }
         }
      }
      delete obj1;
      delete obj2;
   }
   catch(DefinitionException exp)
   {
      exp.vvDisplay();
   }
}

//пошук найменшої площі з усіх
void CColection :: vSearchMinSquare(TStringGrid *sg)
{
   try
   {
      if(ListR.size() == 0 && ListN.size() ==0)
         throw DefinitionException(6,"There are not elements!");
      if(ListR.size() == 0)
         throw DefinitionException(7,"There are not RP elements, please choose Definition only for NRP!");
      if(ListN.size()== 0)
         throw DefinitionException(8,"There are not NRP elements, please choose Definition only for RP!");
      int k = 0;
      CResidentialPremises *obj1 = new CResidentialPremises;
      *obj1 = ListR.back();
      for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR)
         if(itR->isDefinitionSquareMin(*obj1))
            *obj1 = *itR;
      CNonResidentialPremises *obj2 = new CNonResidentialPremises;
      *obj2 = ListN.back();
      for(list <CNonResidentialPremises> :: iterator itN = ListN.begin();itN != ListN.end();++itN)
         if(itN->isDefinitionSquareMin(*obj2))
            *obj2 = *itN;
      if(obj1->nGetTotalArea() >= obj2->nGetTotalArea()){
         for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR){
            if(itR->nGetTotalArea() == obj1->nGetTotalArea()){
               itR->vPrintRPInForm(k, sg);
               ++k;
            }
         }
         for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN){
            if(itN->nGetTotalArea() == obj1->nGetTotalArea()){
               itN->vPrintNRPInForm(k, sg);
               ++k;
            }
         }
      }
      else{
         for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR){
            if(itR->nGetTotalArea() == obj2->nGetTotalArea()){
               itR->vPrintRPInForm(k,sg);
               ++k;
            }
         }
         for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN){
            if(itN->nGetTotalArea() == obj2->nGetTotalArea()){
               itN->vPrintNRPInForm(k, sg);
               ++k;
            }
         }
      }
      delete obj1;
      delete obj2;
   }
   catch(DefinitionException exp)
   {
      exp.vvDisplay();
   }
}

//додавання елементу
void CColection :: vAddObjects(TStringGrid *sg)
{
   CResidentialPremises *obj1;
   CNonResidentialPremises *obj2;
   bool isRP;
   if(sg->Cells[0][1] == "RP")
      isRP = true;
   else
      isRP = false;
   unsigned int i = 0;
   if(sg->Cells[0][1] == "" )
      throw AddInFormException(9,"You uncorrectly entered type!");
   //Адреса
   if(sg->Cells[1][1] == "" )
      throw AddInFormException(16,"You uncorrectly entered address!");
   string sTmpString3 = (sg->Cells[1][1]).c_str();
   i = 0;
   while(i < sTmpString3.length()){
      if(!isalpha(sTmpString3[i]))
          throw AddInFormException(16,"You uncorrectly entered address!");
      ++i;
   }
   //Власник
   if(sg->Cells[2][1] == "")
      throw AddInFormException(17,"You uncorrectly entered owner!");
   string sTmpString4 = (sg->Cells[2][1]).c_str();
   i = 0;
   while(i < sTmpString4.length()){
      if(!isalpha(sTmpString4[i]))
         throw AddInFormException(17,"You uncorrectly entered owner!");
      ++i;
   }
   //Кількість кімнат
   if(!isUint((sg->Cells[3][1]).c_str()) || (sg->Cells[3][1] == ""))
      throw AddInFormException(18,"You don`t entered a number in Number rooms!");
   //Загальна площа
   if(!isUint((sg->Cells[4][1]).c_str()) || (sg->Cells[4][1] == ""))
      throw AddInFormException(19,"You don`t entered a number in Total area!");
   if(isRP){
      //Тип
      obj1 = new CResidentialPremises;
      if(sg->Cells[0][1] != "RP")
         throw AddInFormException(9,"You don`t entered a right type!");
      //Площа кухні
      if(!isUint((sg->Cells[5][1]).c_str()) || (sg->Cells[5][1] == ""))
         throw AddInFormException(10,"You don`t entered a number in Kitchen area!");
      //Площа кімнат
      if(!isUint((sg->Cells[6][1]).c_str()) || (sg->Cells[6][1] == ""))
         throw AddInFormException(11,"You don`t entered a number in Rooms area!");
      //Ціна
      if(!isUint((sg->Cells[8][1]).c_str()) || (sg->Cells[8][1] == ""))
         throw AddInFormException(13,"You don`t entered a number in Price!");
      //чи сума площ не більша за загальну
      if(StrToInt(sg->Cells[5][1]) < 0 || StrToInt(sg->Cells[6][1]) < 0 || StrToInt(sg->Cells[8][1]) < 0 ||
         StrToInt(sg->Cells[3][1]) < 0 || StrToInt(sg->Cells[4][1]) < 0)
         throw AddInFormException(5,"You entered a negative number!");
      if((StrToInt(sg->Cells[6][1]) + StrToInt(sg->Cells[5][1]) )
         > StrToInt(sg->Cells[4][1]))
         throw AddInFormException(12,"Square of Kitchen and Rooms are bigger than Total area!");

      //Стан ремонту
      if(sg->Cells[7][1] == "")
         throw AddInFormException(14,"You uncorrectly entered repair condition!");
      string sTmpString1 = (sg->Cells[7][1]).c_str();
      i = 0;
      while(i < sTmpString1.length()){
         if(!isalpha(sTmpString1[i]) )
            throw AddInFormException(14,"You uncorrectly entered repair condition!");
         ++i;
      }
   }
   else if(!isRP){
      //Тип
      obj2 = new CNonResidentialPremises;
      if(sg->Cells[0][1] != "NRP")
         throw AddInFormException(9,"You don`t entered a right type!");
      //Ціна
      if(!isUint((sg->Cells[6][1]).c_str()) || (sg->Cells[6][1] == ""))
         throw AddInFormException(13,"You don`t entered a number in Price!");
      if(StrToInt(sg->Cells[6][1]) < 0 || StrToInt(sg->Cells[3][1]) < 0 || StrToInt(sg->Cells[4][1]) < 0)
         throw AddInFormException(5,"You entered a negative number!");
      //Цільове призначення
      if(sg->Cells[5][1] == "")
         throw AddInFormException(15,"You uncorrectly entered purpose!");
      string sTmpString2 = (sg->Cells[5][1]).c_str();
      i = 0;
      while(i < sTmpString2.length()){
         if(!isalpha(sTmpString2[i]))
            throw AddInFormException(15,"You uncorrectly entered purpose!");
         ++i;
      }
   }
   if(isRP){
      obj1->vSetType((sg->Cells[0][1]).c_str());
      obj1->vSetAddress((sg->Cells[1][1]).c_str());
      obj1->vSetOwner((sg->Cells[2][1]).c_str());
      obj1->vSetNumbersRooms(StrToInt(sg->Cells[3][1]));
      obj1->vSetTotalArea(StrToInt(sg->Cells[4][1]));
      obj1->vSetKitchenArea(StrToInt(sg->Cells[5][1]));
      obj1->vSetRoomsArea(StrToInt(sg->Cells[6][1]));
      obj1->vSetRepairCondition((sg->Cells[7][1]).c_str());
      obj1->vSetPrice(StrToInt(sg->Cells[8][1]));
      ListR.push_back(*obj1);
      delete obj1;
   }
   else{
      obj2->vSetType((sg->Cells[0][1]).c_str());
      obj2->vSetAddress((sg->Cells[1][1]).c_str());
      obj2->vSetOwner((sg->Cells[2][1]).c_str());
      obj2->vSetNumbersRooms(StrToInt(sg->Cells[3][1]));
      obj2->vSetTotalArea(StrToInt(sg->Cells[4][1]));
      obj2->vSetPurpose((sg->Cells[5][1]).c_str());
      obj2->vSetPrice(StrToInt(sg->Cells[6][1]));
      ListN.push_back(*obj2);
      delete obj2;
   }
}

//вивід об'єктів
void CColection :: vPrintObjects(TStringGrid *sg)
{
   int i = 0;
   for(list <CResidentialPremises> :: iterator itR = ListR.begin();itR != ListR.end();++itR, ++i)
      itR->vPrintRPInForm(i, sg);
   for(list <CNonResidentialPremises> :: iterator itN = ListN.begin();itN !=ListN.end();++itN,++i)
      itN->vPrintNRPInForm(i, sg);
}

//видалення усіх елементів
void CColection :: vDeleteAllObjects(TEdit *ed)
{
   ed->Text = IntToStr(CSummator()(ListR,ListN));
   ListR.clear();
   ListN.clear();
}

//пошук максимальноої площі RP
void CColection :: vSearchMaxSquareRP(TStringGrid *sg)
{
   try
   {
      if(ListR.size()== 0)
         throw DefinitionException(7,"There are not RP elements!");
      int k = 0;
      CResidentialPremises *obj1 = new CResidentialPremises;
      *obj1 = ListR.back();
      for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR)
         if(itR->isDefinitionSquareMax(*obj1))
            *obj1 = *itR;
      for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR){
         if(itR->nGetTotalArea() == obj1->nGetTotalArea()){
            itR->vPrintRPInForm(k, sg);
            ++k;
         }
      }
      delete obj1;
   }
   catch(DefinitionException exp)
   {
      exp.vvDisplay();
   }
}

//пошук мінімальної площі RP
void CColection :: vSearchMinSquareRP(TStringGrid *sg)
{
   try
   {
      if(ListR.size() ==0)
         throw DefinitionException(7,"There are not RP elements!");
      int k = 0;
      CResidentialPremises *obj1 = new CResidentialPremises;
      *obj1 = ListR.back();
      for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR)
         if(itR->isDefinitionSquareMin(*obj1))
            *obj1 = *itR;
      for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR){
         if(itR->nGetTotalArea() == obj1->nGetTotalArea()){
            itR->vPrintRPInForm(k,sg);
            ++k;
         }
      }
      delete obj1;
   }
   catch(DefinitionException exp)
   {
      exp.vvDisplay();
   }
}

//пошук максимальної площі NRP
void CColection :: vSearchMaxSquareNRP(TStringGrid *sg)
{
   try
   {
      if(ListN.size() == 0)
         throw DefinitionException(8,"There are not NRP elements!");
      int k = 0;
      CNonResidentialPremises *obj1 = new CNonResidentialPremises;
      *obj1 = ListN.back();
      for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN)
         if(itN->isDefinitionSquareMax(*obj1))
            *obj1 = *itN;
      for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN){
         if(itN->nGetTotalArea() == obj1->nGetTotalArea()){
            itN->vPrintNRPInForm(k,sg);
            ++k;
         }
      }
      delete obj1;
   }
   catch(DefinitionException exp)
   {
      exp.vvDisplay();
   }
}

//пошук мінімальна площі NRP
void CColection :: vSearchMinSquareNRP(TStringGrid *sg)
{
   try
   {
      if(ListN.size() == 0)
         throw DefinitionException(8,"There are not NRP elements!");
      int k = 0;
      CNonResidentialPremises *obj1 = new CNonResidentialPremises;
      *obj1 = ListN.back();
      for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN)
         if(itN->isDefinitionSquareMin(*obj1))
            *obj1 = *itN;
      for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN){
         if(itN->nGetTotalArea() == obj1->nGetTotalArea()){
            itN->vPrintNRPInForm(k,sg);
            ++k;
         }
      }
      delete obj1;
   }
   catch(DefinitionException exp)
   {
      exp.vvDisplay();
   }
}


//пошук власників, які мають більше двох нерухомостей
void CColection :: vSearchOwnerWith2(TStringGrid *sg)
{
   //контейнер для пошуку власника,який має більше двох приміщень
   map <string,int> mOwnersMap;
   map <string, int> :: iterator i;
   string sOwners;
   for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR)
      sOwners += itR->sGetOwner() + " ";
   for(list <CNonResidentialPremises> :: iterator itN =ListN.begin(); itN != ListN.end();++itN)
      sOwners += itN->sGetOwner() + " ";
   istringstream ist(sOwners);
   while (ist >> sOwners)
      mOwnersMap[sOwners]++;
   int j =0;
   for (i = mOwnersMap.begin(); i != mOwnersMap.end(); ++i){
      if(i->second >= 2){
         for(list <CResidentialPremises> :: iterator itR = ListR.begin(); itR != ListR.end();++itR){
            if(i->first == itR->sGetOwner()){
               itR->vPrintRPInForm(j,sg);
               ++j;
            }
         }
         for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN){
            if(i->first  == itN->sGetOwner())
            {
               itN->vPrintNRPInForm(j,sg);
               ++j;
            }
         }
      }
   }
}

//видалення обраного елемента
void CColection :: vDeleteChooseObject(TStringGrid *sg, TEdit *ed)
{
   unsigned int nTop = sg->Selection.Top;
   if(sg->Cells[0][nTop] == "")
      throw OtherException(21,"You don`t choosed element!");
   list <CResidentialPremises> :: iterator itR = ListR.begin();
   list <CNonResidentialPremises> :: iterator itN = ListN.begin();
   for(unsigned int i = 0; i < (ListR.size() + ListN.size())*25;++i){
      if(i == nTop && sg->Cells[0][i] == "RP"){
         ed->Text = IntToStr(CSummator()(*itR));
         ListR.erase(itR);
         break;
      }
      else if(i == nTop && sg->Cells[0][i] == "NRP"){
         ed->Text = IntToStr(CSummator()(*itN));
         ListN.erase(itN);
         break;
      }
      if(sg->Cells[0][i] == "RP")
         ++itR;
      else if(sg->Cells[0][i] == "NRP")
         ++itN;
   }
   for(int i = 0;i < sg->ColCount;i++)
      for(int j = 1; j < sg->RowCount;j++)
         sg->Cells[i][j] = "";
   vPrintObjects(sg);
}

//збереження у файл
void CColection :: vSaveToFile()
{
   TStringList *List = new TStringList();
   List->Clear();
   string sStr;
   for(list <CResidentialPremises> :: iterator itR = ListR.begin();itR != ListR.end();++itR){
      sStr = "";
      sStr +="|";
      sStr += itR->sGetType()+"|" + itR->sGetAddress() + "|" + itR->sGetOwner() +"|" +
      toString(itR->nGetNumberRooms()) + "|"  + toString(itR->nGetTotalArea()) + "|"
      +toString(itR->nGetKitchenArea()) + "|" + toString(itR->nGetRoomsArea()) +
      "|" + itR->sGetRepairCondition() + "|" +  toString(itR->nGetPrice()) + "|" ;
      List->Add(sStr.c_str());
   }
   for(list <CNonResidentialPremises> :: iterator itN = ListN.begin(); itN != ListN.end();++itN){
      sStr = "";
      sStr +="|";
      sStr += itN->sGetType()+ "|" + itN->sGetAddress() + "|" + itN->sGetOwner()
      + "|" + toString(itN->nGetNumberRooms()) + "|"  + toString(itN->nGetTotalArea()) +
      "|" +itN->sGetPurpose() + "|" + toString(itN->nGetPrice()) + "|" ;
      List->Add(sStr.c_str());
   }
   List->SaveToFile("Result.txt");
}

//пошук за заданим параметром
bool CColection :: isSeachByParametr(int _nCheckSearch ,TEdit *ed, TStringGrid *sg)
{
   int j = 0;
   if(ed->Text == "")
      throw SearchInFormException(22,"You don`t entered a parametr!");
   bool isCheckedSearch, isWasDeletingElement = false;
   for(list <CResidentialPremises> :: iterator itR = ListR.begin();itR != ListR.end();++itR){
      isCheckedSearch = false;
      switch(_nCheckSearch){
         case 1:{
            string sTmpString = ed->Text.c_str();
            unsigned int i = 0;
            while(i < sTmpString.length()){
               if(!isalpha(sTmpString[i]))
                  throw SearchInFormException(16,"You uncorrectly entered address!");
               ++i;
            }
            if(itR->sGetAddress() ==  ed->Text.c_str())
               isCheckedSearch = true;
            break;
         }
         case 2:{
            string sTmpString = ed->Text.c_str();
            unsigned int i = 0;
            while(i < sTmpString.length()){
               if(!isalpha(sTmpString[i]))
                  throw SearchInFormException(17,"You uncorrectly entered owner!");
               ++i;
            }
            if(itR->sGetOwner() ==  ed->Text.c_str())
               isCheckedSearch = true;
            break;
         }
         case 3:{
            if(!isUint(ed->Text.c_str()) || (ed->Text.c_str() == ""))
               throw SearchInFormException(18,"You don`t entered a number in number rooms!");
            if(itR->nGetNumberRooms() ==  StrToInt(ed->Text))
               isCheckedSearch = true;
            break;
         }
         case 4:{
            if(!isUint(ed->Text.c_str()) || (ed->Text.c_str() == ""))
               throw SearchInFormException(19,"You don`t write a number in total area!");
            if(itR->nGetTotalArea() ==  StrToInt(ed->Text))
               isCheckedSearch = true;
            break;
         }
         case 5:{
            if(!isUint(ed->Text.c_str()) || (ed->Text.c_str() == ""))
               throw SearchInFormException(10,"You don`t entered a number in kitchen square!");
            if(itR->nGetKitchenArea() ==  StrToInt(ed->Text))
               isCheckedSearch = true;
            break;
         }
         case 6:{
            if(!isUint(ed->Text.c_str()) || (ed->Text.c_str() == ""))
               throw SearchInFormException(11,"You don`t entered a number in rooms area!");
            if(itR->nGetRoomsArea() ==  StrToInt(ed->Text))
               isCheckedSearch = true;
            break;
         }
         case 7:{
            string sTmpString = ed->Text.c_str();
            unsigned int i = 0;
            while(i < sTmpString.length()){
               if(!isalpha(sTmpString[i]))
                   throw SearchInFormException(14,"You uncorrectly entered repair condition!");
               ++i;
            }
            if(itR->sGetRepairCondition() ==  ed->Text.c_str())
               isCheckedSearch = true;
            break;
         }
         case 8:
            break;
         case 9:{
            if(!isUint(ed->Text.c_str()) || (ed->Text.c_str() == ""))
               throw SearchInFormException(13,"You don`t entered a number in price!");
            if(itR->nGetPrice() ==  StrToInt(ed->Text))
               isCheckedSearch = true;
            break;
         }
      }
      if(!isCheckedSearch && !isWasDeletingElement)
         isWasDeletingElement = false;
      else
         isWasDeletingElement = true;
      if(isCheckedSearch){
         itR->vPrintRPInForm(j,sg);
         ++j;
      }
   }
   for(list <CNonResidentialPremises> :: iterator itN = ListN.begin();itN != ListN.end();++itN){
      isCheckedSearch = false;
      switch(_nCheckSearch){
         case 1:{
            string sTmpString = ed->Text.c_str();
            unsigned int i = 0;
            while(i < sTmpString.length()){
            if(!isalpha(sTmpString[i]))
               throw SearchInFormException(16,"You uncorrectly entered address!");
            ++i;
            }
            if(itN ->sGetAddress() ==  ed->Text.c_str())
               isCheckedSearch = true;
            break;
         }
         case 2:{
            string sTmpString = ed->Text.c_str();
            unsigned int i = 0;
            while(i < sTmpString.length()){
               if(!isalpha(sTmpString[i]))
                  throw SearchInFormException(17,"You uncorrectly entered owner!");
               ++i;
            }
            if(itN->sGetOwner() ==  ed->Text.c_str())
               isCheckedSearch = true;
            break;
         }
         case 3:{
            if(!isUint(ed->Text.c_str()) || (ed->Text.c_str() == ""))
               throw SearchInFormException(18,"You don`t entered a number in number rooms!");
            if(itN->nGetNumberRooms() ==  StrToInt(ed->Text))
               isCheckedSearch = true;
            break;
         }
         case 4:{
            if(!isUint(ed->Text.c_str()) || (ed->Text.c_str() == ""))
               throw SearchInFormException(19,"You don`t entered a number in total area!");
            if(itN->nGetTotalArea() ==  StrToInt(ed->Text))
               isCheckedSearch = true;
            break;
         }
         case 8:{
            string sTmpString = ed->Text.c_str();
            unsigned int i = 0;
            while(i < sTmpString.length()){
               if(!isalpha(sTmpString[i]))
                  throw SearchInFormException(15,"You uncorrectly entered purpose!");
               ++i;
            }
            if(itN->sGetPurpose() ==  ed->Text.c_str())
               isCheckedSearch = true;
            break;
         }
         case 9:{
            if(!isUint(ed->Text.c_str()) || (ed->Text.c_str() == ""))
               throw SearchInFormException(13,"You don`t entered a number in price!");
            if(itN->nGetPrice() ==  StrToInt(ed->Text))
               isCheckedSearch = true;
            break;
         }
         default:
            break;
      }
      if(!isCheckedSearch && !isWasDeletingElement)
         isWasDeletingElement = false;
      else
         isWasDeletingElement = true;
      if(isCheckedSearch){
         itN->vPrintNRPInForm(j,sg);
         ++j  ;
      }
   }
   if((!isCheckedSearch) && (isWasDeletingElement == false) )
      isWasDeletingElement = false;
   else
      isWasDeletingElement = true;
   return isWasDeletingElement;
}

//сортування за цільовим призначенням
void CColection :: vSortingPurpose(TStringGrid *sg)
{
   int i = 0;
   ListN.sort(isSortPurpose);
   for(list <CNonResidentialPremises> :: iterator itN = ListN.begin();itN != ListN.end();++itN, ++i)
      itN->vPrintNRPInForm(i,sg);
}

//сортування за адресою
void CColection :: vSortingAddress(TStringGrid *sg)
{
   int i = 0;
   ListR.sort(isSortAddressR);
   ListN.sort(isSortAddressN);
   list <CNonResidentialPremises> :: iterator itN = ListN.begin();
   list <CResidentialPremises> :: iterator itR = ListR.begin();
   while(1){
      if(itN == ListN.end() && itR == ListR.end())
         break;
      if(itR->sGetAddress() <= itN->sGetAddress()){
         itR->vPrintRPInForm(i,sg);
         ++itR;
         ++i;
         if(itR == ListR.end()){
            while(itN != ListN.end()){
               itN->vPrintNRPInForm(i,sg);
               ++itN;
               ++i;
            }
            break;
         }
      }
      else if(itN->sGetAddress() < itR->sGetAddress()){
         itN->vPrintNRPInForm(i,sg);
         ++itN;
         ++i;
         if(itN == ListN.end()){
            while(itR != ListR.end()){
               itR->vPrintRPInForm(i,sg);
               ++itR;
               ++i;
            }
            break;
         }
      }
   }
}

//сортування за кількістю кімнат
void CColection :: vSortingNumberRooms(TStringGrid *sg)
{
   int i = 0;
   ListR.sort(isSortNumberRoomsR);
   ListN.sort(isSortNumberRoomsN);
   list <CNonResidentialPremises> :: iterator itN = ListN.begin();
   list <CResidentialPremises> :: iterator itR = ListR.begin();
   while(1){
      if(itN == ListN.end() && itR == ListR.end())
      break;
      if(itR->nGetNumberRooms() <= itN->nGetNumberRooms()){
         itR->vPrintRPInForm(i,sg);
         ++itR;
         ++i;
         if(itR == ListR.end()){
            while(itN != ListN.end()){
               itN->vPrintNRPInForm(i,sg);
               ++itN;
               ++i;
            }
            break;
         }
      }
      else if(itN->nGetNumberRooms() < itR->nGetNumberRooms()){
         itN->vPrintNRPInForm(i,sg);
         ++itN;
         ++i;
         if(itN == ListN.end()){
            while(itR != ListR.end()){
               itR->vPrintRPInForm(i,sg);
               ++itR;
               ++i;
            }
            break;
         }
      }
   }
}

