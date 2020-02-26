#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int calcCost (string fileName)
{
    ifstream myfile;
    myfile.open(fileName);
    if (myfile.fail())
    {
        return -1;
    }
    else
    {
        string line;
        string productName[100];
        double quantity[100];
        double costPerItem[100];
        int i = 0;
        double costOfProducts = 0;
        double total = 0;
        while (getline(myfile, line))
        {
            if (line != "")
            {
                string array[100];
                Split(line, ',', array, 100);
                productName[i] = array[0];
                quantity[i] = stod(array[1]);
                costPerItem[i] = stod(array[2]);
                costOfProducts = quantity[i] * costPerItem[i];
                cout << productName[i] << ": " << costOfProducts << endl;
                total = total + costOfProducts;
                i++;
            }
            
        }
        cout << "Total: " << total << endl;
        return i;
    }
}