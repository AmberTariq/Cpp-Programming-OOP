#include <iostream>
using namespace std;
int main() {
    int roll_number;
    cout<<"Enter your roll number : "<<endl;
    cin>>roll_number;
    
    int total=0;
    int marks[5];
    for(int i=0;i<5;i++){
        cout<<"Enter marks in subject "<<i+1<<" : ";
        cin>>marks[i];
        total+=marks[i];
    }
    
    
    float percentage=(total/500.0)*100.0;
    
    cout<<"Your total marks obtained are : "<<total<<endl;
    cout<<"Your percentage is : "<<percentage<<"%"<<endl;
    

    return 0;
}