//Kalei Lewis: CS1300 Fall 2018
//Recitation 102: Paramjot Singh
//Cloud9 Workspace Editor: ide.c9.io/kaleilewis/kale6834
//Homework #2 Problem 1

/**
 * Algorithm: convert number of seconds given into hours, minutes, seconds
 * 1. input number of seconds
 * 2. convert seconds into hours
 * 3. convert remainder of hours into minutes
 * 4. convert remainder of minutes into seconds
 * Input parameters: number of seconds
 * Output parameters: hours, minutes, seconds
 * Returns: nothing
 */

#include <iostream>
using namespace std;

void convertSeconds (int SecondsGiven){
    int hours = SecondsGiven / 3600; //seconds need to be divded by 3600 because there are 3600 seconds in 1 hour
    int SecondsInRemainder = SecondsGiven % 3600; //this will give us the remainder of seconds from hours
    int minutes = SecondsInRemainder / 60; //we need to divide those seconds by 60 because there are 60 seconds in a minute
    int seconds = SecondsInRemainder % 60; //this will give us our seconds from remainder of minutes
    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s)" << endl;
}
int main ()
{
    convertSeconds (86400); //test case 1 for convertSeconds. This should output 24 hours 0 minutes 0 seconds.
    convertSeconds (3671); //test case 2 for convertSeconds. This should output 1 hour 1 minute 11 seconds.
    return 0;
}