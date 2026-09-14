#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
public:
    int val;
    ListNode *next;

    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool searchKey(ListNode* head, int key) {
        if(head->val == key) return true;
        ListNode* temp = head;

        while(temp->next){
            if(temp->val == key) return true;
            temp = temp->next;
        }

        if(temp->val == key) return true;

        return false;
    }
};

// Technique:
// Linear Search Traversal in LL

// Approach:
// 1. Check head node (single node case)
// 2. Traverse until second last node using while(temp->next)
// 3. Check tail node separately (while loop misses it)

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}
