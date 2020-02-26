#include <iostream>
using namespace std;

double calculateCost (double distance, double avgSpeed, double gasPrice)
{
    int mpg;
    if (avgSpeed > 62)
    {
        double tripCost = (distance / 26) * gasPrice;
        return tripCost;
    }
    if (avgSpeed <= 62)
    {
        double tripCost = (distance / 30) * gasPrice;
        return tripCost;
    }
}

int main ()
{
    cout << calculateCost (600, 60, 2.5) << endl;
    cout << calculateCost (520, 65, 2.2) << endl;
}