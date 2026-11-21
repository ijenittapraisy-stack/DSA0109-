
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int id;
    string phone;

    Person(string n, int i, string p) {
        name = n;
        id = i;
        phone = p;
    }
};

class Student : virtual public Person {
public:
    string program;
    double cgpa;

    Student(string n, int i, string p, string pr, double c)
        : Person(n, i, p) {
        program = pr;
        cgpa = c;
    }
};

class Staff : virtual public Person {
public:
    string department;
    double salary;

    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p) {
        department = d;
        salary = s;
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string pr, double c,
                      string d, double s)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {}
};

class ResearchScholar : public Student {
public:
    double fellowship;

    ResearchScholar(string n, int i, string p,
                    string pr, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, pr, c) {
        fellowship = f;
    }
};

int main() {
    TeachingAssistant ta("Ravi", 101, "9876543210",
                         "IT", 8.5, "CSE", 30000);

    ResearchScholar rs("Kavi", 102, "9876543211",
                       "CSE", 9.0, 15000);

    cout << "TEACHING ASSISTANT\n";
    cout << "Name: " << ta.name << endl;
    cout << "ID: " << ta.id << endl;
    cout << "Programme: " << ta.program << endl;
    cout << "CGPA: " << ta.cgpa << endl;
    cout << "Department: " << ta.department << endl;
    cout << "Salary: " << ta.salary << endl;

    cout << "\nRESEARCH SCHOLAR\n";
    cout << "Name: " << rs.name << endl;
    cout << "Programme: " << rs.program << endl;
    cout << "CGPA: " << rs.cgpa << endl;
    cout << "Fellowship: " << rs.fellowship << endl;

    return 0;
}
