#include <iostream>
#include <fstream>
using namespace std;

/**
 * Algorithm:
 * Write a function called saveData that converts the first n values of the array 
 * into doubles and compute their average. 
 * 
 */
 
 
void saveData (string fileName, string array[], int valuesInArray, int sizeOfArray)
{
    double sum = 0;
    ofstream myfile; //we are going to be writing to a file
    myfile.open (fileName); //open the file name
    if (myfile.fail()) //if the file did not open
    {
        cout << "file open failed" << endl;
    }
    else
    {
        if (valuesInArray == 0) //if there are no values in the array
        {
            for (int i = 0; i < sizeOfArray; i++) //read through the array
            {
                myfile << "Name: " << array[i]; //print out the name in the array
            }
        }
        else if (valuesInArray > 0) //if there are values in the array
        {
            for (int i = 0; i < sizeOfArray - 1; i++) //traverse the array
            {
                sum += stod(array[i]); //add sum and value in array each time the loop is run
            }
            sum = sum / (sizeOfArray - 1); //average equals sum / number of values in array
            myfile << "Name: " << array[valuesInArray] << endl; //send the name to the file. name is at the index value = values in array
            myfile << "Avg: " << sum << endl; //send te average to the file
            
        }
    }
}