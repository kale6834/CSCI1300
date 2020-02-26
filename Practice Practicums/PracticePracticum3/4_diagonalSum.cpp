#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int diagonalSum (int arr[][3], int row)
{
    int count = 0;
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            count = arr[0][0] + arr[1][1] + arr[2][2];
        }
    }
    return count;
}


//if (i == j)
// {
    // count = count + arr[i][j];
// }