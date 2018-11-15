#include <vcl.h>
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>

#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Unit2.h"
#include "File2.h"
#include "Unit1.h"

TRES *RES;
__fastcall TRES::TRES(TComponent* Owner)
        : TForm(Owner){}
using namespace std;

CColection objects;

int nCheckSearch;
bool isDelete;
bool isCheckDeleteElement;

//заборонити доступ до функцій
void vEnabledF()
{
   RES->Sorting1->Enabled = false;
   RES->Definition1->Enabled = false;
   RES->Search1->Enabled = false;
   RES->Delete1->Enabled = false;
   RES->Save1->Enabled = false;
   RES->Print1->Enabled = false;
}

//дати доступ до функцій
void vEnabledT()
{
   RES->Edit2->Visible = false;
   RES->Label3->Visible = false;
   RES->Sorting1->Enabled = true;
   RES->Print1->Enabled = true;
   RES->Definition1->Enabled = true;
   RES->Search1->Enabled = true;
   RES->Add1->Enabled = true;
   RES->Delete1->Enabled = true;
   RES->Save1->Enabled = true;
}

//добавлення статусбар
void __fastcall TRES::FormCreate(TObject *Sender)
{
   StatusBar1->Panels->Add();
   StatusBar1->Panels->Items[0]->Text = "Waiting for press Start or Add...";
   vEnabledF();
   StringGrid1->Cells[0][0] = "Type";
   StringGrid1->Cells[1][0] = "Address ";
   StringGrid1->Cells[2][0] = "Owner";
   StringGrid1->Cells[3][0] = "Numbers of rooms";
   StringGrid1->Cells[4][0] = "Total area,m^2";
   StringGrid1->Cells[5][0] = "Kitchen area,m^2";
   StringGrid1->Cells[6][0] = "Rooms area,m^2";
   StringGrid1->Cells[7][0] = "Repair condition";
   StringGrid1->Cells[8][0] =  "Purpose";
   StringGrid1->Cells[9][0] = "Price,$";
}

//зчитування, ініціалізація об'єктів, виведення
void __fastcall TRES::Start1Click(TObject *Sender)
{
   try
   {
      objects.vReadFile(StringGrid1);
      objects.vCreateObjects(StringGrid1);
      objects.vPrintObjects(StringGrid1);
      StatusBar1->Panels->Items[0]->Text = "Reading and output was completed. Waiting for a choice ..." ;
      vEnabledT();
      Start1->Enabled = false;
      StringGrid1->Visible = true;
      StringGrid2->Visible = false;
      Button4->Visible = false;
   }
   catch(OtherException exp)
   {
      vEnabledF();
      for(int i = 0;i < StringGrid1->ColCount;i++)
         for(int j = 1; j < StringGrid1->RowCount;j++)
            StringGrid1->Cells[i][j] = "";
      exp.vvDisplay();
   }
   catch(ReadFileException exp)
   {
      vEnabledF();
      for(int i = 0;i < StringGrid1->ColCount;i++)
         for(int j = 1; j < StringGrid1->RowCount;j++)
            StringGrid1->Cells[i][j] = "";
      exp.vvDisplay();
   }
}

//вибір додавання житлового приміщення
void __fastcall TRES::RP3Click(TObject *Sender)
{
   vEnabledF();
   Add1->Enabled = false;
   Start1->Enabled = false;
   StringGrid1->Visible = false;
   StringGrid2->Visible = true;
   Button4->Visible = true;
   objects.vPrintObjects(StringGrid1);
   for(int i=0;i < RES->StringGrid2->ColCount;i++)
      RES->StringGrid2->Cells[i][1] = "";
   StringGrid2->ColCount = 9;
   StringGrid2->ColWidths[7] = 93;
   StringGrid2->Width = 709;
   Button4->Left = 280;
   StringGrid2->Cells[0][0] = "Type";
   StringGrid2->Cells[1][0] = "Address ";
   StringGrid2->Cells[2][0] = "Owner";
   StringGrid2->Cells[3][0] = "Numbers of rooms";
   StringGrid2->Cells[4][0] = "Total area,m^2";
   StringGrid2->Cells[5][0] = "Kitchen area,m^2";
   StringGrid2->Cells[6][0] = "Rooms area,m^2";
   StringGrid2->Cells[7][0] = "Repair condition";
   StringGrid2->Cells[8][0] = "Price,$";
   StatusBar1->Panels->Items[0]->Text =
   "You choose Add RP. Waiting for press ADD ELEMENT...";
}

