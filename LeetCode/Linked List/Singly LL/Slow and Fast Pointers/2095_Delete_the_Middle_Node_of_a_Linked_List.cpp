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

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head|| !head->next) return nullptr;

        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next->next;

        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode* temp = slowPtr->next;
        slowPtr->next = slowPtr->next->next;
        delete temp;

        return head;
    }
};

// Technique:
// Slow and Fast Pointer (Middle Deletion)

// Approach:
// Step 1 - Edge Case: If list has 0 or 1 node, return NULL as list becomes empty.
// Step 2 - Pointer Setup: slowPtr starts at head, fastPtr at head->next->next to keep slowPtr at node before middle.
// Step 3 - Locate Middle: Move slowPtr by 1 and fastPtr by 2 until fastPtr or fastPtr->next becomes NULL.
// Step 4 - Delete Node: slowPtr->next is the middle node; unlink it and free its memory.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}