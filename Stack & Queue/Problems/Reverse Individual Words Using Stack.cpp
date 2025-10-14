/* 

Question: Given a string, reverse each word in the string using a stack. For example, if the input is 'Hello World', the output should be 'olleH dlroW'.

Core Idea: Use a stack to reverse characters of each word. Push characters onto the stack until a space is encountered, then pop all characters from the stack to form the reversed word. Repeat this for all words in the string. Make sure to handle the last word after the loop.

*/

#include <bits/stdc++.h>
using namespace std;

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

int main() {
    string s;
    getline(cin, s);
    
    revIndividualWords(s);

    cout << s << endl;

    return 0;
}