
#include <iostream>
#include <string>
using namespace std;

class SmartCard {
public:
    int balance;

    void displayBalance() {
        cout << "Card Balance: Rs." << balance << endl;
    }
};

class Passenger {
public:
    string name;
    int age;

    void displayPassenger() {
        cout << "Passenger Name: " << name << endl;
        cout << "Passenger Age: " << age << endl;
    }
};

class Journey {
public:
    int zone;
    int fare;

    void calculateFare() {
        if (zone == 1)
            fare = 10;
        else if (zone == 2)
            fare = 20;
        else if (zone == 3)
            fare = 30;
        else
            fare = 0;
    }
};

int main() {
    Passenger p;
    SmartCard card;
    Journey j;

    p.name = "Ravi";
    p.age = 20;
    card.balance = 100;

    j.zone = 2;
    j.calculateFare();

    p.displayPassenger();

    cout << "Journey Zone: " << j.zone << endl;
    cout << "Journey Fare: Rs." << j.fare << endl;

    if (j.fare > 0 && card.balance - j.fare >= 50) {
        card.balance -= j.fare;
        cout << "Journey Allowed" << endl;
    }
    else {
        cout << "Journey Denied" << endl;
    }

    card.displayBalance();

    return 0;
}
