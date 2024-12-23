#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  for (long long unsigned int i = 0; i < s.length(); i++) {
    char ch = s[i];
    if (ch == '(' || ch == '[' || ch == '{') {
      // for open bracket -> just push
      st.push(ch);
    } else {
      // closing bracket
      if (!st.empty()) {
        if (ch == ')' && st.top() == '(') {
          st.pop();
        } else if (ch == '}' && st.top() == '{') {
          st.pop();
        } else if (ch == ']' && st.top() == '[') {
          st.pop();
        } else {
          // no matches
          return false;
        }
      } else {
        return false;
      }
    }
  }
  if (st.size() == 0) {
    return true;
  } else {
    return false;
  }
}

int main() { return 0; }