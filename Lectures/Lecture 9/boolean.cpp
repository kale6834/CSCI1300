#include <iostream>
using namespace std;

int main() 
{
    bool x, y;
    int a, b, c;
    
    a = 0;
    b = 15;
    c = 7;
    
    x = 0 <= b < 12;
    
    char answer = 'n';
    
    if ((answer == 'Y') || (answer == 'y')){ //every value that doesn't evaluates to 0 is true if not written like this
        cout << "ok";
    }
    else{
        cout << "bye";
    }
    cout << x << endl;
   
}