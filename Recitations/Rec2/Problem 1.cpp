#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl;
    float radius;
    cin >> radius;
    float volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    float surfacearea;
    surfacearea = (4.0) * M_PI * pow(radius, 2);
    cout << "volume: " << volume << endl;
    cout << "surfacearea: " << surfacearea << endl;
    
    //your code goes here
   
}
