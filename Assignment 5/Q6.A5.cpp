#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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

    void print() const {
        cout << type() << " " << patient
             << ": " << total() << '\n';
    }
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(string p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OP";
    }
};

class InPatient : public Bill {
    int days;
    double perDay, surgery;

public:
    InPatient(string p, int d, double rate, double s)
        : Bill(p), days(d), perDay(rate), surgery(s) {}

    double total() const override {
        return days * perDay + surgery;
    }

    string type() const override {
        return "IP";
    }
};

class DayCare : public Bill {
    double packagePrice;

public:
    DayCare(string p, double price)
        : Bill(p), packagePrice(price) {}

    double total() const override {
        return packagePrice;
    }

    string type() const override {
        return "DC";
    }
};

class Emergency : public Bill {
    double baseCharge, hourlyCharge;
    int hours;

public:
    Emergency(string p, double base, double hourly, int h)
        : Bill(p), baseCharge(base),
          hourlyCharge(hourly), hours(h) {}

    double total() const override {
        return baseCharge + hourlyCharge * hours;
    }

    string type() const override {
        return "ER";
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
    double coverLimit, copayPercent;

public:
    Insurance(double limit, double copay)
        : coverLimit(limit), copayPercent(copay) {}

    string name() const override {
        return "Insurance";
    }

    double amountCovered(const Bill& bill) const override {
        double amount = bill.total() * (1 - copayPercent / 100);
        return min(amount, coverLimit);
    }
};

class GovernmentScheme : public Payer {
public:
    string name() const override {
        return "GovernmentScheme";
    }

    double amountCovered(const Bill& bill) const override {
        if (bill.type() == "OP") return 1000;
        if (bill.type() == "IP") return 30000;
        if (bill.type() == "DC") return 15000;
        if (bill.type() == "ER") return 3000;
        return 0;
    }
};

int main() {
    vector<Bill*> bills;

    bills.push_back(new OutPatient("Ravi", 500, 1200));
    bills.push_back(new InPatient("Meena", 3, 2500, 40000));
    bills.push_back(new DayCare("Arun", 18000));
    bills.push_back(new Emergency("Kavi", 2000, 1000, 3));

    SelfPay self;
    Insurance insurance(50000, 10);
    GovernmentScheme government;

    vector<Payer*> payers = {&self, &insurance, &government};

    cout << "BILL DETAILS\n";

    double grandTotal = 0;

    for (Bill* b : bills) {
        b->print();
        grandTotal += b->total();
    }

    cout << "Total " << grandTotal << "\n\n";

    cout << "PAYER COMPARISON\n";

    for (Bill* b : bills) {
        for (Payer* p : payers) {
            cout << b->type() << " "
                 << b->getPatient() << " - "
                 << p->name() << " covers: "
                 << p->amountCovered(*b) << '\n';
        }
    }

    for (Bill* b : bills) {
        delete b;
    }

    return 0;
}