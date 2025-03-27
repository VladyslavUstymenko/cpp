/*

Завдання 1

Необхідно описати функцію
(тіло функції) таким чином, щоб функція повертала у програму значення true,
якщо введений рік високосний, або false, якщо введено не високосний рік.

*/

#include <iostream>
using namespace std;

bool isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

int main(void)
{
    int year;

    cout << "Enter a year: ";
    cin >> year;

    cout << year << " -> " << isLeap(year) << endl;
}