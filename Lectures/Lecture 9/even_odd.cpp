#include <iostream>
using namespace std;

void isNumberEven(int num) 
{
    int result = num%2;
    if (result == 0) 
    {
        cout << "Number is even.";
    } 
    else 
    {
        cout << "Number is odd.";
    }
}

main() {
    int number;
    cout << "Please enter a number:";
    cin >> number;
    
    // how do we test
}
