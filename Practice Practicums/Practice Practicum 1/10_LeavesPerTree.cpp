#include <iostream>
using namespace std;

void LeavesPerTree (double leaves)
{
    leaves = (leaves / 1031) / 0.001;
    if (leaves < 10000)
    {
        cout << leaves << endl;
    }
    else
    {
        cout << leaves << endl << "More leaves than last year" << endl;
    }
}