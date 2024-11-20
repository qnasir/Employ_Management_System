#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name, department;
    int id;

public:
    Employee(string n, int i) : name(n), id(i), department("General") {}
    Employee(string n, int i, string dept) : name(n), id(i), department(dept) {}

    virtual void displayDetails() {
        cout << "Name: " << name << ", ID: " << id
             << ", Department: " << department << endl;
    }

    virtual void calculateSalary() = 0; // Pure virtual function
};
