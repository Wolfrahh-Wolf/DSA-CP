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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firstEven = even;

        while(even && even->next){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }

        odd->next = firstEven;

        return head;
    }
};

// Technique:
// Odd-Even Position Separation

// Approach:
// Step 1 - Initialize: odd=head(1st), even=2nd, save firstEven
// Step 2 - Re-wire: odd→3rd→5th..., even→4th→6th...
// Step 3 - Connect: odd tail → firstEven head
// Step 4 - Return original head

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}