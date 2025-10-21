#include <bits/stdc++.h>
using namespace std;

// Check if character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Operator precedence
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for(char c : infix) {
        if(isalnum(c)) { // operand
            postfix += c;
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        } else if(isOperator(c)) {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                if(c == '^' && st.top() == '^') break; // right-associative
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Convert infix to prefix
string infixToPrefix(string infix) {
    // Step 1: Reverse infix
    reverse(infix.begin(), infix.end());
    for(char &c : infix) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    // Step 2: Convert reversed infix to postfix
    string revPostfix = infixToPostfix(infix);

    // Step 3: Reverse postfix to get prefix
    reverse(revPostfix.begin(), revPostfix.end());
    return revPostfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);

    cout << "Prefix: " << prefix << endl;

    return 0;
}
