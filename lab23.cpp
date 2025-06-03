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

        if (rem == 0)
        {
            return to_string(whole);
        }

        if (whole == 0)
        {
            return (numerator < 0 ? "-" : "") + to_string(rem) + "/" + to_string(denominator);
        }

        return to_string(whole) + " " + to_string(rem) + "/" + to_string(denominator);
    }

    Fraction operator+(const Fraction& other) const

    {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const

    {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const

    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const

    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
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
        cout << "Denominator cannot be zero." << endl;
        exit(1);
    }

    return Fraction(num, den);
}

int main() 
{
    cout << "Enter first fraction: ";
    Fraction a = readFraction();
    cout << "You entered: " << a.toMixedString() << endl;

    cout << "Enter second fraction: ";
    Fraction b = readFraction();
    cout << "You entered: " << b.toMixedString() << endl;

    cout << endl << "Results:" << endl;
    cout << a.toMixedString() << " + " << b.toMixedString() << " = " << (a + b).toMixedString() << endl;
    cout << a.toMixedString() << " - " << b.toMixedString() << " = " << (a - b).toMixedString() << endl;
    cout << a.toMixedString() << " * " << b.toMixedString() << " = " << (a * b).toMixedString() << endl;
    cout << a.toMixedString() << " / " << b.toMixedString() << " = " << (a / b).toMixedString() << endl;
}