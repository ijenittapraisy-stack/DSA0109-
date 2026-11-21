
#include <iostream>
using namespace std;

constexpr int INNER_FARE = 10;
constexpr int MIDDLE_FARE = 20;
constexpr int OUTER_FARE = 30;
constexpr int PEAK_SURCHARGE = 20;
constexpr int MIN_BALANCE = 50;

enum class Zone {
    Inner, Middle, Outer
};

int main() {
    Zone z = Zone::Middle;
    int fare = 0;

    switch (z) {
        case Zone::Inner:
            fare = INNER_FARE;
            break;

        case Zone::Middle:
            fare = MIDDLE_FARE;
            break;

        case Zone::Outer:
            fare = OUTER_FARE;
            break;
    }

    cout << "Inner Fare: Rs." << INNER_FARE << endl;
    cout << "Middle Fare: Rs." << MIDDLE_FARE << endl;
    cout << "Outer Fare: Rs." << OUTER_FARE << endl;
    cout << "Peak Surcharge: " << PEAK_SURCHARGE << "%" << endl;
    cout << "Minimum Balance: Rs." << MIN_BALANCE << endl;
    cout << "Selected Fare: Rs." << fare << endl;

    return 0;
}
