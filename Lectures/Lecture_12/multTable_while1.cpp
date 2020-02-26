#include <iostream>
using namespace std;

int main()
{
    // write a multiplication table for 5
    /* Output:
    5 10 15 20 25 30 35 ... 50
    */
    
    //Option 1: addition/accumulation
    // int i = 5;
    // int out = 0;
    // while (out < 50)
    // {
    //     out = out + 5;
    //     cout << out << " ";
    // }
    
    // return 0;
    
    //Option 2: multiplication
    const int i = 5;
    int j = 1;
    while (j < 11)
    {
        cout << i * j << " ";
        j++;//one variable needs to change
    }
    return 0;
}
