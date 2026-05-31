#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Person {
public:
    char name[50]; 
    int age;

    // Parameterized constructor
    Person(const char* pName, int pAge) {
        strcpy(name, pName);
        age = pAge;
    }

    // Default constructor needed for empty initialization before reading
    Person() {
        strcpy(name, "");
        age = 0;
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {

    Person person1("Alice Smith", 21);

    ofstream binWrite("person.bin", ios::binary);
    if (!binWrite) {
        cout << "Error opening binary file for writing!" << endl;
        return 1;
    }
    binWrite.write(reinterpret_cast<char*>(&person1), sizeof(Person));
    binWrite.close();
    cout << "person1 object successfully written to 'person.bin'." << endl;

    Person readPerson;
    ifstream binRead("person.bin", ios::binary);
    if (!binRead) {
        cout << "Error opening binary file for reading!" << endl;
        return 1;
    }
    binRead.read(reinterpret_cast<char*>(&readPerson), sizeof(Person));
    binRead.close();

    cout << "\nData successfully read back from binary file:" << endl;
    readPerson.display();

    return 0;
}


