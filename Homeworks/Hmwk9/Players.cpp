#include "Players.h"


Players::Players()
{
    player = ""; //player is set to an empty string
    alive = true; //alive is set to true, meaning they are alive
}

void Players::setUsername(string input)
{
    player = input;
}

string Players::getUsername()
{
    return player;
}

void Players::setAlive(bool kill)
{
    alive = kill;
}

bool Players::getAlive()
{
    return alive;
}
