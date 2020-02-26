#include <iostream>
#include <math.h>
using namespace std;

void sphereVolume (float radius){
    float volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
}
    

int main(){
    cout << "Enter a radius: " << endl;
    float radius;
    cin >> radius;
    sphereVolume (radius);
    
    //your code goes here
   
}
