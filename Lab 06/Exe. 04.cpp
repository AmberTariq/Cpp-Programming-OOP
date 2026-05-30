#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string occupation;
public:
  
    Person(string _occupation) : occupation(_occupation) {}

    virtual ~Person() {}

    virtual void Draw() {
        cout << "A person can draw in many ways" << endl;
    }
};

class Artist : public Person {
public:
    Artist() : Person("artist") {}
    
    void Draw() override {
        cout << "An artist can draw with a paint brush" << endl;
    }
};

class Gunman : public Person {
public:
    Gunman() : Person("gunman") {}
    
    void Draw() override {
        cout << "A gunman draws a gun to shoot" << endl;
    }
};

int main() {
 
    Person* people[3];

    people[0] = new Person("None");
    people[1] = new Artist();
    people[2] = new Gunman();

    cout << "--- Calling Draw() Polymorphically ---" << endl;
    for(int i = 0; i < 3; i++) {
        people[i]->Draw();
    }

    for(int i = 0; i < 3; i++) {
        delete people[i];
    }

    return 0;
}
