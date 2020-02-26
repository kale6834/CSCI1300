#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Book.h"
#include "User.h"

int main(){
    User user1 = User();
    cout << user1.getNumRatings() << endl;
}