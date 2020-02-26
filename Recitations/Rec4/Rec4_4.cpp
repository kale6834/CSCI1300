//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Recitation 4 - Problem #4

/**
 * Algorithm: Write a function to print a diamond with given side length to the screen.
 * 1. determine number of spaces per row
 * 2. determine number of stars per row
 * 3. determine pattern
 * Input parameters: an integer number
 * Output: a diamond pattern
 * Returns: nothing
 */
 

#include <iostream>
using namespace std;

void printDiamond (int n)
{   
    //start at space 1, row 1
    int x = 1;
    //while row is less than number
    while (x <= n)
    {
        //start at column one
        int y = 1;
        //while space is less than the number minus row
        while (y <= (n-x))
        {
            //print spaces
            cout << " ";
            //increase number of spaces
            y++;
        }
        //set variable equal to one, which will print out the stars
        int z = 1;
        //while star is less than 2 times number minus 1
        while (z <= (2*x-1))
        {
            //print out stars
            cout << "*";
            //increase number of stars
            z++;
        }
        //increase number of rows. it will add until it reaches number given
        x++;
        cout << endl;
    }
    //x is n-1 because we want to decrease one minus the number given
    //or else we would end up with too many rows
    x = n-1;
    //while rows are greater than one
    while (x >= 1)
    {
        //these while loops were copied from the above while loops
        //because we want to perform the same function, except we 
        //are decreasing
        int y = 1;
        while (y <= (n-x))
        {
            cout << " ";
            y++;
        }
        int z = 1;
        while (z <= (2*x-1))
        {
            cout << "*";
            z++;
        }
        //decrease number of rows
        x--;
        //this orders the code to go to the next row
        cout << endl;
    }
}

int main ()
{
    printDiamond (4); //test case 1. output:
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    printDiamond (3); //test case 2. output:
    //   *
    //  ***
    // *****
    //  ***
    //   *
}