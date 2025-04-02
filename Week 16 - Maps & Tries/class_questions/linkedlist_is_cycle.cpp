#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  int data;
  ListNode* head;
  ListNode* next;

  ListNode(int data) {
    this->data = data;
    this->head = NULL;
    this->next = NULL;
  }
};

bool hasCycle(ListNode *head) {
  unordered_map<ListNode *, bool> mapping;
  ListNode *temp = head;

  while (temp != NULL) {
    // address check
    if (mapping.find(temp) != mapping.end()) {
      // cycle present
      return true;
    }
    // address store
    else {
      // node not visited beforehand
      // store
      mapping[temp] = true;
    }
    temp = temp->next;
  }
  // cycle absent
  return false;
}

int main() { return 0; }
