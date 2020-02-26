#include <iostream>
#include <string>
using namespace std;

/**
 * Write a function called PrintOddPattern that takes in no parameters nor returns any value, 
 * and prints 3 rows and 5 columns as follows: asterisk('*') in even columns, dollar('$') in odd columns.
 * Your function should be named PrintOddPattern.
 * Your function has no input argument
 * Your function has no return value
 * Your function should print the expected output as described above. Refer to the example below
 */

void PrintOddPattern ()
{
    int y = 0;
    int x = 0;
    int width = 3;
    for (y = 0; y < width; y++)
    {
        for (x = 0; x < 5; x++)
        {
            if (x == 0 || x == 2 || x == 4)
            {
                cout << "$";
            }
            else
            {
                cout << "*";
            }
        }
        
        cout << endl;
    }
}

int main ()
{
    PrintOddPattern();
}