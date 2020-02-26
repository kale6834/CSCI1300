#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: Write a function to return the last index at which a 
 * character is used in a string.
 * 1. write a letter
 * 2. write a word
 * 3. scan word for letter
 * 4. return find indexes it is on
 * 5. return last index location
 * Input parameters: a character, a string
 * Output: index location of character given
 * Returns: index location of character given
 */

int getLastIndex (char letter, string word)
{
    //variable a is = -2, which will be returned if the character can not be found in the string
    int a = -2;
    //if string is empty, then -1 will be returned
    if (word.length () == 0 || letter == 0)
    {
        a = -1;
    }
    //if the above condition is not met
    else
    {
        for (int i = word.length () - 2; i >= 0; i--)
        {
            //check if i in the word is equal to the letter given
            if (word[i] == letter);
            {
                return i;//the index will be  returned
            }
        }
    }
    //-2 will be returned from above
    return a;
}

int main ()
{
    char letter = 'o'; //test case 1. output should be 6
    string word = "lollipop";
    cout << getLastIndex (letter, word) << endl;
    char letter = 'p'; //test case 2. output should be 9
    string word = "mississippi";
    cout << getLastIndex (letter, word) << endl;
}