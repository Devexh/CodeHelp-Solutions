#include <bits/stdc++.h>
using namespace std;

void printFirstNegative(int *arr, int n, int k) {
  deque<int> dq;

  // process first k elements - first window
  for (int index = 0; index < k; index++) {
    int element = arr[index];
    if (element < 0) {
      dq.push_back(index);
    }
  }

  // process remaining windows -> Removal and addition
  for (int index = k; index < n; index++) {
    // aage badhne se pehle purani window ka answer nikalo
    if (dq.empty()) {
      cout << "0 " << endl;
    } else {
      cout << arr[dq.front()] << " ";
    }
    // cout << dq.front() << " ";
    // Removal - jo bhi index out of range h, usko queue me se remove kardo
    if (index - dq.front() >= k) {
      dq.pop_front();
    }
    // Addition
    if (arr[index] < 0) {
      dq.push_back(index);
    }
  }

  if (dq.empty()) {
    cout << "0 " << endl;
  } else {
    cout << arr[dq.front()] << " ";
  }
}

int main() {
  // queue<int> q;
  // q.push(2);
  // q.push(-5);
  // q.push(4);
  // q.push(-1);
  // q.push(-2);
  // q.push(0);
  // q.push(-2);

  int arr[] = {2, -5, 4, -1, -2, 0, 5};
  int size = 7;
  int k = 3;
  printFirstNegative(arr, size, k);

  // cout << "Printing Queue: " << endl;
  // while (!q.empty()) {
  //     int element = q.front();
  //     q.pop();
  //     cout << element << " ";
  // }

  return 0;
}
