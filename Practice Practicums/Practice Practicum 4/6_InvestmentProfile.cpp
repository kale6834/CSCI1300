#include <iostream>
#include <string>
using namespace std;

#ifndef INVESTMENTPROFILE_H
#define INVESTMENTPROFILE_H
class InvestmentProfile
{
    public:
    InvestmentProfile();
    InvestmentProfile(string, float);
    void setCompanyName(string);
    string getCompanyName();
    void setSharesHeld(float);
    float getSharesHeld();
    string influence();
    
    private:
    string companyName;
    float sharesHeld;
};
#endif

InvestmentProfile::InvestmentProfile()
{
    companyName = "Company co.";
    sharesHeld = 100.0;
}

InvestmentProfile::InvestmentProfile(string x, float y)
{
    companyName = x;
    sharesHeld = y;
}

void InvestmentProfile::setCompanyName(string input)
{
    companyName = input;
}

string InvestmentProfile::getCompanyName()
{
    return companyName;
}

void InvestmentProfile::setSharesHeld(float input)
{
    sharesHeld = input;
}

float InvestmentProfile::getSharesHeld()
{
    return sharesHeld;
}

string InvestmentProfile::influence()
{
    if (sharesHeld < 50.0)
    {
        return "Minority Shareholder";
    }
    else if (sharesHeld >= 50 && sharesHeld < 100)
    {
        return "Majority Shareholder";
    }
    else if (sharesHeld >= 100)
    {
        return "Sole Shareholder";
    }
}