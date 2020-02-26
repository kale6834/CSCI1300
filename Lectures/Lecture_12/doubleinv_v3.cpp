#include <iostream>
using namespace std;

// change problem: either double the initial 
// investment or at 13 years, whichever comes first

int main()
{  
   // what should we modify above while loop?
   const double RATE = 5;
   const double INITIAL_BALANCE = 10000;
   const double TARGET = 2 * INITIAL_BALANCE;
   const int TARGET_YEAR = 13;
   double balance = INITIAL_BALANCE;
   int year = 0;


   // what should we modify in while loop?
   while (balance < TARGET) 
   {
      year++;
      double interest = balance * RATE / 100;
      balance = balance + interest;
   }

   cout << "The investment doubled after "
        << year << " years." << endl;

   return 0;
}
