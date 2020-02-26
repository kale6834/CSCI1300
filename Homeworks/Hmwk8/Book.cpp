//function definitions
//don't have to include iostream and all that jazz
//because it's in our .h file
//this allows our .cpp file to read everything in the header file including member variables
#include "Book.h"

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

// Book book1; //garbage
// Book book 1 = Book(); //""
// Book book 1 = Book ("", "");