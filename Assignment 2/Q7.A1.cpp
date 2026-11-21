#include <iostream>
using namespace std;

class SavingsAccount
{
    int accno;
    float balance;
    float transactions[10];
    int count, start;

public:
    SavingsAccount()
    {
        accno = 101;
        balance = 0;
        count = 0;
        start = 0;
    }

    void deposit(float amount)
    {
        balance = balance + amount;

        int pos = (start + count) % 10;

        if (count < 10)
        {
            transactions[pos] = amount;
            count++;
        }
        else
        {
            transactions[start] = amount;
            start = (start + 1) % 10;
        }
    }

    void display()
    {
        cout << "Account Number = " << accno << endl;
        cout << "Balance = " << balance << endl;
        cout << "Last 10 Transactions:" << endl;

        for (int i = 0; i < count; i++)
        {
            int pos = (start + i) % 10;
            cout << transactions[pos] << endl;
        }
    }
};

int main()
{
    SavingsAccount s;

    for (int i = 1; i <= 12; i++)
    {
        s.deposit(1000);
    }

    s.display();

    return 0;
}