/*

Знайдіть кількість днів, що пройшли від
вашого дня народження до поточної дати

*/

#include <iostream>
#include <ctime>
using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

bool isLeap(int year)
{
    if (year % 4 == 0)
    { 
        return true;
    }
    else
    {
        return false;
    }
}

int monthLength(int year, int month)
{
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    {
        return 31;
    }
    case 4: case 6: case 9: case 11:
    {
        return 30;
    }
    case 2:
    {
        if (isLeap(year) == true)
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

Date today()
{
    time_t t = time(NULL);
    tm tl;
    localtime_s(&tl, &t);

    Date now;
    now.year = tl.tm_year + 1900;
    now.month = tl.tm_mon + 1;
    now.day = tl.tm_mday;

    return now;
}


int daysBetween(Date from, Date to)
{
    int days = 0;

    while (from.year < to.year || from.month < to.month || from.day < to.day)
    {
        days++;
        from.day++;

        if (from.day > monthLength(from.year, from.month))
        {
            from.day = 1;
            from.month++;
        }

        if (from.month > 12)
        {
            from.month = 1;
            from.year++;
        }
    }

    return days;
}

int main()
{
    Date start = { 2025, 02, 1 };
    Date now = today();

    cout << "Number of days: " << daysBetween(start, now) << endl;
}