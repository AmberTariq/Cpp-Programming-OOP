#include<iostream>
#include<iomanip>
using namespace std;
class tollbooth{
	int totalcars;
	double amount;
	public:
		tollbooth() {
			totalcars = 0;
			amount = 0.0;
		}
		
	void payingCar(){
		totalcars++;
		amount += 0.5;
	}
	void display(){
		cout<<"Total Number of Cars passed: "<<totalcars<<endl;
		cout<<"Total Amount of Cash collected: "<< fixed << setprecision(2) << amount <<endl;
	}
};
int main(){
	tollbooth t;
	t.payingCar();
	t.payingCar();
	t.payingCar();
	t.payingCar();
	t.payingCar();
	
	t.display();
	return 0;
}

