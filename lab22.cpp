/* Написати клас, що повинен забезпечувати текстове представлення
коректно відображати цілі частини, тобто 7 / 4 повинно відображатися як "1 3/4"
коректно відображати знак, тобто - 3 / 4 та 3 / -4 повинні відображатися як "-3/4"
надавати представлення у вигляді числа з плаваючою комою */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Fraction
{
public:
    Fraction(int numerator, int denominator)
    {
        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }

        this->numerator = numerator;
        this->denominator = denominator;
        simplify();
    }

    string toString()
    {
        int whole = numerator / denominator;
        int remainder = abs(numerator % denominator);
        string sign = (numerator < 0 && whole == 0) ? "-" : "";

        if (remainder == 0)
        {
            return to_string(whole);
        }

        else if (whole == 0)
        {
            return sign + to_string(remainder) + "/" + to_string(denominator);
        }

        else
        {
            return to_string(whole) + " " + to_string(remainder) + "/" + to_string(denominator);
        }
    }

    double toDouble()
    {
        return static_cast<double>(numerator) / denominator;
    }

private:

    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify()
    {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }
};

int main(void)
{
    string input;
    getline(cin, input);

    int num, den;
    char slash;
    stringstream ss(input);
    ss >> num >> slash >> den;

    if (den == 0)
    {
        cout << "Error: Denominator cannot be zero!" << endl;
        return 1;
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
}