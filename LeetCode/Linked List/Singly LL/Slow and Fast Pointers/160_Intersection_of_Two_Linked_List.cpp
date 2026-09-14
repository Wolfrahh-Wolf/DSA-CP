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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;

        ListNode* tempHeadA = headA;
        ListNode* tempHeadB = headB;

        while(tempHeadA != tempHeadB){
            tempHeadA = tempHeadA->next;
            tempHeadB = tempHeadB->next;

            if(tempHeadA == tempHeadB) return tempHeadA; 

            if(!tempHeadA) tempHeadA = headB;
            if(!tempHeadB) tempHeadB = headA;
        }

        return tempHeadA; // No intersection 
    }
};

// Technique:
// Two-Pointer Race (Length Equalization)

// Approach:
// Step 1 - Dual Traversal: Both pointers move simultaneously through their lists.
// Step 2 - Length Equalization: When one reaches end, jump to other's head.
// Step 3 - Guaranteed Meeting: Either they meet at intersection OR both reach nullptr simultaneously.
//          Since, pointers both travel same distance in total i.e., N + M
// Step 4 - Intersection Found: First meeting point is intersection node.

// TC: O(N + M) 
// N=len(A)
// M=len(B)
//     Each list traversed at most twice
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}