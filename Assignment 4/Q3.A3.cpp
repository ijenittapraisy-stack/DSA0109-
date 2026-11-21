
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Person Constructor\n";
    }

    ~Person() {
        cout << "Person Destructor\n";
    }
};

class Address {
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {
        cout << "Address Constructor\n";
    }

    ~Address() {
        cout << "Address Destructor\n";
    }

    string display() {
        return city + "-" + to_string(pin);
    }
};

class Student : public Person {
    long long regNo;
    Address home;

public:
    Student(string n, int a, long long r, string c, int p)
        : Person(n, a), regNo(r), home(c, p) {
        cout << "Student Constructor\n";
    }

    ~Student() {
        cout << "Student Destructor\n";
    }

    void print() {
        cout << regNo << " " << name
             << " (" << age << ") "
             << home.display() << endl;
    }
};

int main() {
    Student s("Kavya", 19, 192311001, "Salem", 636001);

    s.print();

    return 0;
}
