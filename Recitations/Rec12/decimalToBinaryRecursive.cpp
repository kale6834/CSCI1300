#include <iostream>
#include <string>
using namespace std;

string decimalToBinaryRecursive(int number)
{
    
    if (number == 0)
    {
        return "0";
    }
    if (number % 2 == 0)
    {
        return decimalToBinaryRecursive(number / 2) + "0";
    }
    else
    {
        return decimalToBinaryRecursive(number / 2) + "1";
    }
    decimalToBinaryRecursive(number);
}

int main ()
{
    
}