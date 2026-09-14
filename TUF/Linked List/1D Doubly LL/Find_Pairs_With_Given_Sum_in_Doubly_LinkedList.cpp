#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> ans;

        if(!head || !head->next) return ans;

        ListNode* low  = head;
        ListNode* high = head;
        
        while(high->next) high = high->next;

        while(low && high && low != high && low->val < high->val) {
            int sum = low->val + high->val;
            
            if(sum == target) {
                ans.push_back({low->val, high->val});
                low = low->next;
                high = high->prev;
            }
            else if(sum < target) low = low->next;
            else high = high->prev;
        }

        return ans;
    }
};

// Technique:
// Two Pointers (Sorted Doubly Linked List)

// Approach:
// 1. Initialize low at head, high at tail of sorted DLL
// 2. While low < high (both position AND value):
//    - sum = low.val + high.val
//    - if sum == target → record pair, move both inward
//    - if sum < target → increment low (need larger sum)
//    - if sum > target → decrement high (need smaller sum)
// 3. `low->val < high->val` ensures no duplicate/reverse pairs

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}