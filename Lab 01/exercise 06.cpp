#include <iostream>
using namespace std;

float saving_acc(float total, float withdraw) {
    float fee = withdraw * 0.02;      // 2% fee
    float tax = 0;

    if (withdraw > 50000)
        tax = withdraw * 0.05;        // 5% tax

    return total - withdraw - fee - tax;
}

float current_acc(float total, float withdraw) {
    float fee = 100;                  // fixed fee
    float tax = 0;

    if (withdraw > 50000)
        tax = withdraw * 0.05;        // 5% tax

    return total - withdraw - fee - tax;
}

int main() {
    float total_amount = 200000;
    float withdraw;
    char acc_type;
    int acc_no;

    cout << "Enter your 6-digit account number: ";
    cin >> acc_no;

    cout << "Select account type (S for Savings / C for Current): ";
    cin >> acc_type;

    cout << "Enter withdrawal amount: ";
    cin >> withdraw;

    if (withdraw > 100000 || withdraw <= 0) {
        cout << "Invalid withdrawal amount!" << endl;
        return 0;
    }

    float remaining;

    switch (acc_type) {
        case 'S':
        case 's':
            remaining = saving_acc(total_amount, withdraw);
            break;

        case 'C':
        case 'c':
            remaining = current_acc(total_amount, withdraw);
            break;

        default:
            cout << "Invalid account type!" << endl;
            return 0;
    }

    cout << withdraw << " amount successfully withdrawn!" << endl;
    cout << "Remaining Balance: " << remaining << endl;
    cout << "Thank you for using online banking!" << endl;

    return 0;
}
