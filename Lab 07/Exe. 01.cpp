#include <iostream>
using namespace std;

class Dynamic2DArray {
    int r, c;
    int** data;

public:
    // Combined Default & Parameterized Constructor
    Dynamic2DArray(int rows = 1, int cols = 1) : r(rows), c(cols) {
        data = new int*[r];
        for (int i = 0; i < r; ++i) data[i] = new int[c]{0}; 
    }

    // Copy Constructor
    Dynamic2DArray(const Dynamic2DArray& other) : r(other.r), c(other.c) {
        data = new int*[r];
        for (int i = 0; i < r; ++i) {
            data[i] = new int[c];
            for (int j = 0; j < c; ++j) data[i][j] = other.data[i][j];
        }
    }

    // Destructor
    ~Dynamic2DArray() {
        for (int i = 0; i < r; ++i) delete[] data[i];
        delete[] data;
    }

    // Assignment Operator
    Dynamic2DArray& operator=(const Dynamic2DArray& other) {
        if (this == &other) return *this;
        this->~Dynamic2DArray(); // Clean up current memory
        r = other.r; c = other.c;
        data = new int*[r];
        for (int i = 0; i < r; ++i) {
            data[i] = new int[c];
            for (int j = 0; j < c; ++j) data[i][j] = other.data[i][j];
        }
        return *this;
    }

    // Indexing
    int* operator[](int i) { return data[i]; }

    // Overloaded + and -
    Dynamic2DArray operator+(const Dynamic2DArray& o) {
        Dynamic2DArray res(r, c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) res[i][j] = data[i][j] + o.data[i][j];
        return res;
    }

    Dynamic2DArray operator-(const Dynamic2DArray& o) {
        Dynamic2DArray res(r, c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) res[i][j] = data[i][j] - o.data[i][j];
        return res;
    }

    // Overloaded * (Matrix Multiplication)
    Dynamic2DArray operator*(const Dynamic2DArray& o) {
        Dynamic2DArray res(r, o.c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < o.c; j++)
                for (int k = 0; k < c; k++)
                    res[i][j] += data[i][k] * o.data[k][j];
        return res;
    }

    void display() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Dynamic2DArray A(2, 2), B(2, 2);
    
    // Assign values using the overloaded [] operator
    A[0][0] = 1; A[0][1] = 2; A[1][0] = 3; A[1][1] = 4;
    B[0][0] = 2; B[0][1] = 0; B[1][0] = 1; B[1][1] = 2;

    cout << "Matrix A:" << endl; A.display();
    cout << "Matrix B:" << endl; B.display();

    Dynamic2DArray C = A + B;
    cout << "A + B:" << endl; C.display();

    Dynamic2DArray D = A * B;
    cout << "A * B:" << endl; D.display();

    return 0;
}
