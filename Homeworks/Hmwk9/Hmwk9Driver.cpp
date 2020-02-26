// CSCI1300 Fall 2018
// Author: Kalei Lewis
// Recitation: 102 - Paramjot Singh
// Cloud9 Workspace Editor Link: https://ide.c9.io/kaleilewis/kale6834
// Hmwk9/Project 3

/**
 * sources:
 * 1. Cathleen helped me fix some of my errors
 * 2. I worked with Justin to brainstorm this project
 */

#include <iostream>
#include <string>
using namespace std;

#include "Gameplay.h"

void displayMenu()
{
    cout << "YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:\n"
                   "-OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS\n"
                   "-FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK\n"
                   "-AMMUNITION - $2 BUYS A BELT OF 20 BULLETS. YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD\n"
                   "-MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS\n"
                   "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD.\n"
                   "\n";
}

int main ()
{
    string month;
    string day;
    Gameplay gameplay; //gameplay class and object
    int people = 0;
    string username;
    string riverFile = "river-milestones.txt"; //text file of river milestones provided
    string fortFile = "fort-milestones.txt"; //text file of fort milestones provided
    Gameplay(); //sets all private members in gameplay class to null
    gameplay.milestonesForts(fortFile); //reads in the fort milestones text
    gameplay.milestonesRivers(riverFile); //reads in the river milestones text
    displayMenu(); //gives the intro of the game
    while (people < 5) //while there are under 5 players
    {
        cout << "Enter a player name." << endl;
        getline(cin,username); //reads to the end of the username
        gameplay.addPlayers(username); //adds the user to the game
        people++; //number of people increase every time someone is added
    }
    
    gameplay.visitStore();
    
    while (!(day >= "1" && day <= "31") || !(month >= "3" && month <= "5"))
    {
        cout << "You can choose to leave on 3/28/1847 or choose a departure date between 3/1/1847 and 5/1/1847" << endl;
        cout << "Remember you must make it to Oregon City by 11/30/1847" << endl;
        cout << "Enter the numerical month in which you would like to leave" << endl;
        getline(cin, month);
        cout << "Enter the day in which you would like to leave" << endl;
        getline(cin, day);
    }
    if ((day >= "1" && day <= "31") || (month >= "3" && month <= "5"))
    {
        gameplay.travelDate(stoi(month),stoi(day)); //sets the date that the party will start to travel
    }
    
    
    gameplay.takeTurns(); //gives the options to rest, continue, hunt, or quit game
}