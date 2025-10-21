#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    stack<char> st;
    string processed = "";

    // Preprocess: lowercase and remove spaces
    for(char c : s) {
        if(c != ' ') {
            processed += tolower(c);
        }
    }

    // Push all characters into stack
    for(char c : processed) {
        st.push(c);
    }

    // Compare characters with stack top
    for(char c : processed) {
        if(c != st.top()) {
            return false;
        }
        st.pop();
    }

    return true;
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    if(isPalindrome(s))
        cout << "Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;

    return 0;
}
