// CSCI1300 Fall 2018
// Author: Kalei Lewis
// Recitation: 102 - Paramjot Singh
// Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
// hmwk7

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Book.h"
#include "User.h"

int split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }
 
int readBooks (string fileBooks, Book allBooks[], int numBooks, int LibraryCapacity = 200)
{
    //we are going to read the file
    ifstream myfile;
    //open the file that is going to be inputed
    myfile.open(fileBooks);
    //if the file failed to open
    
    if (myfile.fail())
    {
        return -1; //return 1
    }
    //the line is going to be an empty string
    string line = "";
    //i have a temporary placeholder array as a string
    string Placeholder[200];
    //book counter is started at 0
    int BookCounter = numBooks;
    string bookname[200];
    string authorname[200];
    
    //while we are getting the line from my file to the end of the line
    while (getline(myfile, line))
    {
        //call the split function and split the line when there is a comma
        //the split lines will go into the placeholder array with a length of 50
        split(line, ',', Placeholder, 200);
        //the first array will be the book titles, and they will be at index 1 since they come after the ','
        allBooks[BookCounter].setTitle(Placeholder [1]);
        //the second array will be the book authors, and they will be at index 0 since they are at the beginning of the line
        allBooks[BookCounter].setAuthor(Placeholder [0]);
        
        // allBooks[BookCounter] = book1;
        //bookcounter is increased each time
        BookCounter++;  
    }
    return BookCounter;

}
//////////////////////////////////////////////////////////////////////////


/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: string, the name of the file to be read
 * @param: string array, usernames
 * @param: 2D int array, list of ratings for each user (first index specifies user)
 * @param: int, the number of users currently stored in the array
 * @param: int, row capacity of the 2D array (convention: array[row][column]) [assume to be 100]
 * @param: int, column capacity of the 2D array [assume to be 50]
 * @return: the number of users in total
 */

 //////////////////////////////////////////////////////////////////////////
 // 
 /**
  * Algorithm:
  * 1. check to see if file is open
  * 2. if file is not open, return -1
  * 3. if file is open, continue with function
  * 4. split users and ratings into a 2d array
  * 5. print out the users as they are added to the array
  */
  
 //first index of UserRatings[][] specifies usernames
 int readRatings (string fileRatings, User username[], int numUsers, int userCapacity = 200)
{
    //we are going to read the file
    ifstream myfile;
    //open the file that is inputed
    myfile.open(fileRatings);
    //if the file fails to open, return -1
    if (myfile.fail())
    {
        return -1;
    }
    //this will be the variable that will go into the row of the array, for the usernames
    int UserCounter = numUsers;
    //an extra variable to call the split functions
    int num_Ratings = 0;
    //this is the array that the users are going to go into
    string Blocks [200];
    //create an empty string
    string line = "";
    //the user's ratings are going to go into this array
    string userRatings[200];
    //while we are reading from the beginning of the line to the end of the line
    while (getline(myfile,line))
    {
        // User user1; //create an object from that class
        // user1();
        
      //usernames separated from ratings by a comma
      split(line, ',', Blocks, 200);
      //set username, which will go into the blocks array at index 0
      username[UserCounter].setUsername(Blocks [0]);
      //parse ratings and split the numbers in index 1 into the ratings array
      num_Ratings = split(Blocks[1], ' ', userRatings, 200);
      
      //print out the usernames as they are added to the system
      cout << username[UserCounter].getUsername() << "..." << endl;
      for (int kk = 0; kk < num_Ratings; kk++)
      {
          //kk is the column capacity, equal to 50, which is the number of books in the system
          //the stoi function will change that variable into an integer
        username[UserCounter].setRatingAt(kk, stoi(userRatings[kk]));
      }
      //usercounter is increased at the end of the for loop in order to get the correct number of users
      UserCounter++;
    }
    return UserCounter;
     
 }
 //////////////////////////////////////////////////////////////////////////


 //////////////////////////////////////////////////////////////////////////
 //
 /**
  * Algorithm:
  * 1. if book is not found, print out no books are stored
  * 2. if book is found, print out a list of books
  */
  
 void printAllBooks (Book allBooks[], int numBooks)
 {
     //if the wrong text file was inputed or if the file was never entered
     if (numBooks == -1 || numBooks == 0)
     {
         cout << "No books are stored" << endl;
     }
     else
     {
         cout << "Here is a list of books" << endl;
         //create a for loop to output the books
         for (int i = 0; i < numBooks; i++)
         {
             cout << allBooks[i].getTitle() << " by " << allBooks[i].getAuthor() << endl;
         }
     }
 }
 
 /**
  * Algorithm:
  * 1. go through usersnames
  * 2. if username is found, find how many books they've read
  * 3. if their ratings are greater than 0, add that to number of books read
  */
  
//  int ReadCountHelperFunction (string UserNames[], int numUsers, string username)
//  {
//      //this userindex had to be set at -1 in order to make everything work
//      int userIndex = -1;
//      //booksread will be started at 0
//      int booksRead = 0;
//      //find the user
//      for (int i = 0; i < numUsers; i++)
//      {
//          //as long as the input username is equal to the usernames in the database
//          if (username == UserNames[i])
//          {
//              //userindex equals the username
//              userIndex = i;
//          }
//      }
//      //if username is not equal to the usernames in the database
//      if (userIndex == -1)
//      {
//         cout << username << " does not exist in the database" << endl;
//      }
//      else
//      {
//         return userIndex;
 
//      } 
// }
 
