
#include <iostream>
using namespace std;

#define MAX 5 
class CircularQueue {
    int arr[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1; 
    }
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    bool isFull() {
        return (front == (rear + 1) % MAX);
    }
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full";
            return;
        }
        if (isEmpty()) { 
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = item;
        cout << item << " inserted.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "queue empty";
            return;
        }

        int item = arr[front];
        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        cout << item << " removed";
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};


int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); 
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.enqueue(70);  

    q.display();

    return 0;
}
 