#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Stats
{
    public:
    Stats();
    void ReadFile(string);
    float getAvgStringLength();
    string getLongestString();
    
    private:
    string data[50];
    int dataSize;
    int counter;
};

Stats::Stats()
{
    dataSize = 50;
    counter = 0;
}

void Stats::ReadFile(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            data[counter] = line;
            counter++;
        }
    }
}

float Stats::getAvgStringLength()
{
    float average = 0.0;
    for (int i = 0; i < counter; i++)
    {
        average = data[i].length() + average;
    }
    return average / counter;
}

string Stats::getLongestString()
{
    float max = 0.0;
    string best;
    for (int i = 0; i < counter; i++)
    {
        if (data[i].length() > max)
        {
            best = data[i];
        }
    }
    return best;
}