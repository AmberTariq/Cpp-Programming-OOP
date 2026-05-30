#include <iostream>
#include <string>
using namespace std;

class Payroll; 

class Employee {
private:
    string name;
    int id;
    string designation;
    double salary;

public:
    Employee(string n, int i, string d, double s) 
        : name(n), id(i), designation(d), salary(s) {}

    void display() {
        cout << name << " (" << designation << ") - ID: " << id 
             << " | Current Salary: $" << salary << endl;
    }
    friend class Payroll; 
};

class Payroll {
public:
    void updateSalary(Employee &e, double newSalary) {
        // Payroll can access e.salary directly because it is a friend
        e.salary = newSalary;
        cout << "Salary updated successfully for " << e.name << endl;
    }
};

int main() {
    Employee emp("Alice", 101, "Software Engineer", 50000);
    Payroll system;

    emp.display();
    system.updateSalary(emp, 55000); // Payroll modifies private salary
    emp.display();

    return 0;
}
