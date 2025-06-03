// Завдання 1

/*

Напишіть програму, яка зчитує два рядки тексту.
Перший рядок повинен містити список пар "ім’я=значення",
розділених комами. Кожна пара має бути у такому форматі: "ім’я=значення".
Другий рядок повинен містити шаблон, який слід заповнити
значеннями з першого рядка. Заповнювач (placeholder) повинен мати
вигляд "[ім’я]" і має бути замінений на відповідне значення.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string values;
    string temp;

    cout << "Enter name=value pairs (comma-separated): " << endl;
    getline(cin, values);

    cout << "Enter the template with placeholders: " << endl;
    getline(cin, temp);

    string names[100];
    string vals[100];

    int count = 0;
    int start = 0;

    while (start < values.length())
    {
        int comma = values.find(',', start);

        if (comma == -1)
        {
            comma = values.length();
        }

        int eq = values.find('=', start);

        if (eq != -1 && eq < comma)
        {
            names[count] = values.substr(start, eq - start);
            vals[count] = values.substr(eq + 1, comma - eq - 1);
            count++;
        }
        start = comma + 1;
    }

    int pos = 0;
    while (pos < temp.length())
    {
        if (temp[pos] == '[')
        {
            int end = temp.find(']', pos);
            if (end == -1)
            {
                break;
            }

            string key = temp.substr(pos + 1, end - pos - 1);
            string val = key;

            for (int i = 0; i < count; i++)
            {
                if (names[i] == key)
                {
                    val = vals[i];
                    break;
                }
            }
            temp.replace(pos, end - pos + 1, val);
            pos += val.length();
        }
        else
        {
            pos++;
        }
    }

    cout << temp;
}