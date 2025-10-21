#include <bits/stdc++.h>
using namespace std;

class QueueUsingArray{
    int start = -1;
    int end = -1;
    int capacity = 10;
    int arr[10];

public:
    void enqueue(int x){ 
        if (end == capacity -1){
            cout << "Stack Overflow" << endl;
            return;
        } else if (isEmpty()){
            start = 0;
            end = 0;
            arr[end] = x; 
        } else {
            end++;
            arr[end] = x;
        }
    }

    int top(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[start];
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Stack Underflow" << endl;
        } else if (start == end){
            start = -1;
            end = -1;
        } else {
            start++;
        }
    }

    int size(){
        return isEmpty() ? 0 : end - start + 1;
    }

    bool isEmpty(){
        return start == -1 && end == -1;
    }

    void display(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements (front to back): ";
        for (int i = start; i <= end; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    QueueUsingArray q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.top() << endl;
    q.dequeue();
    cout << q.top() << endl;
    q.display();

    return 0;
}