#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countLinesNotStartingWithA() {
    ifstream file("STORY.TXT");
    if (!file) {
        cout << "Error: Could not open 'STORY.TXT'." << endl;
        return;
    }

    string line;
    int count = 0;

    while (getline(file, line)) {
        if (!line.empty()) {
            if (line[0] != 'A' || line[0] != 'a') {
                count++;
            }
        } else {
            count++; 
        }
    }

    file.close();
    cout << "The number of lines not starting with alphabet 'A' is: " << count << endl;
}

int main() {
    ofstream createStory("STORY.TXT");
    createStory << "The rose is red.\n";
    createStory << "A girl is playing there.\n";
    createStory << "There is a playground.\n";
    createStory << "An airplane is in the sky.\n";
    createStory << "Numbers are not allowed in the password.\n";
    createStory.close();

    countLinesNotStartingWithA();

    return 0;
}
