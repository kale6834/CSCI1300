#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: Write the code to declare and populate the three arrays 
 * listed below. You are not writing a function; your code will be placed 
 * directly in to our main() function for evaluation. For testing/development 
 * in cloud9, simply write the code in your own main() function.
 * 1. first function will have an array of 10 floating point values initialized at -459.67
 * 2. second function will have an array of strings of the colors red, blue, green, cyan, and magenta in that order
 * 3. third function will have an array of 100 positive integers from 1 - 100
 * Input values: none
 * Output: none
 * Returns: 0
 */
 
int main ()
{
    float temps [10] = {-459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67};
    string colors [] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
    int sequence [100] 
    //in order to get values from 1 - 100 i will need a while loop if i don't want to write out every number
    //start i (index) at 0
    int i = 0;
    //while the index is still under 100
    //run
    while (i < 100)
    {
        //the index of the sequence is equal to the index + 1
        sequence [i] = i + 1;
        //increase the index every time
        i++;
    }
    return 0;
}