#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
using namespace std;

class BillingError : public runtime_error {
public:
    using runtime_error::runtime_error;
};

class ClaimError : public BillingError {
public:
    using BillingError::BillingError;
};

class Bill {
protected:
    string patient;

public:
    Bill(string p) : patient(p) {}

    virtual ~Bill() = default;

    virtual double total() const = 0;
    virtual string type() const = 0;

    string getPatient() const {
        return patient;
    }
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(string p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        if (consultation < 0 || tests < 0)
            throw BillingError("negative outpatient charge");

        return consultation + tests;
    }

    string type() const override {
        return "OutPatient";
    }
};

class InPatient : public Bill {
    int days;
    double perDay, surgery;

public:
    InPatient(string p, int d, double rate, double s)
        : Bill(p), days(d), perDay(rate), surgery(s) {}

    double total() const override {
        if (days < 0 || perDay < 0 || surgery < 0)
            throw BillingError("invalid inpatient charge");

        return days * perDay + surgery;
    }

    string type() const override {
        return "InPatient";
    }
};

// New bill type
class DiagnosticBill : public Bill {
    double scanCharge, labCharge;

public:
    DiagnosticBill(string p, double scan, double lab)
        : Bill(p), scanCharge(scan), labCharge(lab) {}

    double total() const override {
        if (scanCharge < 0 || labCharge < 0)
            throw BillingError("negative diagnostic charge");

        return scanCharge + labCharge;
    }

    string type() const override {
        return "DiagnosticBill";
    }
};

class Payer {
public:
    virtual ~Payer() = default;

    virtual string name() const = 0;
    virtual double amountCovered(const Bill& bill) const = 0;
};

class SelfPay : public Payer {
public:
    string name() const override {
        return "SelfPay";
    }

    double amountCovered(const Bill& bill) const override {
        return bill.total();
    }
};

class Insurance : public Payer {
    double limit;

public:
    Insurance(double coverLimit) : limit(coverLimit) {}

    string name() const override {
        return "Insurance";
    }

    double amountCovered(const Bill& bill) const override {
        return min(limit, bill.total() * 0.90);
    }
};

// New payer
class CorporatePayer : public Payer {
    double coveragePercent;
    double maximum;

public:
    CorporatePayer(double percent, double maxCover)
        : coveragePercent(percent), maximum(maxCover) {}

    string name() const override {
        return "CorporatePayer";
    }

    double amountCovered(const Bill& bill) const override {
        return min(
            maximum,
            bill.total() * coveragePercent / 100.0
        );
    }
};

void processBill(const Bill& bill, const Payer& payer) {
    double total = bill.total();
    double covered = payer.amountCovered(bill);

    if (covered < 0 || covered > total)
        throw ClaimError("invalid covered amount");

    cout << bill.type()
         << " - " << bill.getPatient()
         << " | Total: " << total
         << " | " << payer.name()
         << " covers: " << covered
         << " | Patient pays: " << total - covered
         << '\n';
}

int main() {
    vector<unique_ptr<Bill>> bills;

    bills.push_back(
    unique_ptr<Bill>(new OutPatient("Ravi", 500, 1200))
);

bills.push_back(
    unique_ptr<Bill>(new InPatient("Meena", 3, 2500, 40000))
);

bills.push_back(
    unique_ptr<Bill>(new DiagnosticBill("Arun", 4500, 1500))
);

    SelfPay self;
    Insurance insurance(50000);
    CorporatePayer corporate(80, 60000);

    vector<Payer*> payers = {
        &self, &insurance, &corporate
    };

    cout << "HOSPITAL BILLING SYSTEM\n";

    for (const auto& bill : bills) {
        for (const Payer* payer : payers) {
            try {
                processBill(*bill, *payer);
            }
            catch (const exception& e) {
                cout << "Billing error: "
                     << e.what() << '\n';
            }
        }
    }

    cout << "\nEXCEPTION TEST\n";

    try {
        OutPatient invalid("TestPatient", -100, 500);
        cout << invalid.total() << '\n';
    }
    catch (const BillingError& e) {
        cout << "Caught expected error: "
             << e.what() << '\n';
    }

    cout << "\nProgram completed successfully.\n";
    cout << "Smart pointers release bill objects automatically.\n";

    return 0;
}