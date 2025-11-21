#include <bits/stdc++.h>
using namespace std;

class Stack {
    int arr[100];
    int topIndex;

public:
    Stack() { topIndex = -1; }

    void push(int x) {
        if (topIndex >= 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }

    int getAt(int index) { // get element at index 0..topIndex
        if (index < 0 || index > topIndex) return -1;
        return arr[index];
    }
};

class QueueUsingTwoStacks {
    Stack s1, s2;

    void transferIfNeeded() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
    }

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        transferIfNeeded();
        if (s2.isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << s2.pop() << " dequeued\n";
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        // Display s2 (front elements)
        for (int i = s2.size() - 1; i >= 0; i--) {
            cout << s2.getAt(i) << " ";
        }

        // Display s1 (rear elements)
        for (int i = 0; i < s1.size(); i++) {
            cout << s1.getAt(i) << " ";
        }
        cout << endl;
    }
};

int main() {
    QueueUsingTwoStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue: ";
    q.display();

    q.dequeue();
    q.dequeue();

    cout << "Queue after two dequeues: ";
    q.display();

    q.enqueue(50);
    q.enqueue(60);

    cout << "Queue after enqueues: ";
    q.display();

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
