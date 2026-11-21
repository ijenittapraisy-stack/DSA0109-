
#include <iostream>
using namespace std;

int calculateFare(int zone, int hour) {
    int fare;

    switch (zone) {
        case 1: fare = 1000; break;
        case 2: fare = 2000; break;
        case 3: fare = 3000; break;
        default: return -1;
    }

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20)) {
        fare += fare * 20 / 100;
    }

    return fare;
}

int main() {
    int zones[] = {1, 2, 3, 1, 2};
    int hours[] = {7, 9, 12, 18, 20};

    cout << "FARE TESTING REPORT\n";

    for (int i = 0; i < 5; i++) {
        int f = calculateFare(zones[i], hours[i]);

        cout << "Journey " << i + 1
             << " | Zone: " << zones[i]
             << " | Hour: " << hours[i]
             << " | Fare: ";

        if (f == -1) {
            cout << "Invalid Zone";
        }
        else {
            cout << "Rs." << f / 100
                 << "." << (f % 100 < 10 ? "0" : "")
                 << f % 100;
        }

        cout << endl;
    }

    return 0;
}
