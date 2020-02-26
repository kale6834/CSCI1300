#include <iostream>
using namespace std;

// change problem: either double the initial 
// investment or at 13 years, whichever comes first

int main()
{  
   // what should we modify above while loop?
   const double RATE = 5;
   const double INITIAL_BALANCE = 10000;
   const double TARGET = 29000;
   const int TARGET_YEAR = 50;
   double balance = INITIAL_BALANCE;
   int year = 0;
   int z = 1;

   // what should we modify in while loop?
   while (z == 1) 
   {
      year++;
      double interest = balance * RATE / 100;
      balance = balance + interest;
      if (balance >= TARGET)
      {
         z = 0;
      }
      if (year >= TARGET_YEAR)
      {
         z = 0;
      }
   }

   cout << "The investment doubled after "
        << year << " years." << endl;

   return 0;
}
