#include <iostream>
using namespace std;

// AM or PM?
void isAM_PM(int myHour);

int main() 
{
    int hour;
    cout << "Please enter the current hour:";
    cin >> hour;
    
    isAM_PM(hour);  // function call
    
    return 0;
}

void isAM_PM(int myHour)
{
    if (myHour >= 0 && myHour < 12){
        cout << "AM";
    }
    if (myHour >= 12 && myHour <= 24){
        cout << "PM";
    }
}