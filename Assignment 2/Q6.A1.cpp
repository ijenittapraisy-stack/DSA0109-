#include <iostream>
using namespace std;

class Time
{
    int h, m;

public:
    Time(int hh, int mm)
    {
        h = hh;
        m = mm;
    }

    friend int minutesBetween(Time a, Time b);
    friend bool earlier(Time a, Time b);
};

inline int minutesBetween(Time a, Time b)
{
    int t1 = a.h * 60 + a.m;
    int t2 = b.h * 60 + b.m;

    if (t1 > t2)
        return t1 - t2;

    return t2 - t1;
}

inline bool earlier(Time a, Time b)
{
    int t1 = a.h * 60 + a.m;
    int t2 = b.h * 60 + b.m;

    return t1 < t2;
}

int main()
{
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "Time Difference = "
         << minutesBetween(departure, arrival) << endl;

    cout << "Is Arrival Earlier? "
         << boolalpha << earlier(arrival, departure);

    return 0;
}