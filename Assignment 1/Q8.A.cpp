
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int zone, hour;
    long long balance;

    cout << "Enter zone (1-3): ";

    while (!(cin >> zone) || zone < 1 || zone > 3) {
        cout << "Invalid zone. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter hour (0-23): ";

    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter balance: ";

    while (!(cin >> balance) || balance < 0) {
        cout << "Invalid balance. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int fare = zone * 10;

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20)) {
        fare += fare * 20 / 100;
    }

    cout << fixed << setprecision(2);

    cout << "\nJOURNEY REPORT\n";
    cout << "Zone: " << zone << endl;
    cout << "Hour: " << hour << endl;
    cout << "Fare: Rs." << fare << ".00" << endl;
    cout << "Balance: Rs." << balance << ".00" << endl;

    return 0;
}
