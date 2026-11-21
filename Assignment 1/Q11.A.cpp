
#include <iostream>
using namespace std;

constexpr long long FARE[] = {1000, 2000, 3000};
constexpr long long MINIMUM_BALANCE = 5000;

class MetroSystem {
public:
    long long calculateFare(int zone, bool peak) {
        if (zone < 1 || zone > 3) {
            return -1;
        }

        long long fare = FARE[zone - 1];

        if (peak) {
            fare += fare * 20 / 100;
        }

        return fare;
    }

    bool validateJourney(long long balance, long long fare) {
        return fare >= 0 &&
               balance - fare >= MINIMUM_BALANCE;
    }
};

int main() {
    MetroSystem metro;

    long long balance = 10000;

    for (int zone = 1; zone <= 3; zone++) {
        long long fare = metro.calculateFare(zone, false);

        cout << "Zone " << zone
             << " Fare: Rs." << fare / 100 << endl;

        if (metro.validateJourney(balance, fare)) {
            balance -= fare;
            cout << "Journey Approved" << endl;
        }
        else {
            cout << "Journey Denied" << endl;
        }
    }

    cout << "\nFinal Balance: Rs."
         << balance / 100 << endl;

    cout << "\nRecommended Design:\n";
    cout << "Use OOP, constexpr and integer paise.\n";
    cout << "Use long long for network collections.\n";
    cout << "Use a centralized fare table.\n";

    return 0;
}
