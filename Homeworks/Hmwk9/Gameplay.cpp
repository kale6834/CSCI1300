#include "Gameplay.h"

Gameplay::Gameplay()
{
    numMoney = 1000.00; //the party has $1000 after they payed $200 for the wagon
    totalBill = 0;
    milesToGo = 2040;
    numPlayers = 0;
    numBullets = 0;
    milesTraveled = 0; //start at 0 mile traveled
    billCounter = 0;
}

int split (string str, char c, string array[], int size)//split function used when reading into the files
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
 
 
int randomNumbers2(int min, int max) //random number generator
{
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

// int main(){
//     int num = 0;
//     // need to write before calling rand() to seed the random number generator
//     srand(time(0));
    
//     for(int i=0;i<10;++i)
//     {
//         // random numbers between 3 and 10
//         num = randomNumbers2(1,3);
//         cout<<num<<" ";
//     }
// }

void Gameplay::addPlayers (string username) //adds user the database
{
        players[numPlayers].setUsername(username); //set the username
        players[numPlayers].setAlive(true); //sets the user to true, which means alive
        numPlayers++; //increase the number of players each time the function is called
}

int Gameplay::buyOxen(int numItems)
{
    
    billCounter = numItems + billCounter; //this is used to determine if the player spent more than $200 on oxen
    totalBill = (numItems * 40) + totalBill;
    if (billCounter > 5) //if the number is more than 5, which is $200
    {
        cout << "You cannot spend more than $200 on oxen. Please try again." << endl;
    }
    if (totalBill > numMoney) //if the bill is more than the amount of money the party has
    {
        cout << "You do not have enough money. Please choose another amount" << endl;
    }
    else
    {
        numMoney = numMoney - totalBill; //subtract from money each time the player calls this function
        supplies.setNumOxen(supplies.getNumOxen() + numItems * 2); //there are two oxen in a yoke
    }
    cout << "You have " << supplies.getNumOxen() << " oxen." << endl;
    return numItems;
}

int Gameplay::buyFood (int numItems)
{
    totalBill = totalBill + (numItems * 0.50); //bill equals previous bill + new bill
    if (totalBill > numMoney) //if bill is more than amount of money party has
    {
        cout << "You do not have enough money. Please choose another amount." << endl;
    }
    else
    {
        numMoney = numMoney - totalBill; //amount of money equals amount of money - bill
        supplies.setNumFood(supplies.getNumFood() + numItems); //set the pounds of food
    }
    cout << "You now have " << supplies.getNumFood() << " lbs in your supply." << endl;
    return numItems;
}

int Gameplay::buyAmmo(int numItems)
{
    totalBill += 2 * numItems; //boxes of bullets are $2/box
    if (totalBill > numMoney) //if the bill is more than the amount of money party has
    {
        cout << "You do not have enough money. Please choose another amount." << endl;
    }
    else
    {
        numMoney = numMoney - totalBill; //amount of money equals old amount of money - bill
            
        numBullets = numItems * 20; //there are 20 bullets in a box
        supplies.setNumAmmo(supplies.getNumAmmo() + numBullets); //set number of bullets
    }
    cout << "You now have " << supplies.getNumAmmo() << " in your arsenal." << endl;
    return numItems;
}

int Gameplay::buyWagonParts(int numItems)
{
    totalBill += (numItems * 20); //each wagon part costs $20
    if (totalBill > numMoney) //if bill is more than amount of money party has
    {
        cout << "You do not have enough money. Please choose another amount." << endl;
    }
    else
    {
        numMoney = numMoney - totalBill; //subtract bill from amount of money party has
        supplies.setNumWagonParts(supplies.getNumWagonParts() + numItems); //set number of wagon parts
    }
    cout << "You now have " << supplies.getNumWagonParts() << " in your arsenal." << endl;
}

int Gameplay::buyMedKits(int numItems)
{
    totalBill += (numItems * 25); //each med kit costs $25
    if (totalBill > numMoney) //if bill is more money than party has
    {
        cout << "You do not have enough money. Please choose another amount." << endl;
    }
    else
    {
        supplies.setNumMedKits(supplies.getNumMedKits() + numItems); //set number of med kits
    }
    cout << "You now have " << supplies.getNumMedKits() << " in your aresenal." << endl;
    return numItems;
}

double Gameplay::getTotalBill()
{
    
    
    cout << "$" << totalBill << setprecision(2) << fixed << endl; //increases by 25% each time
    
    return totalBill;
}

void storeMenu()
{
    cout << "Select which one you would like to buy" << endl;
    cout << "1: Buy oxen" << endl;
    cout << "2: Buy food" << endl;
    cout << "3: Buy ammo" << endl;
    cout << "4: Buy wagon parts" << endl;
    cout << "5: Buy med kits" << endl;
    cout << "6: Print total bill" << endl;
    cout << "7: Exit" << endl;
}
int Gameplay::visitStore() //ask player what kind of supplies they want to buy and store that into the supplies class
{
    int OxenCounter, FoodCounter, AmmoCounter, WagonPartCounter, MedKitCounter;
    string answer;
    Supplies();
    string numItems;
    int counter = 0; //counter to increase amount of bill each time the party visits a store
    
    
    storeMenu(); //calls the store menu at the beginning of the turn
    getline(cin, answer);
    while (answer != "7") //7 sends the player on their way
    {
        
        
        switch(stoi(answer))
        {
            case 1:
                    cout << "There are two oxen in a yoke. Each yoke cost $40. How many would you like to buy?" << endl;
                    getline(cin, numItems);
                    OxenCounter = buyOxen (stoi(numItems));
                    cout << endl;
                    break;
                case 2:
                    cout << "Now you need to buy food. I recommend buying at least 200lb per person. Food cost $0.50 per pound." << endl;
                    cout << "How many pounds of food would you like to buy?" << endl;
                    getline(cin, numItems);
                    FoodCounter = buyFood (stoi(numItems));
                    cout << endl;
                    break;
                case 3: 
                
                    cout << "How many boxes of bullet would you like to buy? Remember that 20 bullets are in 1 box." << endl;
                    getline(cin, numItems);
                    AmmoCounter = buyAmmo(stoi(numItems));
                    cout << endl;
                    break;
                    
                case 4: 
                    cout << "How many wagon parts would you like to buy? This consists of wheels, axles, and tongues." << endl;
                    getline(cin, numItems);
                    WagonPartCounter = buyWagonParts(stoi(numItems));
                    cout << endl;
                    break;
                    
                case 5: 
                    cout << "How many wagon parts would you like to buy?" << endl;
                    getline(cin, numItems);
                    MedKitCounter = buyMedKits(stoi(numItems));
                    cout << endl;
                    break;
                    
                case 6: 
                    totalBill = totalBill + (getTotalBill() + (totalBill*(counter * 0.25))); 
                    cout << endl;
                    break;
                    
                case 7: 
                    return (stoi(answer));
                    break;
                
                default:
                    cout << "Invalid input" << endl;
        }
        storeMenu();
        getline(cin, answer);
    }
    counter += counter;
    counter ++; //increase counter each time
}

void Gameplay::travelDate(int month, int day)
{
    bool valid = false;
    while (valid == false) //while it is not ready to set day and month
    {
        if (month == 3)
        {
            if (day >= 1 && day <= 31) //if days are within range
            {
                valid = true;
            }
                
        }
        else if (month == 4)
        {
            if (day >= 1 && day <= 30) //if days are within range
            {
                valid = true;
            }
        }
        else if (month == 5)
        {
            if (day == 1) //if day is only 1
            {
                valid = true;
            }
        }
    }
    
    if (valid == true) //if appopriate conditions have been met
    {
        date.setMonth(month); //set month to start travel
        date.setDay(day); //set date to start travel
    } 
}

int Gameplay::takeTurns()
{
    Date();
    string choice;
    billCounter = 0;
    cout << "Date: " << date.getMonth() << " " << date.getDay() << " 1847" << endl; //get the day and the month
    cout << "Miles traveled: " << milesTraveled << endl; //display miles traveled
    // cout << "Distance until next milestone: " << endl;
    cout << "Food available: " << supplies.getNumFood() << endl; //display food available
    cout << "Number of bullets availalbe: " << supplies.getNumAmmo() << endl; //display number of bullets
    cout << "Cash available: $" << numMoney << endl << endl; //display amount of money in party
    
    cout << "You can choose to rest, continue, hunt, or quit." << endl; //menu choices
    cout << "1: Rest" << endl;
    cout << "2: Continue on trail" << endl;
    cout << "3: Hunt" << endl;
    cout << "4: Quit" << endl; //end game
    
    int misfortune = randomNumbers2(1,100); //chance of misfortune happening
    getline(cin, choice);
    while (choice != "4") //while choice is not going to end game
    {
        srand(time(0));
        // random numbers between 1 and 3
        int daysOfRest = randomNumbers2(1,3); //random days of rest
        
        switch(stoi(choice))
        {
            
            case 1:
                rest(numPlayers, daysOfRest);
                if (misfortune >= 1 && misfortune <= 40) //40% chance of misfortune happening
                {
                    misfortunesHappen(numPlayers);
                }
                raiderAttack(milesTraveled); //raiders can attack after every turn
                cout << endl;
                break;
                
            case 2:
                continueTrail();
                if (misfortune >= 1 && misfortune <= 40)
                {
                    misfortunesHappen(numPlayers);
                }
                raiderAttack(milesTraveled);
                cout << endl;
                break;
                
            case 3:
                hunt();
                if (misfortune >= 1 && misfortune <= 40)
                {
                    misfortunesHappen(numPlayers);
                }
                raiderAttack(milesTraveled);
                cout << endl;
                break;
                
            case 4: //game ends
                cout << "It is sad that you had to cut your trip short." << endl;
                return 0;
            default:
                cout << "Invalid input. Please try again." << endl;
            
        }
        cout << "Date: " << date.getMonth() << " " << date.getDay() << " 1847" << endl;
        cout << "Miles traveled: " << milesTraveled << endl;
        // cout << "Distance until next milestone: " << endl;
        cout << "Food available: " << supplies.getNumFood() << endl;
        cout << "Number of bullets availalbe: " << supplies.getNumAmmo() << endl;
        cout << "Cash available: $" << numMoney << endl << endl;
        cout << "You can choose to rest, continue, hunt, or quit." << endl;
        cout << "1: Rest" << endl;
        cout << "2: Continue on trail" << endl;
        cout << "3: Hunt" << endl;
        cout << "4: Quit" << endl;
        getline(cin, choice);
    }
}

void Gameplay::rest(int numPlayers, int days)
{
    for (int i = 0; i < numPlayers; i++) //run the food eaten function for the number of players there are
    {
        supplies.foodEaten(3);
    }
    if (supplies.getNumFood() < 0) //if there is less than 0lbs of food
    {
        supplies.setNumFood(0); //set pounds of food to 0
    }
    cout << "There is " << supplies.getNumFood() * days << " lbs of food left in your wagon." << endl;
    date.setDay(date.getDay() + days); //change days after resting
}

int Gameplay::continueTrail()
{
    srand(time(0));
    int num = 0;
    int counter = 0; 
    int counter2 = 1;
    
    int restDays = randomNumbers2(1,3);
    
    for (int i = 0; i < numPlayers; i++) //run funtion for number of players there are in the party
    {
        supplies.setNumFood(supplies.getNumFood() - (supplies.foodEaten(3) * 14));  //lbs of food eaten per day are three * 14 days
    }
    if (supplies.getNumFood() < 0)
    {
        supplies.setNumFood(0);
    }
    
    num = randomNumbers2(70,140); //num = random number of miles traveled
    milesTraveled = milesTraveled + num; //miles traveled equals previous number + new number
    if (milesTraveled >= rivers[counter].getRiverMiles() && milesTraveled <= rivers[counter2].getRiverMiles()) //if party is between river and river
    {
        reachedRiver(num, counter); 
        milesTraveled = rivers[counter].getRiverMiles() + milesTraveled;
    }
    else if (milesTraveled >= rivers[counter].getRiverMiles() && milesTraveled <= forts[counter2].getFortMiles()) //if party is between river and fort
    {
       reachedRiver(num, counter);
       milesTraveled = rivers[counter].getRiverMiles() + milesTraveled;
    }
    else if (milesTraveled >= forts[counter].getFortMiles() && milesTraveled <= forts[counter2].getFortMiles()) //if party is between fort and fort
    {
        reachedFort(num, counter);
        milesTraveled = forts[counter].getFortMiles() + milesTraveled;
    }
    else if (milesTraveled >= forts[counter].getFortMiles() && milesTraveled <= rivers[counter2].getRiverMiles()) //if party is between fort and river
    {
        reachedFort(num, counter);
        milesTraveled = forts[counter].getFortMiles() + milesTraveled;
    }
    else if (milesTraveled >= 2040) //if miles traveled is equal to or more than 2040, which is the landmark where Oregon City is
    {
        milesTraveled = 2040;
        cout << "Congratulations! You made it to Oregon City! You win!" << endl; //person wins the game
        return 0;
    }
    counter++; //increase first counter each time
    counter2++; //increase 2nd counter each time
    cout << "You have traveled " << milesTraveled << " miles" << endl; //cout miles traveled
    
    cout << "You have " << supplies.getNumFood() << " lbs of food left in your wagon." << endl; //cout lbs of food left
    date.setDay(date.getDay() + 14); //set days
    if (date.getMonth() >= 11 && date.getDay() >= 30 && milesTraveled < 2040) //if the day is 11/30/1847
    {
        cout << "You did not make it to Oregon City by 11/30/1847." << endl;
        cout << "GAME OVER" << endl;
        return 0;
    }
    return milesTraveled;
}

int Gameplay::hunt()
{
    srand(time(0));
    bool encountered = false;
    bool correct = false;
    int foodLost = 0;
    int turn = 0;
    int num = 0;
    int guess;
    int answer;
    int rabbit = randomNumbers2(1,10);
    int fox = randomNumbers2(1,8);
    int deer = randomNumbers2(1,100);
    int bear = randomNumbers2(1,100);
    int moose = randomNumbers2(1,100);
    if (rabbit >= 1 && rabbit <= 5) //50% chance of running into a rabbit
    {
        cout << "You got lucky! You encountered a rabbit! Do you want to hunt?: Press '1' for Yes or '2' for No." << endl;;
        cin >> answer;
        if (answer == 1)
        {
            
            if (supplies.getNumAmmo() >= 10) //if the number of bullets are equalt to or more than 10
            {
                while (correct == false || turn <= 3) //loop for the player to guess the puzzle 3 times
                {
                    cout << "Guess a number between 1 and 10";
                    cin >> guess;
                    num = randomNumbers2(1,10);
                    if (guess == num) //if guess is equal to random number
                    {
                        correct = true; //player won the puzzle
                        numBullets = numBullets - 10; //player loses 10 bullets
                        supplies.setNumAmmo(numBullets);
                        supplies.setNumFood(supplies.getNumFood() + 2); //player gains 2lbs of food
                        encountered = true;
                        if (supplies.getNumFood() > 1000) //if there is more than 1000lbs of food on the wagon
                        {
                            foodLost = supplies.getNumFood() - 1000;
                            supplies.setNumFood(1000 - foodLost);
                            cout << "Unfortunately your party had to leave behind " << foodLost << " lbs of food behind." << endl;
                        }
                    }
                    turn++;
                }
            }
            else
            {
                cout << "You cannot hunt without the appropriate amount of bullets" << endl;
            }
        }
    }
    if (fox == 1 || fox == 2) //25% chance of encountering a fox
    {
        cout << "You got lucky! You encountered a fox! Do you want to hunt?: Press '1' for Yes and '2' for No." << endl;;
        cin >> answer;
        if (answer == 1)
        {
            
            if (supplies.getNumAmmo() >= 10)
            {
                while (correct == false || turn <= 3)
                {
                    cout << "Guess a number between 1 and 10";
                    cin >> guess;
                    num = randomNumbers2(1,10);
                    if (guess == num)
                    {
                        correct = true;
                        numBullets = numBullets - 8; //player loses 8 bullets when hunting the fox
                        supplies.setNumAmmo(numBullets);
                        supplies.setNumFood(supplies.getNumFood() + 5); //player gains 5lbs of food
                        if (supplies.getNumFood() > 1000)
                        {
                            foodLost = supplies.getNumFood() - 1000;
                            supplies.setNumFood(1000 - foodLost);
                            cout << "Unfortunately your party had to leave behind " << foodLost << " lbs of food behind." << endl;
                        }
                        encountered = true;
                    }
                    turn++;
                }
            }
            else
            {
                cout << "You cannot hunt without the appropriate amount of bullets" << endl;
            }
        }
    }
    if (deer >= 1 && deer <= 15) //15% chance of encountering a deer
    {
        cout << "You got lucky! You encountered a deer! Do you want to hunt?: Press '1' for Yes and '2' for No." << endl;;
        cin >> answer;
        if (answer == 1)
        {
            
            if (supplies.getNumAmmo() >= 10)
            {
                while (correct == false || turn <= 3)
                {
                    cout << "Guess a number between 1 and 10";
                    cin >> guess;
                    num = randomNumbers2(1,10);
                    if (guess == num)
                    {
                        correct = true;
                        numBullets = numBullets - 5; //loses 5 bullets for hunting deer
                        supplies.setNumAmmo(numBullets);
                        supplies.setNumFood(supplies.getNumFood() + randomNumbers2(30,55)); //get anywhere between 30 and 55 lbs of food from deer
                        encountered = true;
                        if (supplies.getNumFood() > 1000)
                        {
                            foodLost = supplies.getNumFood() - 1000;
                            supplies.setNumFood(1000 - foodLost);
                            cout << "Unfortunately your party had to leave behind " << foodLost << " lbs of food behind." << endl;
                        }
                    }
                    turn++;
                }
            }
            else
            {
                cout << "You cannot hunt without the appropriate amount of bullets" << endl;
            }
        }
    }
    if (bear >= 1 && bear <= 7) //7% chance of encountering a bear
    {
        cout << "You got lucky! You encountered a bear! Do you want to hunt?: Press '1' for Yes and '2' for No" << endl;
        cin >> answer;
        if (answer == 1)
        {
            
            if (supplies.getNumAmmo() >= 10)
            {
                while (correct == false || turn <= 3)
                {
                    cout << "Guess a number between 1 and 10";
                    cin >> guess;
                    num = randomNumbers2(1,10);
                    if (guess == num)
                    {
                        correct = true;
                        numBullets = numBullets - 10; //loses 10 bullets for hunting bear
                        supplies.setNumAmmo(numBullets);
                        supplies.setNumFood(supplies.getNumFood() + randomNumbers2(100,350)); //gets 100 - 350lbs of food from bear
                        encountered = true;
                        if (supplies.getNumFood() > 1000)
                        {
                            foodLost = supplies.getNumFood() - 1000;
                            supplies.setNumFood(1000 - foodLost);
                            cout << "Unfortunately your party had to leave behind " << foodLost << " lbs of food behind." << endl;
                        }
                    }
                    turn++;
                }
            }
            else
            {
                cout << "You cannot hunt without the appropriate amount of bullets" << endl;
            }
        }
    }
    if (moose >= 1 && moose <= 5) //5% chance of encountering moose
    {
        cout << "You got lucky! You encountered a moose! Do you want to hunt?: Press '1' for Yes and '2' for No." << endl;
        cin >> answer;
        if (answer == 1)
        {
            
            if (supplies.getNumAmmo() >= 10)
            {
                while (correct == false || turn <= 3)
                {
                    cout << "Guess a number between 1 and 10";
                    cin >> guess;
                    num = randomNumbers2(1,10);
                    if (guess == num)
                    {
                        correct = true;
                        numBullets = numBullets - 12; //loses 12 bullets from hunting moose
                        supplies.setNumAmmo(numBullets);
                        if (supplies.getNumAmmo() < 0)
                        {
                            supplies.setNumAmmo(0);
                        }
                        supplies.setNumFood(supplies.getNumFood() + randomNumbers2(300,600)); //gets 300-600lbs of food from moose
                        encountered = true;
                        if (supplies.getNumFood() > 1000)
                        {
                            foodLost = supplies.getNumFood() - 1000;
                            supplies.setNumFood(1000 - foodLost);
                            cout << "Unfortunately your party had to leave behind " << foodLost << " lbs of food behind." << endl;
                        }
                    }
                    turn++;
                }
            }
            else
            {
                cout << "You cannot hunt without the appropriate amount of bullets" << endl;
            }
        }
    }
    if (encountered == true) //if the party went hunting
    {
        cout << "How well would you like the party to eat tonight?" << endl;
        cout << "(1)Poorly: 2lbs of food per person" << endl;
        cout << "(2)Moderately: 3lbs of food per person" << endl;
        cout << "(3)Well: 5lbs of food per person" << endl;
        cin >> answer;
        if (answer == 1)
        {
            supplies.foodEaten(2);
        }
        else if (answer == 2)
        {
            supplies.foodEaten(3);
        }
        else if (answer == 3)
        {
            supplies.foodEaten(5);
        }
        else
        {
            cout << "Invalid input. Please try again." << endl;
            cin >> answer;
        }
    }
    return encountered;
}

int Gameplay::misfortunesHappen(int numPlayers)
{
    srand(time(0));
    int misfortune = randomNumbers2(1,3); //3 types of misfortunes can happen
    int playerIndex = randomNumbers2(0, numPlayers - 1); //start at the first index and end at the last index
    switch(misfortune)
    {
        case 1:
            misfortuneDiseases(playerIndex); //player will become sick
            break;
        case 2:
            supplies.setNumOxen(supplies.getNumOxen() - 1); //loses oxen
            cout << "Oh no! One of your oxen died! You have " << supplies.getNumOxen() << " left" << endl;
            if (supplies.getNumOxen() <= 0)
            {
                cout << " You have no more oxen. You are unable to continue your journey." << endl;
                return 0;
            }
            break;
        case 3: //loses wagon part
            cout << "Oh no! One of your wagon parts is broken!" << endl; 
            if (supplies.getNumWagonParts() > 0)
            {
                supplies.setNumWagonParts(supplies.getNumWagonParts() - 1);
            }
            else if (supplies.getNumWagonParts() <= 0)
            {
                cout << "You have no more wagon parts. You are unable to continue your journey." << endl;
                return 0;
            }
            break;
        default:
            cout << "Invalid input" << endl;
    }
    return misfortune;
}

int Gameplay::misfortuneDiseases (int player)
{
    srand(time(0));
    int diseases = randomNumbers2(1,6);
    int deathChance = randomNumbers2(1,100);
    string answer;
    bool valid = false;
    if (players[player].getAlive() == true) //if that player is alive
    {
        switch(diseases)
        {
            case 1:
                cout << "Oh no!" << players[player].getUsername() << " has typhoid!" << endl;
                if (supplies.getNumMedKits() > 1) //if player has a medical kit
                {
                    supplies.setNumMedKits(supplies.getNumMedKits() - 1);
                    if (deathChance >= 1 && deathChance <= 50) //player has a 50% chance of living
                    {
                        players[player].setAlive (false); //player is dead
                        cout << "Oh no!" << players[player].getUsername() << " died of typhoid!" << endl;
                        numPlayers--; //lose a player
                    }
                }
                else
                {
                    while (answer != "1" || answer != "2") //while input is invalid
                    {
                        cout << "You do not have a medical kit. You can either choose to: (1) Rest, (2) Press on!" << endl;
                        getline(cin,answer);
                    }
                        switch(stoi(answer))
                        {
                            case 1:
                                rest(numPlayers, 3);
                                if (deathChance >= 1 && deathChance <= 30) //player has a 30% chance of dying
                                {
                                    players[player].setAlive(false); //player is dead
                                    cout << "Oh no!" << players[player].getUsername() << " died of typhoid!" << endl;
                                    numPlayers--; //lose a player
                                }
                                break;
                            case 2:
                                if (deathChance >= 1 && deathChance <= 70) //player has a 70% chance of dying
                                {
                                    players[player].setAlive(false); //player is dead
                                    cout << "Oh no!" << players[player].getUsername() << " died of typhoid!" << endl;
                                    numPlayers--;
                                } 
                                break;
                            default:
                                cout << "Invalid input. Please enter '1' to Rest or '2' to Press On." << endl;
                        }
                }
                break;
            case 2:
                cout << "Oh no!" << players[player].getUsername() << " has cholera!" << endl;
                if (supplies.getNumMedKits() > 1) //if player has a med kit
                {
                    supplies.setNumMedKits(supplies.getNumMedKits() - 1); //use it
                    if (deathChance >= 1 && deathChance <= 50) //player has a 50% chance of dying
                    {
                        players[player].setAlive (false); //player is dead
                        cout << "Oh no!" << players[player].getUsername() << " died of cholera!" << endl;
                        numPlayers--; //lose one player
                    }
                }
                else
                {
                    while (answer != "1" || answer != "2") //while input is invalid
                    {
                        cout << "You do not have a medical kit. You can either choose to: (1) Rest, (2) Press on!" << endl;
                        getline(cin,answer);
                    }
                        switch(stoi(answer))
                        {
                            case 1:
                                rest(numPlayers, 3);
                                if (deathChance >= 1 && deathChance <= 30) //player has a 30% chance of dying
                                {
                                    players[player].setAlive(false); //player is dead
                                    cout << "Oh no!" << players[player].getUsername() << " died of cholera!" << endl;
                                    numPlayers--; //lose a player
                                }
                                break;
                            case 2:
                                if (deathChance >= 1 && deathChance <= 70) //player has a 70% chance of dying
                                {
                                    players[player].setAlive(false); //player is dead
                                    cout << "Oh no!" << players[player].getUsername() << " died of cholera!" << endl;
                                    numPlayers--; //lose a player
                                }
                                break;
                            default:
                                cout << "Invalid input. Please enter '1' to Rest or '2' to Press On." << endl;
                        }
                }
                break;
            case 3:
                cout << "Oh no!" << players[player].getUsername() << " has diarrhea!" << endl;
                if (supplies.getNumMedKits() > 1)
                {
                    supplies.setNumMedKits(supplies.getNumMedKits() - 1);
                    if (deathChance >= 1 && deathChance <= 50)
                    {
                        players[player].setAlive (false);
                        cout << "Oh no!" << players[player].getUsername() << " died of diarrhea!" << endl;
                        numPlayers--;
                    }
                }
                else
                {
                    while (answer != "1" || answer != "2") //while input is invalid
                    {
                        cout << "You do not have a medical kit. You can either choose to: (1) Rest, (2) Press on!" << endl;
                        getline(cin,answer);
                    }
                        switch(stoi(answer))
                        {
                            case 1:
                                rest(numPlayers, 3);
                                if (deathChance >= 1 && deathChance <= 30)
                                {
                                    players[player].setAlive(false);
                                    cout << "Oh no!" << players[player].getUsername() << " died of diarrhea!" << endl;
                                    numPlayers--;
                                 }
                                break;
                            case 2:
                                if (deathChance >= 1 && deathChance <= 70)
                                {
                                    players[player].setAlive(false);
                                    cout << "Oh no!" << players[player].getUsername() << " died of diarrhea!" << endl;
                                    numPlayers--;
                                }
                                break;
                            default:
                                cout << "Invalid input" << endl;
                        }
                }
                break;
            case 4:
                cout << "Oh no!" << players[player].getUsername() << " has the measles!" << endl;
                if (supplies.getNumMedKits() > 1)
                {
                    supplies.setNumMedKits(supplies.getNumMedKits() - 1);
                    if (deathChance >= 1 && deathChance <= 50)
                    {
                        players[player].setAlive (false);
                        cout << "Oh no!" << players[player].getUsername() << " died of the measles!" << endl;
                        numPlayers--;
                    }
                }
                else
                {
                    while (answer != "1" || answer != "2") //while input is invalid
                    {
                        cout << "You do not have a medical kit. You can either choose to: (1) Rest, (2) Press on!" << endl;
                        getline(cin,answer);
                    }
                        switch(stoi(answer))
                        {
                            case 1:
                                rest(numPlayers, 3);
                                if (deathChance >= 1 && deathChance <= 30)
                                {
                                    players[player].setAlive(false);
                                    cout << "Oh no!" << players[player].getUsername() << " died of the measles!" << endl;
                                    numPlayers--;
                                }
                                break;
                            case 2:
                                if (deathChance >= 1 && deathChance <= 70)
                                {
                                    players[player].setAlive(false);
                                    cout << "Oh no!" << players[player].getUsername() << " died of the measles!" << endl;
                                    numPlayers--;
                                }
                                break;
                            default:
                                cout << "Invalid input. Please enter '1' to Rest or '2' to Press On." << endl;
                        }
                }
                break;
            case 5:
                cout << "Oh no!" << players[player].getUsername() << " has dysentery!" << endl;
                if (supplies.getNumMedKits() > 1)
                {
                    supplies.setNumMedKits(supplies.getNumMedKits() - 1);
                    if (deathChance >= 1 && deathChance <= 50)
                    {
                        players[player].setAlive (false);
                        cout << "Oh no!" << players[player].getUsername() << " died of dysentery!" << endl;
                        numPlayers--;
                    }
                }
                else
                {
                    while (answer != "1" || answer != "2") //while input is invalid
                    {
                        cout << "You do not have a medical kit. You can either choose to: (1) Rest, (2) Press on!" << endl;
                        getline(cin,answer);
                    }
                        switch(stoi(answer))
                        {
                            case 1:
                                rest(numPlayers, 3);
                                if (deathChance >= 1 && deathChance <= 30)
                                {
                                    players[player].setAlive(false);
                                    cout << "Oh no!" << players[player].getUsername() << " died of dysentery!" << endl;
                                    numPlayers--;
                                }
                                break;
                            case 2:
                                if (deathChance >= 1 && deathChance <= 70)
                                {
                                    players[player].setAlive(false);
                                    cout << "Oh no!" << players[player].getUsername() << " died of dysentery!" << endl;
                                    numPlayers--;
                                }
                                break;
                            default:
                                cout << "Invalid input. Please enter '1' to Rest or '2' to Press On." << endl;
                        }
                }
                break;
            case 6:
                cout << "Oh no!" << players[player].getUsername() << " has a fever!" << endl;
                if (supplies.getNumMedKits() > 1)
                {
                    supplies.setNumMedKits(supplies.getNumMedKits() - 1);
                    if (deathChance >= 1 && deathChance <= 50)
                    {
                        players[player].setAlive (false);
                        cout << "Oh no!" << players[player].getUsername() << " died of a fever!" << endl;
                        numPlayers--;
                    }
                }
                else
                {
                    while (answer != "1" || answer != "2") //while input is invalid
                    {
                        cout << "You do not have a medical kit. You can either choose to: (1) Rest, (2) Press on!" << endl;
                        getline(cin,answer);
                    }
                        switch(stoi(answer))
                        {
                            case 1:
                                rest(numPlayers, 3);
                                if (deathChance >= 1 && deathChance <= 30)
                                {
                                    players[player].setAlive(false);
                                    cout << "Oh no!" << players[player].getUsername() << " died of a fever!" << endl;
                                    numPlayers--;
                                 }
                                break;
                            case 2:
                                if (deathChance >= 1 && deathChance <= 70)
                                {
                                    players[player].setAlive(false);
                                    cout << "Oh no!" << players[player].getUsername() << " died of a fever!" << endl;
                                    numPlayers--;
                                }
                                break;
                            default:
                                cout << "Invalid input. Please enter '1' to Rest or '2' to Press On." << endl;
                        }
                }
                break;
            default:
                cout << "Invalid input" << endl;
            
        }
        if (players[0].getAlive() == false) //if the first player dies
        {
            cout << "GAME OVER" << endl;
            return 0;
        }
    }
    return diseases;
}

double Gameplay::raiderAttack(int milesTraveled)
{
    srand(time(0));
    string choice;
    int attack = randomNumbers2(1,100);
    int win = randomNumbers2(1,10);
    bool correct = false;
    int turn = 0;
    int guess = 0;
    int num = 0;
    int foodLost = 0;
    double attackProbability = (((((pow(((milesTraveled/100) - 4), 2)) + 72)/((pow(((milesTraveled/100) - 4), 2)) + 12)) - 1)/10) * 100; //probability equation for raider attack
    if (attack >= 1 && attack <= attackProbability)
    {
        while (!(choice >= "1" && choice <= "3"))
        {
            cout << "Riders ahead! They look hostile!" << endl;
            cout << "You have three choices. Press '1' to run, '2' to attack, or '3' to surrender" << endl;
            getline(cin,choice);
        }
        switch(stoi(choice))
        {
            case 1:
                cout << "All living members are still alive, but in order to flee the raiders, you had to leave behind one ox, 10lbs of food, and 1 wagon part." << endl;
                supplies.setNumOxen(supplies.getNumOxen() - 1); //lose an ox
                supplies.setNumFood(supplies.getNumFood() - 10); //lose 10lbs of food
                if (supplies.getNumOxen() <= 0)
                {
                    cout << "GAME OVER" << endl; //game ends if player has no more oxen
                    return 0;
                }
                else if (supplies.getNumFood() <= 0)
                {
                    cout << "GAME OVER" << endl; //game ends if player has no more food left
                    return 0;
                }
                break;
            case 2:
                cout << "In order to win the battle, you must solve the puzzle." << endl;
                while (correct == false || turn < 3)
                {
                    cout << "Guess a number between 1 and 10";
                    cin >> guess;
                    num = randomNumbers2(1,10);
                    if (guess == win) //if the puzzle was won
                    {
                        correct = true; //puzzle was solved
                        supplies.setNumFood(supplies.getNumFood() + 50); //player gains 50lbs of food
                        supplies.setNumAmmo(supplies.getNumAmmo() + 50); //player gains 50 bullets
                        cout << "You have gained 50lbs of food and 50 bullets." << endl;
                        if (supplies.getNumFood() > 1000) //if player has more than 1000lbs of food
                        {
                            foodLost = supplies.getNumFood() - 1000; //calculate food lost
                            supplies.setNumFood(1000 - foodLost);
                            cout << "Unfortunately your party had to leave behind " << foodLost << " lbs of food behind." << endl;
                        }
                    }
                    else if (guess != win && turn >= 3) //if the puzzle wasn't solved
                    {
                        numMoney = numMoney - (numMoney * 0.25); //lose a quarter of cash reserves
                        supplies.setNumAmmo(supplies.getNumAmmo() - 50); //lose 50 bullets
                        cout << "You lost a quarter of your cash reserves and 50 bullets." << endl;
                    }
                    turn++;
                }
                break;
            case 3:
                cout << "Because you surrendered, you lost a quarter of your cash reserves." << endl;
                numMoney = numMoney - (numMoney * 0.25); //player loses a quarter of cash reserves
                break;
            default:
                cout << "Invalid input" << endl;
                
        }
    }
    // takeTurns();
    return attackProbability;
}

int Gameplay::milestonesForts(string fileForts) //reads into the fort milestones text
{
    ifstream myfile; //read file
    myfile.open(fileForts); //open file
    if (myfile.fail()) //if file failed to open
    {
        return -1;
    }
    
    int FortCounter = 0;
    string line = "";
    string Placeholder[6];
    while (getline(myfile,line))
    {
        split (line, ',', Placeholder,6);
        forts[FortCounter].setFortNames(Placeholder[0]); //set names at index 0
        forts[FortCounter].setFortMiles(stoi(Placeholder[1])); //set miles at index 1
        FortCounter++;
    }
    return FortCounter;
}

int Gameplay::milestonesRivers(string fileRivers) //reads from river milestones txt
{
    ifstream myfile; //read file
    myfile.open(fileRivers); //open file
    if (myfile.fail()) //if file failed to open
    {
        return -1;
    }
    
    int RiverCounter = 0;
    string line = "";
    string Placeholder[4];
    while (getline(myfile, line))
    {
        split(line, ',', Placeholder,4); 
        rivers[RiverCounter].setRiverNames(Placeholder[0]); //set names at index 0
        rivers[RiverCounter].setRiverMiles(stoi(Placeholder[1])); //set miles at index 1
        rivers[RiverCounter].setRiverDepths(stoi(Placeholder[2])); //set depths at index 2
        RiverCounter++;
    }
   
    return RiverCounter;
}

int Gameplay::reachedFort (int num, int numFort)
{
    string choice, answer;
    bool store = false;
    bool valid = false;
    while (choice != "1" || choice != "2") //while choice is not valid
    {
        cout << "You were prepared to travel " << num << " miles, but you arrived at " << forts[numFort].getFortNames() << endl;
        cout << "You can either choose to: (1) Rest, (2) Visit Store" << endl;
        getline(cin,choice);
    }
        switch(stoi(choice))
        {
            case 1:
                while (valid == false) //while player is not through resting
                {
                    rest(numPlayers, 1);
                    while (answer != "1" || answer != "2") //while answer is not valid
                    {
                        cout << "Would you like to rest again? Press '1' for Yes and '2' for No." << endl;
                        getline(cin, answer);
                    }
                    if (answer == "2")
                    {
                        valid = true; //player is through resting
                    }
                }
                break;
                
            case 2:
                while (store == false)
                {
                    visitStore();
                    while (answer != "1" || answer != "2") //while answer is not valid
                    {
                        cout << "Would you like to visit the store again? Press '1' for Yes and '2' for No." << endl;
                        getline(cin, answer);
                    }
                        
                    if (answer == "2")
                    {
                        valid = true;
                    }
                }
                break;
            default:
                cout << "Invalid input." << endl;
        }
}

int Gameplay::reachedRiver(int num, int numRiver)
{
    string choice, answer;
    bool valid = false;
    int drown = randomNumbers2(1,10);
    while (choice != "1" || choice != "2") //while choice is not valid
    {
        cout << "You were prepared to travel " << num << " miles, but you arrived at " << rivers[numRiver].getRiverNames() << endl;
        cout << "You can either choose to: (1) Rest, (2) Cross River" << endl;
        getline(cin,choice);
    }
        switch(stoi(choice))
        {
            case 1:
                rest(numPlayers, 1);
                while (answer != "1" || answer != "2") //while answer is not valid
                {
                    cout << "Would you like to rest again? Press '1' for Yes and '2' for No." << endl;
                    getline(cin, answer);
                }
                if (answer == "2")
                {
                    valid = true;
                }
                break;
            case 2:
                valid = true;
                if (rivers[numRiver].getRiverDepths() > 3) //if river is more than 3ft deep
                {
                    cout << "This river is " << rivers[numRiver].getRiverDepths() << " ft deep." << endl;
                    cout << "This river requires a ferry for you to cross. The ferry is $10 per person." << endl;
                    if (numMoney < (10 * numPlayers)) //if player does not have enough money
                    {
                        while (answer != "1" || answer != "2") //while answer is not valid
                        {
                            cout << "It looks like you are out of money. Would you like to (1) Take a chance or (2) Quit Game?" << endl; //player has the option to cross river or quite game
                            getline(cin, answer);
                        }
                        switch(stoi(answer))
                        {
                            case 1:
                                if (drown >= 1 && drown <= 4) //player has a 40% chance of drowning
                                {
                                    cout << "You did not make it across the river unscathed. You lost 1 oxen." << endl; //if they drown, they lose one oxen
                                    supplies.setNumOxen(supplies.getNumOxen() - 1);
                                    if (supplies.getNumOxen() <= 0) //if oxen is 0 or less
                                    {
                                        cout << "You do not have anymore oxen to continue on this journey." << endl; //they lose the game
                                        cout << "GAME OVER" << endl;
                                        return 0;
                                    }
                                }
                            case 2:
                                cout << "It is unfortunate you had to cut your trip short." << endl;
                                cout << "GAME OVER" << endl;
                                return 0;
                            default:
                                cout << "Invalid input. Please try again." << endl;
                        }
                    }
                }
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                cin >> choice;
        }
    return numRiver;
}