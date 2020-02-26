#include <iostream>
#include <string>
using namespace std;

string decimalToBinaryIterative(int number)
{
    string binary, temporary;
    if (number == 0)
        {
            return "0";
        }
    while (number >= 1)
    {
        
        if (number % 2 == 0)
        {
            binary = binary + "0";
            number = number / 2;
        }
        else
        {
            binary = binary + "1";
            number = number / 2;
        }
        
    }
    
    for (int i = 0; i < binary.length() / 2; i++)
    {
        swap(binary[i], binary[binary.length() - i - 1]);
    }
    
    
    return binary;
    
}

int main ()
{
    cout << decimalToBinaryIterative(26) << endl;
}