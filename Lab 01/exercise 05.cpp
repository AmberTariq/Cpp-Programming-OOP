#include <iostream>
using namespace std;
void sum(int arr[3][3],int brr[3][3],int result[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            result[i][j]=arr[i][j]+brr[i][j];
        }
    }
}

void multiply(int arr[3][3],int brr[3][3],int result[3][3]){
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            result[i][j]=0;
            for(int k=0;k<3;k++){
                result[i][j]+=arr[i][k]*brr[k][i];
            }
        }
    }
}
int main() {
    
    int m1[3][3],m2[3][3],sum_result[3][3],multiply_result[3][3];
    
    cout<<"Entering element of matrix one ..."<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter element at index ["<<i<<","<<j<<"] : ";
            cin>>m1[i][j];
        }
    }
    
    cout<<"Entering element of matrix two ..."<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter element at index ["<<i<<","<<j<<"] : ";
            cin>>m2[i][j];
        }
    }
    
    sum(m1,m2,sum_result);
    multiply(m1,m2,multiply_result);
    
    cout<<"Result of addition of matrices."<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<sum_result[i][j]<<" ";
            
        }
        cout<<endl;
    }
    
        
    cout<<"Result of multiplication of matrices."<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<multiply_result[i][j];
            
        }
        cout<<endl;
    }
    
    
    
    
    
    
    
   

    return 0;
}