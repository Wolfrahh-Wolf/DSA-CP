#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
public:
    int val;
    ListNode* prev;
    ListNode* next;

    // Constructors
    ListNode() : val(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : val(x), prev(nullptr),  next(nullptr) {}
    ListNode(int x, ListNode* prev, ListNode* next) : val(x), prev(prev), next(next) {}
};

class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        if(!head || !head->next) return head;

        ListNode* current = head->next;

        while(current){
            ListNode* prevNode = current->prev;
            ListNode* currNode = current;
            ListNode* nextNode = current->next;

            if(prevNode && prevNode->val == currNode->val){
                if(prevNode) prevNode->next = nextNode;
                if(nextNode) nextNode->prev = prevNode;

                delete currNode;
            }

            current = nextNode;
        }

        return head;
    }
};

// Technique:
// Prev-Current Comparison (Sorted Doubly Linked List)

// Approach:
// Traverse from 2nd node, compare each node with its previous.
// If values match (consecutive duplicates in sorted list), bypass current node.
// Update bidirectional links: prev.next → next, next.prev → prev.
// Always advance via pre-saved nextNode pointer (crash-proof).

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}