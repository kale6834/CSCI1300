////Kalei Lewis: CS1300 Fall 2018
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor: ide.c9.io/kaleilewis/kale6834
//Homework #2 Problem 3

/**
 * Algorithm (calculate the US population after 365 days)
 * 1. With the current US population, calculate how many people will be added with a birth every 8 seconds in 365 days.
 * 2. With the current US population, calculate how many people will be subtracted with a death every 12 seconds in 365 days.
 * 3. With the current US population, calculate how many people will be added with an immigrante very 27 secodns in 365 days.
 * 4. Calculate the population by adding births and immigrants and subtracting deaths. 
 * Input parameter: initial population
 * Output parameter: total of population in 365 days
 * Returns: total of population in 365 days
 */
 
#include <iostream>
using namespace std;

int population (int InitialPopulation){
    int seconds = 31536000;
    int birth = seconds / 8; //since there are 8 births in a year, we need to divide it by the number of seconds in a year
    int death = seconds / 12; //since there are 12 deaths every second, we need to divide it by the number of seconds in a year
    int immigrant = seconds / 27; //since there are 27 immigrants every seconds, we need to divide that by the number of seconds in a year
    int total = InitialPopulation + birth - death + immigrant; //since births and immigrants are an addition to the population, we will add them. 
    //Since deaths are a substraction from the population, we need to subtract in this equation.
    return total;
}

int main()
{   
    int InitialPopulation;
    cout << "The population will be " << population (1000000) << " in 365 days." <<endl; //test case 1 for population. 
    cout << "The population will be " << population (500000) << " in 365 days." <<endl; //test case 2 for population
    return 0;
}