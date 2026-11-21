
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int journeys[] = {20000, 500000, 3000000};

    double doubleFare = 10.10;
    long long paiseFare = 1010;

    cout << fixed << setprecision(2);

    for (int i = 0; i < 3; i++) {
        double doubleTotal = journeys[i] * doubleFare;
        long long paiseTotal =
            static_cast<long long>(journeys[i]) * paiseFare;

        cout << "\nJourneys: " << journeys[i] << endl;

        cout << "Double Total: Rs."
             << doubleTotal << endl;

        cout << "Integer Paise Total: Rs."
             << paiseTotal / 100 << "."
             << setw(2) << setfill('0')
             << paiseTotal % 100 << setfill(' ') << endl;
    }

    return 0;
}
