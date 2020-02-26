#include <iostream>
#include <string>
using namespace std;

// class Building
// {
// public:
//   Building();
//   void set_height(double count);
//   void get_data() const;
 
// private:
//   double height;
// };
// Building::Building() 
// {
//   cout << "Constructor" << endl;
// }
// void Building::get_data() const
// {
//   cout << height << endl;
// }
// void Building::set_height(double count)
// {
//   height = count;
// }
// int main()
// {
//   Building blg1;
//   Building blg2;
//   blg1.set_height(10);
//   blg2.set_height(50);
//   blg1.get_data();
//   blg2.get_data();
//   return 0;
// }

// class CashRegister
// {
// public:
//   void set_item_count(int count);
 
// private:
//   int item_count;
// };
// void CashRegister::set_item_count(int count)
// {
//   item_count = count;
// }
// int main()
// {
//   CashRegister reg1;
//   reg1.set_item_count(15);
//   cout << "Item count: " << reg1.item_count;
//   return 0;
// }

// class Car
// {
// public:
//   double get_speed() const;
 
//   Car();
//   Car(double dspeed);
 
// private:
//   double speed;
// };
// Car::Car()
// {
//   speed = 0;
// }
// Car::Car(double dspeed)
// {
//   speed = dspeed;
// }
// double Car::get_speed() const
// {
//   return speed;
// }
// int main()
// {
//   Car c1;
//   Car c2(5);
//   double sum_speed = 0;
//   sum_speed = c1.get_speed() + c2.get_speed();
//   cout << sum_speed << endl;
//   return 0;
// }

class Month
{
public:
   int get_Month_num() const;
   string get_Month() const;
   Month(int);
private:
   int mon;
};
void main()
{
  Month m(3);
  cout << get_Month() << “ is #“ << get_Month_num() << endl;
  m.Month(4);
  cout << get_Month() << “ is #“ << get_Month_num() << endl;
}