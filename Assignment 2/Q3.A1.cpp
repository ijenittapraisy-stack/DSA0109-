#include <iostream>
using namespace std;

double charge(double weight, bool express = false, bool insured = false)
{
    double amount = weight * 10;

    if (express == true)
        amount = amount + 50;

    if (insured == true)
        amount = amount + 30;

    return amount;
}

int charge(int grams)
{
    return grams / 100;
}

int main()
{
    cout << "Normal Charge = " << charge(2.0) << endl;
    cout << "Express Charge = " << charge(2.0, true) << endl;
    cout << "Insured Charge = " << charge(2.0, false, true) << endl;
    cout << "Integer Charge = " << charge(200);

    return 0;
}