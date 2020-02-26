#include <iostream>
using namespace std;

//ten elemnts of double type can be stored under one name as an array
//double values [10];
//quantity of elements (10) - the size of the aray must be a constant
//arrays must be a collection of data of the same type
//all characters, all integers, all doubles...etc...

//declare the array - allocates memory
//int score [5] is like declaring 5 separate variables
//variables will be garbage

//when you define an array, you can specify the initial values
//double values [] = {32, 54, 67.5, 29, 35...}

//disadvantage: size must be known at declaration

int main()
{  
   const int CAPACITY = 10;
   //array is called values
   double values[CAPACITY];
   // int size = 10;
   //usually you would put capacity here. if you put capacity here, then it would
   //set the values of array equal to zero
   
   //certain compilers will not let you do this because 'size' is not a constant
   //good programming practice is to use the constant in the for loop
   for (int i = 0; i < CAPACITY; i++)
   {
      //to get squares 
      //values [i] = (i+1)*(i+1)
      values[i] = i + 1;
      cout << values [i] << endl;
   }

   
   return 0;
}