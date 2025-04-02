#include <bits/stdc++.h>
using namespace std;

int main() {
  // create max_heap
  priority_queue<int> pq;
  // insertion
  pq.push(10);
  pq.push(20);
  pq.push(30);
  pq.push(40);
  pq.push(50);

  cout << "Top element of heap: " << pq.top() << endl;

  pq.pop();

  cout << "Top element of heap: " << pq.top() << endl;
  cout << "Size of max heap: " << pq.size() << endl;

  if (pq.empty()) {
    cout << "Empty" << endl;
  } else {
    cout << "Not Empty" << endl;
  }

  // min heap creation
  priority_queue<int, vector<int>, greater<int>> mpq;
  // insertion
  mpq.push(100);
  mpq.push(90);
  mpq.push(70);

  cout << "Top element of heap: " << mpq.top() << endl;
  mpq.pop();
  cout << "Top element of heap: " << mpq.top() << endl;
  cout << "Size of max heap: " << mpq.size() << endl;

  if (mpq.empty()) {
    cout << "Empty" << endl;
  } else {
    cout << "Not Empty" << endl;
  }

  return 0;
}