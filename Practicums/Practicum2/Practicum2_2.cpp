#include <iostream>
#include <string>
using namespace std;

void PrintZeros(string str) 
{
    for (int i = 0; i < str.length(); i++) 
    {
        if (str[i] == '0') 
        {
            cout << str[i];
        }
    }
}

int main ()
{
    PrintZeros ("zero0, one1, two2");
}