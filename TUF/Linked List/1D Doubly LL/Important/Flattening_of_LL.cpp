#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Definition of special linked list:
struct ListNode{
    int val;
    ListNode *next;
    ListNode *child;

    ListNode(){
        val = 0;
        next = NULL;
        child = NULL;
    }

    ListNode(int data1){
        val = data1;
        next = NULL;
        child = NULL;
    }

    ListNode(int data1, ListNode *next1, ListNode* next2){
        val = data1;
        next = next1;
        child = next1;
    }
};

class Solution{
private:
    ListNode* mergeList(ListNode* list1, ListNode* list2){
        ListNode dummy(-1);
        ListNode* newList = &dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                newList->child = list1;
                newList = list1;
                list1 = list1->child;
            }
            else{
                newList->child = list2;
                newList = list2;
                list2 = list2->child;
            }
        }

        if(list1) newList->child = list1;
        else newList->child = list2;

        return dummy.child;
    }

public:
    ListNode* flattenLinkedList(ListNode* &head) {
        if(!head || !head->next) return head;

        ListNode* mergeHead = flattenLinkedList(head->next);
        head =  mergeList(head, mergeHead);

        return head;
    }
};

// Technique:
// Recursive Post-order Flattening + Merge

// Approach:
// Recursively flatten the tail first (post-order traversal).
// Merge current head with already-flattened tail using mergeList.
// mergeList creates sorted chain by comparing node values and linking via child pointers.

// TC: O(N log N) - Merge cost at each level
// SC: O(H) - Recursion depth (H = max tree depth)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}