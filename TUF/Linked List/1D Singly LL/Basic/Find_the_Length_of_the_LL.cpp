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
    int getLength(ListNode* head) {
        if(!head) return 0;

        int cnt = 1;
        ListNode* temp = head;

        while(temp->next){
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
};

// Technique:
// Single Pass LL Traversal

// Approach:
// Initialize count = 1 for head node. Traverse using temp pointer.
// Increment count and move temp to next->next until reaching end.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}