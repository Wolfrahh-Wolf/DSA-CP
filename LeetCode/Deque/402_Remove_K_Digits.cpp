#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string removeKdigits(string nums, int k){
        deque<char> dq;
        string ans = "";

        for(char num : nums){
            while(k && !dq.empty() && dq.back() > num){
                dq.pop_back();
                k--;
            }

            dq.push_back(num);
        }

        while(!dq.empty() && k--) dq.pop_back();

        while(!dq.empty() && dq.front() == '0') dq.pop_front();

        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }

        if(ans.empty()) return "0";
        
        return ans;
    }
};

// Technique:
// Monotonic Deque (Greedy)

// Approach:
// Maintain a monotonically increasing deque.
// For each digit, remove larger digits from
// the back while deletions are available.
// This ensures smaller digits appear earlier,
// producing the smallest possible number.
// If deletions still remain after traversal,
// remove digits from the end since they are
// the largest remaining choices.
// Remove leading zeros and construct
// the final answer string.

// TC: O(N)
// N => Length of the input string
// Each digit is inserted and removed
// at most once

// SC: O(N)
// N => Deque storage for digits

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}