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
    ListNode* findMiddleNode(ListNode* head){
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(fastPtr && fastPtr->next ){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        return slowPtr;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* firstHalf = head;
        ListNode* originalSecondHalf = reverseList(findMiddleNode(head));
        ListNode* secondHalf = originalSecondHalf;

        while(firstHalf && secondHalf ){
            if(firstHalf->val != secondHalf->val){
                originalSecondHalf = reverseList(originalSecondHalf);
                return false;
            }

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        originalSecondHalf = reverseList(originalSecondHalf);
        
        return true;
    }
};

// Technique:
// Slow-Fast Pointer
// Reverse Second Half

// Approach:
// Step 1 - Find Middle: Slow(1 step), Fast(2 steps) → slow at middle
// Step 2 - Reverse Half: Reverse second half starting from middle
// Step 3 - Compare: Traverse both halves simultaneously checking values
// Step 4 - Restore: Reverse second half back to original structure

// TC: O(2N) = > O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}