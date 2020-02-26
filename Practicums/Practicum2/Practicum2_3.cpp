#include <iostream>
#include <string>
using namespace std;

void naturalDiagonal(int num)
{
   for (int i = 1; i <= num ; i++)
   { 
       for (int j = 1; j <= num; j++)
       {
            if (i != j)
             {
                cout << i;
             }
             else 
             {
                cout << "*";
             }
        }
        cout << endl;
    }

}

int main ()
{
    naturalDiagonal(5);
    // naturalDiagonal(11);
}