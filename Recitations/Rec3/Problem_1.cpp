//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Recitation 3 - Problem #1

/**
 * Algorithm:
 * Write a function named numberSign that takes one integer parameter, returns nothing, and 
 * prints whether that integer is "negative", "positive", or "zero".
 * 1. Input number
 * 2. If it is less than zero, it is negative.
 * 3. If it is more than zero, it is positive.
 * 4. If it is equal to zero, then it is zero.
 * Input parameters: an integer number
 * Output: positive, negative, or zero depending on the integer input
 * Returns: nothing
 */
 
#include <iostream>
using namespace std;

void numberSign (int number){
    if (number < 0) //if input number is less than zero
    {
        cout << "negative" <<endl; //we want to print that it is negative
    }
        else if (number > 0) //if input number is greater than zero
        {
            cout << "positive" <<endl; //we want to print that it is positive
        } 
        else if (number == 0) //if input number is equal to zero
        {
            cout << "zero" << endl; //we want to print that it is zero
        }
}
int main ()
{
    numberSign (4); //test case 1. output should be positive
    numberSign (-4); //test case 2. output should be negative
    numberSign (0); //test case 3. output should be zero
    return 0; 
}