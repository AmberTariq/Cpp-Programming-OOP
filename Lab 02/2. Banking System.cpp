#include<iostream>
using namespace std;

class BankingSys{
	float balance = 0.0;
	int transactions = 0;
	
	public:
		void check_balance(){
			cout<<"Your current balance is Rs."<<balance<<endl;
			
		}
	
		void deposit(float amount){
			if(amount>0){
				balance+=amount;
				transactions+=1;
				cout<<"Rs."<<amount<<" have been deposited to your account."<<endl;
			} else {
				cout<<"Enter a Valid amount!"<<endl;
			}
		}
		
		void withdraw(float amount){
				if(amount<0 || amount>balance){
				cout<<"Enter a Valid amount!"<<endl;
				return;
			} else {
				balance-=amount;
				transactions+=1;
				cout<<"Rs."<<amount<<" have been deducted from your account."<<endl;
				
			}
		}
		
		void get_transactions(){
			cout<<"The amount of transactions performed uptill now are: "<<transactions<<endl;
		}
		
		void get_interest(){
			float amount = balance*0.05*5;
			cout<<"The interest earned for 5 years on your balance is Rs."<<amount<<endl;
		}
		
		int exit(){
			return 0;
		}
			
};

	void display_menu(){
	cout<<"<<       MENU        >> "<<endl;
 	cout<<"====================="<<endl;
    cout<<"1.Display balance."<<endl;
    cout<<"2.Deposit amount."<<endl;
    cout<<"3.Withdraw amount."<<endl;
    cout<<"4.Get transaction number."<<endl;
    cout<<"5.Get Interest earned in 5 years."<<endl;
    cout<<"6.Exit the program."<<endl;
    cout<<"====================="<<endl<<endl;
    }
		
		int main(){
			
			BankingSys No1;
			display_menu();
			
			No1.deposit(78934.32);
			No1.check_balance();
			No1.withdraw(1235.05);
			No1.check_balance();
			No1.get_transactions();
			No1.get_interest();
			No1.exit();
			
			return 0;
		}





















