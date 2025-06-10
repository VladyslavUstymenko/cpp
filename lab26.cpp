/*  Напиcати ієрархію з двох класів: базового класу IPAddress
та похідного класу IPAddressChecked. Перший містить значення
IP-адреси, а похідний клас має одне додаткове логічне значення.
Обидва класи мають конструктор, конструктор копіювання та метод print.
Метод print у похідному класі також виводить значення свого логічного значення.
Використати методи базового класу у похідному. Написати тестовий код для отримання
вхідних даних від користувача. Створити один об'єкт IPAddress та два об'єкти IPAddressChecked.
Вивести значення для всіх трьох об'єктів  */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class IPAddress
{
protected:
    string address;
public:
    IPAddress(const string& addr)
    {
        address = addr;
    }

    IPAddress(const IPAddress& other)
    {
        address = other.address;
    }

    void print() const
    {
        cout << "IP Address: " << address << endl;
    }

    string getAddress() const
    {
        return address;
    }
};

class IPAddressChecked : public IPAddress
{
    bool correct;
public:
    IPAddressChecked(const string& addr) : IPAddress(addr)
    {
        correct = validateIP(addr);
    }

    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other)
    {
        correct = other.correct;
    }

    void print() const
    {
        IPAddress::print();
        cout << (correct ? "Correct" : "Not Correct") << endl;
    }

private:
    bool validateIP(const string& addr)
    {
        int parts = 0;
        char dot;
        int num;
        istringstream iss(addr);

        while (iss >> num)
        {
            if (num < 0 || num > 255)
            {
                return false;
            }

            parts++;

            if (parts == 4)
            {
                break;
            }

            if (!(iss >> dot) || dot != '.')
            {
                return false;
            }
        }


        return parts == 4 && iss.eof();
    }
};

int main()
{
    string ip1, ip2, ip3;

    cout << "Enter IP address for IPAddress object: ";
    cin >> ip1;
    cout << "Enter IP address for first IPAddressChecked object: ";
    cin >> ip2;
    cout << "Enter IP address for second IPAddressChecked object: ";
    cin >> ip3;

    IPAddress obj1(ip1);
    IPAddressChecked obj2(ip2);
    IPAddressChecked obj3(ip3);

    cout << "Object 1:" << endl;
    obj1.print();

    cout << "Object 2:" << endl;
    obj2.print();

    cout << "Object 3:" << endl;
    obj3.print();
}