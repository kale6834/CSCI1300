#include <iostream>
#include <string>
using namespace std;

/**
 * Algorithm: Write a function that takes a string of four genomes and calculates the difference between them and picks the best genome.
 * 1. calculate similarity score
 * 2. input two strings
 * 3. traverse both strings
 * 4. determine where they are different
 * 5. subtract sequence length by hamming distance and divide by sequence length
 * 6. edge cases: if strings are empty, if bacteria length is longer than genomes, if the genome lengths don't match
 * 7. find the similarity scores between the genomes and bacteria lengths
 * 8. determine the max score
 * 9. print out statement depending on max score
 * Input arguments: simScore(two string sequences), analyzer(three genome strings and one bacteria string)
 * Output: which genome is the best match
 * Returns: simScore returns the similarity score and analyzer returns nothing
 */
 
 
double simScore (string s1, string s2);
void analyzer (string g1, string g2, string g3, string bacteria);

//similarity score calculator that takes two sequences as the input
//since value must be a decimal, function needs to be a double
double simScore (string s1, string s2)
{
    //hamming distance is initialized at zero
    //counts where the corresponding characters in a string are different
    double hammingDistance = 0;
    //final similarity score is initialized at zero
    double simscore = 0;
    //if the sequence 1 and sequence 2 length don't match
    if (s1.length () != s2.length ())
    {
        //return 0
        return 0;
    }
    //if the sequence 1 and sequence 2 length are empty
    else if (s1.length () == 0 || s2.length () == 0)
    {
        //return 0
        return 0;
    }
    //if sequence 1 and sequence 2 lengths match
    else if (s1.length () == s2.length ())
    {
        //enter the fore loop, scanning the length of the first sequence
        for (int i = 0; i < s1.length(); i++)
        {//if the index in sequence one does not match the same place in the index in sequence two
            if (s1[i] != s2[i])
            {//increase the hamming distance
                hammingDistance++;
            }
        }
        //since this loop ran with both sequences being equal to each other, i only have to worry about the length of one sequence
        //similarity score is equal to the string lengths - hamming distance divided by string lengths
        simscore = (s1.length() - hammingDistance) / s1.length();
    }
    //similarity score is returned
    return simscore;
    
}
//this is the function that will call the simScore function and determine which is the best match for the doctors to use
//input takes three genome strings and one bacteria string
void analyzer (string g1, string g2, string g3, string bacteria)
{//all of my local variables are initialized at zero
    int i = 0;
    double max = 0;
    double max1 = 0;
    double max2 = 0;
    double max3 = 0;
    //if genome 1, 2, and 3 are empty, output the print statement
    if (g1 == "" || g2 == "" || g3 == "" || bacteria == "")
    {
        cout << "Genome and sequence cannot be empty." << endl;
    }
    //if none of the genome lengths match
    else if (g1.length () != g2.length() || g1.length() != g3.length() || g2.length() != g3.length() || g3.length() != g1.length() || g3.length() != g2.length())
    {
        cout << "Genome length does not match." << endl;
    }
    //if the bacteria length is bigger than the genome lengths
    else if (bacteria.length() > g1.length() || bacteria.length() > g2.length() || bacteria.length() > g3.length())
    {
        cout << "Sequence length must be smaller than genome length." << endl;
    }
    //if none of these conditions are met, go into this condition
    else 
    {//this for loop will run along the length of genome one, but only for the number of indexes in the bacteria string
        for (i = 0; i < g1.length() - bacteria.length(); i++)
        {
            //if the similarity score is bigger than max1, which is zero
            //this will call the function simScore and will evaluate the substring of genome 1 from where the bacteria and genome match to the end
            if (simScore(g1.substr(i, bacteria.length()), bacteria) >= max1)
            {//the new value of max1 will equal the simScore function that was called
                max1 = simScore(g1.substr(i, bacteria.length()), bacteria);
            }
        }
        //this for loop will run along the length of genome 2, but only for the number of indexes in the bacteria string
        for (i = 0; i < g2.length() - bacteria.length (); i++)
        {//if the similarity score is bigger than max2, which is zero
        //this will call the function simScore and will evaluate the substring of genome 2 from where the bacteria and genome match to the end
            if (simScore(g2.substr(i, bacteria.length()), bacteria) >= max2)
            {//the new value of max2 will equal the value of the simScore function that was called
                max2 = simScore(g2.substr(i, bacteria.length()), bacteria);
            }
        }
        //this for loop will run along the length of genome 3, but only for the number of indexes in the bacteria string
        for (i = 0; i < g3.length() - bacteria.length (); i++)
        {//if the similarity score is bigger than max3, which is zero
        //this will call the function simScore and will evaluate the substring of genome 3 from where the bacteria and genome match to the end
            if (simScore(g3.substr(i, bacteria.length()), bacteria) >= max3)
            {//the new value of max3 will equal the value of the simScore function that was called
                max3 = simScore(g3.substr(i, bacteria.length()), bacteria);
            }
        }
        //if max1 is greater than max2 and max3
        if (max1 > max2 && max1 > max3)
        {
            cout << "Genome 1 is the best match." << endl;
        }
        //if max2 is greater than max1 and max3
        else if (max2 > max1 && max2 > max3)
        {
            cout << "Genome 2 is the best match." << endl;
        }
        //if max3 is greater than max1 and max2
        else if (max3 > max1 && max3 > max2)
        {
            cout << "Genome 3 is the best match." << endl;
        }
        //if max1 and max2 are the best genome match
        //i had to say that max1 could not be equal to max3 or else this statement would be printed
        else if (max1 == max2 && max2 == max1 && max1 != max3)
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
        }
        //if max2 and max3 are the best genome match
        //i had to say that max2 could not equal max1 or else this statement would be printed
        else if (max2 == max3 && max3 == max2 && max2 != max1)
        {
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        //if max1 and max3 are the best genome match
        //i had to say that max1 could not equal max2 or this statement would print out
        else if (max1 == max3 && max3 == max1 && max1 != max2)
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        //if max1 and max2 and max3 are all the best genome matches
        else if (max1 == max2 && max1 == max3 && max2 == max3 && max2 == max1 && max3 == max2 && max3 == max1)
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        
    }
}

int main ()
{
    analyzer ("AATGTTTCAC", "GACCGACTAA", "AAGGTGCTCC", "TACTA");//test case 1. output should be "genome 2 is the best match"
    string g1 = "TAAGGCA";
    string g2 = "TCTGGGC";
    string g3 = "CTAATAT";
    string seq = "AAG";
    analyzer(g1,g2,g3,seq); //test case 2. output should be "genome 1 is the best match"
    analyzer("AC","AC","AC","AC"); //test case 3. output should be "genome 1, 2, and 3 is the best match"
}
    