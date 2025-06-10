/*
Завдання 1
Удосконити програму з прикладу, щоб вона виводила повідомлення,
коли користувач вводить недійсні дані. Додати код для ручного виклику
винятку, використовуючи ключове слово throw, коли користувач вводить 0. */

#include <iostream>
#include <stdexcept>
using namespace std;

int main(void)
{
    int a = 8, b = 0, c = 0;

    try
    {
        cout << "Enter a non-zero integer: ";
        if (!(cin >> b))
        {
            throw invalid_argument("Invalid input! Not an integer.");
        }

        if (b == 0)
        {
            throw runtime_error("Division by zero is not allowed!");
        }

        c = a / b;
        cout << "Result: " << c << endl;
    }
    catch (const invalid_argument& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const runtime_error& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "An unknown error occurred." << endl;
    }
}