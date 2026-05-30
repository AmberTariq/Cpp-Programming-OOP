#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string carId, brand;
    bool available = true;
    virtual bool isAvailable() = 0;
    virtual void rent() = 0;
};

class Car : public Vehicle {
public:
    Car(string id, string b) { carId = id; brand = b; }
    bool isAvailable() { return available; }
    void rent() { available = false; cout << brand << "| Car Id: "<<carId<<" rented successfully.\n"; }
};

class RentalSystem {
public:
    void rentVehicle(Vehicle *v) {
        if(v->isAvailable() && v!=nullptr) v->rent();
        else cout << "Vehicle not available.\n";
    }
};

int main() {
    Vehicle* list[2];
    list[0] = new Car("101", "Toyota");
    list[1] = new Car("102", "Honda");

    RentalSystem sys;
    sys.rentVehicle(list[0]);
    sys.rentVehicle(list[1]);
    return 0;
}
