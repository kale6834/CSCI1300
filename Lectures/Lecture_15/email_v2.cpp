#include <iostream>
#include <string>
using namespace std;

int main()
{
    string email;
    
    cout << "Enter your email ID: ";
    cin >> email;
    
    bool flag = false;
    int i = 0;
    string s;
    //need a variable that hasn't been modified in the for loop
    int index = -1;
    
    // for loop equivalent
    for(i = 0; i < email.length(); i++)
    {
        s = email.substr(i,1);
        if (s == "@")
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
    // while (email[i] != '\0') // after each string there is a NULL character '\0'
    // {
    //     if (email[i] == '@') {
    //         cout << "You have mail!!!";
    //         break;
    //     }
    //     i++;
    // }