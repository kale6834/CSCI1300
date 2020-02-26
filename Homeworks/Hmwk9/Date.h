#include <iostream>
#include <string>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
    public:
    
    Date();
    
    void setMonth(int); //sets the month
    
    int getMonth(); //returns the month
    
    void setDay(int); //sets the day
    
    int getDay(); //returns the day
    
    private:
    int numMonth;
    int numDay;
    int numYear = 1847; //numYear is a constant
    int daysInMonth = 0;
};

#endif