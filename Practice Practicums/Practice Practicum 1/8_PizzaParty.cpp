#include <iostream>
using namespace std;

double PizzaParty (int numberOfPizzas, double costPerPizza, double discount)
{
    double cost;
    if (numberOfPizzas < 10)
    {
        cost = (numberOfPizzas * costPerPizza) + 10;
    }
    else if (numberOfPizzas >= 10)
    {
        cost = (numberOfPizzas * (costPerPizza - (discount * costPerPizza)));
    }
    return cost;
}