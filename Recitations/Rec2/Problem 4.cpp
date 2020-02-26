#include <iostream>
#include <math.h>
using namespace std;

void classGreeting (int course){
    cout << "Hello, CS " << course << " World!" << endl;
}

int main(){
    cout << "Enter a CS course number " << endl;
    int course;
    cin >> course;
    classGreeting (course);
    
    //your code goes here
   
}