//вибір додавання нежитлового приміщення
void __fastcall TRES::NRP3Click(TObject *Sender)
{
   objects.vPrintObjects(StringGrid1);
   for(int i=0;i<RES->StringGrid2->ColCount;i++)
         RES->StringGrid2->Cells[i][1] = "";
   vEnabledF();
   Add1->Enabled = false;
   Start1->Enabled = false;
   StringGrid1->Visible = false;
   StringGrid2->Visible = true;
   Button4->Visible = true;
   StringGrid2->ColCount = 7;
   StringGrid2->Width = 550;
   Button4->Left = 190;
   StringGrid2->Cells[0][0] = "Type";
   StringGrid2->Cells[1][0] = "Address ";
   StringGrid2->Cells[2][0] = "Owner";
   StringGrid2->Cells[3][0] = "Numbers of rooms";
   StringGrid2->Cells[4][0] = "Total area,m^2";
   StringGrid2->Cells[5][0] = "Purpose";
   StringGrid2->Cells[6][0] = "Price,$";
   StatusBar1->Panels->Items[0]->Text =
   "You choose Add NRP. Waiting for press ADD ELEMENT...";
}

//додавання приміщення
void __fastcall TRES::Button4Click(TObject *Sender)
{
   try{
      StringGrid1->Visible = true;
      StringGrid2->Visible = false;
      Button4->Visible = false;
      objects.vAddObjects(StringGrid2);
      for(int i = 0;i < StringGrid1->ColCount;i++)
         for(int j = 1; j < StringGrid1->RowCount;j++)
            StringGrid1->Cells[i][j] = "";
      objects.vPrintObjects(StringGrid1);
      StatusBar1->Panels->Items[0]->Text =
      "Add element was compled. Waiting for a choice...";
      vEnabledT();
      Start1->Enabled = false;
   }
   catch(AddInFormException exp){
      exp.vvDisplay();
      StatusBar1->Panels->Items[0]->Text = "Error. Waiting for a choice";
      if(RES->StringGrid1->Cells[0][1] != "")
      {
         vEnabledT();
         Start1->Enabled = false;
      }
      else
      {
         Add1->Enabled = true;
         Start1->Enabled = true;
      }
   }
}

//видалення усіх об'єктів
void __fastcall TRES::AllElements1Click(TObject *Sender)
{
   objects.vDeleteAllObjects(Edit2);
   Edit2->Visible = true;
   Label3->Visible = true;
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   StatusBar1->Panels->Items[0]->Text =
   "Delete all elements was completed. Waiting for a choice ...";
   Start1->Enabled = true;
   Add1->Enabled = true;
   vEnabledF();
}

//вибір видалення обраного елемента
void __fastcall TRES::ChooseElement1Click(TObject *Sender)
{
   Start1->Enabled = false;
   Add1->Enabled = false;
   vEnabledF();
   try
   {
      if(StringGrid1->Cells[0][1] == "")
         throw OtherException(20,"There are not elements for delete!");
      RES->Button5->Visible = true;
      ShowMessage ("Choose element for delete in StringGrid.");
      StatusBar1->Panels->Items[0]->Text =
      "You choose Delete. Waiting for a choice element ...";
      isCheckDeleteElement = true;
   }
   catch (OtherException exp)
   {
      exp.vvDisplay();
   }
}

//видалення обраного приміщення
void __fastcall TRES::Button5Click(TObject *Sender)
{
   try{
      if(isDelete)//чи був вибраний елемент,після нажимання на кнопку видалення
      {
         RES->Button5->Visible = false;
         objects.vDeleteChooseObject(StringGrid1,Edit2);
         StatusBar1->Panels->Items[0]->Text =
         "Delete element was completed. Waiting for press Start or Add ...";
         Start1->Enabled = false;
         vEnabledT();
         Edit2->Visible = true;
         Label3->Visible = true;
      }
      isDelete = false;
      if(StringGrid1->Cells[0][1] == ""){
         vEnabledF();
         Start1->Enabled = true;
         Add1->Enabled = true;
      }
   }
   catch(OtherException exp){
      exp.vvDisplay();
      Start1->Enabled = false;
      vEnabledT();
      StatusBar1->Panels->Items[0]->Text =
      "Delete element was not completed. Waiting for a choice ...";
   }
}

