#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cmath>
using namespace std;

//book header
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

//book.cpp

//default constructor
//scope resolution
//allows us to see all of the information that is in the class
Book::Book()
{
    title = "";
    author = "";
}

string Book::getTitle()
{
    return title;
}

void Book::setTitle(string bookname)
{
    title = bookname;
}

string Book::getAuthor()
{
    return author;
}

void Book::setAuthor(string authorname)
{
    author = authorname;
}


//overload constructor
Book::Book(string bookname, string authorname)
{
    title = bookname;
    author = authorname;
}

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


class Library
{
    public:
    //default constructor
    Library(); //sets both numBooks and numUsers value to 0
    
    int readBooks (string); //populates the book array. returns total number of books in the array as an int
    
    int readRatings (string); //takes a file and populates the user array. returns number of users in the array as an int
    
    void printAllBooks (); //prints all books stored in books array
    
    // int ReadCountHelperFunction(users, int, string);
    
    int getCountReadBooks (string); //returns number of books read by user
    
    // int AvgRatingHelper(books, string, int);
    
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

Library::Library ()
{
    numBooks = 0;
    numUsers = 0;
}

void Library::setNumBooks(int n)
{
    numBooks = n;
}

// int Library::getNumBooks()
// {
//     return numBooks;
// }

void Library::setNumUsers(int n)
{
    numUsers = n;
}

// int Library::getNumUsers();
// {
//     return numUsers;
// }

int split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length() && count < size; i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } 
        else 
        {
            word = word + str[i];
        }
    }
    return count ;
 }
 
int Library::readBooks (string fileBooks)
{
    ifstream myfile; //we are going to read the file
    myfile.open(fileBooks); //open the file that is going to be inputed
    
    if (myfile.fail()) //if the file failed to open
    {
        return -1; //return 1
    }
    string line = ""; //the line is going to be an empty string
    string Placeholder[200]; //i have a temporary placeholder array as a string
    int BookCounter = numBooks; //book counter is started at 0
    // if (BookCounter <= 200 && numBooks <= 200)
    // {
        while (numBooks < sizeBook && getline(myfile, line)) //while we are getting the line from my file to the end of the line
        {
            //call the split function and split the line when there is a comma
            //the split lines will go into the placeholder array with a length of 50
            split(line, ',', Placeholder, 200);
            //the first array will be the book titles, and they will be at index 1 since they come after the ','
            books[BookCounter].setTitle(Placeholder [1]);
            //the second array will be the book authors, and they will be at index 0 since they are at the beginning of the line
            books[BookCounter].setAuthor(Placeholder [0]);
            
            BookCounter++;  //bookcounter is increased each time
            numBooks = BookCounter;
            // if (numBooks > sizeBook)
            // {
            //     return BookCounter;
            // }
        }
    // }
    return BookCounter;
}

int Library::readRatings (string fileRatings)
{
    ifstream myfile; //we are going to read the file
    myfile.open(fileRatings); //open the file that is inputed
    if (myfile.fail()) //if the file fails to open, return -1
    {
        return -1;
    }
    int UserCounter = numUsers; //this will be the variable that will go into the row of the array, for the usernames
    int num_Ratings = 0; //an extra variable to call the split functions
    string Blocks [200]; //this is the array that the users are going to go into
    string line = ""; //create an empty string
    string userRatings[200]; //the user's ratings are going to go into this array
    while (numUsers < sizeUser && getline(myfile,line)) //while we are reading from the beginning of the line to the end of the line
    {
      split(line, ',', Blocks, 200); //usernames separated from ratings by a comma
      users[UserCounter].setUsername(Blocks [0]); //set username, which will go into the blocks array at index 0
      num_Ratings = split(Blocks[1], ' ', userRatings, 200); //parse ratings and split the numbers in index 1 into the ratings array
      
      cout << users[UserCounter].getUsername() << "..." << endl; //print out the usernames as they are added to the system
      for (int kk = 0; kk < num_Ratings; kk++)
      {
          //kk is the column capacity, equal to 50, which is the number of books in the system
          //the stoi function will change that variable into an integer
        users[UserCounter].setRatingAt(kk, stoi(userRatings[kk]));
      }
      UserCounter++; //usercounter is increased at the end of the for loop in order to get the correct number of users
      numUsers = UserCounter;
      if (numUsers > sizeUser)
      {
          return UserCounter; //if there are more users than the size of the array break
      }
    }
    return UserCounter;
}

void Library::printAllBooks()
{
     if (numBooks <= 0 || numBooks <= 0) //if the wrong text file was inputed or if the file was never entered
     {
         cout << "Database has not been fully initialized" << endl;
     }
     else
     {
         cout << "Here is a list of books" << endl;
         
         for (int i = 0; i < numBooks; i++) //create a for loop to output the books
         {
             cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
         }
     }
}

