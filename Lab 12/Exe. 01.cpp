#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Calculate length
    int length = inputString.length();
    cout << "Length of the entered string: " << length << " characters." << endl;

    // Writing to file
    ofstream outFile("characters.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }
    outFile << inputString;
    outFile.close();
    cout << "String successfully saved to 'characters.txt'." << endl;

    // reading from file
    ifstream inFile("characters.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "Fetching characters from file: ";
    char ch;
    while (inFile.get(ch)) {
        cout << ch;
    }
    cout << endl;
    inFile.close();

    return 0;
}
