#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
protected:
    string name;
    int quantity;

public:
    Item(string n, int q) : name(n), quantity(q) {}
    virtual ~Item() {}
    
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    
    virtual double calculateSubtotal() = 0; 
};

class BakedGoods : public Item {
protected:
    double discount = 0.10; // 10% discount

public:
    BakedGoods(string n, int q) : Item(n, q) {}
};

class Cakes : public BakedGoods {
private:
    double price = 600.0;

public:
    Cakes(int q) : BakedGoods("Cake", q) {}
    
    double calculateSubtotal() override {
        double totalBeforeDiscount = price * quantity;
        return totalBeforeDiscount * (1.0 - discount);
    }
};

class Bread : public BakedGoods {
private:
    double price = 200.0;

public:
    Bread(int q) : BakedGoods("Bread", q) {}
    
    double calculateSubtotal() override {
        double totalBeforeDiscount = price * quantity;
        return totalBeforeDiscount * (1.0 - discount);
    }
};

class Drinks : public Item {
private:
    double discount = 0.05; // 5% discount
    double price = 100.0;

public:
    Drinks(int q) : Item("Drink", q) {}
    
    double calculateSubtotal() override {
        double totalBeforeDiscount = price * quantity;
        return totalBeforeDiscount * (1.0 - discount);
    }
};

int main() {
    int cakesQty = 0, breadQty = 0, drinksQty = 0;

    cout << "--- Bakery Billing Input ---\n";
    cout << "Enter quantity of Cakes ordered: ";
    cin >> cakesQty;
    cout << "Enter quantity of Bread ordered: ";
    cin >> breadQty;
    cout << "Enter quantity of Drinks ordered: ";
    cin >> drinksQty;

    vector<Item*> orderReceipt;
    if (cakesQty > 0) orderReceipt.push_back(new Cakes(cakesQty));
    if (breadQty > 0) orderReceipt.push_back(new Bread(breadQty));
    if (drinksQty > 0) orderReceipt.push_back(new Drinks(drinksQty));

    double grandTotal = 0.0;
    cout << "\n================ RECEIPT ================\n";
    for (Item* item : orderReceipt) {
        double itemTotal = item->calculateSubtotal();
        cout << item->getName() << " x " << item->getQuantity() 
             << " \t Subtotal (with discount): Rs. " << itemTotal << "\n";
        grandTotal += itemTotal;
    }
    cout << "-----------------------------------------\n";
    cout << "Grand Total Bill: Rs. " << grandTotal << "\n";
    cout << "=========================================\n";

    // Clean up dynamic memory
    for (Item* item : orderReceipt) {
        delete item;
    }

    return 0;
}
