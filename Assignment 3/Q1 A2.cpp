
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int copies;

public:
    // Default constructor
    Book() : Book("Unknown", 0) {}

    // Parameterized constructor
    Book(string t, int c) : title(t), copies(c < 0 ? 0 : c) {}

    // Constructor with title only
    Book(string t) : Book(t, 1) {}

    void display() {
        cout << "Book: " << title << endl;
        cout << "Copies: " << copies << endl;
    }
};

int main() {
    Book b1;
    Book b2("C++ Programming");
    Book b3("Java Programming", 5);

    cout << "Book 1:" << endl;
    b1.display();

    cout << "\nBook 2:" << endl;
    b2.display();

    cout << "\nBook 3:" << endl;
    b3.display();

    return 0;
}
