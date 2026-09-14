#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& nums) {
        vector<int> ans;
        int maxElem = INT_MIN;
        int n = nums.size();
        
        for(int i = n-1; i>=0; i--){
            if(nums[i] > maxElem){
                ans.push_back(nums[i]);
            }
            maxElem = max(nums[i], maxElem);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Technique:
// Array Traversal (Right-to-Left Scan)

// Approach:
// Traverse the array from right to left.
// Maintain the maximum element seen so far.
// If the current element is greater than
// the maximum element encountered on its right,
// it is a leader.
// Add such elements to the answer array.
// Update the running maximum after processing
// each element.
// Since leaders are collected in reverse order,
// reverse the answer array before returning it.

// TC: O(N)
// N => Length of the array

// SC: O(K)
// K => Number of leaders stored in the answer array

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}