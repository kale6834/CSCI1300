#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double matrixAverage (int array[][2], int row)
{
    double sum = 0;
    double avg = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum = sum + array[i][j];
        }
    }
    avg = sum / (row * 2);
    return avg;
}

int main()
{
    // int array[2][2]={{1,1},{3,4}}; 

    // cout << matrixAverage(array, 2) << endl;
    int array[4][2]={{3,4},{78,98},{12,-11},{1909,4}};

    cout << matrixAverage(array, 4);
}