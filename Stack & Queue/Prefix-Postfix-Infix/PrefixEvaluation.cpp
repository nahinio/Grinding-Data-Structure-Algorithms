#include <bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s){
  stack<int> st;
  
  for(int i = s.length() - 1; i >= 0; i--){
    if(s[i] >= '0' && s[i] <= '9'){
      st.push(s[i] - '0');
    }else {
      int n1 = st.top();
      st.pop();
      int n2 = st.top();
      st.pop();
      
      if(s[i] == '+') st.push(n1 + n2);
      else if(s[i] == '-') st.push(n1 - n2);
      else if(s[i] == '*') st.push(n1 * n2);
      else if(s[i] == '/') st.push(n1 / n2);
      else if(s[i] == '^') st.push(pow(n1, n2));
    }
  }
  return st.top();
}

int main() 
{
    string s;
    cin >> s;
    
    cout << prefixEvaluation(s) << endl;
    
    return 0;
}