#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> guestList;
    string inputName;

    cout << "=== Premium Event Management System ===" << endl;
    cout << "Begin adding guests below. Type 'stop' or 'exit' once the entry group is finalized.\n" << endl;

    while (true) {
        cout << "Enter guest name: ";
        getline(cin, inputName);

        // Standard exit check routine
        if (inputName == "stop" || inputName == "Stop" || inputName == "exit" || inputName == "Exit") {
            break;
        }

        if (inputName.empty()) {
            cout << "[Warning]: Empty entries are bypassed." << endl;
            continue;
        }

        // structural return flags to inform user of filter performance.
        auto result = guestList.insert(inputName);
        if (!re sult.second) {
            cout << " -> Notice: '" << inputName << "' is a duplicate and was filtered out." << endl;
        }
    }

    cout << "\n=== Final Verified Guest List Directory ===" << endl;
    int index = 1;
    for (const string& guest : guestList) {
        cout << index++ << ". " << guest << endl;
    }

    cout << "\nTotal verified unique attendees: " << guestList.size() << endl;

    return 0;
}
