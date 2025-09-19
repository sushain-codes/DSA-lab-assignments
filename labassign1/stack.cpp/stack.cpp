#include<iostream>
using namespace std;
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x){
    if(top == MAX - 1){
        cout<<"cannot push further"<<endl;
    }else{
        stack[++top] = x;
    }
}
void pop(){
    if(top == -1){
        cout<<"empty stack"<<endl;
    }else{
        cout<<stack[top--]<<" popped out"<<endl;
    }
}
void peek(){
    if(top == -1){
        cout<<"empty stack"<<endl;
    }else{
        cout<<stack[top]<<" is at the top"<<endl;
    }
}

void display(){
    if(top == -1){
        cout<<"nothing to display"<<endl;
    }else{
        for(int i=0;i<=top;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    peek();
    display();    return 0;
}