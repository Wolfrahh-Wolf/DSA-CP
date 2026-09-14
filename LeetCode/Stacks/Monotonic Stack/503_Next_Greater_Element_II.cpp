#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);

        stack< int> st;

        for(int i = 2 * n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }

            if(st.empty()) ans[i % n] = -1;
            else {
                ans[i % n] = st.top();
            }

            st.push(nums[i % n]);
        }

        return ans;
    }
};

// Technique:
// Monotonic Stack (Circular Next Greater Element)

// Approach:
// Traverse the array twice from right to left
// to simulate circular traversal.
// Maintain a decreasing stack storing potential
// next greater elements.
// Remove all elements smaller than or equal to
// the current element since they cannot be answers.
// The top of the stack gives the next greater element
// for the current position.
// Push the current element into the stack for future comparisons.

// TC: O(N)
// N => Number of elements
// Each element is pushed and popped at most once

// SC: O(N)
// N => Stack storage in worst case

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}