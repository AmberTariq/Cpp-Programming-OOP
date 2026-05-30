#include <iostream>
#include <cmath>
using namespace std;

class Vector {
public:
    double x, y;

    Vector(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    Vector operator+(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

    Vector operator-(const Vector& other) {
        return Vector(x - other.x, y - other.y);
    }

    Vector operator*(double scalar) {
        return Vector(x * scalar, y * scalar);
    }

    Vector operator/(double scalar) {
        if(scalar != 0)
            return Vector(x / scalar, y / scalar);
        else {
            cout << "Error: Division by zero!" << endl;
            return Vector(0, 0);
        }
    }

    double magnitude() {
        return sqrt((x * x) + (y * y));
    }

    void display() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Vector v1(3, 4);
    Vector v2(1, 2);

    cout << "V1: "; v1.display(); cout << endl;
    cout << "V2: "; v2.display(); cout << endl;

    Vector vSum = v1 + v2;
    cout << "Sum: "; vSum.display(); cout << endl;

    Vector vSub = v1 - v2;
    cout << "Subtraction: "; vSub.display(); cout << endl;

    Vector vScaled = v1 * 2.5;
    cout << "Scaled (v1 * 2.5): "; vScaled.display(); cout << endl;

    Vector vDiv = v1 / 2.0;
    cout << "Divided (v1 / 2.0): "; vDiv.display(); cout << endl;

    cout << "Magnitude of V1: " << v1.magnitude() << endl;

    return 0;
}
