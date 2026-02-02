#include<iostream>
using namespace std;
class complex{
	int *real;
	int *imag;
	
	public:
		complex(){
			real= NULL;
			imag = NULL;
		}
		
		complex(int r, int i){
			real = new int(r);
			imag = new int(i);
		}
		
		complex( const complex& obj){
			real = new int(*obj.real);
			imag = new int(*obj.imag);
		}
		
		void show_comp(){
			cout<<"Complex number : "<<*real<<"+"<<*imag<<"i"<<endl;
		}
		
		~complex(){
			delete real;
			delete imag;
		}
		
};

int main(){
	complex one(4,7);
	complex two(1,3);
	one.show_comp();
	two.show_comp();
	
	return 0;
	
}