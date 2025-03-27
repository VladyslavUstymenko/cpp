/*

Задайте двовимірний масив. Заповнити його випадковими значеннями. Виведіть
на екран, елементи, що знаходяться на головній діагоналі, побічній діагоналі,
кількість парних та непарних елементів масиву.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int rows = 5, cols = 5;

    srand(time(nullptr));

    int** array = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        *(array + i) = new int[cols];
    }

    cout << "Generated matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(array + i) + j) = rand() % 100;
            cout.width(4);
            cout << *(*(array + i) + j);
        }
        cout << endl;
    }

    cout << "Main diagonale elements: " << endl;
    for (int i = 0; i < rows && i < cols; i++)
    {
        cout << *(*(array + i) + i) << " ";
    }
    cout << endl;

    cout << "Side diagonale elements: " << endl;
    for (int i = 0; i < rows && i < cols; i++)
    {
        cout << *(*(array + i) + (cols - 1 - i)) << " ";
    }
    cout << endl;

    int count1 = 0, count2 = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (*(*(array + i) + j) % 2 == 0)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
    }

    cout << "Pair elements number: " << count1 << endl;
    cout << "Odd elements number: " << count2 << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] * (array + i);
    }

    delete[] array;
}