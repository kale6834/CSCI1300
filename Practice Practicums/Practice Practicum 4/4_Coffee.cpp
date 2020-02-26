#include <iostream>
#include <string>
using namespace std;

#ifndef COFFEE_H
#define COFFEE_H
class Coffee
{
    public:
    Coffee();
    Coffee (string, float);
    void setRoastType(string);
    string getRoastType();
    void setTemp(float);
    float getTemp();
    string drinkability();
    
    private:
    string roastType;
    float temp;
};

#endif

Coffee coffee;

Coffee::Coffee()
{
    roastType = "";
    temp = 180.0;
}

Coffee::Coffee(string input, float degree)
{
    roastType = input;
    temp = degree;
}

void Coffee::setRoastType(string input)
{
    roastType = input;
}

string Coffee::getRoastType()
{
    return roastType;
}

void Coffee::setTemp(float input)
{
    temp = input;
}

float Coffee::getTemp()
{
    return temp;
}

string Coffee::drinkability()
{
    string drinkable;
    if (temp < 100.0)
    {
        drinkable = "Too Cold";
    }
    else if (temp >= 100.0 && temp < 160.0)
    {
        drinkable = "Just Right";
    }
    else if (temp >= 160.0 && temp < 180.0)
    {
        drinkable = "Hot";
    }
    else if (temp >= 180.0)
    {
        drinkable = "Too Hot";
    }
    return drinkable;
}

