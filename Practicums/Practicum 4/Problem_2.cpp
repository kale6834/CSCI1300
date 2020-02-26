class Shape
{
    public:
    Shape();
    Shape(string, int);
    void setName(string);
    string getName();
    void setSides(int);
    int getSides();
    string getShapeType();
    
    private:
    string name;
    int sides;
};

Shape::Shape()
{
    name = "";
    sides = 3;
}

Shape::Shape (string x, int y)
{
    name = x;
    sides = y;
}

void Shape::setName (string input)
{
    name = input;
}

string Shape::getName ()
{
    return name;
}

void Shape::setSides (int input)
{
    sides = input;
}

int Shape::getSides ()
{
    return sides;
}

string Shape::getShapeType()
{
    if (sides == 3)
    {
        return "Triangle";
    }
    else if (sides == 4)
    {
        return "Rectangle";
    }
    else if (sides == 5)
    {
        return "Pentagon";
    }
    else if (sides >= 6)
    {
        return "Polygon";
    }
}