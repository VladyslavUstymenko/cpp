/* Завдання 1

Необхідно знайти найменший елемент масиву не використовуючи
індексацію. Можна використовувати скільки завгодно вказівників.

*/

#include <iostream>
using namespace std;

int main(void)
{
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };

    int* begin = vector;
    int* end = begin + sizeof(vector) / sizeof(int);
    int n = end - begin;

    cout << "Array: ";
    for (int* p = begin; p < end; p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    int* ptr = begin;
    int min = *ptr;

    for (int* p = ptr + 1; p < ptr + n; p++)
    {
        if (*p < min)
        {
            min = *p;
        }
    }

    cout << "Minimal element: " << min << endl;
}