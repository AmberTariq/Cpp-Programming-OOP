#include<iostream>
#include<string>
#include<exception>
#include<cctype>

using namespace std;
class InvalidPasswordException : public exception {
    string message;
    public:
    InvalidPasswordException(string msg) : message(msg) { }
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};  

void validateLogin(string Username, string password){
    if (password.length()<6){
        throw InvalidPasswordException("Password length must be at least 6 character long!");
    }
    bool hasDigit=false;
    for(char ch: password){
        if(isdigit(ch)) {
            hasDigit = true;
            break;
        }
    }
    
    if(!hasDigit){
        throw InvalidPasswordException("Password must contain at least one digit!");
    }
    
    cout<<"Successful Registration! Account created for "<<Username<<endl;
}

int main() {
    string username, password;
    
    cout << "=== Secure Account Registration ===" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    try {
        validateLogin(username, password);
    } 
    catch (const InvalidPasswordException& e) {
        cout << "\n[SECURITY ERROR] " << e.what() << endl;
    }
    
    return 0;
}
