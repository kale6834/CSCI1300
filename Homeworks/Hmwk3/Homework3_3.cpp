//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Homework 3 - Problem #3

/**
 * Algorith:
 * Write a function daysOfMonth which takes a single input argument, the month, as an integer argument. 
 * Using the input value, the function will calculate the number of days in a particular month, 
 * and print out the number of days.
 * 1. Enter the number of the month
 * 2. Determine what month that equates to
 * 3. Determine what number of days are in that month
 * 4. Output month number and number of days.
 * 5. Cannot input number bigger than 12
 * Input paramters: an integer number
 * Output: month number and number of days
 * Returns: nothing
 */


#include <iostream>
using namespace std;

void daysOfMonth (int month){
    switch (month)
    {
        case 1 :
            cout << "Month 1 has 31 days" << endl; //integer 1 = month 1 = January
            break; //end case statement
        case 2 :
            cout << "Month 2 has 28 or 29 days" << endl; //integer 2 = month 2 = February
            break; //end case statement
        case 3 :
            cout << "Month 3 has 31 days" << endl; //integer 3 = month 3 = March
            break; //end case statement
        case 4 :
            cout << "Month 4 has 30 days" << endl; //integer 4 = month 4 = April
            break; //end case statement
        case 5 :
            cout << "Month 5 has 31 days" << endl; //integer 5 = month 5 = May
            break; //end case statement
        case 6 :
            cout << "Month 6 has 30 days" << endl; //integer 6 = month 6 = June
            break; //end case statement
        case 7 :
            cout << "Month 7 has 31 days" << endl;  //integer 7 = month 7 = July
            break; //end case statement
        case 8 :
            cout << "Month 8 has 31 days" << endl; //integer 8 = month 8 = August
            break; //end case statement
        case 9 :
            cout << "Month 9 has 30 days" << endl; //integer 9 = month 9 = September
            break; //end case statement
        case 10 :
            cout << "Month 10 has 31 days" << endl; //integer 10 = month 10 = October
            break; //end case statement
        case 11 :
            cout << "Month 11 has 30 days" << endl; //integer 11 = month 11 = November
            break; //end case statement
        case 12 :
            cout << "Month 12 has 31 days" << endl; //integer 12 = month 12 = December
            break; //end case statement
        default :
            cout << "Invalid month number" << endl; //if none of these conditions are met, switch to the default statement.
        
    }
}

int main ()
{   //test case 1
    //expected output
    // month 4 has 31 days
    daysOfMonth (4);
    //test case 2
    //expected output
    //month 3 has 30 days
    daysOfMonth (3);
    //test case 3
    //expected output
    //month 2 has 28 or 29 days
    daysOfMonth (2);
    //test case 4
    //expect output
    //invalid month number
    daysOfMonth (18);
}