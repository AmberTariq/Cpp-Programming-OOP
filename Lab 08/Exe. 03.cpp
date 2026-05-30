#include <iostream>
using namespace std;

// Base Class
class Account {
protected:
    double balance;
public:
    Account() : balance(0) {}
    Account(double b) : balance(b) {}

    virtual void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient funds." << endl;
    }
    void checkBalance() { cout << "Balance: Rs. " << balance << endl; }
    virtual ~Account() {} // Virtual destructor for safe inheritance
};

// Level 1: Interest Account (Virtual Inheritance)
class InterestAccount : virtual public Account {
public:
    InterestAccount(double b) : Account(b) {}
    
    void deposit(double amount) override {
        double interest = amount * 0.30; // 30% interest
        balance += (amount + interest);
        cout << "Interest added. New deposit: " << (amount + interest) << endl;
    }
};

// Level 1: Charging Account (Virtual Inheritance)
class ChargingAccount : virtual public Account {
protected:
    const double fee = 25.0;
public:
    ChargingAccount(double b) : Account(b) {}
    
    void withdraw(double amount) override {
        if ((amount + fee) <= balance) {
            balance -= (amount + fee);
            cout << "Withdrawn: " << amount << " | Fee: " << fee << endl;
        } else {
            cout << "Insufficient funds for withdrawal + fee." << endl;
        }
    }
};

// Level 2: Multiple Inheritance (Diamond Problem Resolved via Virtual inheritance)
class ACI : public InterestAccount, public ChargingAccount {
public:
    ACI(double b) : Account(b), InterestAccount(b), ChargingAccount(b) {}

    // Overloaded Transfer functions
    void transfer(double amount, Account &obj) {
        this->withdraw(amount);
        obj.deposit(amount);
    }

    void transfer(double amount, InterestAccount &obj) {
        this->withdraw(amount);
        obj.deposit(amount);
    }

    void transfer(double amount, ChargingAccount &obj) {
        this->withdraw(amount);
        obj.deposit(amount); 
    }
};

int main() {
    // Creating objects
    ACI myAcc(1000);
    InterestAccount savings(500);

    cout << "--- Initial ---" << endl;
    myAcc.checkBalance();

    cout << "\n--- Depositing 1000 (30% interest applies) ---" << endl;
    myAcc.deposit(1000);
    myAcc.checkBalance();

    cout << "\n--- Transferring 500 to Savings ---" << endl;
    myAcc.transfer(500, savings);

    cout << "\n--- Final Balances ---" << endl;
    cout << "My ACI "; myAcc.checkBalance();
    cout << "Savings "; savings.checkBalance();

    return 0;
}
