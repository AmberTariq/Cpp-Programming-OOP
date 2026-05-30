#include <iostream>
#include <string>
using namespace std;

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
        cout << name << " | Salary: $" << salary << endl;
    }

    friend void updateSalaryFunc(Employee &e, double newSalary);
};

void updateSalaryFunc(Employee &e, double newSalary) {
    e.salary = newSalary;
    cout << "Global Function: Salary updated for " << e.name << endl;
}

int main() {
    Employee emp("Bob", 102, "Manager", 70000);
    
    emp.display();
    updateSalaryFunc(emp, 75000);
    emp.display();

    return 0;
}
