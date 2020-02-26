#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Write a function, GasBill, that is given integer value for units used. 
 * The function will return a floating point value for the total cost.  
 * Your function will calculate a cost using the following conditions as 
 * the cost of the gas depends on how much is used. First 100 units are 
 * charged at $1.23 per unit, the next 100 units are $1.14 per unit, 
 * any units above 200 are charged at $1.08 per unit.
 * 1. calculate cost if units are 100 units or less
 * 2. calculate cost if units are 101-200 units
 * 3. calculate cost if units are above 200
 */
 
 double GasBill (int units)
 {
     double TotalCost;
     if (units < 0)
     {
         cout << "Incorrect input" << endl;
     }
     else if (units <= 100 && units >= 0)
     {
         TotalCost = units * 1.23;
     }
     else if (units > 100 && units <= 200)
     {
         TotalCost = 100.00 * 1.23;
         units = units - 100.00;
         TotalCost = TotalCost + units * 1.14;
     }
     else if (units > 200)
     {
         TotalCost = (100.00 * 1.23) + (100.00 * 1.14);
         units = units - 100.00;
         TotalCost = TotalCost + units * 1.08;
     }
     return TotalCost;
 }
 
 int main ()
 {
     cout << GasBill (244) << endl;
     return 0;
 }