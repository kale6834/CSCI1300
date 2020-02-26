#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool similarity (int arr1[][3], int row1, int arr2[][3], int row2)
{
    bool same = false;
    int i = 0;
    if (row1 == row2)
    {
        for (i = 0; i < row1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr1[i][j] == arr2[i][j])
                {
                    same = true;
                }
                if (arr1[i][j] != arr2[i][j])
                {
                    same = false;
                    return same;
                }
            }
        }
    }
    return same;
}

int main ()
{
    int arr1[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
    int arr2[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
    cout << similarity(arr1, 3, arr2, 3) << endl;
    
    // int arr1[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
    // int arr2[3][3]= {{1, 4, 6}, {17, 23, 3}, {5, 15, 25}};
    // cout << similarity(arr1, 3, arr2, 3) << endl;
}