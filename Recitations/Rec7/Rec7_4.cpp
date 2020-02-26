#include <iostream>
#include <fstream>
using namespace std;

/**
 * Write a function getLinesFromFile that reads from a file of integers and stores its
 * content in an array. Each line in the file will either contain a single integer or be empty.
 */
 
int getLinesFromFile (string fileName, int array[], int length)
{
    //if file DNE return -1
    //return numbers in array
    ifstream myfilename;
    myfilename.open (fileName);
    int count = 0;
    if (myfilename.fail())
    {
        return -1;
    }
    if (myfilename.is_open())
    {
        string line = "";
        while (getline(myfilename, line))
        {
            if (line != "")
            {
                if(count < length)
                {
                    array[count] = stoi(line);
                    count++;
                }
            }
        }
        return count;
         
    }
}

int main ()
{
    
}
