#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: Write a function split which takes four input arguments: a string 
 * to be split, a character to split on (“a delimiter”), an array of strings to 
 * fill with the split pieces of the input string, and an integer representing 
 * the maximum number of split string pieces. The function will split the input 
 * string in to pieces separated by the delimiter, and populate the array of 
 * strings with the split pieces up to the provided maximum number of pieces. 
 * Your function will return the number of pieces the string was split into.
 * 1. traverse string
 * 2. add each character to a temporary string
 * 3. find delimiter
 * 4. once index gets to delimiter, add previous string to an array
 * 5. reset temporary string back to zero and run through loop until the end of the phrase length
 * 6. start count at 0
 * 7. every time a word is added to an array, increase count
 * Input parameters: a string to be split, a delimiter character, a string array 
 * to store split pieces, an integer length that stands for the maximum words that can be split
 * Output: number of split words
 * Returns: integer of split words
 */

//something I could ahve added would be phrase += " "
//the phrase is going to be split
int split (string phrase, char letter, string array[], int length)
{
    //start at index 0
    int i = 0;
    //start at word count 0
    int count = 0;
    //this is going to be the temporary string that the characters in the string are added to
    string temp = "";
    //if phrase is empty
    if (phrase == "")
    {
        return 0;
    }
    //if phrase is not empty
    else if (phrase != "")
    {
    //run the for loop
    //run the index until the end of the phrase length, increasing every time
        for (i = 0; i < phrase.length(); i++)
        {//if the index in the phrase is not equal to the delimieter
           if (phrase [i] != letter)
           {//add that string[i] into the temporary string
           //when the for loop restarts, the temporary string will reset back to empty
           //the new temporary string will be the old temporary string plus the current one
                temp = temp + phrase [i];
           }
           //if the index in the phrase is equal to the letter
           //and if the index is not at 0
           //and if the temporary string is not empty still
           else if (phrase [i] == letter && i != 0 && temp != "")
           {
               //once the index in the phrase reaches the delimiter, add the temporary string into the array
               array[count] = temp;
            //this is where the temporary string is reset to empty
               temp = "";
               //increase word count
               count++;
           }
        }
        //this was added in order to get the last word into the string, since the delimiter wasn't hit
        //if the temporary string is not empty
        if (temp != "")
        {//add that temporary string to the array
            array[count] = temp;
            //increase the word count again
            count++;
        }
        //if the input is split into more words than the array can hold
        if (count > length)
        {
            //return -1
            return -1;
        }
        // the count will be returned at the end to break out of the loop
        return count;
    }
    
}

int main ()
{
    string words[6];
    cout << split ("one small step", ' ', words, 6); //test case 1. output should be 3
    split(" one small step ", ' ', words, 6); //test case 2. output should be 3
    split ("cow/big pig/fish", '/', words, 6); //test case 3. output should be 3
    cout << split ("ABCDEFG", ' ', words, 0) << endl; //test case 4. output should be 1
 
    
}