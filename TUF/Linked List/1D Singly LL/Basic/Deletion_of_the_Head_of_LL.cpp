#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
public:
    int data;
    ListNode *next;

    // Constructors
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        if(head == nullptr) return nullptr;
        
        ListNode* temp = head; 

        head = head->next;

        delete temp;

        return head;
    }
};

// Technique:
// Head Node Removal

// Approach:
// Store head reference in temp. Move head pointer to next node.
// Delete original head using temp pointer. Return new head.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}