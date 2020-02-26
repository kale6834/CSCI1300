#include <iostream>
#include <string>
#include <fstream>
using namespace std;



// bool IsPrime (int num)
// {
//     int i;
//     for (i = 2; i < num; i++)
//     {
//         if (num % i == 0)
//         {
//             return false;
//         }
//     }
//     if (num == i)
//     {
//         return true;
//     }
//     else if (num < 0)
//     {
//         return false;
//     }
//     return 0;
// }

int sumOfPositiveOdd (string fileName, int array[], int size)
{
    ofstream myfile;
    myfile.open(fileName);
    int count = 0;
    //int num = 0;
    for (int i = 0; i < size; i++)
    {
        if (!(array[i] % 2 == 0) && array[i] > 0)
        {
            count = count + array[i];
        }
    }
    myfile << count;
    return count;
}

int main()
{
    string fileName = "sumofodds.txt";
    //int array[6] = {-1,4,6,-6,-3,10};
    int array[5] = {1, 2, 3, 4, 5};
    sumOfPositiveOdd(fileName, array, 5);
}