/* Написати чотири класи для реалізації друку різних видів дерев. Один із класів є базовим для трьох інших.
У базовому класі слід створити метод малювання – це єдиний метод цього класу, і це віртуальний метод.
у похідних класах, реалізувати цей метод з трьома різними версіями малювання. У функції main
створити таблицю з трьох вказівників на об'єкти базового класу. створити три об'єкти різних видів дерев і призначте
вказівники на них коміркам раніше створеної таблиці. у циклі for, перебрати таблицю та викликати метод малювання з
кожного елемента таблиці */

#include <iostream>
using namespace std;

class Tree
{
public:
    virtual void draw()
    {
    }
    virtual ~Tree() {}
};

class PineTree : public Tree
{
public:
    void draw() override
    {
        cout << "   *   " << endl;
        cout << "  ***  " << endl;
        cout << " ***** " << endl;
        cout << "*******" << endl;
        cout << "   |   " << endl;
    }
};

class WideTree : public Tree
{
public:
    void draw() override
    {
        cout << "  *****  " << endl;
        cout << " ******* " << endl;
        cout << "*********" << endl;
        cout << " ******* " << endl;
        cout << "   |||   " << endl;
        cout << "   |||   " << endl;
    }
};

class TallTree : public Tree
{
public:
    void draw() override
    {
        cout << "   ***   " << endl;
        cout << "  *****  " << endl;
        cout << "   ***   " << endl;
        cout << "   ||    " << endl;
        cout << "   ||    " << endl;
        cout << "   ||    " << endl;
        cout << "   ||    " << endl;
    }
};

int main()
{
    Tree* forest[3];

    PineTree pine;
    WideTree wide;
    TallTree tall;

    forest[0] = &pine;
    forest[1] = &wide;
    forest[2] = &tall;

    for (int i = 0; i < 3; i++)
    {
        forest[i]->draw();
        cout << endl;
    }
}