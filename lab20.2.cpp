// Завдання 2

// Виправити помилки і додати метод set.

#include <iostream>
using namespace std;

class Square
{
public:
    Square(double side);
    void set(double side);
    double getSide() const;
    double getArea() const;

private:
    double side;
    double area;
    void updateArea();
};

Square::Square(double side)
{
    set(side);
}

void Square::set(double side)
{
    cout << "Input side: " << side << endl;

    if (side < 0)
    {
        cout << "Side cannot be negative." << endl;
        this->side = 0;
    }
    else
    {
        this->side = side;
    }
    updateArea();
}

double Square::getSide() const
{
    return side;
}

double Square::getArea() const
{
    return area;
}

void Square::updateArea()
{
    area = side * side;
}

void print(const Square& square)
{
    cout << "Area = " << square.getArea() << endl;
}

int main()
{
    Square s(4);
    print(s);

    s.set(2.0);
    print(s);

    s.set(-33.0);
    print(s);
}