#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int writeVowels (string fileName, string array[], int length)
{
    ofstream out;
    out.open(fileName);
    
    if (out.is_open())
    {
        string str;
        int count2 = 0;
        for(int i = 0; i < length; i++)
        {
            int count = 0;
            str = array[i];
            if (str.length() == 0)
            {
                
            }
            else
            {
                for (int j = 0; j <str.length(); j++)
                {
                    if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' || 
                    str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U')
                    {
                        count++;
                    }
                }
                out << array[i] << "," << count << endl;
                count2++;
            }
        }
        return count2;
    }
    else
    {
        return -1;
    }
}

int main ()
{
    string lines[] = {"hello","","WORLD"};
    int writeCount = writeVowels("test1.txt", lines, 3);     
    cout<<"Number of lines written: "<< writeCount <<endl;
}