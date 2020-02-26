#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

/**
 * Algorithm: Write a function fileLoadWrite that opens a file and writes to it 
 * the squares of the numbers from 1 to 10, each on its own line.
 * 
 */
 
 
int fileLoadWrite (string fileName)
{
    ofstream myfile;
    myfile.open(fileName);
    if (myfile.fail())
    {
        cout << "-1" << endl;;
    }
    else if (myfile.is_open())
    {
        for (int i = 1; i <= 10; i++)
        {
            myfile << i * i << endl;
        }
        return 0;
    }
}

int main ()
{
    fileLoadWrite("myFile.txt"); //test case 1. output will be a different file of squares from 1 - 10
}