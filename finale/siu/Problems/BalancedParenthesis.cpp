#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // If it's an opening bracket, push it to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        // If it's a closing bracket, check for matching opening one
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false; // No opening bracket found
            }

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched pair
            }
        }
    }

    // If stack is empty, all brackets are balanced
    return s.empty();
}

int main() {
    string str;
    cout << "Enter a string with brackets: ";
    cin >> str;

    if (isBalanced(str)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}