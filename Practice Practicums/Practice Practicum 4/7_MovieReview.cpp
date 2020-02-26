#include <iostream>
#include <string>
using namespace std;

#ifndef MOVIEREVIEW_H
#define MOVIEREVIEW_H
class MovieReview
{
    public:
    MovieReview();
    MovieReview(string, string, int);
    void setName(string);
    string getName();
    void setGenre(string);
    string getGenre();
    void setRating(int);
    int getRating();
    string howYouReallyFeel();
    
    private:
    string name;
    string genre;
    int rating;
};
#endif

MovieReview::MovieReview()
{
    name = "Goofy Movie 2: The Extremely Goofy Movie";
    genre = "Thriller";
    rating = 10;
}

MovieReview::MovieReview(string x, string y, int z)
{
    name = x;
    genre = y;
    rating = z;
}

void MovieReview::setName(string input)
{
    name = input;
}

string MovieReview::getName()
{
    return name;
}

void MovieReview::setGenre(string input)
{
    genre = input;
}

string MovieReview::getGenre()
{
    return genre;
}

void MovieReview::setRating(int input)
{
    rating = input;
}

int MovieReview::getRating()
{
    return rating;
}

string MovieReview::howYouReallyFeel()
{
    if (rating <= 0)
    {
        return "Garbage";
    }
    else if (rating > 0 && rating <= 5)
    {
        return "Boo";
    }
    else if (rating > 5 && rating <= 7)
    {
        return "Meh";
    }
    else if (rating > 7 && rating <= 9)
    {
        return "Good";
    }
    else
    {
        return "Must be THE Goofy Movie 2";
    }
}