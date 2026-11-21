
#include <iostream>
using namespace std;

const int MIN_BALANCE = 50;

class SmartCard {
private:
    int balance;

public:
    SmartCard(int b) {
        balance = b;
    }

    bool canTravel(int fare) {
        return fare >= 0 &&
               balance - fare >= MIN_BALANCE;
    }

    void deduct(int fare) {
        if (canTravel(fare)) {
            balance -= fare;
            cout << "Journey Allowed" << endl;
        }
        else {
            cout << "Journey Denied" << endl;
        }
    }

    void display() {
        cout << "Remaining Balance: Rs."
             << balance << endl;
    }
};

int main() {
    SmartCard card(100);

    card.deduct(20);
    card.display();

    card.deduct(40);
    card.display();

    return 0;
}
