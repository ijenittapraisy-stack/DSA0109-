#include <iostream>
using namespace std;

class BusTicket
{
    static int issued;
    static const int capacity = 3;

    int seat;
    string name;

public:
    BusTicket(string n)
    {
        name = n;
        seat = 0;

        if (issued < capacity)
        {
            issued++;
            seat = issued;
        }
    }

    static int count()
    {
        return issued;
    }

    void display()
    {
        cout << name << ": ";

        if (seat != 0)
            cout << "Seat " << seat;
        else
            cout << "Waiting";

        cout << endl;
    }
};

int BusTicket::issued = 0;

int main()
{
    BusTicket tickets[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (int i = 0; i < 4; i++)
    {
        tickets[i].display();
    }

    cout << "Issued: " << BusTicket::count();

    return 0;
}