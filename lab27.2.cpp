/*
Завдання 2
Вставити блок try-catch у цю програму, щоб вирішити потенційні
проблеми з арифметичними операціями. */

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;

    try
    {
        if (!(cin >> a))
        {
            throw runtime_error("Your input is not valid, you must enter integers.");
        }

        if (!(cin >> b))
        {
            throw runtime_error("Your input is not valid, you must enter integers.");
        }

        if (b == 0)
        {
            throw runtime_error("Your input is not valid, you can't divide by zero.");
        }

        c = a / b;
        cout << c << endl;
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
    }

}