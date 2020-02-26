#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool similarity (int array1[], int size1, int array2[], int size2)
{
    bool samesize = false;
    int i = 0;
    if (size1 == size2)
    {
        for (i = 0; i < size1; i++)
        {
            if (array1[i] == array2[i])
            {
                samesize = true;
            }
            else if (array1[i] != array2[i])
            {
                samesize = false;
                return samesize;
            }
            
        }
        if (size1 == 0 && size2 == 0)
        {
            samesize = true;
        }
    }
    return samesize;
}

int main ()
{
    int arr1[]= {1, 4, 16, 7, 23, 3};
    int arr2[]= {1, 4, 6, 7, 23, 3};
    cout << similarity(arr1, 6, arr2, 6) << endl;
    // int arr1[]= {};
    // int arr2[]= {};
    // cout << similarity(arr1, 0, arr2, 0) << endl;
}