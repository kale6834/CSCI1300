#include <iostream>
#include <string>
using namespace std;


#ifndef PLAYER_H
#define PLAYER_H


class Players
{
    public:
    
    Players(); //defaults private variables to null
    
    string getUsername(); //returns the name of the player
    
    void setUsername(string); //sets the player's name
    
    void setAlive(bool); //sets if the player is alive or dead
    
    bool getAlive(); //returns if the player is alive or dead
    
    
    private:
    string player;
    bool alive;
};

#endif