#include <iostream>
using namespace std;

template <class T>
class mycontainer {
    T element;

public:
    mycontainer(T arg) {
        element = arg;
    }

    void increase() {
        cout << "Original: " << element << endl;
        element++;
        cout << "Increased: " << element << endl;
    }
};

template <>
class mycontainer<char> {
    char element;

public:
    mycontainer(char arg) {
        element = arg;
    }

    void uppercase() {

        cout << "Original Character: " << element << endl;
        if (element >= 'a' && element <= 'z')
            element = element - 32;
        cout << "Uppercase: " << element << endl;
    }
};

int main() {

    mycontainer<int> obj1(10);
    obj1.increase();

    cout << endl;

    mycontainer<char> obj2('b');
    obj2.uppercase();

    return 0;
}
