#include <iostream>
#include <stdio.h>

using namespace std;

/**
 * Algorithm:
 * 1. type in sentence
 * 2. determine number of spaces
 * 3. determine number of words
 * 4. print out number of words
 * Input parameter: sentence
 * Output: number of words in sentence
 * Returns: number of words in sentence
 */

int getWordCount (string sentence)
{
    //initialize spaces at zero
    int spaces = 0;
    //initialize words at zero
    int words = 0;
    //words = spaces + 1
    //if there is nothing in the string, there are zero words
    if (sentence.length () == 0)
    {
        words = 0;
    }
    else
    {
        //initialize index at 0
        //this loop will run for until i is the sentence length
        for (int i = 0; i < sentence.length (); i++)
        {
            //if the sentence has a space in it
            if (sentence [i] == 32)
            {
                spaces++;
            }
        }
    }
    //return the number of words
    return words + 1;
}

int main ()
{
    string sentence = "Go"; //test case 1. should be 1 word
    cout << getWordCount (sentence) << " word" << endl;
    string sentence = ""; //test case 2. should be 0 words
    cout << getWordCount (sentence) << " words" << endl;
    string sentence = "I went"; //test case 3. should be 2 words
    cout << getWordCount (sentence) << " words" << endl;
    string sentence = "Colorless green ideas dream furiously"; //test case 4. shoud be 5 words
    cout << getWordCount (sentence) << " words" << endl;
    string sentence = "The rat the cat the dog bit chased escaped";//test case 5. should be 9 words
    cout << getWordCount (sentence) << " words" << endl;
    return 0;
}

// int main ()
// {
//     string s = "Hello, World!";
//     cout << s.length () + 3;
//     for (int i = 0; i < s.length (); i++)
//     {
//         cout << s[i] << endl;
//     }
//     return 0;
// }