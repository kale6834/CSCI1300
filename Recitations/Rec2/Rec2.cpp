#include <iostream>
using namespace std;

void sumAndPrint (int x, int y){
    
    int z = x + y;
    
    cout<<"Sum is "<<z<<endl;
}

int main (){
    int a = 10;
    int b = 12;
    
    int c = a + b;
    
    sumAndPrint(a, b);
    
    cout<<"Sum is "<<c<<endl;
}