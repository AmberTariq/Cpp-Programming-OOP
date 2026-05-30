#include <iostream>
using namespace std;

template<typename T>
class dynamicArray {
    protected: 
    
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual int size() = 0;
    virtual T Front() = 0;
    virtual T Rear() = 0;
    virtual void enqueue(T) = 0;
    virtual void dequeue() = 0;
    virtual void resize() = 0;
    virtual void display() = 0;
    
};

template<class T>
class Queue : public dynamicArray<T> {
    public: 
    int front, rear, capacity, count;
    T* arr;
    
    Queue (int s = 5) {
        capacity = s;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        count = 0; 
        
    }
    
    bool isFull(){
        return count == capacity;
    }
    bool isEmpty(){
        return count == 0;
    }
    
    int size(){
        return count;
    }
    
    T Front() {
        return arr[front];
    }
    
    T Rear(){
        return arr[rear];
    }
    
    void resize(){
        int newCap = capacity*2;
        
        T* temp = new T[newCap];
        for(int i=0; i<count; i++ ){
            temp[i] = arr[(front+ i)% capacity];
        }
        
        delete arr;
        arr = temp;
        
        front = 0;
        rear = count - 1;
        capacity = newCap;
    }
    
    void enqueue(T val){
        if(isFull()) resize();
        rear = (rear + 1)%capacity;
        arr[rear] = val;
        count++;
    }
    
    void dequeue(){
        if (isEmpty()) {
            cout<<"Queue is Empty!"<<endl;
            return;
    }
    cout<<"Removed: "<<arr[front]<<endl;
    front = (front + 1)%capacity;
    count--;
  }
  
  void display(){
      for(int i=0; i<count; i++){
      cout<<arr[(front + i) % capacity]<<" ";
  }
  cout<<endl;
  }
};



int main()
{
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    
    return 0;
}
