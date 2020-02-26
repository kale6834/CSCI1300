#include <iostream>
#include <fstream>
using namespace std;

/**
 * Algorithm:
 * Write a function checkFile that opens up a file. The function takes one 
 * parameter, the name of the file. The function should return true if the file 
 * was opened successfully otherwise it should return false.
 * 
 */
 
 
bool checkFile (string fileName)
{
    //set a variable to act as a switch
    bool openFile = true;
    //read myfile
    ifstream myfile;
    //open the my file
    myfile.open(fileName);
    //if the file is open, then return true
    if (myfile.is_open())
    {
        openFile = true;
    }
    else if (myfile.fail())//if the file fails return false
    {
        openFile = false;
    }
    return openFile; //return true or false depending on if the file was opened.
}

int main()
{
    cout << checkFile("myFile.txt"); //test case 1. should return false since i do not have a file called myFile.txt
}