#include <iostream>
using namespace std;

int main ()
{
    double total;
    int n;
    double input;
    while (cin >> input)
    {
       total = total + input;
       n++;
    }
    if (n != 0)
    {
       double average = total / n;
    }
}