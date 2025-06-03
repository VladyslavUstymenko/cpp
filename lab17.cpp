﻿// Завдання 1

/*

Напишіть функцію, яка перевіряє,
чи є введене число простим, чи ні.

*/

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num))
    {
        cout << num << " is a simple number" << endl;
    }
    else
    {
        cout << num << " is not a simple number" << endl;
    }
}