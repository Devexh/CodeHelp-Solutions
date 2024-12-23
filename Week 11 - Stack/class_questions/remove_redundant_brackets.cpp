#include <bits/stdc++.h>
using namespace std;

bool checkRedundant(string &str) {
  stack<char> st;

  for (long long unsigned int i = 0; i < str.length(); i++) {
    char ch = str[i];

    if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      st.push(ch);
    } else if (ch == ')') {
      int operatorCount = 0;
      while (!st.empty() && st.top() != '(') {
        char temp = st.top();
        if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
          operatorCount++;
        }
        st.pop();
      }
      // yahan par aap tabhi pahunchenge jab aapke stack ke top pe opening
      // bracket hoga
      st.pop();

      if (operatorCount == 0) {
        return true;
      }
    }
  }
  // agar mein yahan tak pahuncha hoon iska matlab har ek bracket ke pair
  // ke beech mein ek operator pakka mila hoga
  return false;
}

int main() {
  string str = "((a+b)*(c+d))";
  bool ans = checkRedundant(str);

  if (ans == true) {
    cout << "Redundant Brackets Present" << endl;
  } else {
    cout << "Redundant Brackets Absent" << endl;
  }
  return 0;
}
