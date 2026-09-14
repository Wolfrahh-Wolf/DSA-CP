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
    ListNode* addTwoNumbers(ListNode* &linkedList1, ListNode* &linkedList2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        ListNode* l1 = linkedList1;
        ListNode* l2 = linkedList2;
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = carry;

            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        
        return dummy.next;
    }
};

// Technique:
// Digit-by-Digit Addition with Carry Propagation

// Approach:
// Step 1 - Initialize: Dummy node + carry tracker + traversal pointer
// Step 2 - Sum Digits: Add current digits from both lists (if exist) + carry
// Step 3 - Create Node: New node with digit = sum % 10, update carry = sum / 10
// Step 4 - Continue: Loop until both lists exhausted AND no carry remains

// TC: O(max(N,M))  // N=len(L1), M=len(L2)
// SC: O(max(N,M))  // Output list length

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}