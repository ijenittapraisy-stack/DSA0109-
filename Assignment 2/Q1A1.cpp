#include <iostream>
using namespace std;

void byValue(int fee)
{
    fee = fee - 1000;
    cout << "Call by Value = " << fee << endl;
}

void byReference(int &fee)
{
    fee = fee - 1000;
    cout << "Call by Reference = " << fee << endl;
}

void byPointer(int *fee)
{
    *fee = *fee - 1000;
    cout << "Call by Pointer = " << *fee << endl;
}

int main()
{
    int fee = 10000;

    byValue(fee);
    cout << "Stored Fee = " << fee << endl;

    byReference(fee);
    cout << "Stored Fee = " << fee << endl;

    byPointer(&fee);
    cout << "Stored Fee = " << fee << endl;

    return 0;
}