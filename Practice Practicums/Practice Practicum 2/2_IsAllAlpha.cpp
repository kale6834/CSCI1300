#include <iostream>
#include <string>
using namespace std;

bool IsAllAlpha (string input)
{
    bool alphabet = true;
    int i = 0;
    for (i = 0; i < input.length (); i++)
    {
        if (input [i] >= 'A' && input [i] <= 'Z' && input [i] >= 'a' && input [i] <= 'z')
        {
            alphabet = true;
        }
        else if (input [i] >= 33 && input [i] <= 64)
        {
            alphabet = false;
        }
    }
    return alphabet;
}

int main ()
{
    cout << IsAllAlpha ("ONETWO") << endl;
    cout << IsAllAlpha ("one2") << endl;
}