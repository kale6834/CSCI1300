#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// int writeCountryDensity(string fileIn, int maxDensity, string fileOut)
// {
//     ifstream in;
//     in.open(fileIn);
//     ofstream out;
//     out.open (fileOut);
//     string line;
//     string country, population, area;
//     int populationcounter = 0;
//     double density = 0;
//     if (in.fail())
//     {
//         return -1;
//     }
//     else
//     {
//         while (getline(in, country, ','))
//         {
//             getline(in, population, ',');
//             getline(in, area);
//             density = stod(population) / stod(area);
//             if(density <= maxDensity)
//             {
//                 out << country << ", " << density << endl;
//                 populationcounter++;
//             }
            
//         }
//         return populationcounter;
//     }
// }

int writeCountryDensity(string fileIn, int maxDensity, string fileOut)
{
    ifstream in;
    in.open(fileIn);
    ofstream out;
    out.open(fileOut);
    if (in.fail())
    {
        return -1;
    }
    else
    {
        string line = "";
        int i = 0;
        string country[2000];
        double population;
        double area;
        double num;
        while (getline(in, line))
        {
            if (line != "")
            {
                string array[3];
                split (line, ',', array, 3);
                country[i] = array[0];
                area = stof(array[1]);
                population = stof(array[2]);
                num = area / population;
                if (num <= maxDensity)
                {
                    out << country[i] << ", " << num << endl;
                    i++;
                }
            }
        }
        return i;
    }
}

int main ()
{
    int n = writeCountryDensity("countryDensity.txt", 70, "out.txt");     
    cout << "Function returned: " << n << endl;
}