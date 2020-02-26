#include <iostream>
#include <string>
using namespace std;

#ifndef TEXTBOOK_H
#define TEXTBOOK_H

class Textbook
{
    public:
    Textbook();
    Textbook (string t, int p, float c, bool o);
    void setTitle (string t);
    string getTitle();
    void setPages (int p);
    int getPages ();
    void setCost (float c);
    float getCost ();
    void setOnline (bool o);
    bool getOnline ();
    float costPerPage ();
    
    private:
    string title;
    int pages;
    float cost;
    bool online;
};

#endif