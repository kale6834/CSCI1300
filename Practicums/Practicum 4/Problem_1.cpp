class Inventory
{
    public:
    Inventory();
    Inventory(string);
    void InitDataMembers();
    bool AddItem(string, int, float);
    float CalcTotalCost();
    float getMaxCost();
    string getMaxQuantityItem();
    
    private:
    string inventoryLocation;
    int nItems;
    string Items[100];
    int ItemQuantity[100];
    float ItemCost[100];
};

