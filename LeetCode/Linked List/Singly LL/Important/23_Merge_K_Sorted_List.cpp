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

class Solution{
private:
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

public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        int n = lists.size();
        if(!n) return nullptr;    

        int gap = 1;

        while(gap < n){
            for(int i = 0; i < n; i += (2 * gap)){
                if(i + gap < n){
                    lists[i] = mergeTwoLists(lists[i], lists[i + gap]);
                }
            }

            gap *= 2;
        }
        
        return lists[0];
    }
};

// Technique:
// Linked List + Divide and Conquer

// Approach:
// Merge the K sorted linked lists in pairs.
// Start with a gap of 1 and merge adjacent lists.
// After each pass, double the gap size.
// Continue until all lists are merged into a single list.
// Use the mergeTwoLists function to merge
// two sorted linked lists efficiently.

// TC: O(N log K)
// N => Total nodes across all linked lists
// K => Number of linked lists
// log K => Number of merge levels

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}