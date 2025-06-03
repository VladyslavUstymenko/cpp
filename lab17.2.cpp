// Завдання 2

/*

Виведіть всі прості числа від 0 і до 21.
Для розв’язання задачі скористайтесь
зразком та функцією, описаною у задачі 1.

*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    for (int i = 0; i <= 21; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}