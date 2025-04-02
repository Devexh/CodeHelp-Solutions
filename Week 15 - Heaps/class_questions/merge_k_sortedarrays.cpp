#include <bits/stdc++.h>
using namespace std;

class Info {
public:
  int data;
  int rowIndex;
  int colIndex;

  Info(int a, int b, int c) {
    this->data = a;
    this->rowIndex = b;
    this->colIndex = c;
  }
};

class Compare {
public:
  bool operator()(Info *a, Info *b) {
    return a->data > b->data; //? MIN_HEAP
    // return a->data < b->data; //? MAX_HEAP
  }
};

void mergeKSortedArrays(int arr[][4], int n, int k, vector<int> &ans) {
  priority_queue<Info *, vector<Info *>, Compare> pq;

  // 1 step: process first K elements
  for (int row = 0; row < k; row++) {
    int element = arr[row][0];
    Info *temp = new Info(element, row, 0);
    pq.push(temp);
  }

  while (!pq.empty()) {
    Info *temp = pq.top();
    pq.pop();
    int topData = temp->data;
    int topRow = temp->rowIndex;
    int topCol = temp->colIndex;

    // store in ans vector
    ans.push_back(topData);

    // next element for the same row, jismein se pop kia h just abhi
    // usse insert bhi to karna hai
    if (topCol + 1 < n) {
      // iska matlab row mein aur element present hai
      Info *newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
      pq.push(newInfo);
    }
  }
}

int main() {
  int arr[3][4] = {
      {1, 4, 8, 11},
      {2, 3, 6, 10},
      {5, 7, 12, 14},
  };
  int n = 4;
  int k = 3;
  vector<int> ans;
  mergeKSortedArrays(arr, n, k, ans);

  cout << "Printing Ans array: " << endl;
  for (long long unsigned int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
