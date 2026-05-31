#include <iostream>
#include <map>
#include <string>

using namespace std;

void displayMap(const map<string, char>& gradeBook) {
    if (gradeBook.empty()) {
        cout << "\nThe grade book database is currently empty." << endl;
        return;
    }
    cout << "\n--- Current Student Grade Directory ---" << endl;
    for (const auto& record : gradeBook) {
        cout << "Student Name: " << record.first << " \t| Grade: " << record.second << endl;
    }
    cout << "---------------------------------------" << endl;
}

void retrieveGrade(const map<string, char>& gradeBook) {
    string name;
    cout << "Enter the student name to query: ";
    cin.ignore();
    getline(cin, name);

    auto it = gradeBook.find(name);
    if (it != gradeBook.end()) {
        cout << "Found: " << name << " holds a grade of '" << it->second << "'." << endl;
    } else {
        cout << "Error: Records indicate that student '" << name << "' is not registered." << endl;
    }
}

void updateGrade(map<string, char>& gradeBook) {
    string name;
    cout << "Enter the student name to update: ";
    cin.ignore();
    getline(cin, name);

    auto it = gradeBook.find(name);
    if (it != gradeBook.end()) {
        char newGrade;
        cout << "Enter the new grade for " << name << ": ";
        cin >> newGrade;
        it->second = toupper(newGrade);
        cout << "Successfully updated " << name << "'s record to " << it->second << "." << endl;
    } else {
        cout << "Error: Update aborted. Student '" << name << "' not found." << endl;
    }
}

void deleteStudent(map<string, char>& gradeBook) {
    string name;
    cout << "Enter the student name to delete: ";
    cin.ignore();
    getline(cin, name);

    auto it = gradeBook.find(name);
    if (it != gradeBook.end()) {
        gradeBook.erase(it);
        cout << "Successfully dropped " << name << " from the database system." << endl;
    } else {
        cout << "Error: Deletion failed. Student '" << name << "' not found." << endl;
    }
}

int main() {
    map<string, char> gradeBook;
    int choice;

    cout << "=== Initial Gradebook Configuration Setup ===" << endl;
    while (true) {
        string name;
        char grade;
        cout << "Enter student name (or type 'stop' to finish initialization): ";
        if (gradeBook.empty()) cin.ignore(); // Clean up standard buffer paths
        getline(cin, name);
        if (name == "stop" || name == "Stop") break;

        cout << "Enter student letter grade: ";
        cin >> grade;
        cin.ignore(); // Clear newline buffer
        
        gradeBook[name] = toupper(grade);
    }

    // Menu Driven Test Suite loops until terminated by engineer selection
    do {
        cout << "\n=== Interactive Map Management Suite ===" << endl;
        cout << "1. Display All Records" << endl;
        cout << "2. Retrieve a Student's Grade" << endl;
        cout << "3. Update a Student's Grade" << endl;
        cout << "4. Delete a Student Entry" << endl;
        cout << "5. Terminate Program" << endl;
        cout << "Enter your operational choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: displayMap(gradeBook); break;
            case 2: retrieveGrade(gradeBook); break;
            case 3: updateGrade(gradeBook); break;
            case 4: deleteStudent(gradeBook); break;
            case 5: cout << "Exiting operations suite safely." << endl; break;
            default: cout << "Invalid input option selected." << endl;
        }
    } while (choice != 5);

    return 0;
}
