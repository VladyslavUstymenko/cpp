// Завдання 3

/* Додати список команд програми:

Команда "create [id] [cap]" спробує створити новий порожній рейс з ідентифікатором[id] та місткістю[cap].
Команда "delete [id]" спробує видалити рейс з ідентифікатором[id].
Команда "add [id] [n]" спробує додати n бронювань до рейсу з ідентифікатором[id].
Команда "cancel [id] [n]" спробує скасувати n бронювань з рейсу з ідентифікатором[id].
Якщо операцію не вдалося виконати з будь - якої причини, програма виведе повідомлення :
"Cannot perform this operation".
Команда "quit" зупиняє виконання програми.
Для спрощення обмежимо максимальну кількість оброблюваних рейсів до десяти. */

#include <iostream>
#include <string>
using namespace std;

class FlightBooking
{
public:
    FlightBooking();
    FlightBooking(int id, int capacity);
    void printStatus();
    bool addReservations(int n);
    bool cancelReservations(int n);
    int getId() const;
    bool isActive() const;

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking()
{
    id = 0;
    capacity = 0;
    reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity)
{
    this->id = id;
    this->capacity = (capacity < 0) ? 0 : capacity;
    this->reserved = 0;
}

void FlightBooking::printStatus()
{
    int percentage;

    if (capacity == 0)
    {
        percentage = 0;
    }
    else
    {
        percentage = (reserved * 100) / capacity;
    }
}

bool FlightBooking::addReservations(int n)
{
    if (n < 0 || reserved + n > capacity * 1.05)
    {
        return false;
    }
    reserved += n;
    return true;
}

bool FlightBooking::cancelReservations(int n)
{
    if (n < 0 || reserved - n < 0)
    {
        return false;
    }
    reserved -= n;
    return true;
}

int FlightBooking::getId() const
{
    return id;
}

bool FlightBooking::isActive() const
{
    return id != 0;
}

int main()
{
    const int MAX_FLIGHTS = 10;
    FlightBooking flights[MAX_FLIGHTS];

    string command;
    while (true)
    {
        cout << "Enter command: ";
        cin >> command;

        if (command == "quit")
        {
            break;
        }
        else if (command == "create")
        {
            int id, cap;
            cin >> id >> cap;

            bool exists = false;
            for (int i = 0; i < MAX_FLIGHTS; i++)
            {
                if (flights[i].getId() == id)
                {
                    exists = true;
                    break;
                }
            }

            if (exists || id == 0)
            {
                cout << "Cannot do this operation" << endl;
                continue;
            }

            bool created = false;
            for (int i = 0; i < MAX_FLIGHTS; i++)
            {
                if (flights[i].isActive() == false )
                {
                    flights[i] = FlightBooking(id, cap);
                    flights[i].printStatus();
                    created = true;
                    break;
                }
            }

            if (created == false)
            {
                cout << "Cannot do this operation" << endl;
            }
        }
        else if (command == "delete")
        {
            int id;
            cin >> id;

            bool deleted = false;
            for (int i = 0; i < MAX_FLIGHTS; ++i)
            {
                if (flights[i].getId() == id)
                {
                    flights[i] = FlightBooking();
                    deleted = true;
                    break;
                }
            }

            if (deleted == false)
            {
                cout << "Cannot do this operation" << endl;
            }
        }
        else if (command == "add")
        {
            int id, n;
            cin >> id >> n;

            bool found = false;
            for (int i = 0; i < MAX_FLIGHTS; i++)
            {
                if (flights[i].getId() == id)
                {
                    if (flights[i].addReservations(n) == false)
                    {
                        cout << "Cannot do this operation" << endl;
                    }
                    else
                    {
                        flights[i].printStatus();
                    }
                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "Cannot do this operation" << endl;
            }
        }
        else if (command == "cancel")
        {
            int id, n;
            cin >> id >> n;

            bool found = false;
            for (int i = 0; i < MAX_FLIGHTS; ++i)
            {
                if (flights[i].getId() == id)
                {
                    if (flights[i].cancelReservations(n) == false)
                    {
                        cout << "Cannot do this operation" << endl;
                    }
                    else
                    {
                        flights[i].printStatus();
                    }
                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "Cannot do this operation" << endl;
            }
        }
        else
        {
            cout << "Unknown command" << endl;
        }
    }
}