#include <iostream>
#include <string>
using namespace std;

int main()
{
    string email = "io@edu.com";
    bool flag = false;
    int i = 0;
    string mySubstring;

    string lookup = ".com";     // look for ".com"

    for(i = 0; i < email.length() - lookup.length() + 1; i++)
    {
        //substring will start at index 0
        //if it matches .com, then we exit the for loop
        mySubstring = email.substr(i,lookup.length());
        if (mySubstring == lookup)
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        cout << "You have mail!!!";
    }
    else
    {
        cout << "Invalid input";
    }

    return 0;
}