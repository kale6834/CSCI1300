#include <iostream>
using namespace std;

string mileage (int flightDistance)
{
    string a;
    if (flightDistance >= 0 && flightDistance <= 10000)
    {
        a = "Bronze";
    }
    else if (flightDistance >10000 && flightDistance <= 15000)
    {
        a = "Silver";
    }
    else if (flightDistance > 15000 && flightDistance <= 30000)
    {
        a = "Gold";
    }
    else if (flightDistance > 30000)
    {
        a = "Platinum";
    }
    else 
    {
        a = "INVALID";
    }
    return a;
}

int main ()
{
    cout << mileage (30000) << endl;
    cout << mileage (-9) << endl;
}