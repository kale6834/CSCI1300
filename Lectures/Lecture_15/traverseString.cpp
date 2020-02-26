#include <iostream>
#include <string>
using namespace std;

// print each character in a given string
void traverse(string x);
int main()
{//this string has 3 characters but starts at position 0
    string str = "ABCerddffds";
    //if you don't know how many characters you have, you can put 'name of variable'.length().
    // ex: str.length(), because str is the variable
    for (int i = 0; i < str.length(); i++)
    {//str[i] will output each character instead of a character at just one position
     cout << "str[0] reads " << str[i] << endl;   
    }
    // traverse(str);
    return 0;
}

// void traverse(string x)
// {//variable i start at position 0
//the loops should end when the i is 3
//     for(int i = 0; i < x.length();i++)
//     {
//         cout << x[i] << endl;
//     }
// }