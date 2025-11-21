#include <bits/stdc++.h>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        // Step 1: Push to q2
        q2.push(x);

        // Step 2: Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << q1.front() << " popped" << endl;
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        queue<int> temp = q1;
        cout << "Stack (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingTwoQueues st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Original Stack: ";
    st.display();

    st.pop();
    st.pop();

    cout << "Stack after two pops: ";
    st.display();

    cout << "Top element: " << st.top() << endl;
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
