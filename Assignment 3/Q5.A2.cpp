
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Time {
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        seconds = h * 3600 + m * 60 + s;
    }

    Time& operator++() {
        seconds++;
        return *this;
    }

    Time operator++(int) {
        Time old = *this;
        seconds++;
        return old;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    void display() const {
        cout << seconds / 3600 << ":"
             << (seconds / 60) % 60 << ":"
             << seconds % 60 << endl;
    }
};

class Playlist {
    vector<string> songs;

public:
    Playlist() {
        songs = {"Song A", "Song B", "Song C"};
    }

    string& operator[](int i) {
        if (i < 0 || i >= (int)songs.size()) {
            throw out_of_range("Invalid playlist index");
        }
        return songs[i];
    }

    const string& operator[](int i) const {
        if (i < 0 || i >= (int)songs.size()) {
            throw out_of_range("Invalid playlist index");
        }
        return songs[i];
    }
};

int main() {
    Time t(0, 0, 5);

    Time a = t++;
    Time b = ++t;

    cout << "Postfix value: ";
    a.display();

    cout << "Prefix value: ";
    b.display();

    cout << "Current time: ";
    t.display();

    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a < b: " << (a < b) << endl;

    Playlist p;

    cout << "Playlist: " << endl;
    cout << p[0] << endl;
    cout << p[1] << endl;

    Time rollover(0, 59, 59);
    ++rollover;

    cout << "After rollover: ";
    rollover.display();

    try {
        cout << p[5];
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}
