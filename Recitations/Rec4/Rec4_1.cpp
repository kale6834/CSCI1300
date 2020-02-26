//CS1300 Fall 2018
//Author: Kalei Lewis
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
//Recitation 4 - Problem #1

/**
 * Algorithm: Write a function to print all positive even integers less than or equal to a max value.
 * 1. input maximum number
 * 2. find numbers divisible by 2 with a remainder zero = even numbers
 * 3. divide numbers by even numbers
 * Input parameters: max number
 * Output: even numbers up to max number
 * Returns: nothing
 */
 

#include <iostream>
using namespace std;

void printEvenNums (int max)
{   
    //i don't care about 0 or 1, so i started with i=2 because i want my output to start at 2
    int i = 2; 
    //while number is less than max number 
    while (i <= max)
    {
        //if number is divisible by 2, it is even
        if (i % 2 == 0)
        {
            //cout even numbers
            cout << i << endl;
        }
        //add 1 to i after every loop
        i++;
    }
}

int main ()
{
    printEvenNums (10); //test case 1. output should values 2-10
    printEvenNums (15); //test case 2. output should be values 2-14
}