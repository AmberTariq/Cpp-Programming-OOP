#include<iostream>
using namespace std;

class Character{
	private:
	int *health;
	int *attackPower;
	int *defense;
	
	public:
		Character(){
			health = new int(100);
			attackPower = new int(50);
			defense = new int(30);
		}
		
		Character(int h, int ap, int d){
			health = new int(h);
			attackPower = new int(ap);
			defense = new int(d);
		}
		
		Character( const Character& obj){
			health = new int(*obj.health);
			attackPower = new int(*obj.attackPower);
			defense = new int(*obj.defense);
		}
		
		~Character(){
			delete health;
			delete attackPower;
			delete defense;
		}
		
		void set_data(int h, int ap, int d ){
			*health = h;
			*attackPower = ap;
			*defense = d;
		}
		
		void get_data(){
			cout<<"\n-------Character Details-------"<<endl;
			cout<<"Health: "<<*health<<endl;
			cout<<"Attack Power: "<<*attackPower<<endl;
			cout<<"Defense: "<<*defense<<endl;
		}	
};

int main(){
	
	Character c1;
	cout<<"\n\"Default Character\""<<endl;
	c1.get_data();
	
	Character c2(150, 100, 50);
	cout<<"\n\"Parameterized Character\""<<endl;
	c2.get_data();
	
	Character c3 = c2;
	cout<<"\n\"Copied Character\""<<endl;
	c3.get_data();
	
	return 0;
}

