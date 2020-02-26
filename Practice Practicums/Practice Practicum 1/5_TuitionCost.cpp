#include <iostream>
using namespace std;

double TuitionCost (int unit, double unitcost)
{
    double cost;
    if (unit <= 16 && unit >= 0 && unitcost >= 0)
    {
        cost = unit * unitcost;
        return cost;
    }
    else if (unit > 16 && unitcost >= 0)
    {
        cost = (16 * unitcost) + (unit - 16) * (unitcost * 1/2);
        return cost;
    }
    else if (unit < 0 || unitcost < 0)
    {
        return -1;
    }
}

int main ()
{
    cout << TuitionCost (16, 200) << endl;
    cout << TuitionCost (15, -500) << endl;
}