#include <iostream>
using namespace std;

class DArray{
    int** data;
    int r, c;
    
public:
    // Parametric Constructor
    DArray(int rows = 1, int cols = 1) : r(rows), c(cols) {
        data = new int*[r];
        for(int i = 0; i < r; ++i) { // Fixed: Changed i < c to i < r
            data[i] = new int[c]{0};
        }
    }
    
    // Copy Constructor
    DArray (const DArray& other) : r(other.r), c(other.c){
        data = new int*[r];
        for(int i = 0; i < r; ++i) {
            data[i] = new int[c];
            for(int j = 0; j < c; ++j) {
                data[i][j] = other.data[i][j];
            }
        } // Fixed: Added missing closing brace for the outer loop
    }
  
    // Destructor
    ~DArray(){
        for(int i = 0; i < r; ++i){
            delete[] data[i];
        }
        delete[] data;
    }
  
    int getRows() const{ return r; }
    int getCols() const{ return c; }
  
    int* operator[](int i) { return data[i]; }
  
    // Binary Search on Sorted 2D Grid
    bool exists(int target){
        int low = 0;
        int high = (r * c) - 1;
      
        while(low <= high){
            int mid = low + (high - low) / 2;
            int mid_val = data[mid / c][mid % c]; // Maps 1D index to 2D index
          
            if(mid_val == target) return true;
            else if(mid_val < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
  
    void display() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{  
    DArray matrix(3, 4);
    
    // Row 0
    matrix[0][0] = 1;  matrix[0][1] = 3;  matrix[0][2] = 5;  matrix[0][3] = 7;
    // Row 1
    matrix[1][0] = 10; matrix[1][1] = 11; matrix[1][2] = 16; matrix[1][3] = 20;
    // Row 2
    matrix[2][0] = 23; matrix[2][1] = 30; matrix[2][2] = 34; matrix[2][3] = 60;

    int target1 = 3;
    int target2 = 13;

    cout << "Searching for " << target1 << ": " << (matrix.exists(target1) ? "true" : "false") << endl;
    cout << "Searching for " << target2 << ": " << (matrix.exists(target2) ? "true" : "false") << endl;
    return 0;
}
