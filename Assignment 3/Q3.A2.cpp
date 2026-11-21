
#include <iostream>
using namespace std;

class Auditorium {
    int rows, seats;
    char** seatMap;

public:
    // Dynamic constructor
    Auditorium(int r, int s) : rows(r), seats(s), seatMap(nullptr) {
        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++) {
                    seatMap[i][j] = 'O';
                }
            }
        }
        cout << "Auditorium created" << endl;
    }

    void book(int r, int s) {
        if (r >= 0 && r < rows && s >= 0 && s < seats) {
            if (seatMap[r][s] == 'O') {
                seatMap[r][s] = 'X';
                cout << "Seat booked" << endl;
            } else {
                cout << "Seat already booked" << endl;
            }
        } else {
            cout << "Invalid seat" << endl;
        }
    }

    void cancel(int r, int s) {
        if (r >= 0 && r < rows && s >= 0 && s < seats) {
            seatMap[r][s] = 'O';
            cout << "Booking cancelled" << endl;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++) {
                cout << seatMap[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Auditorium() {
        for (int i = 0; i < rows; i++) {
            delete[] seatMap[i];
        }

        delete[] seatMap;

        cout << "Auditorium destroyed" << endl;
    }
};

int main() {
    Auditorium a(2, 3);

    a.book(0, 1);
    a.book(1, 2);

    cout << "Seat Map:" << endl;
    a.display();

    a.cancel(0, 1);

    cout << "\nAfter Cancellation:" << endl;
    a.display();

    Auditorium* b = new Auditorium(2, 2);
    b->book(0, 0);
    delete b;

    return 0;
}
