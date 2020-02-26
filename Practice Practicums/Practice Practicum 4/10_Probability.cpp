#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// #ifndef PROBABILITY_H
// #define PROBABILITY_H
class Probability
{
    public:
    Probability();
    void ReadFile(string);
    string getMostLikelyEvent(float);
    
    private:
    float prob_values[50];
    string event[50];
    int counter = 0;
};

// #endif

Probability::Probability()
{
    for (int i = 0; i < 3; i++)
    {
        prob_values[i] = 0.0;
        event[i] = "";
    }
}

void Probability::ReadFile(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line, ','))
        {
            event[counter] = line;
            getline(myfile,line);
            prob_values[counter] = stof(line);
            counter++;
        }
    }
    else
    {
        myfile.close();
    }
}

string Probability::getMostLikelyEvent(float threshold)
{
    for (int i = 0; i < counter; i++)
    {
        if (threshold <= prob_values[i])
        {
            return event[i];
        }
    }
}