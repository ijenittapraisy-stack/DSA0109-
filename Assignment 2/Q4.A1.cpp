#include <iostream>
using namespace std;

class SavingsAccount
{
    int accno;
    float balance;
    float transactions[10];
    int count;

public:
    SavingsAccount()
    {
        accno = 101;
        balance = 0;
        count = 0;
    }

    void deposit(float amount)
    {
        balance = balance + amount;

        if (count < 10)
        {
            transactions[count] = amount;
            count++;
        }
        else
        {
            for (int i = 0; i < 9; i++)
                transactions[i] = transactions[i + 1];

            transactions[9] = amount;
        }
    }

    void withdraw(float amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;

            if (count < 10)
            {
                transactions[count] = -amount;
                count++;
            }
            else
            {
                for (int i = 0; i < 9; i++)
                    transactions[i] = transactions[i + 1];

                transactions[9] = -amount;
            }
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }
    }

    void miniStatement();
};

void SavingsAccount::miniStatement()
{
    cout << "Account Number = " << accno << endl;
    cout << "Balance = " << balance << endl;
    cout << "Transactions:" << endl;

    for (int i = 0; i < count; i++)
        cout << transactions[i] << endl;
}

int main()
{
    SavingsAccount s;

    s.deposit(5000);
    s.deposit(2000);
    s.withdraw(1000);
    s.deposit(3000);

    s.miniStatement();

    return 0;
}