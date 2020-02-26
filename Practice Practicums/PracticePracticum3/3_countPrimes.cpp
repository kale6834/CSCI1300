#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool IsPrime (int num)
{
    int i;
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    if (num == i)
    {
        return true;
    }
    else if (num < 0)
    {
        return false;
    }
    return 0;
}

int countPrimes (int array[], int size)
{
    int count = 0;
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        num = array[i];
        count = count + IsPrime(num);
    }
    return count;
}

int main ()
{
    int array[6] = {3, 4, 7, 8, 9, 1};
    cout << countPrimes(array, 6);
}