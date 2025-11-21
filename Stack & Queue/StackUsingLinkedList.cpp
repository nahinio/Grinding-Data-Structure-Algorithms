#include<bits/stdc++.h>
using namespace std;

class StackUsingLinkedList{
    struct Node{
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
    };

    Node* topNode = nullptr;
    int currentSize = 0;
    
public:
    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        currentSize++;
    }

    int top(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return topNode->data;
    }

    void pop(){
        if (isEmpty()){
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        currentSize--;
    }

    int size(){
        return currentSize;
    }

    bool isEmpty(){
        return currentSize == 0;
    }

    void display(){
        if (isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        Node* current = topNode;
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    StackUsingLinkedList s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    s.display();
    
    return 0;
}