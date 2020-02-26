#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void findDuplicate (int array[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++;
                cout << array[j] << endl;
            }
        }
    }
    if (count == 0)
    {
        cout << "-1" << endl;;
    }
}