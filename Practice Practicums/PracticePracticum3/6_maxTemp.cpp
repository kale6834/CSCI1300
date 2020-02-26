#include <iostream>
#include <fstream>
#include <string>
using namespace std;


 int Split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length() && count < size; i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } 
        else 
        {
            word = word + str[i];
        }
    }
    return count ;
 }
 
 
double maxTemp (string fileTemps)
{
    ifstream myfile;
    myfile.open(fileTemps);
    string Placeholder[7];
    int TempCounter = 0;
    string daysofweek[7];
    double temps[7];
    string line;
    if (myfile.fail())
    {
        return -1;
    }
    else
    {
        
        while (getline(myfile, line))
        {
            if (line != "")
            {
                Split (line, ',', Placeholder, 7);
                daysofweek[TempCounter] = Placeholder[0];
                temps[TempCounter] = stod(Placeholder[1]);
                TempCounter++;
            }
        }
        double max = temps[0];
        for (int i = 1; i < TempCounter; i++)
        {
            if (temps[i] > max)
            {
                max = temps[i];
            }
        }
        return max;
    }
    
}

int main ()
{
    cout << maxTemp("temps.txt") << endl;
}