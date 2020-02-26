#include <iostream>
#include <math.h>
using namespace std;

void sphereSurfaceArea (float radius){
    float surfacearea = (4.0) * M_PI * pow(radius, 2);
    cout << "surface area: " << surfacearea << endl;
    
}
int main(){
    cout << "Enter a radius: " << endl;
    float radius;
    cin >> radius;
    sphereSurfaceArea (radius);
    
    //your code goes here
   
}
