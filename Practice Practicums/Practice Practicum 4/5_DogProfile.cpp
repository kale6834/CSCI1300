#include <iostream>
#include <string>
using namespace std;

#ifndef DOGPROFILE_H
#define DOGPROFILE_H
class DogProfile
{
    public:
    DogProfile();
    DogProfile(string, string, float);
    void setName(string);
    string getName();
    void setTemperament(string);
    string getTemperament();
    void setBitingProbability(float);
    float getBitingProbability();
    string goodBoy();
    
    private:
    string name;
    string temperament;
    float bitingProbability;
};
#endif

DogProfile::DogProfile()
{
    name = "Fido";
    temperament = "always wags tail";
    bitingProbability = -100.0;
}

DogProfile::DogProfile(string dogName, string mean, float x)
{
    name = dogName;
    temperament = mean;
    bitingProbability = x;
}

void DogProfile::setName(string input)
{
    name = input;
}

string DogProfile::getName()
{
    return name;
}

void DogProfile::setTemperament(string input)
{
    temperament = input;
}

string DogProfile::getTemperament()
{
    return temperament;
}

void DogProfile::setBitingProbability(float input)
{
    bitingProbability = input;
}

float DogProfile::getBitingProbability()
{
    return bitingProbability;
}

string DogProfile::goodBoy()
{
    if (bitingProbability <= 1000.0)
    {
        return "Good Boy";
    }
    else if (bitingProbability > 1000.0)
    {
        return "Bad Boy";
    }
}

