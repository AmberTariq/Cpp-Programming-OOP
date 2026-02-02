#include <iostream>
#include <string>
using namespace std;

class BookType {
    string title;
    string authors[4];
    int no_ofAuthors;
    string publisher;
    string ISBN;
    double price;
    int no_ofCopies;

public:

    BookType() {
        title = "";
        no_ofAuthors = 0;
        publisher = "";
        ISBN = "";
        price = 0.0;
        no_ofCopies = 0;
    }

	void setTitle(string t) { title = t; }
	string getTitle() { return title; }
	bool isTitle(string t) { return title == t; }
	
	void setAuthors(string auth[], int n){
		if(n>4) n = 4;
	for (int i = 0; i < n; i++) {
			authors[i] = auth[i];
		}
		no_ofAuthors = n;
	}
	
	void show_authors(){
		for(int i = 0; i<no_ofAuthors; i++){
			cout << authors[i] << (i<no_ofAuthors-1? ",":"")<<endl;
		}
	}
	
	 void setPublisher(string p) { publisher = p; }
    string getPublisher() { return publisher; }

    void setISBN(string isbn) { ISBN = isbn; }
    string getISBN() { return ISBN; }
    bool isISBN(string isbn) { return ISBN == isbn; }

    void setPrice(double p) { price = p; }
    double getPrice() { return price; }

    void setCopies(int c) { no_ofCopies = c; }
    int getCopies() { return no_ofCopies; }
    void updateCopies(int c) { no_ofCopies += c; }
	
	  void showDetail() {
        cout << "\n-----Book Detail-----\n";
        cout << "Title: " << title << endl;
        cout << "Authors: ";
        show_authors();
        cout << "Publisher: " << publisher << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price: " << price << endl;
        cout << "Number of Copies: " << no_ofCopies << endl;
    }
	
};

int main() {
    BookType library[100]; 

    string authors1[2] = {"Author1", "Author2"};
    library[0].setTitle("C++ Programming");
    library[0].setAuthors(authors1, 2);
    library[0].setPublisher("TechBooks");
    library[0].setISBN("123-456-789");
    library[0].setPrice(500);
    library[0].setCopies(10);

    library[0].showDetail();

    string searchTitle = "C++ Programming";
    for (int i = 0; i < 100; i++) {
        if (library[i].getTitle() == searchTitle) {
            cout << "\nBook found by title:\n";
            library[i].showDetail();
            break;
        }
    }

    library[0].updateCopies(5);
    cout << "\nAfter updating copies:\n";
    library[0].showDetail();

    return 0;
}




