//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Homework 3 - Problem #2


/**
 * Algorithm:
 * Write a function countDigits that takes integer as input and returns how many 
 * digits the number has. Assume that all integers are less than 1000 and greater than -1000. 
 * 1. Input number of digits
 * 2. Determine whether number has 1, 2, 3, or 4 digits
 * 3. Output number of digits
 * Input parameters: any number between -1000 and 1000
 * Output: number of digits in the input number
 * Returns: number of digits
 */
 
#include <iostream>
using namespace std;

int countDigits (int number)
{
    //if number is between -99 and -10 or 10 and 99
    if (number >= -99 && number <= -10 || number >= 10 && number <= 99)
    {   //the number will be two digits
        int number = 2;
        return number; //return the value 2
    }
    //if number is between -9 and 9
    else if (number >= -9 && number <= 9)
    {   //the number will be one digit
        int number = 1;
        return number; //return the value 1
    }
    //if number is between -999 and -100 or between 100 and 999
    else if (number >= -999 && number <= -100 || number >= 100 && number <= 999)
    {   //the number will be three digits
        int number = 3;
        return number; //return the value 3
    }
    //if number is equal to 1000 or -1000
    else (number == 1000 || number == -1000);
    {   //the number will be four digits
        int number = 4;
        return number; //return value 4
    }
}

int main ()
{   //test case 1.
    //arguments: number = 86
    //expected output: 2 digits
    cout << countDigits (86) << endl;
    //test case 2.
    //arguments: number = 1000
    //expected output: 4 digits
    cout << countDigits (1000) << endl;
    //test case 3
    //arguments: number = 1
    //expected output: 1 digit
    cout << countDigits (1) << endl;
    //test case 4
    //arguments: number = 237
    //expected output: 3 digits
    cout << countDigits (237) << endl;
}