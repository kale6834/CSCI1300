//header ==> function declarations
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef Book_H
#define Book_H

class Book
{
    public:
    //default constructor
    //sets the member variables to their null states
    Book();
    
    //overload constructor
    //different way of calling the same function
    
    Book(string, string);
    
    string getTitle(); //returns title as a string
    
    void setTitle (string); //assigns title the value of the input string
    
    string getAuthor (); //returns author as a string
    
    void setAuthor (string); //assigns author the value of the input string

    private:
    //member variables
    //these are private because you don't want them to be changed anywhere else
    string title;
    string author;
};

#endif