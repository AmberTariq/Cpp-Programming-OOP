#include <iostream>
using namespace std;

class Queue {
private:
    string arr[10];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return rear < front;
    }

    void enqueue(string job) {
        rear++;
        arr[rear] = job;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No jobs in queue\n";
            return;
        }

        cout << "Printing: "
             << arr[front] << endl;

        front++;
    }
};

int main() {

    Queue printerQueue;

    // Adding print jobs
    printerQueue.enqueue("Document");
    printerQueue.enqueue("Assignment");
    printerQueue.enqueue("Project Report");

    // Processing jobs
    while (!printerQueue.isEmpty()) {

        printerQueue.dequeue();

        cout << "Job completed\n\n";
    }

    cout << "All print jobs completed!" << endl;

    return 0;
}
