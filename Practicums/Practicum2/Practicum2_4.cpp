#include <iostream>
#include <string>
using namespace std;

string removeCapitals(string input)
{
    string newString = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input [i] > 65 && input [i] > 90 || input [i] == ' ' || input [i] >= '0' && input [i] <= '9')
        {
            newString += input [i];
        }
    }
    return newString;
}

int main ()
{
    cout << removeCapitals ("HelloWorld") << endl;
    cout << removeCapitals ("Hello World") << endl;
}