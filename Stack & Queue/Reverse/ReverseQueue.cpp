#include <bits/stdc++.h>
using namespace std;

// Recursive function to reverse an STL queue
void queueReversal(queue<int> &q) {
    if (q.empty()) return;

    int temp = q.front();  // get front element
    q.pop();               // remove it

    queueReversal(q);      // reverse remaining queue

    q.push(temp);          // enqueue at rear (bottom)
}

int main() {
    queue<int> q;

    // Add elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Original Queue: ";
    queue<int> tempQ = q;
    while (!tempQ.empty()) {
        cout << tempQ.front() << " ";
        tempQ.pop();
    }
    cout << endl;

    // Reverse the queue
    queueReversal(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
