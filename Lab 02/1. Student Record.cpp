#include <iostream>
using namespace std;
class student{
    public:
    string name;
    int roll_no;
    int sem;
    char sec;
};
int main() {
   student s[4];
   s[0] = {"Ali",234,2025,'A'};
   s[1] = {"Sarah",127,2024,'C'};
   s[2] = {"Faraz",390,2023,'A'};
   s[3] = {"Ayeza",057,2025,'A'};

for(int i =0; i<4; i++){
    if (s[i].sec == 'A'){
         cout<<"Name: "<<s[i].name<<endl;
         cout<<"Roll no: "<<s[i].roll_no<<endl;
         cout<<"Semester: "<<s[i].sem<<endl;
         cout<<"Section: "<<s[i].sec<<endl;
    }
    cout<<endl;
}

    return 0;
}
