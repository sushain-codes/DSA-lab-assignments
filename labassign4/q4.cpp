#include <iostream>
using namespace std;

#define MAX 100   

class Queue {
    int arr[MAX];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "full";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "empty";
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % MAX;
        size--;
        return x;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "empty";
            return -1;
        }
        return arr[front];
    }
    int getSize() {
        return size;
    }
    void copyFrom(Queue &other) {
        this->front = other.front;
        this->rear = other.rear;
        this->size = other.size;
        for (int i = 0; i < MAX; i++) {
            this->arr[i] = other.arr[i];
        }
    }
};
class StackTwoQ {
    Queue q1, q2;

public:
    void push(int x) {
        q2.enqueue(x);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        q1.copyFrom(q2);
        q2 = Queue(); 
    }
    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1.dequeue();
    }
    int top() {
        if (q1.isEmpty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return q1.frontElement();
    }
    bool empty() {
        return q1.isEmpty();
    }
};
class StackOneQ {
    Queue q;

public:
    void push(int x) {
        int s = q.getSize();
        q.enqueue(x);
        for (int i = 0; i < s; i++) {
            q.enqueue(q.dequeue());
        }
    }
    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.dequeue();
    }
    int top() {
        if (q.isEmpty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        return q.frontElement();
    }

    bool empty() {
        return q.isEmpty();
    }
};
int main() {
StackTwoQ s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top: " << s1.top() << endl;
    s1.pop();
    cout << "Top: " << s1.top() << endl;


    StackOneQ s2;
    s2.push(100);
    s2.push(200);
    s2.push(300);
    cout << "Top: " << s2.top() << endl;
    s2.pop();
    cout << "Top: " << s2.top() << endl;

    return 0;
}
