#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Custom sorting implementation (Bubble Sort)
void customSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of integers to generate/sort: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    // Initialize two identical arrays with pseudo-random numbers for fair benchmarking
    vector<int> vectorForCustom;
    vector<int> vectorForSTL;
    
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int val = rand() % 100; 
        vectorForCustom.push_back(val);
        vectorForSTL.push_back(val);
    }

    if (n <= 20) {
        cout << "\nInitial unsorted generated array: ";
        printVector(vectorForCustom);
    }

    // 1. Benchmarking Custom Sort
    auto startCustom = high_resolution_clock::now();
    customSort(vectorForCustom);
    auto stopCustom = high_resolution_clock::now();
    auto durationCustom = duration_cast<microseconds>(stopCustom - startCustom);

    // 2. Benchmarking STL Sort
    auto startSTL = high_resolution_clock::now();
    sort(vectorForSTL.begin(), vectorForSTL.end());
    auto stopSTL = high_resolution_clock::now();
    auto durationSTL = duration_cast<microseconds>(stopSTL - startSTL);

    if (n <= 20) {
        cout << "Sorted array output: ";
        printVector(vectorForSTL);
    }

    cout << "\n=== Performance Benchmarking Results ===" << endl;
    cout << "Time taken by Custom Sort: " << durationCustom.count() << " microseconds" << endl;
    cout << "Time taken by STL Sort:    " << durationSTL.count() << " microseconds" << endl;

    return 0;
}
