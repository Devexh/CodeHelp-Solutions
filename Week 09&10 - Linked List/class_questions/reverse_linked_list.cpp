#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    ListNode* head;
    ListNode* next;
};

ListNode* reverseList(ListNode* head) { //? iterative
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

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

int main() {
    return 0;
}