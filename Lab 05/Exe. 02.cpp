#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    string name;
    int age;
    string institute;

public:
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setInstitute(string i) { institute = i; }
    
    string getName() { return name; }
    int getAge() { return age; }
    string getInstitute() { return institute; }
};

class HumanitiesTeacher : public Teacher {
private:
    string department = "Humanities";
    string courseName;
    string designation;

public:
    void setCourse(string c) { courseName = c; }
    void setDesignation(string d) { designation = d; }
    
    void display() {
        cout << "\nHumanities Teacher\n";
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Institute: " << getInstitute() << endl;
        cout << "Department: " << department << endl;
        cout << "Course: " << courseName << endl;
        cout << "Designation: " << designation << endl;
    }
};

class ScienceTeacher : public Teacher {
private:
    string department = "Science";
    string courseName;
    string designation;

public:
    void setCourse(string c) { courseName = c; }
    void setDesignation(string d) { designation = d; }
    
    void display() {
        cout << "\nScience Teacher\n";
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Institute: " << getInstitute() << endl;
        cout << "Department: " << department << endl;
        cout << "Course: " << courseName << endl;
        cout << "Designation: " << designation << endl;
    }
};

class MathsTeacher : public Teacher {
private:
    string department = "Maths";
    string courseName;
    string designation;

public:
    void setCourse(string c) { courseName = c; }
    void setDesignation(string d) { designation = d; }
    
    void display() {
        cout << "\nMaths Teacher\n";
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Institute: " << getInstitute() << endl;
        cout << "Department: " << department << endl;
        cout << "Course: " << courseName << endl;
        cout << "Designation: " << designation << endl;
    }
};

int main() {
    HumanitiesTeacher h;
    ScienceTeacher s;
    MathsTeacher m;
    
    string name, institute, course, designation;
    int age;
    
    cout << "Enter Humanities Teacher Details (Name Age Institute Course Designation):\n";
    cin >> name >> age >> institute >> course >> designation;
    h.setName(name); h.setAge(age); h.setInstitute(institute);
    h.setCourse(course); h.setDesignation(designation);
    h.display();
    
    cout << "\nEnter Science Teacher Details (Name Age Institute Course Designation):\n";
    cin >> name >> age >> institute >> course >> designation;
    s.setName(name); s.setAge(age); s.setInstitute(institute);
    s.setCourse(course); s.setDesignation(designation);
    s.display();
    
    cout << "\nEnter Maths Teacher Details (Name Age Institute Course Designation):\n";
    cin >> name >> age >> institute >> course >> designation;
    m.setName(name); m.setAge(age); m.setInstitute(institute);
    m.setCourse(course); m.setDesignation(designation);
    m.display();
    
    return 0;
}
