#include <iostream>
using namespace std;
class DynamicArray {
private:
    int* arr;     
    int size_;  

public:
    DynamicArray(int s) {
        size_ = s;
        arr = new int[size_];
        for (int i = 0; i < size_; i++) {
            arr[i] = 0;
        }
    }

    void push(int value) {
        int* newArr = new int[size_ + 1];
        for (int i = 0; i < size_; i++) {
            newArr[i] = arr[i];
        }

        newArr[size_] = value;
        delete[] arr;
        arr = newArr;
        size_++;
    }

    int size() const {
        return size_;
    }
    
    void display() const {
        for (int i = 0; i < size_; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {

    DynamicArray obj(3); 
    cout << "Initial Array: ";
    obj.display();
    cout << "Size of array: " << obj.size() << endl;

    obj.push(10);
    obj.push(20);

    cout << "After Pushing: ";
    obj.display();

    cout << "Size of array: " << obj.size() << endl;

    return 0;
}
