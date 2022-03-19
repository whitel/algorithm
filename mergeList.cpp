#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int val): val(val), next(nullptr) {};
    ListNode(int val, struct ListNode *next): val(val), next(next) {};
};

ListNode* createList(vector<int> arr) {
    ListNode *result = new ListNode(0);
    ListNode *head = result;

    for(const auto &x : arr) {
        ListNode *temp = new ListNode(x);
        head->next = temp;
        head = head->next;
    }
    return result->next;
}

void printList(ListNode *head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* mergeList(ListNode *headA, ListNode *headB) {
    ListNode *headC = new ListNode(0);
    ListNode *result = headC;
    while(headA && headB) {
        if(headA->val <= headB->val) {
            ListNode *temp = new ListNode(headA->val);
            headC->next = temp;
            headA = headA->next;
        } else if(headA->val > headB->val) {
            ListNode *temp = new ListNode(headB->val);
            headC->next = temp;
            headB = headB->next;
        }
        headC = headC->next;
    }
    headC = headA ? headA : headB;
    return result->next;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9};
    ListNode *headA = createList(a);
    vector<int> b = {2, 4, 6, 8, 10};
    ListNode *headB = createList(b);
    
    ListNode *headC = mergeList(headA, headB);
    printList(headC);
}
