#include<iostream>
using namespace std;

#define MAX 20

class stack{
private:
    char arr[MAX];
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
char pop(){
    if(top == -1){
        return '\0';
    }else{
        return arr[top--];
    }
}
bool isEmpty(){
        return (top == -1);
    }
};

bool matching(char open, char close){
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

bool checking(string exp){
    stack s;
    for(int i=0;i<exp.size();i++){
        char v = exp[i];
        if(v == '(' || v=='{' || v == '['){
            s.push(v);
        }
        else{
            if(v ==')' || v==']' || v == '}'){
                if(s.isEmpty()) return false;
                char c = s.pop();
                if(!matching(c,v)) return false;
            }
        }
    }
    return s.isEmpty();
}

int main(){
    string ss;
    cout<<"enter a string: "<<endl;
    getline(cin, ss);
    if(checking(ss)) {
        cout<<"balanced"<<endl;
    }else{
        cout<<"unbalanced"<<endl;
    }
    return 0;
}