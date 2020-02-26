#include <iostream>
using namespace std;

float PaintHouse (float width, float depth, float DoorsWindows)
{
    float cost;
    if (width >= 0 && depth >= 0 && DoorsWindows >= 0)
    {
        float parameter = 2 * (width + depth);
        if (parameter >= 0 && parameter <= 100)
        {
            cost = (8 * parameter) + (6.75 * DoorsWindows);
            return cost;
        }
        else if (parameter > 100 && parameter <= 200)
        {
            cost = 800 + 10 * (parameter - 100) + (6.75 * DoorsWindows);
            return cost;
        }
        else if (parameter > 200)
        {
            cost = 1800 + 15 * (parameter - 200) + (6.75 * DoorsWindows);
            return cost;
        }
    }
    else 
    {
        return -1;
    }
}

int main ()
{
    PaintHouse (15, 25, 8);
}