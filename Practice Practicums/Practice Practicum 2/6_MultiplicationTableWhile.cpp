#include <iostream>
using namespace std;

void MultiplicationTableWhile ()
{
    int i = 1;
    const int j = 1;
    while (j < 2)
    {
        cout << i * j << " " << endl;
        j++
    }
    while (j < 3)
    {
        i = 2;
        cout << i * j << " ";
        j++;
    }
    cout << endl;
    while (j < 4)
    {
        i = 3;
        cout << i * j << " ";
        j++;
    }
    cout << endl;
    while (j < 5)
    {
        i = 4;
        cout << i * j << " ";
        j++;
    }
    cout << endl;
    while (j < 6)
    {
        i = 5;
        cout << i * j << " ";
        j++
    }
}

int main ()
{
    
}