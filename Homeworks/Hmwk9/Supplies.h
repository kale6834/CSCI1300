#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef SUPPLIES_H
#define SUPPLIES_h

class Supplies
{
    public:
    Supplies ();
    
    void setNumOxen(int);
    
    int getNumOxen();
    
    void setNumFood(int);
    
    int getNumFood();
    
    void setNumAmmo(int);
    
    int getNumAmmo();
    
    void setNumWagonParts(int);
    
    int getNumWagonParts();
    
    void setNumMedKits(int);
    
    int getNumMedKits();
    
    int foodEaten(int); //calculates the amount of food that was eaten while group is resting
    
    // int huntFoodEaten(int);
    
    private:
    int numOxen; //must spend $100-$200. 2 oxen in a yoke. each yoke is $40
    int numFood;
    int numAmmo;
    int numWagonParts;
    int numMedKits;
    
};

#endif