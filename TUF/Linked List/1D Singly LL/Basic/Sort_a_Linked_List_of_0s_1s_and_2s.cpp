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
    ListNode* sortList(ListNode* &head) {
        if(!head || !head->next) return head;

        ListNode* temp = head;

        ListNode dummy0(-1);
        ListNode* zero = &dummy0;

        ListNode dummy1(-1);
        ListNode* one = &dummy1;

        ListNode dummy2(-1);
        ListNode* two = &dummy2;
        
        while(temp){
            if(temp->data == 0){
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = one->next;
            }
            else{
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }

        zero->next = dummy1.next ? dummy1.next : dummy2.next;
        one->next = dummy2.next;
        two->next = nullptr;

        return dummy0.next;
    }
};

// Technique:
// Three-Way Partitioning (Dutch National Flag Algorithm) using Dummy Nodes

// Approach:
// Step 1 - Edge Case: If 0 or 1 node, already sorted, return as is.
// Step 2 - Partition: Traverse once, attach each node to one of three lists (0, 1, 2) using dummy heads.
// Step 3 - Relink: Join 0-list → 1-list → 2-list
//          Handling missing 1s via ternary on dummy1.next i.e., link 0-list → 2-list
// Step 4 - Terminate: Set last node (two) next to nullptr and return dummy0.next as new head.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}