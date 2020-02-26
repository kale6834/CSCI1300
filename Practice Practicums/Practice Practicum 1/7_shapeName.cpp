#include <iostream>
#include <string>
using namespace std;

string shapeName (int surfaces)
{
    string a;
    switch (surfaces)
    {
        case 2 :
            a = "CONE";
            break;
        case 3 :
            a = "CYLINDER";
            break;
        case 4 :
            a = "TRIANGULARPYRAMID";
            break;
        case 6 :
            a = "CUBOID";
            break;
        default :
            a = "UNKNOWN";
    }
    return a;
}