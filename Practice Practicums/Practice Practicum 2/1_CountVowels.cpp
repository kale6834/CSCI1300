#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: function takes an input and returns the number of vowels in a string
 * 1. write string
 * 2. traverse string
 * 3. find number of vowels
 * 4. return number of vowels in string
 */
 

int CountVowels (string phrase)
{
    int i = 0;
    int count = 0;
    if (phrase.length () == 0)
    {
        return - 1;
    }
    else
    {
        for (i = 0; i < phrase.length (); i++)
        {
            if (phrase [i] == 65 || phrase [i] == 69 || phrase [i] == 73 || phrase [i] == 79 || phrase [i] == 85 || 
            phrase [i] == 97 || phrase [i] == 101 || phrase [i] == 105 || phrase [i] == 111 || phrase [i] == 117)
            {
                count++;
            }
        }
        return count;
    }
}

int main ()
{
    cout << CountVowels ("abc def") << endl;
    cout << CountVowels ("binx") << endl;
}