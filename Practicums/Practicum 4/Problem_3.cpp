class Country
{
    public:
    Country();
    int LoadCountry(string);
    int SearchForCountry(string);
    string GetCapital(string);
    
    private:
    string countries[50];
    string capitals[50];
    int counter;
};

Country::Country()
{
    for (int i = 0; i < 50; i++)
    {
        countries[i] = "";
        capitals[i] = "";
    }
    counter = 0;
}

int Country::LoadCountry(string filename)
{
    ifstream myfile;
    myfile.open(filename);
    string line;
    if (myfile.fail())
    {
        return -1;
    }
    else
    {
        while (getline(myfile, line, ','))
        {
            countries[counter] = line;
            getline(myfile, line);
            capitals[counter] = line;
            counter++;
        }
        return 0;
    }
}

int Country::SearchForCountry(string country)
{
    int index = -1;
    for (int i = 0; i < counter; i++)
    {
        if (country == countries[i])
        {
            index = i;
        }
    }
    return index;
}

string Country::GetCapital(string country)
{
    string found = "";
    for (int i = 0; i < counter; i++)
    {
        if (country == countries[i])
        {
            found = capitals[i];
        }
    }
    return found;
}