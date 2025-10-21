#include <bits/stdc++.h>
using namespace std;

int findMiddle(stack<int> st) {
    int n = st.size();
    int midIndex = n / 2; // 0-based, second middle if even

    stack<int> temp;
    for(int i = 0; i < midIndex; i++) {
        temp.push(st.top());
        st.pop();
    }

    int middle = st.top(); // middle element

    // Optional: Restore original stack (if needed)
    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }

    return middle;
}

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60); // stack top -> 60

    cout << "Middle element: " << findMiddle(st) << endl;

    return 0;
}
