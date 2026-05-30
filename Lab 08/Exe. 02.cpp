#include <iostream>
#include <string>

using namespace std;

class Character {
protected:
    string name;
    int level, health;

public:
    Character(string n, int l, int h) : name(n), level(l), health(h) {}
    
    virtual void showStats() {
        cout << "Name: " << name << " | Level: " << level << " | HP: " << health << endl;
    }
    
    virtual ~Character() {} 
};
class Warrior : virtual public Character {
protected:
    int strength;

public:
    Warrior(string n, int l, int h, int s) : Character(n, l, h), strength(s) {}
    
    void slash() { 
        cout << name << " uses SLASH! (Dmg: " << strength * 2 << ")" << endl; 
    }
};

class Mage : virtual public Character {
protected:
    int intelligence;

public:
    Mage(string n, int l, int h, int i) : Character(n, l, h), intelligence(i) {}
    
    void fireball() { 
        cout << name << " casts FIREBALL! (Dmg: " << intelligence * 3 << ")" << endl; 
    }
};

class Mighty : public Warrior, public Mage {
public:
    Mighty(string n, int l, int h, int s, int i)
        : Character(n, l, h), Warrior(n, l, h, s), Mage(n, l, h, i) {}

    void showStats() override {
        Character::showStats(); // Calls base class implementation
        cout << "Attributes: [STR: " << strength << "] [INT: " << intelligence << "]" << endl;
    }
};

int main() {
    Mighty hero("Aragon the Wise", 15, 250, 80, 75);

    hero.showStats();
    hero.slash();
    hero.fireball();

    return 0;
}
