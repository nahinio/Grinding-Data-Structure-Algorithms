#include <bits/stdc++.h>
using namespace std;

int findMiddleRec(stack<int> &st, int curr, int n) {
    if(curr == n / 2) {
        return st.top();
    }

    int x = st.top();
    st.pop();
    int res = findMiddleRec(st, curr + 1, n);
    st.push(x);
    return res;
}

int findMiddle(stack<int> &st) {
    int n = st.size();
    return findMiddleRec(st, 0, n);
}

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60); // top

    cout << "Middle element: " << findMiddle(st) << endl;

    return 0;
}
