//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Recitation 3 - Problem #2

#include <iostream>
using namespace std;

double calcPay (double hours, double rate) //we need two input parameters
{
    if ((hours <= 40) && (hours >= 0) && (rate >= 0)) //hours need to be equal to or less than 40 for the regular rate. rate and hours also need to be above zero.
    {
        double total = hours * rate;
        return total; //we will return the value of the hours * rate
    }
    else if ((hours > 40) && (rate >= 0)) //if hours are over 40, then we will look at this statement. rate still needs to be above or equal to 0
    {
        double overtime = (hours - 40) * (rate * double (1.5)); //i first calculated what the hours would be for overtime
        double total = (40 * rate) + overtime; //then i added that value into the regular total
        return total; //return the total value of 40 hours * rate plus the value we calculated for overtime
    }
    else if ((hours < 0) || (rate < 0)) //if hours or rate is less than zero
    {
        return -1; //return -1
    }
}

int main ()
{
    cout << calcPay (40, 10) <<endl; //test case 1. Output should be 400.
    cout << calcPay (41, 10) <<endl; //test case 2. Output should be 415.
    cout << calcPay (-41, -10) <<endl; //test case 3. Output should be -1.
    return 0;
}