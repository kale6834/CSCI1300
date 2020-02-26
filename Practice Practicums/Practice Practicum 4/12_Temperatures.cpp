#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Temperatures
{
    public:
    Temperatures();
    void ReadFile(string);
    float getMinTemp();
    string getMinTempDay();
    
    private:
    float temp_values[7];
    string days[7];
    int index;
    int day;
};

Temperatures::Temperatures()
{
    for (int i = 0; i < 7; i++)
    {
        temp_values[i] = 120.0;
    }
    index = 0;
    day = 0;
}

void Temperatures::ReadFile(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    string line, array[2];
    if (myfile.is_open())
    {
        int counter = 0;
        while (getline(myfile,line))
        {
            float temp;
            split(line, ',', array, 2);
            days[counter] = array[0];
            temp_values[counter] = stof(array[1]);
            counter++;
        }
        myfile.close();
    }
}

float Temperatures::getMinTemp()
{
    float min = temp_values[0];
    for (int i = 0; i < 7; i++)
    {
        if (temp_values[i] < min)
        {
            min = temp_values[i];
            index = i;
        }
    }
    return min;
}

string Temperatures::getMinTempDay()
{
        if (days[index] == "1")
        {
            return "Sunday";
        }
        else if (days[index] == "2")
        {
            return "Monday";
        }
        else if (days[index] == "3")
        {
            return "Tuesday";
        }
        else if (days[index] == "4")
        {
            return  "Wednesday";
        }
        else if (days[index] == "5")
        {
            return "Thursday";
        }
        else if (days[index] == "6")
        {
            return "Friday";
        }
        else if (days[index] == "7")
        {
            return "Saturday";
        }
}