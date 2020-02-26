#include "Library.h"
#include "Book.h"
#include "User.h"


Library library;
Library::Library ()
{
    numBooks = 0;
    numUsers = 0;
}

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
    
    //if the books or ratings files haven't been read
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;;
        return -1;
    }
    if (userIndex < 0) //if the user wasn't found in the database
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
        // cout << "The average rating for " << bookTitle << " is " << setprecision(2) << fixed << AvgRating << endl;
    }
    return AvgRating;
}

bool Library::addUser (string username) //adds user the database
{
    
    int userIndex = ReadCountHelperFunction(users, numUsers, username); //call the function to find the user index
    if (numUsers == sizeUser) //if the database is full
    {
        cout << "Database full" << endl;
        return false;
    }
    else if(userIndex >= 0) //if the user is found
    {
        cout << username << " already exists in the database" << endl;
        return false;
    }
    else
    {
        for (int i = 0; i < username.length(); i++) //lowercase the name when adding it so you can find it for next time
        {
            username[i] = tolower(username[i]);
        }
        string t = username;
        users[numUsers].setUsername(t); //set the username to lowercase
        users[numUsers].setNumRatings(0); //set their number of ratings to 0
        for (int j = 0; j < numBooks; j++)
        {
            users[numUsers].setRatingAt(j, 0); //set all of the ratings of the books equal to 0
        }
        numUsers++;
        return true;
    }
}

bool Library::checkOutBook(string username, string bookTitle, int newRatingValue) //changes the rating of a book
{
    bool checkout = false;
    int userIndex = ReadCountHelperFunction(users, numUsers, username); //find the user
    int bookIndex = AvgRatingHelper(books, bookTitle, numBooks); //search for the book title
    if (numBooks == 0 || numUsers == 0) //if the files haven't been read
    {
        cout << "Database has not been fully initialized" << endl;
        return false;
    }
    else 
    {
        
        if (userIndex < 0 && bookIndex > 0) //if the user can't be found
        {
            cout << username << " does not exist in the database" << endl;
        }
        
        else if (bookIndex <= 0 && userIndex > 0) //if the book title can't be found
        {
            cout << bookTitle << " does not exist in the database" << endl;
        }
        
        else if ((newRatingValue < 0 || newRatingValue > 5) && userIndex > 0 && bookIndex > 0) //if the rating isn't valid
        {
            cout << newRatingValue << " is not valid" << endl;
        }
        //if the user, book title, or rating isn't valid
        else if (userIndex < 0 && bookIndex <= 0 && (newRatingValue < 0 || newRatingValue > 5))
        {
            cout << username << " does not exist in the database" << endl;
            cout << bookTitle << " does not exist in the database" << endl;
            cout << newRatingValue << " is not valid" << endl;
        }
        else if (userIndex > 0 && (newRatingValue >= 0 && newRatingValue <= 5)) //if the rating is valid and user is found
        {
            users[userIndex].setRatingAt(bookIndex, newRatingValue);
            checkout = true;
        }
    }
    return checkout;
}

void Library::viewRatings(string username)
{
    
    int userIndex = ReadCountHelperFunction(users, numUsers, username); //searches for the user
    if (numBooks == 0 && numUsers == 0) //if the files weren't read
    {
        cout << "Database has not been fully initialized" << endl;
    } 
    else if (userIndex < 0) //if the user can't be found
    {
        cout << username << " does not exist in the database" << endl;
    }
    else if (users[userIndex].getNumRatings() == 0) //if there are no number of ratings
    {
        cout << username << " has not rated any books yet" << endl;
    }
    else
    {
        cout << username << " rated " << users[userIndex].getNumRatings() << " books" << endl; 
        cout << "Here are the books that " << username << " rated" << endl;
        for (int i = 0; i < numBooks; i++) //for loop to go through all of the books that were rated
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

void Library::getRecommendations(string username) //gets the recommendations based on other users
{
    int min = 1000;
    int index = 0;
    int k = 0;
    int count = 0;
    int userIndex = ReadCountHelperFunction(users, numUsers, username); //searches for the user
    int NumberOfReadBooks = 0;
    if (numBooks == 0 || numUsers == 0) //if the files weren't read
    {
        cout << "Database has not been fully initialized" << endl;
    }
    else if (userIndex < 0) //if the user wasn't found
    {
        cout << username << " does not exist in the database" << endl;
    }
    else
    {
        for (int i = 0; i < numUsers; i++)
        {
            if (i != userIndex && users[userIndex].getRatingAt(i) > 0) //if the username isn't equal to the one in the database and rating is above 0
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
        for (int u = 0; u < numUsers; u++) //searches through the user datbase
        {
            for (int r = 0; r < numBooks; r++) //searches through the book database
            {
                if (count < 5) //if the count is less than 5
                {
                    if (users[u].getRatingAt(r) >= 3 && users[u].getRatingAt(r) <= 5 && (users[userIndex].getRatingAt(r) <= 0)) //if the users rating is 3-5 and the one we're comparing it to is equal to 0
                    {
                        if (count == 0)
                        {
                            cout << "Here are the list of recommendations: " << endl;
                            
                        }
                        cout << books[r].getTitle() << " by " << books[r].getAuthor() << endl; //print out all of the books and authors
                        count++;
                    }
                }
            }
        }
        if (count == 0) //if there aren't any recommendations
        {
            cout << "There are no recommendations for " << username << " at the present" << endl;
        } 
            
    }
}
