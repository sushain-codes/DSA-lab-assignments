#include<iostream>
using namespace std;

class queue{
    int arr[20];
    int front, rear, size, capacity;
public:
    queue(int cap = 20){
        front = 0;
        rear = -1;
        size = 0;
        capacity = cap;
    }
    bool isEmpty(){return size == 0;}
    bool isFull(){return size == capacity;}
    void enqueue(int x){
        if(isFull()){
            cout<<"queue is full\n";
            return ;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"queue is empty\n";
        }
        int val = arr[front];
        front = (front + 1)%capacity;
        size--;
        return val;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    int getSize() { return size; }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        
        int i = front;
        while (size>=0) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
            size--;
        }
        cout << endl;
    }

};

void interleaveQueue(queue &q){
    int n = q.getSize();
    if(n%2 != 0){cout<<"invalid\n"; return;}
    int half = n/2;
    queue firsthalf(n);

    for(int i=0;i<half;i++){
        firsthalf.enqueue(q.dequeue());
    }
    while(!firsthalf.isEmpty()){
        q.enqueue(firsthalf.dequeue());
        q.enqueue(q.dequeue());
    }
}


int main(){
    queue q(20);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    q.display();
    return 0;
}