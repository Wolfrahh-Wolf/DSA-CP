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
    ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* newHead = new ListNode(X, nullptr, head);
        head->prev = newHead;

        return newHead;
    }
};

// Technique:
// Doubly Linked List Head Insertion

// Approach:
// Create new node with prev=nullptr, next=old head.
// Update old head's prev to point to new head.
// Return new head pointer.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}