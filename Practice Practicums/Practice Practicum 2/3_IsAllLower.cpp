#include <iostream>
#include <string>
using namespace std;

bool IsAllLower (string phrase)
{
    bool alphabet = true;
    int i = 0;
    for (i = 0; i < phrase.length (); i++)
    {
        if (phrase [i] >= 'a' && phrase [i] <= 'z')
        {
            alphabet = true;
        }
        else if (phrase [i] >= 'A' && phrase [i] <= 'Z' || phrase [i] >= 33 && phrase [i] <= 64)
        {
            return false;
        }
    }
    return alphabet;
}

int main ()
{
    cout << IsAllLower ("onetwo") << endl;
    cout << IsAllLower ("onEtwo") << endl;
    cout << IsAllLower ("^#123") << endl;
}