//обробка нажимання на StringGrid
void __fastcall TRES::StringGrid1Click(TObject *Sender)
{
   if(isCheckDeleteElement){
      StatusBar1->Panels->Items[0]->Text =
      "You choosed element for delete. Waiting for press DELETE ELEMENT ...";
      isCheckDeleteElement = false;
      isDelete = true;
   }
}

//обробка введення у пошуковий Edit
void __fastcall TRES::Edit1Change(TObject *Sender)
{
   StatusBar1->Panels->Items[0]->Text =
   "You entered a parametr. Waiting for press SEARCH ELEMENT ...";
}

//вивести на форму
void vButtonVisible()
{
   RES->Button3->Visible = true;
   RES->Edit1->Visible = true;
   RES->Label4->Visible = true;
   vEnabledF();
   RES->Start1->Enabled = false;
   RES->Add1->Enabled = false;
}

//вибір пошуку адреси
void __fastcall TRES::Address1Click(TObject *Sender)
{
   nCheckSearch = 1;
   vButtonVisible();
   StatusBar1->Panels->Items[0]->Text =
   "You choose Search Address. Waiting for a write parametr ...";
}

//вибір пошуку власника
void __fastcall TRES::Byparametr1Click(TObject *Sender)
{
  nCheckSearch = 2;
  vButtonVisible();
  StatusBar1->Panels->Items[0]->Text =
   "You choose Search Owner. Waiting for a write parametr ...";
}

//вибір пошуку кількості кімнат
void __fastcall TRES::NumbersOf1Click(TObject *Sender)
{
   nCheckSearch = 3;
   vButtonVisible();
   StatusBar1->Panels->Items[0]->Text =
   "You choose Search Number of Rooms. Waiting for a write parametr ...";
}

//вибір пошуку загальної площі
void __fastcall TRES::Totalarea1Click(TObject *Sender)
{
   nCheckSearch = 4;
   vButtonVisible();
   StatusBar1->Panels->Items[0]->Text =
   "You choose Search Total area. Waiting for a write parametr ...";
}

//вибір пошуку площі кухні
void __fastcall TRES::Kitchenarea1Click(TObject *Sender)
{
   nCheckSearch = 5;
   vButtonVisible();
   StatusBar1->Panels->Items[0]->Text =
   "You choose Search Kitchen area. Waiting for a write parametr ...";
}

//вибір пошуку площі кімнат
void __fastcall TRES::Roomsarea1Click(TObject *Sender)
{
   nCheckSearch = 6;
   vButtonVisible();
   StatusBar1->Panels->Items[0]->Text =
   "You choose Search Romms area. Waiting for a write parametr ...";
}

//вибір пошуку стану ремонту
void __fastcall TRES::Repaircondition1Click(TObject *Sender)
{
   nCheckSearch = 7;
   vButtonVisible();
   StatusBar1->Panels->Items[0]->Text =
   "You choose Search Repair condition. Waiting for a write parametr ...";
}

//вибір пошуку цільового призначення
void __fastcall TRES::Purpose1Click(TObject *Sender)
{
   nCheckSearch = 8;
   vButtonVisible();
   StatusBar1->Panels->Items[0]->Text =
   "You choose Search Purpose. Waiting for a write parametr ...";
}

//вибір пошуку ціни
void __fastcall TRES::Price1Click(TObject *Sender)
{
   nCheckSearch = 9;
   vButtonVisible();
   StatusBar1->Panels->Items[0]->Text =
   "You choose Search Price. Waiting for a write parametr ...";
}

//знаходження максимальної площі житлових приміщень
void __fastcall TRES::Rp1Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSearchMaxSquareRP(StringGrid1);
   StatusBar1->Panels->Items[0]->Text =
   "Search max square of RP was completed. Waiting for a choice ...";
}

