#include "User.h"

User::User()
{
    user = "";
    numRatings = 0;
    for (int i = 0; i < size; i++)
    {
        Ratings[i] = -1;
    }
}

//overload constructor
User::User(string username, int arrayRatings[], int rate)
{
    user = username;
    numRatings = rate;
    for (int i = 0; i < rate; i++)
    {
        Ratings[i] = arrayRatings[i];
    }
    for (int i = rate; i < size; i++)
    {
        Ratings[i] = -1;
    }
    
    //call the default constructor before parameterized constructor
}

string User::getUsername()
{
    return user;
}

void User::setUsername(string input)
{
    user = input;
}

int User::getRatingAt(int index)
{
    if (index >= size)
    {
        return -1;
    }
    else
    {
        return Ratings[index];
    }
}

bool User::setRatingAt(int index, int value)
{
    bool updated = false;
    if ((index >= 0 && index <= size) && (value >= 0 && value <= 5))
    {
        Ratings[index] = value;
        updated = true;
    }
    return updated;
}

int User::getNumRatings()
{
    return numRatings;
}

void User::setNumRatings(int input)
{
    numRatings = input;
}

int User::getSize()
{
    return size;
}