#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include <new>
using namespace std;

class ClaimError : public runtime_error {
public:
    using runtime_error::runtime_error;
};

class Resource {
    string name;

public:
    Resource(string n) : name(n) {
        cout << "Created " << name << '\n';
    }

    ~Resource() noexcept {
        cout << "Destroyed " << name << '\n';
    }
};

void validateAmount(double amount) {
    if (amount < 0)
        throw invalid_argument("negative");

    if (amount > 1000000)
        throw out_of_range("too large");

    cout << "ok ";
}

void processAmount(double amount) {
    try {
        validateAmount(amount);
    }
    catch (const out_of_range& e) {
        cout << "[log " << e.what() << "] ";
        throw;
    }
}

double approve(double billed, double cover) {
    if (billed < 0 || cover < 0)
        throw invalid_argument("negative amount");

    if (billed > cover)
        throw ClaimError("exceeds cover");

    return billed;
}

double settle(double billed, double cover) {
    try {
        return approve(billed, cover);
    }
    catch (const ClaimError& e) {
        cout << "audit: " << e.what() << '\n';
        throw;
    }
}

double readNumber(string value) {
    return stod(value);
}

void checkPackage(string code) {
    if (code != "OP" && code != "IP" &&
        code != "DC" && code != "ER") {
        throw runtime_error("unknown package code");
    }

    cout << "Package accepted: " << code << '\n';
}

void forceAllocationFailure() {
    cout << "Requesting a very large allocation...\n";

    size_t count = numeric_limits<size_t>::max();

    int* data = new int[count];

    delete[] data;
}

void runErrorTests() {
    Resource r("BillingResource");

    try {
        validateAmount(-10);
    }
    catch (const exception& e) {
        cout << "Negative charge caught: "
             << e.what() << '\n';
    }

    try {
        double paid = settle(60000, 50000);
        cout << "Paid: " << paid << '\n';
    }
    catch (const ClaimError& e) {
        cout << "Claim rejected: "
             << e.what() << '\n';
    }

    try {
        checkPackage("UNKNOWN");
    }
    catch (const exception& e) {
        cout << "Package error caught: "
             << e.what() << '\n';
    }

    try {
        readNumber("abc");
    }
    catch (const invalid_argument& e) {
        cout << "Number conversion error: "
             << e.what() << '\n';
    }

    try {
        forceAllocationFailure();
    }
    catch (const bad_alloc& e) {
        cout << "Allocation error caught: "
             << e.what() << '\n';
    }
    catch (...) {
        cout << "Other allocation error caught\n";
    }

    cout << "Program continues after the tests\n";
}

int main() {
    cout << "PART 1: OUTPUT PREDICTION TEST\n";

    for (double amount : {100.0, -5.0, 2e6}) {
        try {
            processAmount(amount);
            cout << "done ";
        }
        catch (const exception& e) {
            cout << "caught " << e.what() << ' ';
        }
    }

    cout << "\n\n";

    cout << "PART 2: CLAIM APPROVAL TEST\n";

    double cases[][2] = {
        {40000, 50000},
        {60000, 50000},
        {-1, 50000}
    };

    for (auto& c : cases) {
        try {
            double paid = settle(c[0], c[1]);
            cout << "approved " << paid << '\n';
        }
        catch (const ClaimError& e) {
            cout << "claim rejected: "
                 << e.what() << '\n';
        }
        catch (const exception& e) {
            cout << "error: " << e.what() << '\n';
        }
    }

    cout << "\nPART 3: ERROR CONDITION TESTS\n";

    try {
        runErrorTests();
    }
    catch (...) {
        cout << "Top-level handler caught an unexpected error\n";
    }

    cout << "\nPART 4: RAII AND STACK UNWINDING\n";

    try {
        Resource mainResource("main");

        try {
            Resource functionResource("function");
            throw 42;
        }
        catch (int) {
            cout << "Inner exception caught\n";
        }
    }
    catch (...) {
        cout << "Top-level catch\n";
    }

    return 0;
}