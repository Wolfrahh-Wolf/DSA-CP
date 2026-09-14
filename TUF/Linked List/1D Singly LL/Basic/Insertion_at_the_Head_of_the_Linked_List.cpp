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
    ListNode* insertAtHead(ListNode* &head, int X) {
        //your code goes here
        return new ListNode(X, head);
    }
};

// Technique:
// New Head Creation

// Approach:
// Create new node with value X and set its next to current head.
// Return new node as the updated head.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}