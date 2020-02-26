#include <iostream>
#include <iomanip>
using namespace std;

void calculator (double n1, double n2, char operation)
{
    double answer;
    switch (n1, n2, operation)
    {
        case '+' :
            cout << n1 << " + " << n2 << " = " << n1 + n2;
            break;
        
        case '-' :
            cout << n1 << " - " << n2 << " = " << n1 - n2;
            break;
        case '*' :
            cout << n1 << " * " << n2 << " = " << n1 * n2;
            break;
        case '/' :
            cout << n1 << " / " << n2 << " = " << setprecision (2) << fixed << n1 / n2;
            break;
        default :
            cout << "Invalid operator!" << endl;
    }
}