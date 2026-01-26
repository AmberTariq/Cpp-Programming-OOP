#include <iostream>
using namespace std;
const float pi=3.141;
float area(float radius){
    float surface_area=4*pi*(radius*radius);
    return surface_area;
}

float volume(float radius){
    float vol=(4/3)*pi*(radius*radius*radius);
    return vol;
}
int main() {
    
    float radius,surface_area,vol;
    
    cout<<"Enter radius for sphere : ";
    cin>>radius;
    
    surface_area=area(radius);
    vol=volume(radius);
    
    cout<<"The surface area of the sphere is : "<<surface_area<<"m"<<endl;
    cout<<"The volume of the sphere is : "<<vol<<"m,"<<endl;
    
    
   

    return 0;
}
