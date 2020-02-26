#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: Write a function that takes a candidate substring and returns 
 * the number of times it occurs in another string.
 * 1. write string
 * 2. write substring
//  * 3. look through string
//  * 4. stop when substring is found
//  * Input paramters: a string substring, and a string word
//  * Output: number of times the substring occurs in the string
//  * Returns: how many times the substring occurred in the string
//  */
 

int getMatchCount (string sub, string word)
{
    //find will be initialized at 0
    int find = 0;
    //if the substring or word is empty
    if (sub.length () == 0 || word.length () == 0)
    {
        //-1 will be the output
        find = -1;
    }
    //if the substring input is greater than the word
    else if (sub.length () > word.length ())
    {
        //-2 will be the output
        find = -2;
    }
    else
    {
        //start index at spot 0 and run until the end of the word is reached
        for (int i = 0; i < word.length(); i++)
        {
            //if the start of the substring to the end of the substring equals the substring in the word
            if (word.substr(i, sub.length()) == sub)
            {
                //increase how many times the substring is found in the word
                find++;
            }
        }
    }
    //return how many times the substring is found in the word
    return find;
}

int main ()
{
    string word = "mississippi";//test case 1. output should be 1
    string sub = "ipp";//this will look for the 'ipp' in mississippi
    string word = "mississippi";//test case 2. output should be 2
    string sub = "si"; //i want this to find 'si' in mississippi
    cout << getMatchCount (sub, word) << endl;
}



//if (s.substr (i, sub.length())) = sub
//if we find "si" increase length