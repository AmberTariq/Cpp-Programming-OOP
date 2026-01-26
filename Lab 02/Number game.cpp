#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Game{
	int players;
	int your_score;
	int enemy_score;
	
	public:
		Game(){
			srand(time(0));
			players = rand()%5 + 1;
			your_score = 0;
			enemy_score = 0;
		}
		
		void begin(){
			cout<<"Total Number of players in your team are: "<<players<<endl;
			for (int i =0; i<players; i++){
				int num1 = rand()%10 + 1;
				int num2 = rand()%10 + 1;
				
				cout<<"Pair of Numbers:"<<endl;
				cout<<"Number 1: "<<num1<<endl;
				cout<<"Number 2: "<<num2<<endl;
				
				if(num1==num2){
					cout<<"Enemy got hit by you!"<<endl;
					your_score +=1;
				}  else {
					cout<<"You got hit by enemy!"<<endl;
					enemy_score +=1;
					
				}
				cout<<endl;
			}
		
			if(your_score>enemy_score){
				cout<<"Congratulations, You won the Game!"<<endl;
			} else if(your_score<enemy_score){
				cout<<"Ops, Enemy team has won the game!"<<endl;
			} else {
				cout<<"It's a Tie!"<<endl;
			}
			cout<<"========Game Over=========="<<endl;
		}
};

int main(){
	Game one;
	one.begin();
	return 0;
}














