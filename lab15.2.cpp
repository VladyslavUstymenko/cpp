/*

Завдання 

Написати функцію (ім’я функції monthLength), яка повертатиме довжину
кожного місяця в днях, яка прийматиме два аргументи – номер року (int) і
номер місяця (int) та повертатиме значення кількість днів у місяці (int).

Спосіб 1

*/

#include <iostream>
using namespace std;

bool isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        return 31;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        return 30;
    }
    case 2:
    {
        if (isLeap(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    default:
    {
        return 0;
    }
    }
}

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;

    for (int mo = 1; mo <= 12; mo++)
    {
        cout << monthLength(year, mo) << " ";
    }
    cout << endl;
}