#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int &element) {
  // base case
  if (st.empty()) {
    st.push(element);
    return;
  }

  // one case solved
  int temp = st.top();
  st.pop();

  // recursive call
  insertAtBottom(st, element);

  // backtrack
  st.push(temp);
}

void reverseStack(stack<int> &st) {
  // base case
  if (st.empty()) {
    return;
  }

  // one case solution
  int temp = st.top();
  st.pop();

  // recursion
  reverseStack(st);

  // backtrack
  insertAtBottom(st, temp);
}

void insertSorted(stack<int> &st, int element) {
  // base case
  if (st.empty() || element > st.top()) { //! check if the stack is empty or not
    st.push(element);
    return;
  }

  // one case solution
  int temp = st.top();
  st.pop();

  // recursion
  insertSorted(st, element);

  // backtrack
  st.push(temp);
}

void sortStack(stack<int> &st) {
  // base case
  if (st.empty()) {
    return;
  }

  // one case
  int temp = st.top();
  st.pop();

  // recursion
  sortStack(st);

  // backtrack
  insertSorted(st, temp);
}

int main() {

  stack<int> st;
  st.push(10);
  st.push(7);
  st.push(12);
  st.push(5);
  st.push(11);
  // int element = 400;
  // insertAtBottom(st, element);

  // reverseStack(st);
  // insertSorted(st, 35);
  /// sortStack(st);

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}