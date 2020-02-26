//Kalei Lewis: CS1300 Fall 2018
//Recitation :102 - Paramjot Singh
//Cloud9 Workspace Editor: ide.c9.io/kaleilewis/kale6834
//Homework #2 Problem 2

/**
 *Algorithm: convert celsius to Fahrenheit
 * 1. convert celsius to fahrenheit using celsius * (9/5) + 32
 * 2. print degrees in fahrenheit
 * Input parameter: celsius
 * Output parameter: fahrenheit
 * Return: nothing
 */

#include <iostream>
#include <iomanip>
using namespace std;

void celsiusToFahrenheit (int celsius){
    double Fahrenheit = celsius * double (9.00/5.00) + 32.00; //this is the equation of converting celsius to fahrenheit
    cout << "The temperature of " << celsius << " in fahrenheit is " << setprecision(2) << fixed << Fahrenheit << endl;
}
int main()
{
    celsiusToFahrenheit (64); //test case 1 for celsiusToFahrenheit. This should output 147.20 degrees Fahrenheit.
    celsiusToFahrenheit (38); //test case 2 for celsiusToFahrenheit. This hsould output 100.40 degrees Fahrenheit.
}