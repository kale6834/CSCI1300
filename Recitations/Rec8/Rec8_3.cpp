#include <iostream>
#include <fstream>
using namespace std;

/**
 * Algorithm:
 * Write a function fileLoadRead that reads a file. The function takes a parameter, 
 * the name of the file, and returns the number of lines in the file. It should 
 * open a file in read mode, check for success, and read the lines until the end 
 * of the file. Remember to close the file.
 * 
 */
 
 
int fileLoadRead (string fileName)
{
    ifstream myfile; //read my file
    myfile.open(fileName); //open myfile
    if (myfile.fail()) //if myfile fails to open
    {
        return -1; //return -1
    }
    else //else if it is open
    {
        string line = ""; //set an empty string
        int lineIndex = 0; //set a line index equal to 0
        while (getline(myfile, line)) //while we are getting the line from input to the end of the line
        {
            lineIndex++; //increase line index every time
        }
        myfile.close(); //close myfile
        return lineIndex; //return the number of lines that are in the file
    } 
    
}


int main ()
{
    cout << fileLoadRead ("fileLoadRead.txt"); //test case 1. output should be 6
}