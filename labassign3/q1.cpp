#include<iostream>
using namespace std;

#define MAX 15

class stack{
private:
    int arr[MAX];
    int top;
public:
    stack(){
        top = -1;
    }
    void push(int x){
    if(top == MAX - 1){
        cout<<"stack is full";
    }else{
        arr[++top] = x;
        cout<<x<<" pushed"<<endl;
    }
}
    void pop(){
    if(top == -1){
        cout<<"stack is empty"<<endl;
    }else{
        cout<<arr[top--]<<"popped out";
    }
}
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return (top == MAX - 1);
    }

    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }

    void peek(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<arr[top]<<endl;
        }
    }
};


int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();
    s.isFull();
    s.peek();
    s.display();
    return 0;
}