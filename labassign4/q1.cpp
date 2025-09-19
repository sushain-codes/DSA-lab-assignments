#include<iostream>
using namespace std;

class queue{
    int front, rear, size;
    int arr[5];
public:
    queue(){
        front = 0;
        rear = -1;
        size = 0;
    }
    void enqueue(int x){
        if(size == 5){
            cout<<"queue is full"<<endl;
        }else{
            rear++;
            arr[rear] = x;
            size++;
            cout<<x<<" is added"<<endl;
        }
    }
    void dequeue(){
        if(size == 0){
            cout<<"queue is empty"<<endl;
        }else{
            cout<<arr[front]<< "is removed"<<endl;
            front++;
            size--;
            

        }
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == 5;
    }
    void display(){
           for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        
    }
    }
    void peek(){
        if(size == 0){
            cout<<"queue is empty"<<endl;
        }else{
            
            cout<<arr[front]<<endl;
        }

    }
};


int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
    q.dequeue();
    q.peek();
    q.display();
    
    return 0;
}