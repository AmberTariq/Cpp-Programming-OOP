#include <iostream>
using namespace std;

template <class T1, class T2>
class Calculator {
public:
    void displayResults(T1 a, T2 b) {
        cout << "Sum: " << a + b << endl;
        cout << "Sub: " << a - b << endl;
        cout << "Mul: " << a * b << endl;
        cout << "Div: " << a / b << endl;
    }
};

int main() {
    Calculator<int, double> calc;
    calc.displayResults(10, 2.5);
    return 0;
}


