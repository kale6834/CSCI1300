#include <iostream>
#include <string>
using namespace std;

int CountUpper (string input)
{
    bool alphabet = true;
    int i = 0;
    int count = 0;
    if (input == "")
    {
        return -1;
    }
    else
    {
        for (i = 0; i < input.length (); i++)
        {
            if (input [i] >= 'A' && input [i] <= 'Z')
            {
                count ++;
                alphabet = false;
            }
        }
    }
    if (alphabet == true)
    {
        return -2;
    }
    return count;
}
int main ()
{
    // cout << CountUpper ("ALL THE BEST") << endl;
    cout << CountUpper ("ALL the BEST") << endl;
}