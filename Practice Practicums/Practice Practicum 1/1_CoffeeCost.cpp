#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Write a function named CoffeeCost to calculate the cost of a student's coffee 
 * consumption. The function will take an integer for the number of cups of coffee 
 * and a floating point value for the cost per cup. The function will return a 
 * floating point value for the total cost of coffee. The students use a coffee 
 * house that rewards the student for caffeine overload by giving a free cup 
 * for buying every 12 cups.
 * 1. determine the cost of a cup of coffee
 * 2. cost = units * cost per unit
 * 3. factor in the 12th cup
 */
 

double CoffeeCost (int cups, double price)
{
    double cost;
    double freecost;
    if (cups <= 12)
    {
        cost = cups * price;
    }
    else if (cups > 12)
    {
        freecost = cups / 12;
        cost = cups * price - freecost * price;
    }
    return cost;
}

int main ()
{
    cout << CoffeeCost (11, 3.00) << endl;
    cout << CoffeeCost (14, 3.00) << endl;
    return 0;
}