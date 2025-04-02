#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  ListNode *head;
  ListNode *next;
  ListNode *data;
};

class Compare {
public:
  bool operator()(ListNode *a, ListNode *b) { return a->data > b->data; }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
  priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
  // process first element of every LL
  for (int i = 0; i < lists.size(); i++) {
    ListNode *listHead = lists[i];
    if (listHead != NULL) {
      pq.push(listHead);
    }
  }
  // for new LL
  ListNode *head = NULL;
  ListNode *tail = NULL;

  while (!pq.empty()) {
    ListNode *topNode = pq.top();
    pq.pop();

    // ye first node jo nikali hai, ye hamari first node hai
    if (head == NULL) {
      // pehli node insert karra hoon
      head = topNode;
      tail = topNode;
      if (tail->next != NULL) {
        pq.push(tail->next);
      }
    } else {
      // pehle ke baad me koi node insert kar raha hoon
      tail->next = topNode;
      tail = topNode;
      if (tail->next != NULL) {
        pq.push(tail->next);
      }
    }
  }
  return head;
}

int main() { return 0; }
