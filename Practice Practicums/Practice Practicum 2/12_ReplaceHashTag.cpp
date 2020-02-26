#include <iostream>
#include <string>
using namespace std;

/**
 * Write a function, ReplaceHashTag, that takes a string as input and replaces 
 * all the hashtags (#) characters with @ character. The function returns a string 
 * representing input string containing # character replaced with @ character.
 * Your function should be named ReplaceHashTag
 * Your function has one input argument of type string
 * Your function has one return value of type string representing input string 
 * containing # character replaced with @ character.
 * Your function should not print anything
 */
 
string ReplaceHashTag (string input)
{
    string newString;
    for (int i = 0; i < input.length(); i++)
    {
        if (input [i] != '#')
        {
            newString = newString + input [i];
        }
        else 
        {
            newString = newString + '@';
        }
    }
    return newString;
}

int main ()
{
    cout << ReplaceHashTag("#SKO#Buffs") << endl;
}