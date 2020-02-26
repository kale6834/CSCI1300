#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int countCharacter (string array[], int size, char ch)
{
    int count = 0;
    // string newArray[size];
    for (int i = 0; i < size; i++)
    {
        string s = array[i];
        for (int j = 0; j < s.size();j++)
        {
            if (s[j] == ch)
            {
                count++;
            }
        }
    }
    return count;
}

int main ()
{
    string array[6] = {"elephant", "english", "elegant", "america", "united", "apple"};
    char ch = 'e';
    cout << countCharacter(array, 6, ch) << endl;
}