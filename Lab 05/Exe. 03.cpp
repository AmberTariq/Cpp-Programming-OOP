#include <iostream>

using namespace std;

class Weapons {
public:
    void WeaponsDescription() {
        cout << "Weapons: Tools designed to inflict damage or provide defense.\n";
    }
};

class HotWeapons : public Weapons {
public:
    void HotWeaponsDescription() {
        cout << "Hot Weapons: Use gunpowder, chemical reactions, or heat to explode and fire.\n";
    }
};

class Bombs : public HotWeapons {
public:
    void BombsDescription() {
        cout << "Bombs: Detonate to blow up structures and targets via shockwaves.\n";
    }
};

class NuclearBombs : public Bombs {
public:
    void NuclearBombsDescription() {
        cout << "Nuclear Bombs: Blow up catastrophically, using nuclear fission and fusion.\n";
    }
};

int main() {
    NuclearBombs nuke;
    
    cout << "--- Weapon Hierarchy Description Output ---\n";
    nuke.WeaponsDescription();
    nuke.HotWeaponsDescription();
    nuke.BombsDescription();
    nuke.NuclearBombsDescription();
    
    return 0;
}
