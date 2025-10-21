#include <bits/stdc++.h>
using namespace std;

class StackUsingArray{
    int arr[10];
    int topIndex = -1;
    int capacity = 10;

public:
    void push(int x){
        if (topIndex >= capacity - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    int top(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    void pop(){
        if (isEmpty()){
            cout << "Stack Underflow" << endl;
            return;
        }
        topIndex--;
    }

    int size(){
        return topIndex + 1;
    }

    bool isEmpty(){
        return topIndex == -1;
    }

    void display(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        for (int i = topIndex; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}