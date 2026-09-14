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
private:
    void addOneRecursive(ListNode *head, int &carry){
        if(head->next){
            addOneRecursive(head->next, carry);
        }

        if(carry){
            if(head->val + carry > 9){
                head->val = 0;
                carry = 1;
            }
            else{
                head->val += carry;
                carry = 0;
            }
        }
        else return;
    }

public:
    ListNode *addOne(ListNode *head) {
        if(!head) return nullptr;

        int carry = 1;

        addOneRecursive(head, carry);

        if(carry){
            ListNode *newHead = new ListNode(1, head);
            return newHead;
        }

        return head;
    }
};

// Technique:
// Post-order Recursive Digit Addition

// Approach:
// Step 1 - Post-order Traversal: Recurse to tail first (right-to-left addition)
// Step 2 - Add Carry: For each node, add carry and propagate if sum > 9
// Step 3 - Handle Overflow: If final carry remains, create new head node with 1
// Step 4 - Return: Original head (no overflow) or new head (overflow)

// TC: O(N)
// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}