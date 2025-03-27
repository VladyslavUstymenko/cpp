/*

Завдання 2

Задайте двовимірний динамічний масив цілих чисел розмірністю 3х3 (кількість
елементів виберіть на власний розсуд). Заповнити його випадковими
значеннями. Виведіть на екран, елементи, що знаходяться на головній діагоналі,
побічній діагоналі, кількість парних та непарних елементів масиву.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int** arr = new int* [3];

    for (int i = 0; i < 3; i++)
    {
        arr[i] = new int[3];
    }

    int count1 = 0, count2 = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = rand() % 10;

            if (arr[i][j] % 2 == 0)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
    }

    cout << "Array elements:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Main diagonal elements: ";
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i][i] << " ";
    }
    cout << endl;

    cout << "Secondary diagonal elements: ";
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i][2 - i] << " ";
    }
    cout << endl;

    cout << "Pair numbers: " << count1 << endl;
    cout << "Odd numbers: " << count2 << endl;

    for (int i = 0; i < 3; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}