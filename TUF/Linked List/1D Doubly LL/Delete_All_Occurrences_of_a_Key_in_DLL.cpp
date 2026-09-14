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
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp = head;

        while(temp){
            if(temp->val == target){
                if(temp == head){
                    head = temp->next;
                }
                
                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->prev;

                if(nextNode) nextNode->prev = prevNode;
                if(prevNode) prevNode->next = nextNode;

                delete temp;
                temp = nextNode;
            }

            else temp = temp->next;
        }

        return head;
    }
};

// Technique:
// Doubly Linked List Traversal

// Approach:
// Traverse the doubly linked list node by node.
// Whenever a node contains the target value:
// - Update the head if the node is the first node.
// - Connect its previous and next nodes.
// - Delete the current node.
// - Continue traversal from the next node.
//
// If the current node does not contain the target,
// simply move to the next node.
// Return the updated head of the list.

// TC: O(N)
// N => Number of nodes in the linked list

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}