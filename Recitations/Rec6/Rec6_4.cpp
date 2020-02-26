#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: Write a function getScores which takes three input arguments: 
 * a string of scores, an array of integers to fill with scores, and an integer 
 * representing the maximum number of values that array can contain. The 
 * function will find each substring of the given string separated by space 
 * characters and place the value represented by that string in to the array. 
 * Your function will return the number of integers extracted.
 * 1. traverse string
 * 2. scores will be added to a temporary string
 * 3. when the index hits the delimiter, it will add that temporary string to an array
 * Input parameter: a string of scores, an integer array to hold the score values, 
 * an integer of the maximum amount of numbers that the array can hold
 * Output: number of scores extracted
 * Returns: number of scores extracted
 */
 

int getScores (string scores, int array [], int length)
{
    int i = 0;
    int count = 0;
    string temp = "";
    if (scores == "")
    {
        return 0;
    }
    else if (scores != "")
    {
        for (i = 0; i < scores.length(); i++)
        {
           if (scores [i] != ' ')
           {
                temp = temp + scores [i];
           }
           else if (scores [i] == ' ' && i != 0 && temp != "")
           {
               array[count] = stoi(temp);
            //   cout << array[count] << endl;
               temp = "";
               count++;
           }
        }
        if (temp != "")
        {
            array[count] = stoi(temp);
            // cout << array[count] << endl;
            count++;
        }
        if (count > length)
        {
            return -1;
        }
        return count;
    }
}

int main ()
{
    int nums [6];
    cout << getScores ("15 2007 5", nums, 6) << endl; //test case 1. output should be 3
    cout << getScores ("123 456 789 000", nums, 6) << endl; //test case 2. output should be 4
    cout << getScores ("", nums, 6) << endl; //test case 3. output should be
}