
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string registration;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double rate) {
        registration = r;
        dailyRate = rate;
        rented = false;
    }

    virtual double charge(int days) = 0;

    virtual void display() {
        cout << "Registration: " << registration << endl;
        cout << "Daily Rate: Rs." << dailyRate << endl;
    }

    void rent() {
        if (!rented) {
            rented = true;
            cout << registration << " Rented Successfully\n";
        }
        else {
            cout << "Already Rented\n";
        }
    }

    void returnVehicle(int lateDays) {
        if (rented) {
            rented = false;
            cout << registration << " Returned\n";
            cout << "Late Charge: Rs."
                 << lateDays * 100 << endl;
        }
        else {
            cout << "Vehicle was not rented\n";
        }
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate)
        : Vehicle(r, rate) {}

    double charge(int days) override {
        return dailyRate * days;
    }
};

class TwoWheeler : public Vehicle {
protected:
    double fuel;

public:
    TwoWheeler(string r, double rate, double f)
        : Vehicle(r, rate) {
        fuel = f;
    }

    double charge(int days) override {
        return dailyRate * days + fuel * 5;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string r, double rate, int s)
        : Vehicle(r, rate) {
        seats = s;
    }

    double charge(int days) override {
        return dailyRate * days + seats * 50;
    }
};

class ElectricCar : public Car {
    double battery;

public:
    ElectricCar(string r, double rate, int s, double b)
        : Car(r, rate, s) {
        battery = b;
    }

    double charge(int days) override {
        return dailyRate * days + battery * 10;
    }
};

class ElectricBus : public Vehicle {
    double battery;

public:
    ElectricBus(string r, double rate, double b)
        : Vehicle(r, rate) {
        battery = b;
    }

    double charge(int days) override {
        return dailyRate * days + battery * 10;
    }
};

int main() {
    Vehicle* fleet[5];

    fleet[0] = new Bicycle("BIKE101", 100);
    fleet[1] = new TwoWheeler("BIKE102", 200, 5);
    fleet[2] = new Car("CAR101", 1000, 5);
    fleet[3] = new ElectricCar("EV101", 1500, 5, 20);
    fleet[4] = new ElectricBus("BUS101", 3000, 100);

    cout << "VEHICLE RENTAL SYSTEM\n\n";

    for (int i = 0; i < 5; i++) {
        fleet[i]->display();
        fleet[i]->rent();

        cout << "Rental Charge: Rs."
             << fleet[i]->charge(2) << endl;

        fleet[i]->returnVehicle(1);

        cout << endl;
    }

    for (int i = 0; i < 5; i++) {
        delete fleet[i];
    }

    return 0;
}
