/* Написати клас, що повинен забезпечувати текстове представлення
коректно відображати цілі частини, тобто 7 / 4 повинно відображатися як "1 3/4"
коректно відображати знак, тобто - 3 / 4 та 3 / -4 повинні відображатися як "-3/4"
надавати представлення у вигляді числа з плаваючою комою
користувач повинен мати можливість додавати, ділити, віднімати та ножити дроби
програма має скорочувати дроби до найпростішого вигляду */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Fraction
{
public:
    Fraction(int n = 0, int d = 1)
    {
        if (d < 0)
        {
            n = -n;
            d = -d;
        }
        numerator = n;
        denominator = d;
        simplify();
    }

    string toMixedString() const
    {
        int whole = numerator / denominator;
        int rem = abs(numerator % denominator);
        if (rem == 0) return to_string(whole);
        if (whole == 0) return (numerator < 0 ? "-" : "") + to_string(rem) + "/" + to_string(denominator);
        return to_string(whole) + " " + to_string(rem) + "/" + to_string(denominator);
    }

    double toDouble() const
    {
        return static_cast<double>(numerator) / denominator;
    }

    Fraction operator+(const Fraction& other) const
    {
        int n = numerator * other.denominator + other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction operator-(const Fraction& other) const
    {
        int n = numerator * other.denominator - other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator<(const Fraction& other) const
    {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const
    {
        return other < *this;
    }

    bool operator==(const Fraction& other) const
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

private:
    int numerator, denominator;

    int gcd(int a, int b) const
    {
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void simplify()
    {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }
};

Fraction readFraction()
{
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num, den;
    char slash;
    ss >> num >> slash >> den;
    if (den == 0)
    {
        cout << "Denominator cannot be zero. Exiting." << endl;
        exit(1);
    }
    return Fraction(num, den);
}

int main()
{
    cout << "Enter the first fraction (e.g. 7 / -4): ";
    Fraction a = readFraction();
    cout << "You entered: " << a.toMixedString() << endl;
    cout << "As decimal: " << a.toDouble() << endl;

    cout << "Enter the second fraction: ";
    Fraction b = readFraction();
    cout << "You entered: " << b.toMixedString() << endl;
    cout << "As decimal: " << b.toDouble() << endl;

    cout << endl << "Operations:" << endl;
    cout << a.toMixedString() << " + " << b.toMixedString() << " = " << (a + b).toMixedString() << " (" << (a + b).toDouble() << ")" << endl;
    cout << a.toMixedString() << " - " << b.toMixedString() << " = " << (a - b).toMixedString() << " (" << (a - b).toDouble() << ")" << endl;
    cout << a.toMixedString() << " * " << b.toMixedString() << " = " << (a * b).toMixedString() << " (" << (a * b).toDouble() << ")" << endl;
    cout << a.toMixedString() << " / " << b.toMixedString() << " = " << (a / b).toMixedString() << " (" << (a / b).toDouble() << ")" << endl;

    string sign;
    if (a < b) sign = "<";
    else if (a > b) sign = ">";
    else sign = "=";

    cout << endl << "Comparison: " << a.toMixedString() << " " << sign << " " << b.toMixedString() << endl;
}