int ReadCountHelperFunction (User users[], int numUsers, string username)
{
    //this userindex had to be set at -1 in order to make everything work
    int userIndex = -1;
    //booksread will be started at 0
    int booksRead = 0;
    for (int i = 0; i < username.length(); i++)
    {
        username[i] = tolower(username[i]);
    }
    string t = username;
    //find the user
    for (int i = 0; i < numUsers; i++)
    {
        //as long as the input username is equal to the usernames in the database
        if (t == users[i].getUsername())
        {
            //userindex equals the username
            userIndex = i;
        }
    }
    //if username is not equal to the usernames in the database
    // if (userIndex == -1)
    // {
    //     cout << username << " does not exist in the database" << endl;
    //     return -2;
    // }
    return userIndex;
}

int Library::getCountReadBooks (string username)
{
    int i = 0;
    //number of books will be started at 0
    int NumberOfReadBooks = 0;
    //the userindex will be equal to the value of the help function
    //the helper function is also called right here
    
    int userIndex = ReadCountHelperFunction(users, numUsers, username);
    
    // cout<<"--"<<userIndex<<"--";
    //if the books or ratings files haven't been read
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;;
        return -1;
    }
    if (userIndex < 0)
    {
        cout << username << " does not exist in the database" << endl;
        return -2;
    }
    else //if the files have been read
    {
        //search through the number of books
        //the userindex will be in the row of the 2d array
        //this will be the name of the user
        for (int j = 0; j < numBooks; j++)
        {
            if(users[userIndex].getRatingAt(j) != 0)//if the user ratings are not equal to zero
            {
                NumberOfReadBooks++;//increase the number of read books
            }
        }
        users[userIndex].setNumRatings(NumberOfReadBooks);
    }
    //if the number of read books is equal to or greater than zero, & if the files have been read
    if (NumberOfReadBooks >= 0 && (numBooks > 0 && numUsers > 0))
    {
        // cout << NumberOfReadBooks;
        cout << username << " rated " << users[userIndex].getNumRatings() << " books" << endl;
        return NumberOfReadBooks;
    }
    
    return NumberOfReadBooks;
}

int AvgRatingHelper (Book books[], string bookTitle, int numBooks)
{
    //bookindex is equal to 0
    int bookIndex = 0;
    //search through the books
    for (int i = 0; i < numBooks; i++)
    {
        //if the entered book is equal to the books in the database
        if (bookTitle == books[i].getTitle())
        {
            //the entered book is equal to the bookindex
            bookIndex = i;
        }
    }
    //return to where the function was called
    return bookIndex;
}

double Library::calcAvgRating(string bookTitle)
{
    //number of ratings will be equal to 0
    int num_Ratings = 0;
    //the bookindex is equal to what the helper function is
    int bookIndex = AvgRatingHelper(books, bookTitle, numBooks);
    //the average rating is going to be a double
    double AvgRating = 0.00;
    //if the books or ratings file hasn't been read and the book can't be found in the database
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }
    if (bookIndex <= 0)
    {
        cout << bookTitle << " does not exist in the database" << endl;
        return -2;
    }
    else 
    {
        //for loop to look through the users
        for (int i = 0; i < numUsers; i++)
        { 
            //if the users ratings are not equal to 0
            if (users[i].getRatingAt(bookIndex) != 0)
            {
                //the rating will be equal to the user ratings + the rating in the previous run
                AvgRating = AvgRating + users[i].getRatingAt(bookIndex);
                //number of ratings will be increased each time the loop runs
                num_Ratings++;
            }
        }
        //the average ratings will be equal to the rating found in the for loop and divided by the number of ratings
        AvgRating = AvgRating / num_Ratings;
        //the ratings of the book will be to the second decimal, so we should set the setprecision to 2
        cout << "The average rating for " << bookTitle << " is " << setprecision(2) << fixed << AvgRating << endl;
    }
    return AvgRating;
}

bool Library::addUser (string username)
{
    bool added = false;
    int userIndex = ReadCountHelperFunction(users, numUsers, username);
    if (numUsers == sizeUser)
    {
        cout << "Database full" << endl;
        added = false;
    }
    else if(userIndex >= 0)
    {
        cout << username << " already exists in the database" << endl;
        added = false;
    }
    else
    {
        for (int i = 0; i < username.length(); i++)
        {
            username[i] = tolower(username[i]);
        }
        string t = username;
        users[numUsers].setUsername(t);
        users[numUsers].setNumRatings(0);
        for (int j = 0; j < numBooks; j++)
        {
            users[numUsers].setRatingAt(j, 0);
        }
        numUsers++;
        // cout << "test" << users[numUsers - 1].getUsername();
        // cout << "new ratings" << users[numUsers - 1].getNumRatings();
        
        return true;
    }
}

