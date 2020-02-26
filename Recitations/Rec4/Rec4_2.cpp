//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Recitation 4 - Problem #2

/**
 * Algorithm: Write a function to print all positive multiples of an integer 
 * number less than or equal to a max value.
 * 1. Start with number
 * 2. Determine max value
 * 3. multiply number by 1
 * 4. add one to find new multiple of three
 * 5. print out multiples of three until max value
 * Input parameters: num, max
 * Output: multiples of num
 * Returns: nothing
 */
 

#include <iostream>
using namespace std;

void printMultiples (int num, int max)
{
    //i start with 1 to find first multiple of number
    int out = 1;
    // while the number and multiple of less than max number
    while ((num * out) <= max)
    {
        //print out number by out number
        cout << num * out << endl;
        //increase out number at the end of loop
        out++;
    }
}

int main ()
{
    printMultiples (3, 10); //test case 1. output should be 3, 6, 9.
    printMultiples (4, 15); //test case 2. output should be 4, 8, 12.
}