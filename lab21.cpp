// Завдання 1

//Надрукувати стан щодо відсотка заповненості у форматі як у прикладі

#include <iostream>
using namespace std;

class FlightBooking
{
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
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

int main()
{
    int reserved = 0, capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();
}