#include <iostream>
#include <string>
using namespace std;

string DayOfWeek (int day)
{
    string a;
    switch (day)
    {
        case 1 :
            a = "MONDAY";
            break;
        case 2 : case 3 : case 4 :
            a = "WORKDAY";
            break;
        case 5 :
            a = "FUNDAY";
            break;
        case 6 : case 0 :
            a = "SLEEPDAY";
            break;
        default :
            a = "INVALID";
    }
    return a;
}