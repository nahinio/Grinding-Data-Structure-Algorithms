#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    int arr[10];
    int start, end, capacity;

public:
    CircularQueue() {
        start = -1;
        end = -1;
        capacity = 10;
    }

    bool isEmpty() {
        return start == -1;
    }

    bool isFull() {
        return (end + 1) % capacity == start;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            start = end = 0;
        } else {
            end = (end + 1) % capacity;
        }
        arr[end] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (start == end) {
            start = end = -1;
        } else {
            start = (start + 1) % capacity;
        }
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];
    }

    int size() {
        if (isEmpty()) return 0;
        if (end >= start) return end - start + 1;
        return capacity - (start - end - 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements (front to back): ";
        int i = start;
        while (true) {
            cout << arr[i] << " ";
            if (i == end) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.display();

    return 0;
}
