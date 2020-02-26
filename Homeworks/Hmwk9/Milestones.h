#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef MILESTONES_H
#define MILESTONES_H

class Milestones
{
    public:
    
    Milestones();
    
    void setFortNames (string); //sets the name of the fort
    
    string getFortNames (); //return the name of the fort
    
    void setFortMiles (int); //sets the miles of a certain fort
    
    int getFortMiles (); //returns the miles of a certain fort
    
    void setRiverNames (string); //sets the name of a river
    
    string getRiverNames (); //returns the name of a river
    
    void setRiverMiles (int); //sets the miles of a certain river
    
    int getRiverMiles (); //returns the miles of a certain river
    
    void setRiverDepths(int); //sets the depths of a certain river
    
    int getRiverDepths (); //returns the depths of a certain river
    
    private:
    string fortName;
    int fortMile;
    string riverName;
    int riverMile;
    int riverDepth;
};

#endif