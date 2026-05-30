#include <iostream>

class Base {
private:
    int privateInt = 10;
protected:
    int protectedInt = 20;
public:
    int publicInt = 30;

    int getPrivateInt() const { return privateInt; }
    void setPrivateInt(int val) { privateInt = val; }

    int getProtectedInt() const { return protectedInt; }
    void setProtectedInt(int val) { protectedInt = val; }

    int getPublicInt() const { return publicInt; }
    void setPublicInt(int val) { publicInt = val; }
};


class PublicChild : public Base {
public:
    void demonstrateAccess() {
        std::cout << "\n[PublicChild Inside Member Function]\n";
        // Cannot access privateInt directly. Must use getter/setter.
        std::cout << "Private Member (via Getter): " << getPrivateInt() << "\n";
        
        // protectedInt stays protected. Accessible directly inside child.
        std::cout << "Protected Member (Direct): " << protectedInt << "\n";
        
        // publicInt stays public. Accessible directly inside child.
        std::cout << "Public Member (Direct): " << publicInt << "\n";
    }
};

class ProtectedChild : protected Base {
public:
    void demonstrateAccess() {
        std::cout << "\n[ProtectedChild Inside Member Function]\n";
        // Cannot access privateInt directly. Must use getter/setter.
        std::cout << "Private Member (via Getter): " << getPrivateInt() << "\n";
        
        // protectedInt stays protected. Accessible directly inside child.
        std::cout << "Protected Member (Direct): " << protectedInt << "\n";
        
        // publicInt becomes protected. Accessible directly inside child.
        std::cout << "Public Member (Direct): " << publicInt << "\n";
    }
};

class PrivateChild : private Base {
public:
    void demonstrateAccess() {
        std::cout << "\n[PrivateChild Inside Member Function]\n";
        // Cannot access privateInt directly. Must use getter/setter.
        std::cout << "Private Member (via Getter): " << getPrivateInt() << "\n";
        
        // protectedInt becomes private. Accessible directly inside child.
        std::cout << "Protected Member (Direct): " << protectedInt << "\n";
        
        // publicInt becomes private. Accessible directly inside child.
        std::cout << "Public Member (Direct): " << publicInt << "\n";
    }
};

int main() {

    PublicChild pubObj;
    pubObj.demonstrateAccess();
    std::cout << "\n[Main Function - PublicChild Object]\n";
    std::cout << "Accessing publicInt directly: " << pubObj.publicInt << "\n";
    std::cout << "Accessing privateInt via getter: " << pubObj.getPrivateInt() << "\n";
    std::cout << "Accessing protectedInt via getter: " << pubObj.getProtectedInt() << "\n";

    ProtectedChild protObj;
    protObj.demonstrateAccess();
    std::cout << "\n[Main Function - ProtectedChild Object]\n";
    std::cout << "Direct access to publicInt/protectedInt is BLOCKED.\n";
    std::cout << "Base getters/setters are protected. BLOCKED in main.\n";

    PrivateChild privObj;
    privObj.demonstrateAccess();
    std::cout << "\n[Main Function - PrivateChild Object]\n";
    std::cout << "Direct access to publicInt/protectedInt is BLOCKED.\n";
    std::cout << "Base getters/setters are private. BLOCKED in main.\n";

    return 0;
}
