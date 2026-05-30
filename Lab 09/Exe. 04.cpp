#include <iostream>
using namespace std;

class EncryptionTechnique {
public:
    virtual void encrypt(string text) = 0;
};

class EncryptionTechnique1 : public EncryptionTechnique {
public:
    void encrypt(string text) {

        cout << "Technique 1: ";

        for (char ch : text) {
            cout << int(ch) << " ";
        }

        cout << endl;
    }
};

class EncryptionTechnique2 : public EncryptionTechnique {
public:
    void encrypt(string text) {

        cout << "Technique 2: ";

        for (char ch : text) {
            cout << int(ch) + 2 << " ";
        }

        cout << endl;
    }
};

int main() {

    string msg;

    cout << "Enter message: ";
    getline(cin, msg);

    EncryptionTechnique1 t1;
    EncryptionTechnique2 t2;

    t1.encrypt(msg);
    t2.encrypt(msg);

    return 0;
}
