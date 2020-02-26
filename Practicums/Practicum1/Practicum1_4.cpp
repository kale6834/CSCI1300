#include <iostream>
using namespace std;

double smallestNumber (double a, double b, double c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < a && b < c)
    {
        return b;
    }
    else if (c < a && c < b)
    {
        return c;
    }
}

int main ()
{
    cout << smallestNumber (4, 9, 2.5) << endl;
    cout << smallestNumber (17.2, 3.2, 26.4) << endl;
}