//  /**
//   * Algorithm:
//   * 1. if the books or ratings files haven't been read, say the user wasn't found in the database
//   * 2. if the files were read, find the number of books the users read
//   */
  
//  int getUserReadCount (string username, string UserNames[], int UserRatings [][50], int numUsers, int numBooks)
//  {
//      //number of books will be started at 0
//      int NumberOfReadBooks = 0;
//      //the userindex will be equal to the value of the help function
//      //the helper function is also called right here
//      int userIndex = ReadCountHelperFunction(UserNames, numUsers, username);
//      //if the books or ratings files haven't been read
//      if (numBooks == 0 && numUsers == 0)
//      {
//         cout << username << " does not exist in the database" << endl;
//         return -1;
//      }
//      else //if the files have been read
//      {
//          //search through the number of books
//          for (int i = 0; i < numBooks; i++)
//          {
//              //the userindex will be in the row of the 2d array
//              //this will be the name of the user
//              //i is the index in the number of ratings
//              if(UserRatings[userIndex][i] != 0)//if the user ratings are not equal to zero
//              {
//                  NumberOfReadBooks++;//increase the number of read books
//              }
//          }
//      }
//      //if the number of read books is equal to or greater than zero, & if the files have been read
//      if (NumberOfReadBooks >= 0 && (numBooks > 0 || numUsers > 0))
//      {
//          cout << username << " rated " << NumberOfReadBooks << " books" << endl;
//      }
//      return NumberOfReadBooks;
//  }
 
//  /**
//   * Algorithm: 
//   * 1. look through the book index
//   * 2. if the entered book is equal to a book in the index, then that is the bookindex
//   */
  
// int AvgRatingHelper (string bookTitles[], string BookTitleAvgRating, int numBooks)
// {
//     //bookindex is equal to 0
//     int bookIndex = 0;
//     //search through the books
//     for (int i = 0; i < numBooks; i++)
//     {
//         //if the entered book is equal to the books in the database
//         if (BookTitleAvgRating == bookTitles[i])
//         {
//             //the entered book is equal to the bookindex
//             bookIndex = i;
//         }
//     }
//     //return to where the function was called
//     return bookIndex;
// }
 
//  /**
//   * Algorithm:
//   * 1. find out if the book entered is the same as the book in the database
//   * 2. if files haven't been read or book can't be found, cout it doesn't exist in the database
//   * 3. if the files have been read and the book can be found, find the number of ratings
//   */
  
//  double calcAvgRating (string BookTitleAvgRating, string bookTitles[], int UserRatings[][50], int numUsers, int numBooks)
//  {
//      //number of ratings will be equal to 0
//      int numRatings = 0;
//      //the bookindex is equal to what the helper function is
//      int bookIndex = AvgRatingHelper(bookTitles, BookTitleAvgRating, numBooks);
//      //the average rating is going to be a double
//      double AvgRating = 0.00;
//      //if the books or ratings file hasn't been read and the book can't be found in the database
//      if ((numBooks == 0 && numUsers == 0) || bookIndex == 0)
//      {
//          cout << BookTitleAvgRating << " does not exist in our database" << endl;
//          return 0;
//      }
//      else
//      {
//          //for loop to look through the users
//          for (int i = 0; i < numUsers; i++)
//          { 
//              //if the users ratings are not equal to 0
//              if (UserRatings[i][bookIndex] != 0)
//              {
//                  //the rating will be equal to the user ratings + the rating in the previous run
//                  AvgRating = AvgRating + UserRatings[i][bookIndex];
//                  //number of ratings will be increased each time the loop runs
//                  numRatings++;
//              }
//          }
//          //the average ratings will be equal to the rating found in the for loop and divided by the number of ratings
//          AvgRating = AvgRating / numRatings;
//          //the ratings of the book will be to the second decimal, so we should set the setprecision to 2
//          cout << "The average rating for " << BookTitleAvgRating << " is " << setprecision(2) << fixed << AvgRating << endl;
//      }
//      return AvgRating;
//  }

void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}


int main(int argc, char const *argv[]) {
    string choice;
    int numBooks = 0;
    int numUsers = 0;
    int Ratings[50];
    int numRatings;
    Book allBooks[200];
    User username[200];
    string fileBooks;
    string fileRatings;
    int LibraryCapacity;
    int userCapacity;
    string bookname[200];
    string authorname[200];
    
    //my object from the book class
    //Book;
    
    //my object from the user class
    //User;

    while (choice != "6") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    //get line to read from the input to the end of the books file
                    getline(cin, fileBooks);
                    //the number of books will be equal to what the function set it to
                    numBooks = readBooks (fileBooks, allBooks, numBooks, LibraryCapacity);
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << "Total books in the database: " << numBooks << endl;
                    cout << endl;
                    break;

                case 2:
                    // read user file
                    cout << "Enter a rating file name:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    getline (cin, fileRatings);
                    //the numusers will be equal to the value the readratings function gave it
                    numUsers = readRatings(fileRatings, username, numUsers, userCapacity);
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << "Total users in the database: " << numUsers << endl;
                    cout << endl;
                    break;

                case 3:
                    // print the list of the books
                    
                    //////////////////////////////////////////////////////////////////////////
                    printAllBooks(allBooks, numBooks);
                    //////////////////////////////////////////////////////////////////////////
                    cout << endl;
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    // Your code here. Call the appropriate function(s).
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    // Your code here. Call the appropriate function(s).
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    break;
                case 6:
                    // quit
                    cout << "good bye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl << endl;
            }
    }

    return 0;
}