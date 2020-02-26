#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_SCORES = 5;

int main()
{
    int score[NUM_SCORES];
    
    cout << "Enter 5 scores: \n";
    cin >> score[0];
    cin >> score[1];
    cin >> score[2];
    cin >> score[3];
    cin >> score[4];
    
    // copying to another array. cannot copy one to another
    //has to be initialized one by one
    int newArray[NUM_SCORES];
    for (int i = 0; i < 5; i++)
    {
        newArray[i] = score[i];
    }
    //if we want to print all of the elements in an array, we use another for loop
    //except we'll have a print statement printed on each line
    for (int i = 0; i < 5; i++)
    {
        cout << newArray[i] << endl;
    }
    // the sum of all scores. since you're going to keep adding it in the loop,
    //need to initialize it to 0 outside of the loop
    /**what will change if we want to do a product of all of the scores?
     * multiply in the loop
     * total = total * score[i]; <- you will get 0 with this
     * to fix this, you need to initialize total at 1
     * when doing a product, you want to start at 1 but when adding you want to start at 0
     * will get a negative number because the int number has a maximum amount of memory it can take
     */
    int total = 0;
	for (int i = 0; i < NUM_SCORES; i++)
	{
	    //takes the old value of total and adds to the new value
	   total = total + score[i];
	}
	cout << "Total: " << total<< endl;
    
    // Find average
    cout << "Average: " << double(total)/NUM_SCORES << endl;
    
    // Find max score
    int max = score[0];
    for (int i = 1; i < NUM_SCORES; i++)
    {
        if (score[i] > max)   
        {
            max = score[i];
        }
    }
    cout << "The highest score is " << max << endl;
    
    // Find the position of the highest score
    int pos = 0;
    bool found = false;
    while (pos < NUM_SCORES && !found)
    {
        if (score[pos] == 100) // looking for 100
        {
            found = true;
        }
        else
        {
            pos++;
        }
    }
    if (pos < NUM_SCORES)
    {
        cout << "The index for 100 is: " << pos << endl;
    }
    else
    {
        cout << "100 not found" << endl;
    }

    return 0;
}