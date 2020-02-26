#include <iostream>
using namespace std;

/*Please enter values, Q to quit:
1 2 3 4 5 6 q
1
2
3
4
5
6 <== largest value*/

int main()
{  
   const int CAPACITY = 1000;
   double values[CAPACITY];
   double input;
   int array_size = 0;
   double largest = -10000000000;
   
   cout << "Please enter values (separated by spaces), Q to quit:" << endl;
   int i = 0;
   
   // need to remember how many elements we entered
   //"as long as i can read a double from the keyboard input, this loop will run"
   //asking to get doubles, so as long as you give doubles, it'll run
   //if you give something else other than doubles, it'll stop
   while (cin >> input)
   {
      // check if we haven't entered more than 1000 numbers
      if (i < CAPACITY)
      {
         values[i] = input;
         i++;
      }
   }
   //array_size is the value entered from the user
   array_size = i;
   cout << array_size << endl;
   
   // find the largest
   for (i=0; i < array_size; i++)
   {
      if (values[i] > largest) //largest holds max value so far
      {
         largest = values[i];
      }
   }
   //print them
   for (i=0; i < array_size; i++)
   {
      cout << values[i];
      if (values[i] == largest)
      {
         cout << " <== largest value";
      }
      cout << "\n";
   }
   
   return 0;
}