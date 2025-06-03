#include <iostream>
using namespace std;

class FlightBooking
{
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool addReservations(int n);
    bool cancelReservations(int n);
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;

    if (reserved < 0)
    {
        this->reserved = 0;
    }
    else if (reserved > capacity * 1.05)
    {
        this->reserved = capacity * 1.05;
    }
    else
    {
        this->reserved = reserved;
    }
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
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentage << "%) seats reserved" << endl;
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

int main()
{
    int reserved = 0, capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;

    FlightBooking booking(1, capacity, reserved);

    string command;
    int n;

    while (true)
    {
        cout << "Enter command (add/cancel/quit): ";
        cin >> command;

        if (command == "add")
        {
            cin >> n;
            if (booking.addReservations(n) == false)
            {
                cout << "Cannot do this operation" << endl;
            }

        }
        else if (command == "cancel")
        {
            cin >> n;
            if (booking.cancelReservations(n) == false)
            {
                cout << "Cannot do this operation" << endl;
            }
        }
        else if (command == "quit")
        {
            break;
        }
        else
        {
            cout << "Unknown command" << endl;
        }

        booking.printStatus();
    }
}