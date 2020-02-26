// extract to string
#include <iostream>
#include <string>
using namespace std;
//getline() reads a whole line up to the next '\n', will remove '\n', form it into a string and put it in the line variable
//getline (in_file, line)
//the line is the variable that your line will go into
int main ()
{
  string name;

  cout << "Please, enter your full name: ";
  cin >> name;
  cout << "Hello, " << name << "!\n";
  
  cout << "Please, enter your full name: ";
  getline (cin,name);
  cout << "Hello, " << name << "!\n";

  return 0;
}