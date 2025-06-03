/*

Доповніть код у зразку так, щоб отримати вказану відповідь. (25)
Функції increment — перевантажені, та виконують наступне:

1) При виклику з одним аргументом (змінною int) збільшує змінну на 1
2) При виклику з двома аргументами (змінною int і виразом int)
збільшує змінну на значення виразу.

*/

#include <iostream>
using namespace std;

void increment(int& a)
{
    a = a + 1;
}

void increment(int& a, int b)
{
    a = a + b;
}

int main(void)
{
    int var = 0;

    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
        {
            increment(var);
        }
        else
        {
            increment(var, i);
        }
    }
    cout << var << endl;
}