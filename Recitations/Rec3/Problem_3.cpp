//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Recitation 3 - Problem #2

/**
 * Algorithm:
 * Write a function called checkLeapYear that takes a single integer argument 
 * representing a year and returns 1 if it is a leap year and 0 otherwise. 
 * This function should use a single if statement and Boolean operators.
 * 1. Input year
 * 2. Check if it is before 1582 or after 1582.
 * 3. If before 1582, check if it is divisible by 4.
 * 4. If before 1582 and divisible by 4, then it is a leap year.
 * 5. If after 1582, see if the year is divisible by 4 and not by 100.
 * 6. If it is divisible by 4 and not by 100, then it is a leap year.
 * 7. Check if year is divisible by 4 and 400.
 * 8. If divisible by 4 and 400, then it is a leap year.
 * 9. If none of these conditions are met, then it is not a leap year.
 * Input paramter: year
 * Output: 0 or 1 depending if the year is a leap year or not a leap year
 * Return: 0 or 1
 */


#include <iostream>
using namespace std;

double checkLeapYear (int year)
{
        if (year <= 1582 && year % 4 == 0) //any year before 1582 is divisible by 4
        {
            return 1; //return 1 if it is a leap year
        }
        else if (year > 1582 && year % 4 == 0 && year % 100 != 0) //any year after 1582 that is divisible by 4 but not 100 is a leap year
        {
            return 1; //return 1 if it is a leap year
        }
        else if  (year > 1582 && year % 4 == 0 && year % 400 == 0) //any year after 1582 that is divisible by 4 and 400 is a leap year
        {
            return 1; //return 1 if it is a leap year
        }
        else {//if none of the previous statements fits the conditions presented
            return 0; //return 0 if it is not a leap year
        }
        
}

int main ()
{
        cout << checkLeapYear (2000) << endl; //test case 1. Output should be 1. 
        cout << checkLeapYear (1981) << endl; //test case 2. Output should be 0.
}