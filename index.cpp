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

void addEmployee(string name, int id, string department) {
    cout << "Added employee: " << name << ", ID: " << id
         << ", Department: " << department << endl;
}

void addEmployee(string name, int id, string department, int teamSize) {
    cout << "Added manager: " << name << ", ID: " << id
         << ", Department: " << department << ", Team Size: " << teamSize << endl;
}


int main() {
    // Create Manager, Engineer, and Intern objects
    Manager m1("Alice", 101, "HR", 10, 1500);
    Engineer e1("Bob", 102, "IT", "Backend", 5);
    Intern i1("Charlie", 103, "IT", "Frontend", 2, 800);

    // Display details and calculate salaries
    m1.displayDetails();
    m1.calculateSalary();

    e1.displayDetails();
    e1.calculateSalary();

    i1.displayDetails();
    i1.calculateSalary();

    // Demonstrate function overloading
    addEmployee("Diana", 104, "Finance");
    addEmployee("Eve", 105, "Sales", 8);

    return 0;
}
