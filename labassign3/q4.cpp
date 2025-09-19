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

    char topp(){
        return arr[top];
    }
};

int precedence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    else return -1;
}

string postfix(string exp){
    stack s;
    string ans = "";
    for(int i=0;i<exp.size();i++){
        char ch = exp[i];
        if(isalnum(ch)){
            ans += ch;
        }else if(ch == '('){
            s.push(ch);
        }else if(ch == ')'){
            while(!s.isEmpty() && s.topp() != '('){
                ans += s.pop();
            }
            s.pop();

            }
            else{
                while(!s.isEmpty() && (((precedence(ch) != 3 && precedence(s.topp()) >= precedence(ch)) || 
                   (precedence(ch) == 3 && precedence(s.topp()) > precedence(ch))))){
                    ans += s.pop();
                }
                s.push(ch);
            }
            

        }
        while(!s.isEmpty()){
                ans += s.pop();
            }
        return ans;
    }

    int main(){
        string s;
        cout<<"enter string: "<<endl;
        getline(cin, s);
        string result = postfix(s);
        cout<<"postfix expression is: "<<result<<endl;
        return 0;
    }
