#include <iostream>
#include <string>
#include <fstream>
using namespace std;

 int split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length() && count < size; i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } 
        else 
        {
            word = word + str[i];
        }
    }
    return count ;
 }
 
//  int PrintStudents (string fileIn, int minScore, string fileOut)
//  {
//      string name, score, course;
//      ifstream in;
//      in.open(fileIn);
//      ofstream out;
//      out.open(fileOut);
//      string line;
//      int studentcounter = 0;
//      if (in.fail())
//      {
//          return -1;
//      }
//      else
//      {
//         while (getline (in, name, ',')) //splits line from beginning of line to comma, and that's the name
//         {
//             getline(in, score, ','); //splits line from name to course
//             getline(in, course); //splits line from score to end of line
//             if (stoi(score) >= minScore)
//             {
//                 out << name << ", " << course << endl;
                
//             }
//             studentcounter++; //counts lines
//         }
//         return studentcounter;
//      }
//  }
 
int PrintStudents(string fileIn, int minScore, string fileOut)
{
    ifstream in;
    in.open(fileIn);
    ofstream out;
    out.open (fileOut);
    if (in.fail())
    {
        return -1;
    }
    else
    {
        string line = "";
        int i = 0;
        string name[100];
        string subject[100];
        int num;
        while (getline(in, line))
        {
            if (line != "")
            {
                string array[3];
                split (line, ',', array, 3);
                name[i] = array[0];
                num = stoi(array[1]);
                subject[i] = array[2];
                if (num >= minScore)
                {
                    out << name[i] << ", " << subject[i] << endl;
                }
                i++;
            }
        }
        return i;
    }
}
 
 int main ()
 {
     PrintStudents("studentScores.txt", 80, "minScores.txt");
 }