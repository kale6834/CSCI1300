#include <iostream>
#include <string>
using namespace std;

// how many As are in a given string?
int countAs(string s);
int main()
{
    string str = "AAABBBJJJJDDDDPPP";
    cout << countAs(str) << endl;
    return 0;
}

// int countAs(string s)
// {//if we don't multiple return statements, we can change count to -1
//     int count = 0;
//     if (s.length() == 0) 
//     {
//         return -1;
//     }
//     for(int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == 'A' || s[i] == 'a')
//         {
//             count++;
//         }
//     }
//     return count;
// }

//how many As, Bs, and Cs and all the way to Ps are in a given string?
//can refer to ASCII table
//A = 65, P = 80
//can do arithmatic with them
int countAs (string s)
{
    int count = 0;
    if (s. length () == 0)
    {
        count = -1;
    }
    else 
    {
        for (int i = 0; i < s.length (); i++)
        {
            if (s[i] >= 65 && s[i] <= 80)
            {
                count++;
            }
        }
    }
    return count;
}