#include <iostream>
#include <string>
using namespace std;

#ifndef ODDEVEN_H
#define ODDEVEN_H
class OddEven
{
    public:
    OddEven();
    void ReadFile();
    int getOddCount();
    int getEvenCount();
    
    private:
    int numbers[50];
    int counter;
};
#endif


OddEven::OddEven()
{
    for (int i = 0; i < 50; i++)
    {
        numbers[i] = -1;
    }
    
    odd = 0;
    even = 0;
}

void OddEven::ReadFile(string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    string line;
    int counter = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            numbers[counter] = stoi(line);
            if (numbers[counter] % 2 != 0)
            {
                odd++;
            }
            else if (numbers[counter] % 2 == 0)
            {
                even++;
            }
            counter++;
        }
    }
}

int OddEven::getOddCount()
{
    
    return odd;
}

int OddEven::getEvenCount()
{
    
    return even;
}
