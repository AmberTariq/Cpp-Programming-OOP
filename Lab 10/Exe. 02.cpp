#include <iostream>
using namespace std;

template <typename T1, typename T2>
void universalSwap(T1 &a, T2 &b) {
    cout << "Original values: " << a << " and " << b << endl;
    T1 temp = a;
    a = (T1)b; 
    b = (T2)temp;
    cout << "Swapped values: " << a << " and " << b << endl;
}

int main() {
    int x = 5;
    double y = 10.5;
    universalSwap(x, y);
    return 0;
}
