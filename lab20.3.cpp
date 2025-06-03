// Завдання 3

// Доробити 2 нових методи - get_aria i changet

#include <iostream>
using namespace std;

class AdHocSquare
{
public:
    AdHocSquare(double side) : side(side) {}

    void set_side(double side)
    {
        this->side = side;
    }

    double get_area()
    {
        return side * side;
    }

private:
    double side;
};

class LazySquare
{
public:
    LazySquare(double side) : side(side), area(side* side), side_changed(false) {}

    void set_side(double side)
    {
        if (this->side != side)
        {
            this->side = side;
            side_changed = true;
        }
    }

    double get_area()
    {
        if (side_changed)
        {
            area = side * side;
            side_changed = false;
        }
        return area;
    }

    bool changet()
    {
        return side_changed;
    }

private:
    double side;
    double area;
    bool side_changed;
};

int main()
{
    AdHocSquare adhoc(4.0);
    cout << "AdHocSquare - Side: 4.0, Square: " << adhoc.get_area() << endl;

    LazySquare lazy(5.0);
    cout << "LazySquare - First side: 5.0" << endl;
    cout << "LazySquare - Current square: " << lazy.get_area() << endl;

    lazy.set_side(7.0);

    if (lazy.changet())
        cout << "LazySquare - Side turned to 7, square not changed yet." << endl;
    else
        cout << "LazySquare - Square is renewed." << endl;

    cout << "LazySquare - New square: " << lazy.get_area() << endl;

    if (lazy.changet())
        cout << "LazySquare - Side was changed." << endl;
    else
        cout << "LazySquare - Square is renewed after last update" << endl;
}