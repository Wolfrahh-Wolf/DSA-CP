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
private:
    ListNode* getKthNode(ListNode* curr, int k){
        while(curr && k > 0){
            curr = curr->next;
            k--;
        }

        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;
        
        while(true){
            ListNode* kthNode = getKthNode(groupPrev, k);
            if(!kthNode) break; // Edge Case: nullptr

            ListNode* groupNext = kthNode->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            for(int i = 0; i < k; i++){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            } 

            ListNode* temp = groupPrev->next;
            groupPrev->next = kthNode;
            groupPrev = temp;
        }

        return dummy.next;
    }
};

// Technique:
// Linked List + Iterative Reversal

// Approach:
// Process the linked list in groups of K nodes.
// For each group:
// - Find the K-th node from the current position.
// - If fewer than K nodes remain, stop.
// - Reverse the current group using standard
//   linked list reversal.
// - Connect the reversed group with the
//   previous and next parts of the list.
// Move to the next group and repeat.
// Return the modified head of the list.

// TC: O(N)
// N => Number of nodes in the linked list
// Each node is visited a constant number of times

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}