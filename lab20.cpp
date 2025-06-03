// Завдання 1

// Виправити помилки і створити кілька нових об'єктів.

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
};

void print(Person* person)
{
    cout << "Meet " << person->name << endl;
    cout << person->name << " is " << person->age << " years old" << endl; // Виправлена помилка - відсутність оператора <<
}

int main()
{
    Person person1 = { "Harry", 23 };
    Person person2 = { "Anton", 30 };
    Person person3 = { "Lisa", 45 };

    Person people[] = { person1, person2, person3 };

    int count = sizeof(people) / sizeof(people[0]);

    for (int i = 0; i < count; i++)
    {
        print(&people[i]);
    }
}