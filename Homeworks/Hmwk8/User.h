

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifndef User_H
#define User_H

class User
{
    public:
    //default constructor
    User();
    
    //overload constructor
    User(string, int[], int);
    
    string getUsername (); //returns username
    
    void setUsername (string); //assigns the username the value of the input string
    
    int getRatingAt (int); //returns the rating stored at the specified index
    
    bool setRatingAt (int, int);
    
    int getNumRatings(); //returns numRatings
    
    void setNumRatings(int); //assigns numRatings the value of the input int
    
    int getSize (); //returns size
    
    private:
    string user;
    int Ratings[200];
    int numRatings; //number of books the user has reviewed
    const int size = 200; //the capacity of the ratings array as a constant (200)
};

#endif