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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int length = 1;

        ListNode* tail = head;

        while(tail->next){
            tail = tail->next;
            length++;
        }

        tail->next = head;

        ListNode* newTail = head;
        k = k % length;
        int stepsToNewTail = length - k;

        for(int i = 1; i < stepsToNewTail; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

// Technique:
// Circular Linked List + Offset Break

// Approach:
// 1. Handle edge cases:
//    - Empty list
//    - Single node
//    - k == 0
//    → Return head directly
//
// 2. Traverse once to find:
//    - Length of the list
//    - Tail node
//
// 3. Convert the list into a circular linked list:
//    tail->next = head
//
// 4. Reduce unnecessary rotations:
//    k = k % length
//
// 5. Find the new tail:
//    - Move (length - k - 1) steps from head
//
// 6. Break the circle:
//    - newHead = newTail->next
//    - newTail->next = nullptr
//
// 7. Return newHead

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}