#include <iostream>
#include <iomanip>
#include "cashregister.h"
using namespace std;

//implementation file

CashRegister::CashRegister()
{
   clear();
}

void CashRegister::clear() //defining the function clear from the class cashregister
{
   //don't have to give a variable type since they are declared in the class
   //resets to zero
   item_count = 0; //keep the same spellings from the private class
   total_price = 0;
}

void CashRegister::add_item(double price)
{
   item_count++;
   total_price = total_price + price;
}

double CashRegister::get_total() const
{
   return total_price; 
}

int CashRegister::get_count() const
{
   return item_count; 
}





// void CashRegister::display()
// {
//    cout << item_count << " $" << fixed << setprecision(2) 
//       << total_price << endl;
// }

