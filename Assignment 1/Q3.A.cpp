
#include <iostream>
#include <climits>
using namespace std;

int main() {
    bool peak = true;
    char zone = 'A';
    int hour = 9;
    long long balance = 10000;
    unsigned int journeys = 3000000;
    float surcharge = 20.0f;
    double fare = 30.0;
    auto total = balance + 2000LL;

    cout << "Boolean: " << peak << endl;
    cout << "Character: " << zone << endl;
    cout << "Hour: " << hour << endl;
    cout << "Balance: " << balance << " paise" << endl;
    cout << "Journeys: " << journeys << endl;
    cout << "Surcharge: " << surcharge << "%" << endl;
    cout << "Fare: Rs." << fare << endl;
    cout << "Total Balance: " << total << " paise" << endl;

    cout << "\nDATA TYPE SIZES\n";
    cout << "bool: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;

    cout << "\nINT MAX: " << INT_MAX << endl;
    cout << "INT MIN: " << INT_MIN << endl;

    return 0;
}
