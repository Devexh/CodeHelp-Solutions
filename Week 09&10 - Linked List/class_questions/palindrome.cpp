#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    ListNode* head;
    ListNode* next;
    ListNode* data;
};

ListNode* reverseListRec(ListNode* prev, ListNode* curr) {
    //base case
    if(curr == NULL) {
        return prev;
    }
    //one case solved
    ListNode* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    //Recursion
    ListNode* recursionAns = reverseListRec(prev, curr);
    return recursionAns;
}

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL) {
        fast = fast->next;
        if (fast->next != NULL) {
            fast = fast->next;
            // fast takes 2 step
            slow = slow->next;
        }
    }
    return slow;
}

bool compareList(ListNode* head1, ListNode* head2) {
    while(head1 != NULL && head2 != NULL) {
        if(head1->data != head2->data) {
            return false;
        }
        else {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return true;
}

bool isPalindrome(ListNode* head) {
    //break into 2 halves
    ListNode* midNode = middleNode(head);
    ListNode* head2 = midNode->next;
    midNode->next = NULL;
    //reverse second half
    ListNode* prev = NULL;
    ListNode* curr = head2;
    head2 = reverseListRec(prev, curr);
    //compare both linked list
    bool ans = compareList(head, head2);
    return ans;
}

int main() {
    return 0;
}
