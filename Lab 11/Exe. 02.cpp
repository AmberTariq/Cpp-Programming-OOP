#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class DynamicStack{
    vector<char> elements;
    
    public:
    bool isEmpty(){
        return elements.empty();
    }
    
    void push(char v){
        elements.push_back(v);
    }
    
    void pop(){
        if(!isEmpty()) elements.pop_back();
    }

    char peek(){
        if(!isEmpty()) return elements.back();
    return '\0';
    }
    
    string reverseWords(string sentance) {
        stringstream ss(sentance);
        string word;
        string result = "";
        
        while(ss>>word){
            for(char ch: word){
                push(ch);
            }
            
            while(!isEmpty()){
                result += peek();
                pop();
            }
            result +=" ";
        }
        
        if(!result.empty()){
            result.pop_back();
        }  
          return result;
    }

};

int main() {
    DynamicStack wordStack;
    string inputSentence;

    cout << "=== Sentence Word Reverser ===" << endl;
    cout << "Enter a sentence: ";
    getline(cin, inputSentence);

    string reversedResult = wordStack.reverseWords(inputSentence);

    cout << "\nOriginal: " << inputSentence << endl;
    cout << "Processed: " << reversedResult << endl;

    return 0;
}
