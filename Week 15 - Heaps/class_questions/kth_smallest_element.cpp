#include <bits/stdc++.h>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k) {
  priority_queue<int> pq;
  // first k element ko process kardo
  for (int i = 0; i < k; i++) {
    int element = arr[i];
    pq.push(element);
  }
  // remaining element ko tabhi insert karenge jab vo root se chote honge
  for (int i = k; i < n; i++) {
    int element = arr[i];
    if (element < pq.top()) {
      pq.pop();
      pq.push(element);
    }
  }
  int ans = pq.top();
  return ans;
}

int getKthGreatestElement(int arr[], int n, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  // first k element ko process kardo
  for (int i = 0; i < k; i++) {
    int element = arr[i];
    pq.push(element);
  }
  // remaining element ko tabhi insert karenge jab vo root se chote honge
  for (int i = k; i < n; i++) {
    int element = arr[i];
    if (element > pq.top()) { // change the condition
      pq.pop();
      pq.push(element);
    }
  }
  int ans = pq.top();
  return ans;
}

int main() {
  int arr[] = {3, 5, 4, 6, 9, 8, 7};
  int n = 7;
  int k = 3;
  cout << "3rd greatest number is: " << getKthGreatestElement(arr, n, k)
       << endl;
  cout << "3rd smallest number is: " << getKthSmallestElement(arr, n, k)
       << endl;
  return 0;
}
