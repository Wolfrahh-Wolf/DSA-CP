#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;
        string ans = "";

        for(char num : nums){
            while(k && !st.empty() && st.top() > num){
                st.pop();
                k--;
            }

            st.push(num);
        }

        while(!st.empty() && k--) st.pop();

        while(!st.empty()){ // Efficient Way, cancat will lead to Mem Overflow
            ans.push_back(st.top());
            st.pop();
        }

        while(ans.size() > 0 && ans.back() == '0') ans.pop_back();

        reverse(ans.begin(), ans.end());

        if(!ans.size()) return "0";
        
        return ans;
    }
};

// Technique:
// Monotonic Stack (Greedy)

// Approach:
// Traverse the digits from left to right.
// Maintain a monotonic increasing stack.
// If the current digit is smaller than the top
// of the stack, remove larger digits while
// removals are still available.
// This ensures that larger digits appearing
// before smaller digits are removed first,
// producing the smallest possible number.
// If removals remain after traversal,
// remove digits from the end.
// Construct the final number from the stack.
// Remove leading zeros.
// If the resulting string becomes empty,
// return "0".

// TC: O(N)
// N => Length of the number
// Each digit is pushed and popped at most once

// SC: O(N)
// N => Stack storage + Result string

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}