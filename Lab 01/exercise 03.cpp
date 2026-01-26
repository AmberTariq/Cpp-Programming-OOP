// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    
    float c,f;
    
    cout<<"Enter temperature in Farenheit : ";
    cin>>f;
    
    c=(f-32)/1.8;
    
    cout<<"Your entered temperature in celsius is : "<<c<<" degrees"<<endl;

    return 0;
}