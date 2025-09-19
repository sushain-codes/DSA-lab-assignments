#include<iostream>
using namespace std;

#define MAX 20

class stack{
private:
    string arr[MAX];
    int top;
public:
    stack(){
        top = -1;
    }

    void push(char ch){
    if(top == MAX - 1){
        cout<<"stack is full";
    }else{
        top++;
        arr[top] = ch;
        // cout<<ch<<endl;
    }
}
     void reverse(){
    if(top == -1){
        cout<<"stack is empty"<<endl;
    }else{
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}
}
};

int main(){
    stack s;
    s.push('D');
    s.push('a');
    s.push('t');
    s.push('a');
    s.push('S');
    s.push('t');
    s.push('r');
    s.push('u');
    s.push('c');
    s.push('t');
    s.push('u');
    s.push('r');
    s.push('e');
    s.push('s');
    s.reverse();
    // s.push('e');
    
    return 0;
}