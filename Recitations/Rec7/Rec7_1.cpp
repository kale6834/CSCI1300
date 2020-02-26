#include <iostream>
#include <fstream>
using namespace std;

/**
 * Write a function replaceNums that replaces each element except the first and last by the larger of its two neighbors.
● Your function should be named replaceNums
● Your function should take two parameters: An integer array & The length of the given array
● Your function should not return or print anything
* create new array of the same length
* copy the old array into the new array
*/

void replaceNums (int oldArray[], int length)
{
    // int nums;
    int newArray[length];
    int i;
    for (i = 0; i < length; i++)
    {
        newArray[i] = oldArray [i];
    }
    for (i = 1; i < length - 1; i++)
    {
        if (newArray[i - 1] > newArray [i + 1])
        {
            oldArray [i] = newArray [i - 1];
        }
        else 
        {
            oldArray [i] = newArray [i + 1];
        }
    }
}

int main ()
{
    int nums [5];
    cout << replaceNums(nums, 5) << endl;
}