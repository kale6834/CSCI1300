#include <iostream>
#include <string>
using namespace std;

void PrintPlus ()
{
    int y = 0;
    int x = 0;
    int width = 4;
    for (y = 0; y < width; y++)
    {
        for (x = 0; x < 3; x++)
        {
            cout << "+";
        }
        cout << endl;
    }
}

int main ()
{
    PrintPlus();
}