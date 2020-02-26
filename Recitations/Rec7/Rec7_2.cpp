#include <iostream>
#include <fstream>
using namespace std;

/**
 * Write a function to print all the integers in a two dimensional array. 
 * Each row of the array should be printed on a separate line with the integers separated by commas. 
 * Assume that the array has 5 columns.
 * Your function should be named printTwoDArray Your function should take two input arguments
 * The two dimensional integer array to be printed
 * The length of the given array
 * Your function should not return anything
 * Your function should print the values in the array
 */
 
void printTwoDArray (int array[][5], int length)
{
    int i = 0;
    int j = 0;
    if (length == 0)
    {
        cout << "0" << endl;
    }
    else if (length < 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        for (i = 0; i < length; i++)
        {
            for (j = 0; j < 5; j++)
            {
               if (j == 4)
               {
                   cout << array[i][j];
               }
               else
               {
                   cout << array[i][j] << ",";
               }
            }
            cout << endl;
        }
    }
}
 
 int main ()
 {
     int myArray[4][5]={};
     printTwoDArray(myArray,4);
 }