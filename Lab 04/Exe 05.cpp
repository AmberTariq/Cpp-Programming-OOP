#include <iostream>
using namespace std;
class Hotel {
private:
    string name;
    int days;
    double rent;
    static const double rate;

public:
    Hotel(string n, int d) {
        name = n;
        days = d;
        rent = 0;
    }

    void calculateRent() {
        if (days > 7)
            rent = (days - 1) * rate;  
        else
            rent = days * rate;
    }

    void display() const {  
        cout << "Customer Name: " << name << endl;
        cout << "Days: " << days << endl;
        cout << "Rent: " << rent <<"/-" << endl;
    }
};

const double Hotel::rate = 1000.85;

int main() {

    Hotel c1("Ali", 4);
    Hotel c2("Sara", 9);

    c1.calculateRent();
    c2.calculateRent();

    c1.display();
    cout << "--------------" << endl;
    c2.display();

    return 0;
}
