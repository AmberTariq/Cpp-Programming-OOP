#include<iostream>
#include<cstring>
using namespace std;
class Employee{
	char* first_name; 
	string last_name;
	int salary;
	
	public:
		Employee() {
		  first_name = new char[20];
		}
		
		void set_record(char fname[20], string lname, int sal){
			strcpy(first_name,fname);
			last_name = lname;
			if(sal>0){
				salary = sal;
		}   else {
				salary = 0;
				}
		
	    }
	
		void get_record(){
			cout<<"The Employee name is: "<<first_name<<" "<<last_name<<endl;
			cout<<first_name<<"'s monthly salary is: "<<salary<<endl;
			
		}
	 
	 	~Employee(){
	 		delete[] first_name;
		 }
	
};

int main(){
	Employee E1, E2;
	int E1_salary = 50000;
	int E2_salary = 42000;
	
	E1.set_record("Amber","Tariq",E1_salary);
	E1.get_record();
	E2.set_record("Sahar","Khan",E2_salary);
	E2.get_record();
	
	E1_salary *=1.10;
	E2_salary *=1.10;
	cout<<endl;
	
		
	E1.set_record("Amber","Tariq",E1_salary);
	E1.get_record();
	E2.set_record("Sahar","Khan",E2_salary);
	E2.get_record();
	
	return 0;
}








