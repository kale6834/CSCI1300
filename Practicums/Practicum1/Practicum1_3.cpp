#include <iostream>
using namespace std;

void gameMenu (int num)
{
    switch (num)
    {
        case 1 :
            cout << "Choice 1: Play Game" << endl;
            break;
        case 2 :
            cout << "Choice 2: View Stats" << endl;
            break;
        case 3 :
            cout << "Choice 3: Save Game" << endl;
            break;
        case 4 :
            cout << "Choice 4: Exit Game" << endl;
            break;
        default :
            cout << "Choice 0: Invalid" << endl;
    }
}

int main ()
{
    gameMenu (5);
    gameMenu (14);
}