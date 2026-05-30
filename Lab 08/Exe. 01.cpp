#include <iostream>
#include <string>

using namespace std;

// Base Class
class Vehicle {
protected:
    string type, make, model, color;
    int year;
    double milesDriven;

public:
    Vehicle(string t, string mk, string md, string c, int y, double m)
        : type(t), make(mk), model(md), color(c), year(y), milesDriven(m) {}

    virtual void display() {
        cout << "Type: " << type 
             << "\nMake: " << make 
             << "\nModel: " << model
             << "\nColor: " << color 
             << "\nYear: " << year 
             << "\nMiles: " << milesDriven << endl;
    }
    
    virtual ~Vehicle() {} // Virtual destructor for safe polymorphism
};

class GasVehicle : virtual public Vehicle {
protected:
    double fuelTankSize;

public:
    GasVehicle(string t, string mk, string md, string c, int y, double m, double f)
        : Vehicle(t, mk, md, c, y, m), fuelTankSize(f) {}
};

class ElectricVehicle : virtual public Vehicle {
protected:
    double energyStorage;

public:
    ElectricVehicle(string t, string mk, string md, string c, int y, double m, double e)
        : Vehicle(t, mk, md, c, y, m), energyStorage(e) {}
};

// Level 2: Performance and Weight
class HighPerformance : public GasVehicle {
protected: 
    int horsePower;
    double topSpeed;

public:

    HighPerformance(string t, string mk, string md, string c, int y, double m, double f, int hp, double ts)
        : Vehicle(t, mk, md, c, y, m), GasVehicle(t, mk, md, c, y, m, f), horsePower(hp), topSpeed(ts) {}
        
    void display() override {
        Vehicle::display();
        cout << "Fuel Tank: " << fuelTankSize << "L\nHorsepower: " << horsePower 
             << " HP\nTop Speed: " << topSpeed << " mph" << endl;
    }
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle {
protected:
    double maxWeight;
    int numWheels;
    double length;

public:
    HeavyVehicle(string t, string mk, string md, string c, int y, double m, double f, double e, double w, int wh, double l)
        : Vehicle(t, mk, md, c, y, m), GasVehicle(t, mk, md, c, y, m, f), ElectricVehicle(t, mk, md, c, y, m, e),
          maxWeight(w), numWheels(wh), length(l) {}
};

class Bus : public HeavyVehicle {
    int numSeats;

public:
    Bus(string t, string mk, string md, string c, int y, double m, double f, double e, double w, int wh, double l, int s)
        : Vehicle(t, mk, md, c, y, m), HeavyVehicle(t, mk, md, c, y, m, f, e, w, wh, l), numSeats(s) {}

    void display() override {
        Vehicle::display(); // Show base vehicle info
        cout << "Seats: " << numSeats 
             << "\nFuel Tank: " << fuelTankSize 
             << "L\nEnergy: " << energyStorage << " kWh" 
             << "\nMax Weight: " << maxWeight << " kg"
             << "\nWheels: " << numWheels 
             << "\nLength: " << length << "m" << endl;
    }
};

int main() {

    Bus myBus("Transit", "Volvo", "9700", "White", 2023, 500.5, 300.0, 150.0, 18000.0, 6, 12.5, 55);

    cout << "--- Bus Details ---" << endl;
    myBus.display();

    return 0;
}
