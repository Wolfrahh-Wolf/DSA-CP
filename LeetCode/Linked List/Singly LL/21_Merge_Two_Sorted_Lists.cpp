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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }

        if(list1) temp->next = list1;
        if(list2) temp->next = list2;

        return dummy.next;  
    }
};

// Technique:
// Linked List (Iterative Merge)

// Approach:
// Create a dummy node to simplify list construction.
// Compare the current nodes of both sorted lists.
// Attach the smaller node to the merged list
// and move the corresponding pointer forward.
// Continue until one list is exhausted.
// Append the remaining nodes of the non-empty list.
// Return the merged list starting from dummy.next.

// TC: O(N + M)
// N => Length of list1
// M => Length of list2

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}