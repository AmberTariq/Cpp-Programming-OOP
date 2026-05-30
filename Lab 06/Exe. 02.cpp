#include <iostream>
using namespace std;

class Calculator{
private:
    double Num1, Num2, Num3;

public:
    Calculator() {
        cout << "--- Initializing Calculator ---" << endl;
        cout << "Enter value for Number 1: ";
        cin >> Num1;
        cout << "Enter value for Number 2: ";
        cin >> Num2;
        cout << "Enter value for Number 3: ";
        cin >> Num3;
        cout << "-------------------------------" << endl;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(double a, double b, double c) {
        return a + b + c;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double multiply(double a, double b, double c) {
        return a * b * c;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }

    void demonstrate() {
        cout << "\nDemonstrating Overloaded Functions:" << endl;

        cout << "Addition (2 inputs: Num1 + Num2): " << add(Num1, Num2) << endl;
        cout << "Addition (3 inputs: Num1 + Num2 + Num3): " << add(Num1, Num2, Num3) << endl;

        cout << "Multiplication (2 inputs: Num1 * Num2): " << multiply(Num1, Num2) << endl;
        cout << "Multiplication (3 inputs: Num1 * Num2 * Num3): " << multiply(Num1, Num2, Num3) << endl;

        cout << "Subtraction (Num1 - Num2): " << subtract(Num1, Num2) << endl;
        cout << "Division (Num1 / Num2): " << divide(Num1, Num2) << endl;
    }
};

int main() {
    Calculator myCalc;

    myCalc.demonstrate();

    return 0;
}
