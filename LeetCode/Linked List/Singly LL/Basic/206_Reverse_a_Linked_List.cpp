#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
};

// Technique:
// Iterative Pointer Reversal

// Approach:
// 1. Use 3 pointers: prev, curr, next_temp
// 2. For each node: save next → reverse curr→next → move pointers forward
// 3. prev becomes new head when curr reaches null

// TC: O(N)
// SC: O(1)

// Verdict: Optimal


// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        ListNode* front  = head->next;

        front->next = head;
        head->next  = nullptr;

        return newHead;
    }
};

// Technique:
// Recursive Linked List Reversal

// Approach:
// 1. Use recursion to reverse from head->next to end and get newHead.
// 2. Let front = head->next, then point front->next back to head to reverse the link.
// 3. Set head->next = NULL to terminate the list correctly.
// 4. Return newHead from every call to propagate the final head upward.

// TC: O(N) 
// SC: O(N) => Recursive Stack Space

// Verdict: Optimal(Recursive)

int main(){
    // Main Function placeholder for testing
    return 0;
}