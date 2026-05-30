#include <iostream>
#include <string>

using namespace std;

class Media {
protected:
    string title;
public:
    void setMedia(string t) { title = t; }
    void borrow() { cout << "Borrowed: " << title << endl; }
    void returnMedia() { cout << "Returned: " << title << endl; }
};

class Author {
protected:
    string name;
public:
    void setAuthor(string n) { name = n; }
};

class MagazineInfo {
protected:
    int issue;
public:
    void setIssue(int i) { issue = i; }
};

class Director {
protected:
    string dirName;
public:
    void setDirector(string d) { dirName = d; }
};

// Multiple Inheritance Configurations
class Book : public Media, public Author {
public:
    void display() { 
        cout << "Book: " << title << " | Author: " << name << endl; 
    }
};

class Magazine : public Media, public MagazineInfo {
public:
    void display() { 
        cout << "Magazine: " << title << " | Issue: #" << issue << endl; 
    }
};

class DVD : public Media, public Director {
public:
    void display() { 
        cout << "DVD: " << title << " | Director: " << dirName << endl; 
    }
};

int main() {
    Book b1;
    b1.setMedia("The Alchemist");
    b1.setAuthor("Paulo Coelho");

    DVD d1;
    d1.setMedia("Interstellar");
    d1.setDirector("Christopher Nolan");

    cout << "--- Library Inventory ---" << endl;
    b1.display();
    d1.display();

    cout << "\n--- Operations ---" << endl;
    b1.borrow();
    d1.returnMedia();

    return 0;
}
