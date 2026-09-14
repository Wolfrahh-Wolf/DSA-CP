#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    // Constructors
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr),  next(nullptr) {}
    ListNode(int x, ListNode* prev, ListNode* next) : data(x), prev(prev), next(next) {}
};

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        if(!head) return NULL;

        swap(head->next, head->prev);

        if(!head->prev) return head;

        // After Swapping OG Next will be current prev
        return reverseDLL(head->prev);
    }
};

// Technique:
// Recursive Pointer Swapping

// Approach:
// Swap next/prev pointers at current node. Recurse on original next (now prev).
// Base case: when original next becomes null, return new head.

// TC: O(N)
// SC: O(N) => N = Recursion Depth

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}