#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    ListNode* head;
    ListNode* next;
};

int getLength(ListNode* head) {
    int len = 0;
    ListNode* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;  
    }
    return len;
}

// ListNode* middleNode(ListNode* head) {
//     int n = getLength(head);    
//     int position = (n/2)+1;
//     ListNode* temp = head;
//     //int currPos = 1;
//     // while(currPos != position) {
//     //     currPos++;
//     //     temp = temp->next;
//     // }
//     // return temp;

//     while(position != 1) {
//         position--;
//         temp = temp->next;
//     }
//     return temp;
// }

//! Tortoise algorithm (Slow & fast approach)

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            // fast takes 2 step
            slow = slow->next;
        }
    }
    return slow;
}

int main() {
    return 0;
}