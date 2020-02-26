#include <iostream>
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

int main ()
{
    cout << IsPrime (6) << endl;
    cout << IsPrime (5) << endl;
    cout << IsPrime (1) << endl;
    cout << IsPrime (3) << endl;
}