/*

Завдання 1

Задати одновимірний динамічний масив (кількість елементів виберіть на
власний розсуд). Заповнити масив випадковими значеннями з плаваючою
крапкою з діапазону (-2, 2). Знайти кількість додатних та від'ємних чисел.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    float* arr = new float[10];
    int count1 = 0, count2 = 0;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = (rand() % 401 - 200) / 1000.0;

    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";

        if (arr[i] > 0)
        {
            count1++;
        }
        else if (arr[i] < 0)
        {
            count2++;
        }
    }

    cout << endl;
    cout << "Positive numbers: " << count1 << endl;
    cout << "Negative numbers: " << count2 << endl;

    delete[] arr;
}