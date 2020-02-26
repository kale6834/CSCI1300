#include "Player.h"

Player::Player(int nDice)
{
    
    for (int i = 0; i < nDice; i++)
    {
        Dice d1;
        /*
        add Dice object created to array of Dices
        */  
        myDice[i] = d1;
    }
}

void Player::setNumDice(int number)
{
    nDice = number;
}

void Player::playerRoll()
{
    /*
    complete function to roll all the dices
    */
    for (int i = 0; i < nDice; i++)
    {
        myDice[i].roll();
        
    }
}

int Player::getDiceValueAtIndex(int i) const
{
    Dice d = myDice[i];
    int value = d.getFaceValue();
    return value;
    // return myDice[i].getFaceValue();
}