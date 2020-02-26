#include <iostream>
#include <string>
using namespace std;

#ifndef QUARTERBACK_H
#define QUARTERBACK_H

class Quarterback
{
    public:
    Quarterback();
    Quarterback (string n, int comp, int att, int yards, int td, int i);
    Quarterback (string d);
    void setName (string new_name);
    string getName();
    void setComp (int x);
    int getComp ();
    void setAtt (int x);
    int getAtt ();
    void setYards (int x);
    int getYards ();
    void setTD (int x);
    int getTD ();
    void setPick (int x);
    int getPick();
    void PassCompleted (int x);
    void PassAttempted ();
    void Interception();
    float PasserRating();
    void Touchdown (int x);
    
    private:
    float pass_completes;
    float pass_attempts;
    float total_yards;
    int touchdowns;
    float intercepts;
    string name;
    
};

#endif