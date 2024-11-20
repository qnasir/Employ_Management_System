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

class Manager : public Employee {
    int teamSize;
    double bonus;

public:
    Manager(string n, int i, string dept, int t, double b)
        : Employee(n, i, dept), teamSize(t), bonus(b) {}

    void displayDetails() override {
        Employee::displayDetails();
        cout << "Team Size: " << teamSize << ", Bonus: $" << bonus << endl;
    }

    void calculateSalary() override {
        cout << "Manager Salary: $" << (5000 + bonus) << endl;
    }
};

class Engineer : public Employee {
    string specialization;
    int projectCount;

public:
    Engineer(string n, int i, string dept, string spec, int p)
        : Employee(n, i, dept), specialization(spec), projectCount(p) {}

    void displayDetails() override {
        Employee::displayDetails();
        cout << "Specialization: " << specialization
             << ", Projects: " << projectCount << endl;
    }

    void calculateSalary() override {
        cout << "Engineer Salary: $" << (4000 + projectCount * 200) << endl;
    }
};

class Intern : public Engineer {
    double stipend;

public:
    Intern(string n, int i, string dept, string spec, int p, double s)
        : Engineer(n, i, dept, spec, p), stipend(s) {}

    void displayDetails() override {
        Engineer::displayDetails();
        cout << "Stipend: $" << stipend << endl;
    }

    void calculateSalary() override {
        cout << "Intern Salary: $" << stipend << endl;
    }
};
