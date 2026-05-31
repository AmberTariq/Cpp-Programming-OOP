#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream createSource("source.txt");
    createSource << "This is the original content inside the source file.\nLine 2 of data.";
    createSource.close();

    ifstream sourceFile("source.txt");
    ofstream targetFile("destination.txt");

    if (!sourceFile) {
        cout << "Error: Could not open source file!" << endl;
        return 1;
    }
    if (!targetFile) {
        cout << "Error: Could not create destination file!" << endl;
        return 1;
    }

    string line;
    while (getline(sourceFile, line)) {
        targetFile << line << "\n";
    }

    cout << "Success: Contents copied from 'source.txt' to 'destination.txt'." << endl;

    sourceFile.close();
    targetFile.close();
    cout<<"==== Reading 'destination.txt' file ===="<<endl;
    ifstream readFile("destination.txt");
    if(!readFile){
        cout << "Error: Could not open destination file!" << endl;
        return 1;
    }
    string l;
    while(getline(readFile, l)) {
        cout<< l<<endl;
    }
  
    return 0;
}

