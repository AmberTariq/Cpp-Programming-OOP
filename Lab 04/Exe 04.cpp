#include <iostream>
using namespace std;
// Scenario: Bank Account (Account number should not change)
class Account {
private:
    const int account_no;
    double balance;

public:
    Account(int no, double bal) : account_no(no), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
    }

    void display() const {   // const member function
        cout << "Account No: " << account_no << endl;
        cout << "Balance: " << balance << endl;
        cout << "-----------\n";
    }
};

int main() {

    Account a1(1001, 5000);

    a1.display();
    a1.deposit(2000);
    a1.display();

    return 0;
}
