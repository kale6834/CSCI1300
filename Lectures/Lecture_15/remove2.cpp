
#include<iostream>
#include<string>
using namespace std;

// Removes all spaces or dashes from a string 
int main() 
{ 
	string credit_card_number = "4123-5678-9012-3450";
	string newString = "";
	 
	for (int i = 0; i < credit_card_number.length(); i++) 
	{ 	
		if (credit_card_number[i] != ' ' && credit_card_number[i] != '-') //don't add them to newString
 		{ 
			newString += credit_card_number[i];	
 		}
	} 
	cout << newString << endl; 
	return 0; 
}
