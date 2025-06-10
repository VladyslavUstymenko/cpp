/*
Завдання 3
Вставити блоки throw та try-catch замість логічного
значення та параметра res. створити дві
версії коду.

версія, що перехоплює виняток ділення на нуль */

#include <iostream>
#include <stdexcept>
using namespace std;

float internaldiv(float arg1, float arg2)
{
    if (arg2 == 0)
    {
        throw runtime_error("Your input is not valid. You can't divide by zero.");
    }
        
    return arg1 / arg2;
}

float div(float arg1, float arg2)
{
    return internaldiv(arg1, arg2);
}

int main()
{
    float a, b;

    while (cin >> a >> b)
    {
        try
        {
            float r = div(a, b);
            cout << r << endl;
        }
        catch (const runtime_error& e)
        {
            cout << "Are you kidding me?" << endl;
            cout << e.what() << endl;
        }
    }
}