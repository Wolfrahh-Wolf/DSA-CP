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
    ListNode *deleteHead(ListNode *&head) {
        if(!head->next) return NULL;

        ListNode* temp = head->next;
        head->next = nullptr;
        temp->prev = nullptr;
        
        delete head;

        return temp;
    }
};

// Technique:
// Doubly Linked List Head Removal

// Approach:
// Store next node in temp. Sever head's next link.
// Update new head's prev to nullptr. Delete original head.
// Return new head.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}