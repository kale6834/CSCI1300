#include <iostream>
#include <string>
using namespace std;

#ifndef CHILDGROWTH_H
#define CHILDGROWTH_H

class ChildGrowth
{
    public:
    ChildGrowth();
    ChildGrowth(string n);
    ChildGrowth(string n, int a);
    ChildGrowth(string n, int a, float h[], float w[]);
    void setHeight(float []);
    void setWeight(float w[]);
    float feetToMeter(float feet);
    float poundToKg(float pound);
    float calculateBmi(int age);
    string getCategory(int age);
    string getName();
    void setName(string n);
    int getCurrentAge();
    void setCurrentAge(int a);
    
    private:
    string name;
    int currentAge;
    float weightMetricConversion;
    float height[10];
    float weight[10];
};

#endif