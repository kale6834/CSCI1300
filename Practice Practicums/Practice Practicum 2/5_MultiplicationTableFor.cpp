#include <iostream>
using namespace std;

void MultiplicationTableFor ()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j*i << " ";
        }
        cout << endl;
    }
}

int main ()
{
    
}

