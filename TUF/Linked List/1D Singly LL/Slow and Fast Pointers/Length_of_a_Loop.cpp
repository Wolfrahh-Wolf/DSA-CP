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
private:
    int findLoopLength(ListNode *slowPtr, ListNode *fastPtr){
        int cnt = 1;
        slowPtr = slowPtr->next;

        while(slowPtr != fastPtr){
            cnt++;
            slowPtr = slowPtr->next;
        }

        return cnt;
    }

public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(fastPtr && fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr) return findLoopLength(slowPtr, fastPtr);
        }

        return 0;
    }
};

// Technique:
// Slow & Fast Pointer
// Floyd's Cycle Detection

// Approach:
// Step 1 - Loop Detection: Slow moves 1 step, fast moves 2 steps until they collide in cycle
// Step 2 - Length Detection: From collision point, traverse one full loop back to same node while counting
// Loop size = count of nodes in complete cycle traversal

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}