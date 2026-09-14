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
    ListNode* middleNode(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        return slowPtr;
    }
};

// Algorithm
// Tortoise and Hare Algorithm

// Technique:
// Slow and Fast Pointer 

// Approach:
// Move fast pointer two steps and slow pointer one step at a time.
// When fast pointer reaches the end, slow pointer will be at the middle node.
// For Odd  No of Nodes => fastPtr != NULL
// For Even No of Nodes => ffastPtr->next != nullptr

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}