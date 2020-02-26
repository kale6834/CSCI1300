#include <iostream>
#include <string>
using namespace std;

string GolfName (int strokes)
{
    string a;
    switch (strokes)
    {
        case -2 :
            a = "EAGLE";
            break;
        case -1 :
            a = "BIRDIE";
            break;
        case 0 :
            a = "PAR";
            break;
        case 1 :
            a = "BOGIE";
            break;
        case 2 :
            a = "DOUBLE BOGIE";
            break;
        case 3 :
            a = "TRIPLE BOGIE";
            break;
        default :
            a = "NO COMMENT";
    }
    return a;
}

int main ()
{
    GolfName (2);
    GolfName (-2);
    GolfName (4);
}