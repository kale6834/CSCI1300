#include <iostream>
#include <string>
using namespace std;

void PrintAsterisks ()
{
    int y = 0;
    int x = 0;
    int width = 3;
    for (y = 0; y < width; y++)
    {
        for (x = 0; x < 4; x++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main ()
{
    PrintAsterisks ();
}