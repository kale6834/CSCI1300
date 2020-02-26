////Kalei Lewis: CS1300 Fall 2018
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor: ide.c9.io/kaleilewis/kale6834
//Homework #2 Problem 4

/**
 * Algorithm : calculate luminosity of star
 * 1. give brightness and distance of star
 * 2. calculate luminosity with the formula (4 * brightness * 3.14159 * distance)^2
 * 3. print how bright the star is
 * Input parameter: brightness, distance
 * Output parameter: luminosity
 * Returns: luminosity
 */
 

#include <iostream>
#include <math.h>
using namespace std;

int luminosity (double brightness, double distance) {
    int Luminosity = 4 * brightness * 3.14159 * pow(distance,2);
    return Luminosity;
}

int main ()
{
    cout << "Your star is " <<luminosity (1.5, 17.8) << " watts." <<endl; //test case 1 for luminosity
    cout << "Your star is " <<luminosity (0.254, 1.97) << " watts." <<endl; //test case 2 for luminosity
    return 0;
    
}