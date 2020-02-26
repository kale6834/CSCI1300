#include <iostream>
#include <string>
#include <vector>
using namespace std;

void modifyVector(vector<int>& vector1)
{
    
    int value;
    cout << "Please enter an integer value: " << endl;
    cin >> value;
    if (value > 0)
    {
        while (value > 0)
        {
            if (vector1.size() == 0)
            {
                vector1.push_back(value);
            }
            else if ((value % 5) == 0)
            {
                vector1.erase(vector1.begin() + 0);
            }
            else if ((!(value % 5) == 0) && (value % 3) == 0)
            {
                vector1.pop_back();
            }
            else 
            {
                vector1.push_back(value);
            }
            cout << "Please enter an integer value: " << endl;
            cin >> value;
        }
    }
}

int main ()
{
    vector <int> vector1;
    modifyVector(vector1);
}