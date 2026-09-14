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
private:
    ListNode* findMiddleNode(ListNode* head) {
        if(!head|| !head->next) return head;

        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;

        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        return slowPtr;
    }

    ListNode* mergeTwoSortedSinglyList(ListNode* list1, ListNode* list2){
        // Using Stack Allocated Node for easy memory managment

        ListNode dummyNode(-1);
        ListNode* temp = &dummyNode;

        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        // Adding the last remaining element
        temp->next = list1 ? list1 : list2;

        return dummyNode.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* middle = findMiddleNode(head);

        ListNode* right = middle->next;
        middle->next = nullptr; // To give a end for left List i.e., to stop at the middle element
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoSortedSinglyList(left, right);
    }
};

// Technique:
// Merge Sort on Linked List (Slow & Fast Pointer + Merge)

// Approach:
// Step 1 - Base Case: If list has 0 or 1 node, it is already sorted.
// Step 2 - Split: Use slow-fast pointers to find middle, cut into left and right halves.
// Step 3 - Recurse: Recursively sort left and right halves independently.
// Step 4 - Merge: Merge two sorted halves using a dummyNode and linear merge procedure.

// TC: O(N log N)  // Each level merges N nodes over log N levels.
// SC: O(log N)    // Recursion stack depth for merge sort on linked list.

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}