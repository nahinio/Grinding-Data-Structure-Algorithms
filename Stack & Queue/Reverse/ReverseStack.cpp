#include <bits/stdc++.h>
using namespace std;

class Stack {
    vector<int> arr;

public:
    void push(int x) {
        arr.push_back(x);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int topElem = arr.back();
        arr.pop_back();
        return topElem;
    }

    bool isEmpty() {
        return arr.empty();
    }

    void display() {
        cout << "Stack (top to bottom): ";
        for (int i = arr.size() - 1; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Insert element x at the bottom of stack recursively
void insertAtBottom(Stack &st, int x) {
    if (st.isEmpty()) {
        st.push(x);
        return;
    }

    int topx = st.pop();
    insertAtBottom(st, x);
    st.push(topx);
}

// Reverse the stack using recursion
void reverseStack(Stack &st) {
    if (st.isEmpty())
        return;

    int x = st.pop();
    reverseStack(st);
    insertAtBottom(st, x);
}

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Original Stack:\n";
    st.display();

    reverseStack(st);

    cout << "Reversed Stack:\n";
    st.display();

    return 0;
}
