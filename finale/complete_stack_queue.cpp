#include <bits/stdc++.h>
using namespace std;

// ==================== STACK USING ARRAY ====================
class StackUsingArray{
    int arr[100];
    int topIndex = -1;
    int capacity = 100;

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

    int pop(){
        if (isEmpty()){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    int size(){
        return topIndex + 1;
    }

    bool isEmpty(){
        return topIndex == -1;
    }

    int getAt(int index) {
        if (index < 0 || index > topIndex) return -1;
        return arr[index];
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

// ==================== QUEUE USING ARRAY ====================
class QueueUsingArray{
    int start = -1;
    int end = -1;
    int capacity = 100;
    int arr[100];

public:
    void enqueue(int x){ 
        if (end == capacity -1){
            cout << "Queue Overflow" << endl;
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

    int front(){
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue Underflow" << endl;
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
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements (front to back): ";
        for (int i = start; i <= end; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ==================== CIRCULAR QUEUE ====================
class CircularQueue {
    int arr[100];
    int start, end, capacity;

public:
    CircularQueue() {
        start = -1;
        end = -1;
        capacity = 100;
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

// ==================== STACK USING TWO QUEUES ====================
class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
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

// ==================== QUEUE USING TWO STACKS ====================
class QueueUsingTwoStacks {
    StackUsingArray s1, s2;

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
            cout << "Queue Underflow" << endl;
            return;
        }
        s2.pop();
    }

    int front() {
        transferIfNeeded();
        if (s2.isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s2.top();
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements (front to rear): ";
        for (int i = s2.size() - 1; i >= 0; i--) {
            cout << s2.getAt(i) << " ";
        }
        for (int i = 0; i < s1.size(); i++) {
            cout << s1.getAt(i) << " ";
        }
        cout << endl;
    }
};

// ==================== UTILITY FUNCTIONS ====================

// Sort Stack using extra stack
void sortStackUsingStack(stack<int> &input) {
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

// Sort Stack using recursion
void insertSorted(stack<int> &st, int value) {
    if (st.empty() || st.top() <= value) {
        st.push(value);
        return;
    }
    int topVal = st.top();
    st.pop();
    insertSorted(st, value);
    st.push(topVal);
}

void sortStackRecursive(stack<int> &st) {
    if (st.empty()) return;
    int topVal = st.top();
    st.pop();
    sortStackRecursive(st);
    insertSorted(st, topVal);
}

// Sort Queue using extra queue
int minIndex(queue<int> &q, int sortedIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (curr <= min_val && i <= sortedIndex) {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);
    }
    return min_index;
}

void insertMinToRear(queue<int> &q, int min_index) {
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}

void sortQueue(queue<int> &q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

// Reverse Stack
void insertAtBottom(StackUsingArray &st, int x) {
    if (st.isEmpty()) {
        st.push(x);
        return;
    }
    int topx = st.pop();
    insertAtBottom(st, x);
    st.push(topx);
}

void reverseStack(StackUsingArray &st) {
    if (st.isEmpty()) return;
    int x = st.pop();
    reverseStack(st);
    insertAtBottom(st, x);
}

// Reverse Queue
void queueReversal(queue<int> &q) {
    if (q.empty()) return;
    int temp = q.front();
    q.pop();
    queueReversal(q);
    q.push(temp);
}

// Infix to Postfix
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else if(isOperator(c)) {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                if(c == '^' && st.top() == '^') break;
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// Infix to Prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for(char &c : infix) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }
    string revPostfix = infixToPostfix(infix);
    reverse(revPostfix.begin(), revPostfix.end());
    return revPostfix;
}

// Postfix Evaluation
int postfixEvaluation(string s){
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }else {
            int n2 = st.top(); st.pop();
            int n1 = st.top(); st.pop();
            if(s[i] == '+') st.push(n1 + n2);
            else if(s[i] == '-') st.push(n1 - n2);
            else if(s[i] == '*') st.push(n1 * n2);
            else if(s[i] == '/') st.push(n1 / n2);
            else if(s[i] == '^') st.push(pow(n1, n2));
        }
    }
    return st.top();
}

// Prefix Evaluation
int prefixEvaluation(string s){
    stack<int> st;
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }else {
            int n1 = st.top(); st.pop();
            int n2 = st.top(); st.pop();
            if(s[i] == '+') st.push(n1 + n2);
            else if(s[i] == '-') st.push(n1 - n2);
            else if(s[i] == '*') st.push(n1 * n2);
            else if(s[i] == '/') st.push(n1 / n2);
            else if(s[i] == '^') st.push(pow(n1, n2));
        }
    }
    return st.top();
}

// Balanced Parenthesis
bool isBalanced(string str) {
    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

// Check Palindrome
bool isPalindrome(string s) {
    stack<char> st;
    string processed = "";
    for(char c : s) {
        if(c != ' ') {
            processed += tolower(c);
        }
    }
    for(char c : processed) {
        st.push(c);
    }
    for(char c : processed) {
        if(c != st.top()) {
            return false;
        }
        st.pop();
    }
    return true;
}

// Find Middle (Iterative)
int findMiddleIterative(StackUsingArray st) {
    int n = st.size();
    int midIndex = n / 2;
    StackUsingArray temp;
    for(int i = 0; i < midIndex; i++) {
        temp.push(st.top());
        st.pop();
    }
    return st.top();
}

// Find Middle (Recursive)
int findMiddleRec(StackUsingArray &st, int curr, int n) {
    if(curr == n / 2) {
        return st.top();
    }
    int x = st.top();
    st.pop();
    int res = findMiddleRec(st, curr + 1, n);
    st.push(x);
    return res;
}

int findMiddleRecursive(StackUsingArray &st) {
    int n = st.size();
    return findMiddleRec(st, 0, n);
}

// Reverse Individual Words
void revIndividualWords(string &s){
    stack<char> st;
    string result = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] != ' '){
            st.push(s[i]);
        } else {
            while(!st.empty()){
                result += st.top();
                st.pop();
            }
            result += ' ';
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    s = result;
}

// ==================== MAIN MENU SYSTEM ====================

void basicStackDemo() {
    StackUsingArray s;
    int ch, val;
    while(true) {
        cout << "\n=== Basic Stack Operations ===" << endl;
        cout << "1. Push\n2. Pop\n3. Top\n4. Size\n5. Is Empty\n6. Display\n7. Back" << endl;
        cout << "Choice: "; cin >> ch;
        if(ch == 1) { cout << "Value: "; cin >> val; s.push(val); }
        else if(ch == 2) { s.pop(); }
        else if(ch == 3) { cout << "Top: " << s.top() << endl; }
        else if(ch == 4) { cout << "Size: " << s.size() << endl; }
        else if(ch == 5) { cout << (s.isEmpty() ? "Empty" : "Not Empty") << endl; }
        else if(ch == 6) { s.display(); }
        else if(ch == 7) { break; }
    }
}

void basicQueueDemo() {
    QueueUsingArray q;
    int ch, val;
    while(true) {
        cout << "\n=== Basic Queue Operations ===" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Size\n5. Is Empty\n6. Display\n7. Back" << endl;
        cout << "Choice: "; cin >> ch;
        if(ch == 1) { cout << "Value: "; cin >> val; q.enqueue(val); }
        else if(ch == 2) { q.dequeue(); }
        else if(ch == 3) { cout << "Front: " << q.front() << endl; }
        else if(ch == 4) { cout << "Size: " << q.size() << endl; }
        else if(ch == 5) { cout << (q.isEmpty() ? "Empty" : "Not Empty") << endl; }
        else if(ch == 6) { q.display(); }
        else if(ch == 7) { break; }
    }
}

void circularQueueDemo() {
    CircularQueue q;
    int ch, val;
    while(true) {
        cout << "\n=== Circular Queue Operations ===" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Back" << endl;
        cout << "Choice: "; cin >> ch;
        if(ch == 1) { cout << "Value: "; cin >> val; q.enqueue(val); }
        else if(ch == 2) { q.dequeue(); }
        else if(ch == 3) { cout << "Front: " << q.front() << endl; }
        else if(ch == 4) { q.display(); }
        else if(ch == 5) { break; }
    }
}

void expressionConversionDemo() {
    int ch;
    string expr;
    while(true) {
        cout << "\n=== Expression Conversion ===" << endl;
        cout << "1. Infix to Postfix\n2. Infix to Prefix\n3. Evaluate Postfix\n4. Evaluate Prefix\n5. Back" << endl;
        cout << "Choice: "; cin >> ch;
        if(ch == 1) {
            cout << "Enter infix: "; cin >> expr;
            cout << "Postfix: " << infixToPostfix(expr) << endl;
        } else if(ch == 2) {
            cout << "Enter infix: "; cin >> expr;
            cout << "Prefix: " << infixToPrefix(expr) << endl;
        } else if(ch == 3) {
            cout << "Enter postfix: "; cin >> expr;
            cout << "Result: " << postfixEvaluation(expr) << endl;
        } else if(ch == 4) {
            cout << "Enter prefix: "; cin >> expr;
            cout << "Result: " << prefixEvaluation(expr) << endl;
        } else if(ch == 5) { break; }
    }
}

void stringOperationsDemo() {
    int ch;
    string s;
    while(true) {
        cout << "\n=== String Operations ===" << endl;
        cout << "1. Check Balanced Parenthesis\n2. Check Palindrome\n3. Reverse Individual Words\n4. Back" << endl;
        cout << "Choice: "; cin >> ch;
        cin.ignore();
        if(ch == 1) {
            cout << "Enter expression: "; getline(cin, s);
            cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;
        } else if(ch == 2) {
            cout << "Enter string: "; getline(cin, s);
            cout << (isPalindrome(s) ? "Palindrome" : "Not Palindrome") << endl;
        } else if(ch == 3) {
            cout << "Enter string: "; getline(cin, s);
            revIndividualWords(s);
            cout << "Result: " << s << endl;
        } else if(ch == 4) { break; }
    }
}

int main() {
    int choice;
    cout << "\n======================================" << endl;
    cout << "  COMPLETE STACK & QUEUE SYSTEM" << endl;
    cout << "======================================" << endl;

    while(true) {
        cout << "\n=== MAIN MENU ===" << endl;
        cout << "1. Basic Stack Operations" << endl;
        cout << "2. Basic Queue Operations" << endl;
        cout << "3. Circular Queue" << endl;
        cout << "4. Stack Using Two Queues" << endl;
        cout << "5. Queue Using Two Stacks" << endl;
        cout << "6. Expression Conversion & Evaluation" << endl;
        cout << "7. String Operations (Balanced, Palindrome, etc)" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) { basicStackDemo(); }
        else if(choice == 2) { basicQueueDemo(); }
        else if(choice == 3) { circularQueueDemo(); }
        else if(choice == 4) {
            StackUsingTwoQueues s;
            cout << "Demo: Pushing 10, 20, 30\n";
            s.push(10); s.push(20); s.push(30);
            s.display();
            cout << "Top: " << s.top() << endl;
        }
        else if(choice == 5) {
            QueueUsingTwoStacks q;
            cout << "Demo: Enqueuing 10, 20, 30\n";
            q.enqueue(10); q.enqueue(20); q.enqueue(30);
            q.display();
            cout << "Front: " << q.front() << endl;
        }
        else if(choice == 6) { expressionConversionDemo(); }
        else if(choice == 7) { stringOperationsDemo(); }
        else if(choice == 8) {
            cout << "\nThank you for using the program!" << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}