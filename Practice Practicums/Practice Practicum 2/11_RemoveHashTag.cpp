#include <iostream>
#include <string>
using namespace std;

/**
 * Write a function, RemoveHashTag, that takes a string as input and removes all 
 * the hashtags (#) characters. The function returns a string value without the hashtag characters.
 * Your function should be named RemoveHashTag
 * Your function has one input argument of type string
 * Your function has one return value of type string representing input string without the hashtag character.
 * Your function should not print anything string RemoveHashTag (string input)
 */
string RemoveHashTag (string input) 
{
    string newString = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input [i] != '#')
        {
            newString += input [i];
        }
    }
    return newString;
}

int main ()
{
    cout << RemoveHashTag ("#SKO#Buffs") << endl;
}