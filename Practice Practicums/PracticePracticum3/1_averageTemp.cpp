#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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

float averageTemp (string fileTemps)
{
    ifstream myfile;
    myfile.open(fileTemps);
    //ofstream out;
    //out.open("file2.txt");
    float AvgTemp = 0;
    if (myfile.fail())
    {
        return -1;
    }
    else
    {
        string Placeholder[2];
        string line = "";
        while (getline(myfile, line))
        {
            if (line != "")
            {
                Split(line, ',', Placeholder, 2);
                AvgTemp = AvgTemp + stof(Placeholder[1]);
            }
        }
        AvgTemp = AvgTemp / 7;
        return AvgTemp;
    }
    in.close();
}

int main ()
{   
    string fileTemps = "temps.txt";
    cout << fixed << setprecision(2) << averageTemp(fileTemps);
}
