// CSCI 1300 FALL 2018
// Author: Kalei Lewis
// Recitation: 102 - Paramjot Singh
// Cloud 9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834

/**
 * Algorithm:
 * 1. Start game
 * 2. Start with user first
 * 3. If user wants to roll a dice, go to next loop
 * 4. While user's answer is still yes, roll dice
 * 5. If dice is 1 or 6, turn total is 0 and goes to computer's turn
 * 6. If dice is 15, turn total is 15 and goes to computer's turn
 * 7. If dice is 2, 4, or 5, the dice value is the turn total and user is asked to roll again
 * 8. Continue loop depending on user's answer
 * 9. If user's answer is no, go to computer's turn
 * 10. Computer's turn will continue until turn total is 10 or more
 * 11. Rolling dice will be the same for computer as it is for the user
 */

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;
 
int rollDice();
int ComputerRoll();
int UserRoll();
void game();

int main ()
{
    game ();
    return 0;
}

/**
 * rollDice
 * returns a random integer between 1 and 6, works as a rolling dice.
 * returns value, int number (1-6)
 */

int rollDice ()
{
    return random () % 6 + 1;
}

//computer
int ComputerRoll ()
{
    //turn total is declared as 0 initially
    int turnTotal = 0;
    //this needs to be printed at the beginning of every turn
    cout << "It is now computer's turn" << endl << endl;
    //if the turn total is less than 10, jump into the loop
    if (turnTotal <10)
    {//as long as turn total is less than 10, continue loop
        while (turnTotal < 10)
        {
            //this calls the function and sets the roll equal to rollDice, so it knows where to take the value
            int roll = rollDice();
            //if roll is equal to 1 or 6
            if (roll == 1 || roll == 6)
            {//turn total is zero
                turnTotal = 0;
                //print what the computer rolled
                cout << "Computer rolled a " << roll << endl;
                //print what the computer's turn total is
                cout << "Computer turn total is " << turnTotal << endl;
                //return the turn total and go back to where the function was called
                return turnTotal;
            }
            //if roll equals 3
            else if (roll == 3)
            {
                //turn total is 15
                turnTotal = 15;
                //print out what comptuer rolled
                cout << "Computer rolled a " << roll << endl;
                //print out what computer's turn total is
                cout << "Computer turn total is " << turnTotal << endl;
                //return the turn total and go back to where the function was called
                return turnTotal;
            }
            //if the roll is a 2, 4, or 5
            else if (roll == 2 || roll == 4 || roll == 5)
            {
                //the turntotal equals the roll, but we need to add that to the previous turn totals
                turnTotal = turnTotal + roll;
                //print what the computer rolled
                cout << "Computer rolled a " << roll << endl;
                //print what the computer's turn total is
                cout << "Computer turn total is " << turnTotal << endl;
            }
        }
    }
    //return the turn total to break out of the while loop
    return turnTotal;
}

int UserRoll ()
{
    //turn total is set to zero
    int turnTotal = 0;
    //the user's answer is going to be a character
    char answer = ' ';
    cout << "Do you want to roll a dice (Y/N)?: " << endl;
    cin >> answer;
    //if answer equals a Y or y, jump into loop
    if (answer == 'Y' || answer == 'y')
    {//as long as answer is Y or y stay in loop
        while (answer == 'Y' || answer == 'y')
        {//the roll is set equals to whatever the dice rolls, and the rollDice function is also called
                int roll = rollDice();
                //if roll is equal to 1 or 6
                if (roll == 1 || roll == 6)
                {
                    //if roll is 1 or 6, turn total is zero
                    turnTotal = 0;
                    //print out what user rolled
                    cout << "You rolled a " << roll << endl;
                    //print out what turn total is
                    cout << "Your turn total is " << turnTotal << endl;
                    //return turn total, return to where function was called
                    return turnTotal;
                }
                //if roll is equal to 3
                else if (roll == 3)
                {
                    //print out what user rolled
                    cout << "You rolled a " << roll << endl;
                    //turn total is going to equal 15
                    turnTotal = 15;
                    //print out what the turn total is
                    cout << "Your turn total is " << turnTotal << endl;
                    //return the turn total and return to where the function was called
                    return turnTotal;
                }
                //if the roll is a 2, 4, or 5
                else if (roll == 2 || roll == 4 || roll == 5)
                {
                    //the turn total is equal to the roll, but it also needed to be added to the previous turn totals
                    turnTotal = turnTotal + roll;
                    //print out what the user rolled
                    cout << "You rolled a " << roll << endl;
                    //print out what the user's turn total is
                    cout << "Your turn total is " << turnTotal << endl;
                    cout << "Do you want to roll again (Y/N)?:" << endl;
                    cin >> answer;
                }
        }
        //break to get out of while loops
        //if user says no, then it will return to where it was called from
        return turnTotal;
    }
    //if the user doesn't enter y or Y initially
    else
    {
        //return to where the function was called
        return turnTotal;
    }
}

//this will determine if the game is over or not
int endOfGame (int ComputerTotal, int HumanTotal)
{
    //this initiates if the computer or human total is more than or equal to 100
    if (ComputerTotal >= 100 || HumanTotal >= 100)
    {
        //if the computer total is equal to or greater than 100, the computer wins
        if (ComputerTotal >= 100)
        {
            cout << "Congratulations! computer won this round of jeopardy dice!" << endl;
        }
        //if the human total is equal to or greater than 100, the human wins
        else if (HumanTotal >= 100)
        {
            cout << "Congratulations! human won this round of jeopardy dice!" << endl;
        }
    }
}

void game ()
{
    //computer and human total starts initially at the beginning of the function at 0
    int ComputerTotal = 0;
    int HumanTotal = 0;
    cout << "Welcome to Jeopardy Dice!" << endl << endl;
    //as long as the computer total and human total is less than 100, continue game
    while (ComputerTotal < 100 && HumanTotal < 100)
    {
        //if the computer total is less than 100, start the game
        //this will be checked also after the computer's total is added up, so it jumps to the user's turn
        if (ComputerTotal < 100)
        {
            cout << "It is now human's turn" << endl << endl;
            HumanTotal = UserRoll () + HumanTotal;
            cout << "computer: " << ComputerTotal << endl;
            cout << "human: " << HumanTotal << endl << endl;
        }
        //this will check to see if the human's total is less than 100 or not, 
        //so it will be checked after the human's roll and will jump to the computer's turn
        if (HumanTotal < 100)
        {
            ComputerTotal = ComputerRoll () + ComputerTotal;
            cout << "computer: " << ComputerTotal << endl;
            cout << "human: " << HumanTotal << endl << endl;
        }
    }
    //endOfGame will be called if the while loop is not true
    //break to get out of while loop
    endOfGame (ComputerTotal, HumanTotal);
}