//знаходження мінімальної площі житлових приміщень
void __fastcall TRES::RP2Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSearchMinSquareRP(StringGrid1);
   StatusBar1->Panels->Items[0]->Text =
   "Search min square of RP was completed. Waiting for a choice ...";
}

//знаходження максимальної площі нежитлових приміщень
void __fastcall TRES::NRP1Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSearchMaxSquareNRP(StringGrid1);
   StatusBar1->Panels->Items[0]->Text =
   "Search max square of NRP was completed. Waiting for a choice ...";
}

//знаходження мінімальної площі нежитлових приміщень
void __fastcall TRES::NRP2Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSearchMinSquareNRP(StringGrid1);
   StatusBar1->Panels->Items[0]->Text =
   "Search min square of NRP was completed. Waiting for a choice ...";
}

//знаходження максимальної площі усіх приміщень
void __fastcall TRES::ALL1Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSearchMaxSquare(StringGrid1);
   StatusBar1->Panels->Items[0]->Text =
   "Search max square of all buidings was completed. Waiting for a choice ...";
}

//знаходження мінімальної площі усіх приміщень
void __fastcall TRES::ALL2Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSearchMinSquare(StringGrid1);
   StatusBar1->Panels->Items[0]->Text =
   "Search min square of all buidings was completed. Waiting for a choice ...";
}
//сортування за призначенням
void __fastcall TRES::PurposeazOnlyforNRP1Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSortingPurpose(StringGrid1);
   StatusBar1->Panels->Items[0]->Text = "Sorting of purpose was completed. Waiting for a choice ...";
}

//знаходження власників, які зареєстрували більше 2 приміщень
void __fastcall TRES::Whohave2RP1Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSearchOwnerWith2(StringGrid1);
   StatusBar1->Panels->Items[0]->Text =
   "Search owners who have more than 2 buildings was completed. Waiting for a choice ...";
}

//сортування за адресою
void __fastcall TRES::Addressaz1Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSortingAddress(StringGrid1);
   StatusBar1->Panels->Items[0]->Text = "Sorting of adress was completed. Waiting for a choice ...";
}

//сортування за кількістю кімнат
void __fastcall TRES::Rooms1Click(TObject *Sender)
{
   for(int i = 0;i < StringGrid1->ColCount;i++)
      for(int j = 1; j < StringGrid1->RowCount;j++)
         StringGrid1->Cells[i][j] = "";
   objects.vSortingNumberRooms(StringGrid1);
   StatusBar1->Panels->Items[0]->Text = "Sorting of number of rooms was completed. Waiting for a choice ...";
}

//збееження у файл
void __fastcall TRES::Save1Click(TObject *Sender)
{
   objects.vSaveToFile();
   StatusBar1->Panels->Items[0]->Text =
   "Save in file was completed. Waiting for a choice ...";
}

//пошук за заданими параметрами
void __fastcall TRES::Button3Click(TObject *Sender)
{
   bool isWasDeletingElement;
   try{
      for(int i = 0;i < StringGrid1->ColCount;i++)
         for(int j = 1; j < StringGrid1->RowCount;j++)
            StringGrid1->Cells[i][j] = "";
      isWasDeletingElement = objects.isSeachByParametr(nCheckSearch, Edit1, StringGrid1);
      if(!isWasDeletingElement){
         Print1->Enabled = true;
         StatusBar1->Panels->Items[0]->Text =
         "Search element was completed,element was not searched. Waiting for a choice ...";
      }
      else
         StatusBar1->Panels->Items[0]->Text =
         "Search element was completed,element was searched. Waiting for a choice ...";
      vEnabledT();
      Button3->Visible = false;
      Edit1->Visible = false;
      Label4->Visible = false;
   }
   catch(SearchInFormException exp){
      exp.vvDisplay();
      StatusBar1->Panels->Items[0]->Text = "Error.Try again.";
   }
}
//вивід об'єктів
void __fastcall TRES::Print1Click(TObject *Sender)
{
   objects.vPrintObjects(StringGrid1);
}
//---------------------------------------------------------------------------

