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
private:
    ListNode *findStartingPoint(ListNode* slowPtr, ListNode* fastPtr){
        while(slowPtr != fastPtr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        return slowPtr;
    }

public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr) return findStartingPoint(head, fastPtr);
        }

        return NULL;
    }
};

// Algorithm:
// Tortoise and Hare

// Technique:
// Floyd's Cycle Detection + Cycle Entry Point

// Approach:
// Step 1 => Floyd's: Find whether loop exist
// Step 2 => IF Loop Exist, Reset one pointer to head, move both (1 step) → meet at cycle start
// Math Proof: Distance(head→meet) = Distance(head→cycle_start)

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}