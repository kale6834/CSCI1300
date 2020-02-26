#include <iostream>
#include <string>
using namespace std;

// how many As, Bs and Cs combined are in a given string
int CountABC(string x);
int main()
{
    string str = "ABCAAA";
    cout << CountABC(str) << endl;
    
    return 0;
}

int CountABC(string x)
{
    if (x.length() == 0) {
        return -1;
    }
    int count = 0;
    
    for(int i=0; i < x.length();i++)
    {
        //if (x[i] == 'A' || x[i] == 'B' || x[i] == 'C')
        if (x[i] >= 'A' && x[i] <='C')
        {
            count++;
        }
    }
    return count;
}