#include <iostream>
#include <string>
using namespace std;

/**
 * Write a function floodMap which takes three arguments, a two-dimensional array 
 * of doubles indicating the height of the terrain at a particular point in space 
 * (assume that there are 4 columns), an int indicating the number of rows in the map, 
 * and a double indicating the current water level. The function should print out 
 * a "map" of which points in the array are below the water level. In particular, 
 * each position at or below the water level will be represented with a * and each 
 * position above the water level will be represented with a '_'.
● Your function should be named floodMap
● Your function should take three parameters: A two-dimensional array of doubles 
    with 4 columns, The number of rows in the array, A double indicating the current water level.
● Your function should print a flood map as described.
*/


void floodMap (double array [][4], int rows, double waterLevel)
{
    int i;
    int j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < 4; j++)
        {
           if (array[i][j] <= waterLevel)
           {
               cout << "*";
           }
           else
           {
               cout << "_";
           }
        }
        cout << endl;
    }
}

int main ()
{
    double map[1][4] = {{5.0, 7.6, 3.1, 292}};
    floodMap(map, 1, 6.0);
}