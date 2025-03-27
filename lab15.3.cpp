/*

Завдання

Написати функцію (ім’я функції monthLength), яка повертатиме довжину
кожного місяця в днях, яка прийматиме два аргументи – номер року (int) і
номер місяця (int) та повертатиме значення кількість днів у місяці (int).

Спосіб 2

*/

#include <iostream>
#include <vector>
using namespace std;

bool isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month)
{
    vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month < 1 || month > 12)
    {
        return 0;
    }

    if (month == 2 && isLeap(year))
    {
        return 29;
    }

    return days[month - 1];
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