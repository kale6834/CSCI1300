// CSCI1300 Fall 2018
// Author: <Your name>
// Recitation: <123> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk8 / Project2


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Book.h"
#include "User.h"
#include "Library.h"

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
 void displayMenu(){
     cout << "Select a numerical option:" << endl;
     cout << "======Main Menu=====" << endl;
     cout << "1. Read book file" << endl;
     cout << "2. Read user file" << endl;
     cout << "3. Print book list" << endl;
     cout << "4. Find number of books user rated" << endl;
     cout << "5. Get average rating" << endl;
     cout << "6. Add a User" << endl;
     cout << "7. Checkout a book" << endl;
     cout << "8. View Ratings" << endl;
     cout << "9. Get Recommendations" << endl;
     cout << "10. Quit" << endl;
 }



int main(int argc, char const *argv[])
{
  string choice;
    int num_Ratings = 0;
    int numBooks = 0;
    int numUsers = 0;
    int userIndex;
    int bookIndex;
    Book allBooks[200];
    User users[200];
    Library library;
    string fileBooks, fileRatings, username, newRatingValue, bookTitle;
    string bookname[200];
    string authorname[200];
    bool added;
    bool checkout;
    
    Library();
    while (choice != "10") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    
                    //get line to read from the input to the end of the books file
                    getline(cin, fileBooks);
                    // fileBooks = "books.txt";
                    //the number of books will be equal to what the function set it to
                    numBooks = library.readBooks (fileBooks);
                    
                    if (numBooks == -1)
                    {
                        cout << "No books saved to the database" << endl << endl;
                    }
                    //if the right file was entered and the readbooks function ran properly
                    else
                    {
                        cout << "Total books in the database: " << numBooks << endl;
                        cout << endl;
                    }
                        break;

                case 2:
                    // read user file
                    cout << "Enter a rating file name:" << endl;

                    getline (cin, fileRatings);
                    // fileRatings = "ratings.txt";
                    //the numusers will be equal to the value the readratings function gave it
                    numUsers = library.readRatings(fileRatings);
                    
                    if (numUsers == -1)
                    {
                        cout << "No users saved to database" << endl << endl;
                    }
                    //if the file was read and the function ran properly
                    else
                    {
                        cout << "Total users in the database: " << numUsers << endl;
                        cout << endl;
                    }
                    break;

                case 3:
                    // print the list of the books
                    
                    library.printAllBooks();
                    cout << endl;
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    
                    getline(cin, username);
                    library.getCountReadBooks(username);
                    cout << endl;
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;

                    getline (cin, bookTitle);
                    library.calcAvgRating(bookTitle);
                    
                    cout << endl;
                    break;
                    
                case 6:
                    //add user
                    cout << "Enter username: " << endl;
                    
                    getline (cin, username);
                    added = library.addUser (username);
                    
                    if (added == true)
                    {
                        cout << "Welcome to the library " << username << endl;
                    }
                    if (added == false)
                    {
                        cout << username << " could not be added in the database" << endl;
                    }
                    cout << endl;
                    break;
                    
                case 7:
                    //check out book
                    cout << "Enter username: " << endl;
                    getline (cin, username);
                    
                    cout << "Enter book title: " << endl;
                    getline (cin, bookTitle);
                    
                    cout << "Enter rating for the book: " << endl;
                    getline (cin, newRatingValue);
                    checkout = library.checkOutBook(username, bookTitle, stoi(newRatingValue));
                    
                    if (checkout == false)
                    {
                        cout << username << " could not check out " << bookTitle << endl;
                    }
                    if (checkout == true)
                    {
                        cout << "We hope you enjoyed your book. The rating has been updated" << endl;
                    }
                    cout << endl;
                    break;
                    
                case 8:
                    //view a user's rating
                    cout << "Enter username: " << endl;
                    getline(cin, username);
                    library.viewRatings(username);
                    
                    cout << endl;
                    break;
                    
                case 9:
                    //get recommendations between users
                    cout << "Enter username: " << endl;
                    getline(cin, username);
                    library.getRecommendations(username);
                    
                    cout << endl;
                    break;
                    
                case 10:
                    // quit
                    cout << "good bye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl << endl;
            }
    }

	return 0;
}