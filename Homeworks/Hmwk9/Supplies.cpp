#include "Supplies.h"

Supplies::Supplies()
{
    numOxen = 0;
    numFood = 0;
    numAmmo = 0;
    numWagonParts = 0;
    numMedKits = 0;
}

int randomNumbers(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

void Supplies::setNumOxen(int input)
{
    numOxen = input;
}

int Supplies::getNumOxen()
{
    return numOxen;
}

void Supplies::setNumFood(int input)
{
    numFood = input;
}

int Supplies::getNumFood()
{
    return numFood;
}

void Supplies::setNumAmmo(int input)
{
    numAmmo = input;
}

int Supplies::getNumAmmo()
{
    return numAmmo;
}

void Supplies::setNumWagonParts(int input)
{
    numWagonParts = input;
}

int Supplies::getNumWagonParts()
{
    return numWagonParts;
}

void Supplies::setNumMedKits(int input)
{
    numMedKits = input;
}

int Supplies::getNumMedKits()
{
    return numMedKits;
}

int Supplies::foodEaten (int input)
{
    numFood = numFood - input;
    return numFood;
}

// int Supplies::huntFoodEaten(int input)
// {
//     numFood = numFood - input;
//     return numFood;
// }

