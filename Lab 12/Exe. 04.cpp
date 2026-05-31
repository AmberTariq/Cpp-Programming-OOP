#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Participant{
    string name;
    int id;
    int score;
    
    public:
    void input(){
        ofstream inFile("participant.dat", ios::app);
        if(!inFile){
            cout<<"Error opening file!"<<endl;
        }
        
        cout<<"Enter ID: "<<endl;
        cin>>id;
        cin.ignore();
        cout<<"Enter name: "<<endl;
        getline(cin,name);
        cout<<"Enter Score: "<<endl;
        cin>>score;
        
        inFile<<id<<","<<name<<","<<score<<endl;
        inFile.close();
        cout<<"Record saved successfully!"<<endl;
        
    }
    
    void output(){
        bool found = false;
        int searchID;
        
        ifstream inFile("participant.dat");
            if(!inFile){
            cout<<"Error opening file!"<<endl;
        }
        
        cout<<"Enter ID to search: "<<endl;
        cin>>searchID;
        
        string tempID, tempScore;
        while(getline(inFile, tempID, ',')){
            getline(inFile,name, ',');
            getline(inFile,tempScore);
            
            id = stoi(tempID);
            score = stoi(tempScore);
            
            if(searchID == id){
                found = true;
                cout<<"===== Participant Found ===="<<endl;
                cout<<"Name: "<<name;
                cout<<"ID: "<<id;
                cout<<"Score: "<<score;
                break;
            } 
            
        }
        
        if(!found){
                cout<<"No participant found for id '"<<searchID<<"' in records."<<endl; 
            }
    }
    
    void max(){
        string topname = "None";
        int maxVal = -1;
        
        ifstream inFile("participant.dat");
            if(!inFile){
            cout<<"Error opening file!"<<endl;
        }
        
          
        string tempID, tempScore;
        while(getline(inFile, tempID, ',')){
            getline(inFile,name, ',');
            getline(inFile,tempScore);
            
         if(score>maxVal){
             maxVal = score;
             topname = name;
           }
        
        }
        if(maxVal != -1){
            cout << "\n=== Highest Score Reference ===" << endl;
            cout << "Participant Name: " << topname << endl;
            cout << "Highest Score:    " << maxVal << endl; 
            
        } else {
            cout<<"No records available to evaluate."<<endl;
        }
        
        inFile.close();
    }
};

int main(){
    Participant p;
    int choice;

    do {
        cout << "\n=== Participant Database Suite ===";
        cout << "\n1. Input Data";
        cout << "\n2. Search Participant";
        cout << "\n3. Highest Score";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: p.input(); break;
            case 2: p.output(); break;
            case 3: p.max(); break;
            case 4: cout << "Program Ended Successfully.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 4);
    return 0;
}

