#include <iostream>
#include <string>

using namespace std;

/**
 * Algorithm:
 * Write a function to count the number of digits in a string.
 * 1. determine difference between digits and letters
 * 2. run through string a character at a time
 * 3. pick out digits vs letters
 * 4. output number of digits
 * Input parameters: digits
 * Output: number of digits in a string
 * Returns: number of digits in a string
 */
 
int getDigitCount (string digits)
{
    //initial count of digits in a string is zero
    int count = 0;
    //initialize index at point zero
    //run the index until the end of the string length
    //increase number of index every time
    for (int i = 0; i < digits.length (); i++)
    {
        //if digits are between 0 and 9
        if (digits[i] >= 48 && digits [i] <= 57)
        {
            //increase count every time
            count++;
        }
    }
    //return count
    return count;
}

int getDigitCount(string digits);
int main ()
{
    string digits = "12345"; //test case 1. output should be 5 digits
    cout << getDigitCount(digits) << endl;
    string digits = "a blue house"; //test case 2. output should be 0 digits
    cout << getDigitCount(digits) << endl;
    string digits = "a0aaa"; //test case 3. output should be 1 digit
    cout << getDigitCount(digits) << endl;
    return 0;
}