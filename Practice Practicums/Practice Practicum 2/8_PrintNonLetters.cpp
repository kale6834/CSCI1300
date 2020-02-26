#include <iostream>
#include <string>
using namespace std;


void PrintNonLetters (string input)
{
    string output;
    int i = 0;
    bool Letters = true;
    if (input == "")
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (i = 0; i <= input.length(); i++)
        {
            if (input [i] > 9 && input [i] < 64  || (input [i] > 90 && input [i] < 97) || input [i] > 122)
            {
                cout << input [i];
                Letters = false;
            }
        }
    }
    if (Letters == true)
    {
       cout << -2; 
    }
}

int main ()
{
   PrintNonLetters ("one1, two2");
}