#include "Date.h"

Date::Date()
{
    numMonth = 3; //this is the first month that the party can travel
    numDay = 28; //this is the first day of month 3 that the party can travel
}

void Date::setMonth(int input)
{
    numMonth = input;
    if (numMonth >= 3 && numMonth <= 5 && (numMonth % 2 != 0)) //if the month is 3, 4, or 5 and is not even
    {
        daysInMonth = 31; //number of days = 31
    }
    else if ((numMonth % 2 == 0) && numMonth >= 5 && numMonth <= 9) //if the month is 5, 6, 7, or 9 and is even
    {
        daysInMonth = 31; //number of days = 31
    }
    else
    {
        daysInMonth = 30; //if the other conditions aren't met, then the number of days are 30
    }
}


int Date::getMonth()
{
    return numMonth;
}

void Date::setDay(int input)
{
    numDay = input;
    if (numMonth == 3 || numMonth == 5 || numMonth == 7 || numMonth == 8) //if the month is 3, 5, 7, or 8
    {
        daysInMonth = 31; //number of days = 31
        if (numDay > 31) //if number of days is more than 31
        {
            numMonth++; //the month will need to be increased
            setMonth(numMonth); //set the month
            numDay = 1; //the day of the month will start over at 1
        }
    }
    else if (numMonth == 4 || numMonth == 6 || numMonth == 9) //if the month is 4, 6, or 9
    {
        daysInMonth = 30; //days in month is 30
        if (numDay > 30) //if the number of days goes over 30
        {
            numMonth++; //increase the month number
            setMonth(numMonth); //set the month
            numDay = 1; //the day number will start over at 1
        }
    }
}

int Date::getDay()
{
    return numDay;
}