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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        for(int i = 0; i < n; i++){
            fastPtr = fastPtr->next;
        }

        if(!fastPtr){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while(fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        ListNode* temp = slowPtr->next;
        slowPtr->next = slowPtr->next->next;
        
        delete temp;

        return head;
    }
};

// Technique:
// Slow & Fast Pointer
// Two-Pointer Gap Method

// Approach:
// Step 1 - Gap Creation: Move fast n steps ahead of slow
// Step 2 - Edge Case: If fast at end, remove head
// Step 3 - Sync Movement: Move both until fast reaches end
// Step 4 - Remove: slow->next is nth from end

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}