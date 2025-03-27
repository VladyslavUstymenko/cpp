/* Завдання 2

Необхідно заповнити масив значеннями, які перетворять її в таблицю множення.

*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int matrix[10][10] = {};

    int* start = &matrix[0][0];
    int* end = start + 10 * 10;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int offset = i * 10 + j;
            *(start + offset) = (i + 1) * (j + 1);
        }
    }

    int count = 0;
    for (int* p = start; p < end; p++)
    {
        cout << setw(4) << *p;
        count++;

        if (count % 10 == 0)
        {
            cout << endl;
        }
    }
}