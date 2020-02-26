//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Homework 3 - Problem #1

/**
 * Algorithm:
 *Write a function collatzStep which takes a single integer argument and returns an integer. 
 *The return value should be the next value in the Collatz sequence based on the value of the input parameter. 
 *If the given value n is even, the next value should be n/2 . If n is odd, the next value should be 3n+1. 
 *If the given value is not positive the function should return 0.
 * 1. Input number
 * 2. Input numbers must be greater than 0.
 * 3. If input number is even, divide by 2.
 * 4. If input number is odd, multiply by 3 and add 1.
 * 5. If input number is less than zero, return 0.
 * Input paramters: an integer number
 * Output: new value of number
 * Returns: value if a positive number and 0 if it's a negative number
 */
 
 
#include <iostream>
using namespace std;

int collatzStep (int number)
{
    if (number >= 0 && number % 2 == 0) //if number if greater than 0 and divisible by 2
    {
        int value = number / 2; //divide number by 2
        return value; //return new value
    }
    else if (number >= 0 && number % 2 != 0) //if number is greater than 0 and not divisible by 2
    {
        int value = (3 * number) + 1; //multiply number by 3 and add 1
        return value; //return new value
    }
    else (number < 0); //if number is less than zero
    {
        return 0; //return zero
    }
}

int main ()
{   //test case 1. 
    //expected output
    //2
    cout << collatzStep (4) << endl;
    //test case 2.
    //expected output
    //22
    cout <<collatzStep (7) << endl;
    //test case 3.
    //expected output
    //0
    cout << collatzStep (-5) <<endl;
}