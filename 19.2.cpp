// Завдання 2

/*

Напишіть програму, яка зчитуватиме рядок тексту як пароль і перевірятиме його відповідність наведеним нижче правилам.
Пароль повинен:

1) Містити рівно вісім символів;
2) Містити щонайменше одну велику літеру;
3) Містити щонайменше одну малу літеру;
4) Містити щонайменше одну цифру;
5) Містити щонайменше один спеціальний символ.

Якщо будь-яке з цих правил порушено, програма повинна повідомити користувача, чому пароль є некоректним.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string password;
    cout << "Enter your password: " << endl;
    getline(cin, password);

    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;

    if (password.length() != 8)
    {
        cout << "The password must be exactly 8 characters long" << endl;
        return 0;
    }

    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_upper = true;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lower = true;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_digit = true;
        }
        else
        {
            has_special = true;
        }
    }

    if (has_upper == false)
    {
        cout << "The password must have at least one upper-case letter" << endl;
    }
    if (has_lower == false)
    {
        cout << "The password must have at least one lower-case letter" << endl;
    }
    if (has_digit == false)
    {
        cout << "The password must have at least one digit" << endl;
    }
    if (has_special == false)
    {
        cout << "The password must have at least one special character" << endl;
    }
    if (has_upper == true && has_lower == true && has_digit == true && has_special == true)
    {
        cout << "The password is valid";
    }
}