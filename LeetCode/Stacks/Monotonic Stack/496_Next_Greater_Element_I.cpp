#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        unordered_map<int, int> nextGreater;
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty()){
                nextGreater[nums2[i]] = -1;
            }
            else{
                nextGreater[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(nextGreater[nums1[i]]);
        }

        return ans;
    }
};

// Technique:
// Monotonic Stack + Hashing

// Approach:
// Traverse nums2 from right to left using a decreasing stack.
// Remove smaller elements since they cannot be the next greater.
// The top of the stack gives the next greater element
// for the current number.
// Store mappings in a hash map.
// Use the map to directly build answers for nums1.

// TC: O(N + M)
// N => Size of nums2
// M => Size of nums1
// Each element is pushed and popped at most once

// SC: O(N)
// N => Stack + Hash map storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}