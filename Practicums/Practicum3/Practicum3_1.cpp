#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printNormalHeartRates (string patientNames[], int HR[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (HR[i] >= 70 && HR[i] <= 190)
        {
            cout << patientNames [i] << " " << HR[i] << endl;
        }
    }
}

int main ()
{
    string patientNames["Joe", "Jack", "Amy", "Bob"];
    int HR[90, 60, 200, 100];
    printNormalHeartRates(patientNames, HR, 4);
}