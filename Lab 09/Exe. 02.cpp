#include <iostream>
using namespace std;

class Store {
protected:
    double total_bill;
public:
    Store(double b) { total_bill = b; }
    virtual void finalBill() = 0;
};

class ImtiazStore : public Store {
public:
    ImtiazStore(double b) : Store(b) {}
    void finalBill() {
        cout << "Imtiaz Bill (7% off): " << total_bill * 0.93 << endl;
    }
};

class BinHashimStore : public Store {
public:
    BinHashimStore(double b) : Store(b) {}
    void finalBill() {
        cout << "Bin Hashim Bill (5% off): " << total_bill * 0.95 << endl;
    }
};

int main() {
    Store *s1 = new ImtiazStore(1000);
    Store *s2 = new BinHashimStore(1000);
    s1->finalBill();
    s2->finalBill();
    return 0;
}
