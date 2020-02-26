#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef PLAYERS_H
#define PLAYERS_H
class Players
{
    public:
    Players();
    void ReadFile(string);
    float MaxSalary();
    string MaxSalaryName();
    
    private:
    float salaries[50];
    string names[50];
    int counter = 0;
};
#endif

Players::Players()
{
    for (int i = 0; i < 50; i++)
    {
        salaries[i] = {-1.0};
        names[i] = {""};
    }
    
}

void Players::ReadFile(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    string line;
    string Placeholder[50];
    if (myfile.is_open())
    {
        while (getline(myfile, line, ','))
        {
            // split(line,',',Placeholder,50);
            names[counter] = line;
            getline(myfile, line);
            salaries[counter] = stof(line);
            counter++;
        }
    }
    else
    {
        myfile.close();
    }
}

float Players::MaxSalary()
{
    float max = 0.0;
    for (int i = 0; i < 50; i++)
    {
        if (salaries[i] > max)
        {
            max = salaries[i];
        }
    }
    return max;
}

string Players::MaxSalaryName()
{
    float max = 0.0;
    string best;
    for (int i = 0; i < 50; i++)
    {
        if (salaries[i] > max)
        {
            best = names[i];
        }
    }
    return best;
}