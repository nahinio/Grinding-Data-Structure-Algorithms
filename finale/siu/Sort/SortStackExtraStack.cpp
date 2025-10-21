#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &input) {
    stack<int> temp;

    while (!input.empty()) {
        int curr = input.top();
        input.pop();

        while (!temp.empty() && temp.top() > curr) {
            input.push(temp.top());
            temp.pop();
        }

        temp.push(curr);
    }

    while (!temp.empty()) {
        input.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    sortStack(s);

    cout << "Sorted stack (Top to Bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
