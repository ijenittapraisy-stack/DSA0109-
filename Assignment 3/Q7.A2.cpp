#include <iostream>
#include <complex>
using namespace std;

int main()
{
    complex<double> a(10, 20);
    complex<double> b(5, 10);

    cout << "Addition: " << a + b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Magnitude: " << abs(a) << endl;

    return 0;
}