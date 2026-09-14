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
    bool hasCycle(ListNode *head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if(slowPtr == fastPtr) return true;
        }

        return false;
    }
};

// Algorithm:
// Tortoise and Hare

// Technique:
// Slow & Fast Pointers
// Floyd's Cycle Detection

// Approach:
// 1. Slow pointer moves 1 step, fast pointer moves 2 steps
// 2. If they meet (slow == fast), cycle exists
// 3. If fast reaches end first, no cycle

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}