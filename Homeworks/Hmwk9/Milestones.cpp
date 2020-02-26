#include "Milestones.h"

Milestones::Milestones()
{
    fortName = "";
    fortMile = 0;
    riverName = "";
    riverMile = 0;
    riverDepth = 0;
}

void Milestones::setFortNames (string input)
{
    fortName = input;
}

string Milestones::getFortNames ()
{
    return fortName;
}

void Milestones::setFortMiles (int input)
{
    fortMile = input;
}

int Milestones::getFortMiles ()
{
    return fortMile;
}

void Milestones::setRiverNames (string input)
{
    riverName = input;
}

string Milestones::getRiverNames ()
{
    return riverName;
}

void Milestones::setRiverMiles (int input)
{
    riverMile = input;
}

int Milestones::getRiverMiles ()
{
    return riverMile;
}

void Milestones::setRiverDepths(int input)
{
    riverDepth = input;
}
    
int Milestones::getRiverDepths ()
{
    return riverDepth;
}