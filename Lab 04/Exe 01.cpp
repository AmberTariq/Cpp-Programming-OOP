#include<iostream>
#include<cstring>
using namespace std;

class Employee {
private:
    char* EmployeeName;     
    const int EmployeeId;   

public:

    Employee(const char* name, int id) : EmployeeId(id) {
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }

    ~Employee() {
        delete[] EmployeeName;
    }
 
    void setName(const char* name) {
        delete[] EmployeeName; 
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }

    const char* getName() const {
        return EmployeeName;
    }

    int getId() const {
        return EmployeeId;
    }
    
};

int main() {

    Employee Employee1("Ayesha", 101);
    Employee Employee2("Zainab", 102);
    Employee Employee3("Usman", 103);

    cout << "Before Updating:\n";
    cout << Employee1.getName() << "  " << Employee1.getId() << endl;
    cout << Employee2.getName() << "  " << Employee2.getId() << endl;
    cout << Employee3.getName() << "  " << Employee3.getId() << endl;

    Employee1.setName("Abdullah");
    Employee2.setName("Sarah");

    cout << "\nAfter Updating:\n";
    cout << Employee1.getName() << "  " << Employee1.getId() << endl;
    cout << Employee2.getName() << "  " << Employee2.getId() << endl;
    cout << Employee3.getName() << "  " << Employee3.getId() << endl;

    return 0;
}



