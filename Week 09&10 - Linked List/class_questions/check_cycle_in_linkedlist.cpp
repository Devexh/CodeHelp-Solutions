#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    ListNode* head;
    ListNode* next;
    ListNode* data;
};

bool hasCycle(ListNode* head) {
    
    map<ListNode*, bool> table;

    ListNode* temp = head;
    while(temp != NULL) {
        if (table[temp] == false) {
            table[temp] = true;
        }
        else {
            //cycle is present
            return true;
        }
        temp = temp->next;
    }
    //loop not present
    return false;
}

int main() {
    return 0;
}