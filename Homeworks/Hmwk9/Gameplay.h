#include <iostream>
#include <string>
#include <time.h>
#include <cmath>
#include <iomanip>
#include "Supplies.h"
#include "Players.h"
#include "Date.h"
#include "Milestones.h"
using namespace std;

#ifndef GAMEPLAY_H
#define GAMEPLAY_H



class Gameplay
{
    public:
    
    Gameplay(); //all members are set to null
    
    void addPlayers (string); //adds the player to the game
    
    int buyOxen(int); //function for buying the oxen
    
    int buyFood(int); //function for buying the food
    
    int buyAmmo(int); //function for buying the bullets
    
    int buyWagonParts(int); //function for buying the wagon parts
     
    int buyMedKits(int); //function for buying the med kits
    
    double getTotalBill(); //function for getting the total bill
    
    int visitStore(); //function for visiting the store and has the switch cases
    
    int takeTurns(); //this is the function that gives the player different turns
    
    void rest (int, int); //player will rest in this function
    
    int continueTrail(); //player continues on trail in this function
    
    int hunt(); //player will hunt in this function
    
    void setMilesToGo(int); //function to set miles to go until next milestone
    
    int getMilesToGo(int); //function to get mile to go until next milestone
    
    int misfortuneDiseases(int); //a player could be affected by diseases
    
    int misfortunesHappen(int); //called at the end of every turn, gives different misfortunes
    
    void travelDate(int, int); //sets when the part when leave Missouri
    
    double raiderAttack(int); //this is called at the end of every turn, chance of raiders attacking
    
    int milestonesForts(string); //reads the fort file texts
    
    int milestonesRivers(string); //reads the river file texts
    
    int reachedFort(int, int); //function is called when the player reaches a fort
    
    int reachedRiver(int, int); //this function is called when the player reaches a river
    
    private:
    double numMoney;
    int numPlayers;
    double totalBill;
    int milesToGo;
    int numBullets;
    int milesTraveled;
    int billCounter;
    Supplies supplies;
    Players players[5];
    Date date;
    Milestones forts[6];
    Milestones rivers[4];
    
};

#endif