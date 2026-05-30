#include <iostream>
using namespace std;

class student{
	string *name;
	
	public:
		student(){
			name = new string;
			*name = "Unknown";
			cout<<"Default constructor called\n";
		}
		
		student (string a){
			name = new string;
			*name = a;
			cout<<"Parameterized constructor called\n";
		}
		
		student(const student& obj){
			name = new string;
			*name = *(obj.name);
			cout<<"Copy Constructor called\n";
		}
		
		void setName(string n){
			*name = n;
		}
		
		void display(){
			cout<<"Name: \""<<*name<<"\" At Address: "<<name<<endl;	
		}

		~student(){
			cout<<"\nDestructor called for \"" << *name << "\"\n";
			delete name;
		}
	
};

int main(){
	cout << "Creating s1:\n";
	student s1;
	cout << "\nCreating s2:\n";
	student s2("Amber");
	cout << "\nCreating s3:\n";
	student s3 = s2;
	
	cout << "\nInitial student details:\n";
	s1.display();
	s2.display();
	s3.display();
	
	cout << "\nModifying copied object's name:\n";
    s3.setName("Copied Student");

    cout << "\nAfter modification:\n";
    s2.display();  
    s3.display();
    cout<<"\n End of Main()\n";
	return 0;
}
