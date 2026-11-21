
#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    // Addition operator
    Money operator+(const Money& m) const {
        Money temp;
        temp.paise = paise + m.paise;
        return temp;
    }

    // Equality operator
    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long amount = m.paise;
        out << "Rs " << amount / 100 << "."
            << setw(2) << setfill('0') << amount % 100;
        return out;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << c << endl;
    cout << boolalpha << (c == Money(200)) << endl;

    Money x(0, 75);
    Money y(0, 50);

    cout << "Carry Test: " << x + y << endl;

    return 0;
}
