#include <iostream>
//fstream stands for file stream
#include <fstream>
#include <string>

using namespace std;

double process_name(string Name, double total, double p)
{
   if (total > 0)
   {
      cout << Name << " ";
      total = total - p;
   }
   return total;
}
int main()
{  //if stands for input file
   //looks like every other variable declaration we've done. only the type name is new to us
   ifstream in_file;
   //associate it with a file
   in_file.open("babynames.txt"); //name of file is in double quotes because it's a string
   //they will only work if the directories are together
   //so put the files in the same folder
   //if it's not in the same folder, 
   //window: in_file.open("c:\\nicework\\input.dat")
   //unix: in_file.open("~/nicework/input.dat")
   
    // Check for failure after opening
    //recommended to do before starting to read things from the file
   if (in_file.fail()) 
   { 
      return 0; 
   }
   // declare variables
   int rank;
   string name;  // reuse them for boys and girls
   int count;
   double percent;
   double boy_total = 50;
   double girl_total = 50;
   
   // read one line at a time from file and check if it should be displayed
   while (boy_total > 0 || girl_total > 0)
   {
         //in_file >> is like the same thing as cin >>
         in_file >> rank;
         cout << rank << " ";
         in_file >> name >> count >> percent;
         // process boy info: print rank and the name as long as < 50%
         boy_total = process_name(name, boy_total, percent);
         
         in_file >> name >> count >> percent;
         // process girl info
         girl_total = process_name(name, girl_total, percent);
         
         cout << "\n";
   }
   // in_file.close(); //to close file. put it right before you return the function
   //the file will close anyway with the return
   //good practice is to close it
   return 0;
}	

/*You can use the fileObject.fail() function to check if the file open 
was successful or not. This will return true if the file open has failed and 
false otherwise.*/
