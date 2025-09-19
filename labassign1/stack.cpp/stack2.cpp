#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // If operand, add to result
        if (isalnum(ch)) {
            result += ch;
        }
        // If '(', push
        else if (ch == '(') {
            st.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // Operator
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    getline(cin, exp);

    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}
 