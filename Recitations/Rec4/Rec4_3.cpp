//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Recitation 4 - Problem #3

/**
 * Algorithm: Write a function to print a filled and hollow square of 
 * given width side by side to the screen. The two squares should be 
 * separated by a single space.
 * 1. print a number of columns
 * 2. print a number of rows
 * 3. add space inbetween squares
 * 4. print first row
 * 5. print second row
 * 6. print rows with spaces inbetween first and last spots
 * Input parameters: width
 * Output: one full square and one hollow square with a certain width
 * Returns: nothing
 */
 

#include <iostream>
using namespace std;

void printSquares (int width)
{   
    //y is horizontal and starts at space 0
    int y = 0;
    //x is vertical and starts at space 0
    int x = 0;
    //while vertical is less than width
    while (x < width)
    {
        //increase number of rows at beginning of loop
        x++;
        //while horizontal is less than width
        while (y < width)
        {
            //this will be our visual for the square
            cout << "*";
            //increase horizontal by 1 at end of each loop
            y++;
        }
        //cout space at end of loop
        cout << " ";
        //if vertical is = to 1 or = to width for second square
        if (x == 1 || x == width)
        {
            //reset y equal to 0
            y = 0;
            //while horizontal is less than width
            while (y < width)
            {
                //this qill give us our visual for the square
                cout << "*";
                //increase horizontal each time until width is reached
                y++;
            }
        }
        //if while condition is not true
        else
        {
            //reset horizontal equal to zero
            y = 0;
            //while horizontal is less than width
            while (y < width)
            {
                //if horizontal is in the first column or last column
                if (y == 0 || y == width - 1)
                {
                    //give us the visual for the square
                    cout << "*";
                }
                //if the above conditions are not true
                else 
                {
                    //print the space, which will give us the hollow in the square
                    cout << " ";
                }
                //increase the horizontal at the end of the loop
                y++;
            }
        }
        //this will get us to the next line
        cout << endl;
        //reset horizontal equal to zero
        y = 0;
    }
}

int main ()
{
    printSquares (5); //test case 1. output should be
    // ***** *****
    // ***** *   *
    // ***** *   *
    // ***** *   *
    // ***** *****
    printSquares (10); //test case 2. output should be
    // ********** **********
    // ********** *        *
    // ********** *        *
    // ********** *        *
    // ********** *        *
    // ********** *        *
    // ********** *        *
    // ********** *        *
    // ********** *        *
    // ********** **********
}