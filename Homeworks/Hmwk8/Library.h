#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
using namespace std;



#ifndef LIBRARY_H
#define LIBRARY_H


#include "Book.h"
#include "User.h"

class Library
{
    public:
    //default constructor
    Library(); //sets both numBooks and numUsers value to 0
    
    int readBooks (string); //populates the book array. returns total number of books in the array as an int
    
    int readRatings (string); //takes a file and populates the user array. returns number of users in the array as an int
    
    void printAllBooks (); //prints all books stored in books array
    
    int getCountReadBooks (string); //returns number of books read by user
    
    double calcAvgRating (string); //returns average rating of a specified book as a double
    
    bool addUser (string); //returns true if username was added to the database and false otherwise
    
    bool checkOutBook (string, string, int); //returns true if rating is updated otherwise returns false
    
    void viewRatings (string); //prints all books a user has provided ratings for
    
    void getRecommendations (string); //prints the first 5 book recommendations from the most similar user
    
    void setNumBooks(int);
    
    
    // int getNumBooks();
    
    void setNumUsers(int n);
    
    // int getNumUsers();
    
    private:
    Book books[200];
    User users[200];
    int numBooks;
    int numUsers;
    const int sizeBook = 200;
    const int sizeUser = 200;
    int userIndex;
    int bookIndex;
    int num_Ratings;
};

#endif