bool Library::checkOutBook(string username, string bookTitle, int newRatingValue)
{
    bool checkout = false;
    int userIndex = ReadCountHelperFunction(users, numUsers, username);
    int bookIndex = AvgRatingHelper(books, bookTitle, numBooks);
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        cout << username << " could not check out " << bookTitle << endl;
        checkout = false;
    }
    else 
    {
        
        if (userIndex < 0 && bookIndex > 0)
        {
            cout << username << " does not exist in the database" << endl;
        }
        
        else if (bookIndex <= 0 && userIndex > 0)
        {
            cout << bookTitle << " does not exist in the database" << endl;
        }
        
        else if ((newRatingValue < 0 || newRatingValue > 5) && userIndex > 0 && bookIndex > 0)
        {
            cout << newRatingValue << " is not valid" << endl;
        }
        else if (userIndex < 0 && bookIndex <= 0 && (newRatingValue < 0 || newRatingValue > 5))
        {
            cout << username << " does not exist in the database" << endl;
            cout << bookTitle << " does not exist in the database" << endl;
            cout << newRatingValue << " is not valid" << endl;
        }
        else if (userIndex > 0 && (newRatingValue >= 0 && newRatingValue <= 5))
        {
            // for (int i = 0; i < numUsers; i++)
            // {
            //     for (int j = 0; j < numBooks; j++)
            //     {
            //         users[i].setUsername(username);
            //         users[i].setRatingAt(j, newRatingValue);
            //         //cout << "true" << endl;
            //     }
            // }
            users[userIndex].setRatingAt(bookIndex, newRatingValue);
            checkout = true;
        }
    }
    return checkout;
}

void Library::viewRatings(string username)
{
    
    int userIndex = ReadCountHelperFunction(users, numUsers, username);
    // cout << userIndex << "userIndex" << endl;
    // cout << users[userIndex].getNumRatings() << " num ratings" << endl;
    if (numBooks == 0 && numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
    }
    else if (userIndex < 0)
    {
        cout << username << " does not exist in the database" << endl;
    }
    else if (getCountReadBooks(username) == 0)
    {
        // cout << userIndex << endl;
        // cout << users[userIndex].getNumRatings() << endl;
        cout << username << " has not rated any books yet" << endl;
    }
    else
    {
        cout << "Here are the books that " << username << " rated" << endl;
        for (int i = 0; i < numBooks; i++)
        {
            if (users[userIndex].getRatingAt(i) > 0)
            {
                cout << "Title : " << books[i].getTitle() << endl;
                cout << "Rating : " << users[userIndex].getRatingAt(i) << endl;
                cout << "-----" << endl;
            }
        }
        
    }
}

// int recHelper (User users[], string username, int userIndex, int numBooks, int numUsers)
// {
//     int min = 1000;
//     int recIndex = 0;
//     int k = 0;
//     int compIndex = userIndex;
//     int NumberOfReadBooks = 0;
//     for (int i = 0; i < numUsers; i++)
//     {
        
//         for (int j = 0; j < numBooks; j++)
//         {
//             if(users[i].getRatingAt(j) != 0)//if the user ratings are not equal to zero
//             {
//                 NumberOfReadBooks++;//increase the number of read books
//             }
//         }
//         if (i != userIndex && users[userIndex].getNumRatings() > 0)
//         {
//             int SSD = 0;
//             for (k = 0; k < numBooks; k++)
//             {
//                 SSD = SSD + pow(users[i].getRatingAt(k) - users[userIndex].getRatingAt(k), 2);
//                 if (SSD < min)
//                 {
//                     min = SSD;
//                     recIndex = k;
//                 }
//             }
//         }
//     } 
//     return recIndex;
// }

void Library::getRecommendations(string username)
{
    int min = 1000;
    int index = 0;
    int k = 0;
    int count = 0;
    int userIndex = ReadCountHelperFunction(users, numUsers, username);
    int NumberOfReadBooks = 0;
    // int recIndex = recHelper(users, username, userIndex, numBooks, numUsers);
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
    }
    else if (userIndex < 0)
    {
        cout << username << " does not exist in the database" << endl;
    }
    else
    {
        for (int i = 0; i < numUsers; i++)
        {
            if (i != userIndex && users[userIndex].getRatingAt(i) > 0)
            {
                int SSD = 0;
                for (k = 0; k < numBooks; k++)
                {
                    SSD = SSD + pow(users[i].getRatingAt(k) - users[userIndex].getRatingAt(k), 2);
                    if (SSD < min)
                    {
                        min = SSD;
                        index = k;
                    }
                }
            }
        } 
        for (int u = 0; u < numUsers; u++)
        {
            for (int r = 0; r < numBooks; r++)
            {
                if (count < 5)
                {
                    if (users[u].getRatingAt(r) >= 3 && users[u].getRatingAt(r) <= 5 && (users[userIndex].getRatingAt(r) <= 0))
                    {
                        if (count == 0)
                        {
                            cout << "Here are the list of recommendations: " << endl;
                            
                        }
                        cout << books[r].getTitle() << " by " << books[r].getAuthor() << endl;
                        count++;
                    }
                }
            }
        }
        if (count == 0)
        {
            cout << "There are no recommendations for " << username << " at the present" << endl;
        } 
            
    }
}

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
                    // getline(cin, fileBooks);
                    fileBooks = "books.txt";
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

                    // getline (cin, fileRatings);
                    fileRatings = "ratings.txt";
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
                case 9:
                    //get recommendations between users
                    cout << "Enter username: " << endl;
                    getline(cin, username);
                    library.getRecommendations(username);
                    
                    cout << endl;
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