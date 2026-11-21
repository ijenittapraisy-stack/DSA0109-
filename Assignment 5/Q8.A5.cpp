
#include <iostream>
#include <chrono>
#include <stdexcept>
#include <iomanip>
using namespace std;

using Clock = chrono::high_resolution_clock;

// Base class
class Bill {
public:
    virtual ~Bill() {}
    virtual double total() const = 0;
};

// Outpatient bill
class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(double c, double t) {
        consultation = c;
        tests = t;
    }

    double total() const {
        return consultation + tests;
    }
};

// Inpatient bill
class InPatient : public Bill {
    double days, rate, surgery;

public:
    InPatient(double d, double r, double s) {
        days = d;
        rate = r;
        surgery = s;
    }

    double total() const {
        return days * rate + surgery;
    }
};

// Data for switch comparison
struct BillData {
    int type;
    double first, second, third;
};

double switchTotal(BillData b) {
    switch (b.type) {
        case 0:
            return b.first + b.second;

        case 1:
            return b.first * b.second + b.third;

        default:
            return 0;
    }
}

// Virtual function test
double virtualTest(long long n) {
    OutPatient op(500, 1200);
    InPatient ip(3, 2500, 40000);

    Bill* bills[2] = {&op, &ip};

    double sum = 0;

    for (long long i = 0; i < n; i++) {
        sum += bills[i % 2]->total();
    }

    return sum;
}

// Switch statement test
double switchTest(long long n) {
    double sum = 0;

    for (long long i = 0; i < n; i++) {
        BillData b;

        if (i % 2 == 0)
            b = {0, 500, 1200, 0};
        else
            b = {1, 3, 2500, 40000};

        sum += switchTotal(b);
    }

    return sum;
}

// Measure execution time
template <typename Function>
double measure(Function function) {
    Clock::time_point start = Clock::now();

    double result = function();

    Clock::time_point stop = Clock::now();

    cout << "Calculated total: " << result << endl;

    return chrono::duration<double, milli>(
        stop - start
    ).count();
}

// Claim validation
bool validClaim(double amount) {
    return amount >= 0 && amount <= 50000;
}

// Return code method
int returnValidation(double amount) {
    if (validClaim(amount))
        return 1;

    return 0;
}

// Exception method
int exceptionValidation(double amount) {
    if (amount < 0)
        throw invalid_argument("Negative amount");

    if (amount > 50000)
        throw out_of_range("Above cover");

    return 1;
}

// Performance comparison
void performanceTest() {
    long long sizes[] = {
        1000, 1000000, 10000000
    };

    cout << "\nVIRTUAL VS SWITCH COMPARISON\n";

    cout << fixed << setprecision(3);

    for (int i = 0; i < 3; i++) {
        long long n = sizes[i];

        cout << "\nNumber of bills: " << n << endl;

        double virtualTime = measure(
            [n]() {
                return virtualTest(n);
            }
        );

        cout << "Virtual time: "
             << virtualTime << " ms" << endl;

        double switchTime = measure(
            [n]() {
                return switchTest(n);
            }
        );

        cout << "Switch time: "
             << switchTime << " ms" << endl;
    }
}

// Return code vs exception comparison
void exceptionTest() {
    const long long n = 1000000;

    int percentages[] = {0, 1, 50};

    cout << "\nRETURN CODE VS EXCEPTION COMPARISON\n";

    for (int j = 0; j < 3; j++) {
        int percent = percentages[j];

        long long invalid = n * percent / 100;

        long long acceptedReturn = 0;
        long long acceptedException = 0;

        Clock::time_point start1 = Clock::now();

        for (long long i = 0; i < n; i++) {
            double amount =
                (i < invalid) ? 60000 : 40000;

            acceptedReturn += returnValidation(amount);
        }

        Clock::time_point stop1 = Clock::now();

        Clock::time_point start2 = Clock::now();

        for (long long i = 0; i < n; i++) {
            double amount =
                (i < invalid) ? 60000 : 40000;

            try {
                acceptedException +=
                    exceptionValidation(amount);
            }
            catch (const exception&) {
                // Invalid claim rejected
            }
        }

        Clock::time_point stop2 = Clock::now();

        double returnTime =
            chrono::duration<double, milli>(
                stop1 - start1
            ).count();

        double exceptionTime =
            chrono::duration<double, milli>(
                stop2 - start2
            ).count();

        cout << "\nInvalid claims: "
             << percent << "%" << endl;

        cout << "Return code accepted: "
             << acceptedReturn << endl;

        cout << "Return code time: "
             << returnTime << " ms" << endl;

        cout << "Exception accepted: "
             << acceptedException << endl;

        cout << "Exception time: "
             << exceptionTime << " ms" << endl;
    }
}

int main() {
    cout << "B3 PERFORMANCE ANALYSIS\n";

    cout << "\nCORRECTNESS TEST\n";

    cout << "Virtual total: "
         << virtualTest(10) << endl;

    cout << "Switch total: "
         << switchTest(10) << endl;

    performanceTest();

    exceptionTest();

    cout << "\nAll tests completed successfully.\n";

    return 0;
}
