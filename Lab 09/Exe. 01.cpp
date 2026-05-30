#include <iostream>
using namespace std;

class ArrayMultiplier {
public:
    virtual void calculate() = 0; // Pure virtual function
};

class ArrayMultiplier1D : public ArrayMultiplier {
public:
    void calculate() {
        int arr[3] = {1, 2, 3};
        int res = 1;
        for(int i=0; i<3; i++) res *= arr[i];
        cout << "1D Array Product: " << res << endl;
    }
};

class ArrayMultiplier2D : public ArrayMultiplier {
public:
    void calculate() {
        int arr[2][2] = {{1, 2}, {3, 4}};
        int res = 1;
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++) res *= arr[i][j];
        cout << "2D Array Product: " << res << endl;
    }
};

int main() {
    ArrayMultiplier *m1 = new ArrayMultiplier1D();
    ArrayMultiplier *m2 = new ArrayMultiplier2D();
    m1->calculate();
    m2->calculate();
    return 0;
}
