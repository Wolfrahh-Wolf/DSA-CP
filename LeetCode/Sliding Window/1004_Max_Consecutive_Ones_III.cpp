#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestOnes(vector<int>& nums, int k){
        int n = nums.size();

        int l = 0;
        int r = 0;

        int zero = 0;
        int maxLen = INT_MIN;

        while(r < n){
            if(nums[r] == 0) zero++;

            if(zero > k){
                if(nums[l] == 0) zero--;
                l++;
            }
            
            if(zero <= k) maxLen = max(maxLen, (r - l + 1));

            r++;
        }

        return maxLen;
    }
};

// Technique:
// Sliding Window

// Approach:
// Maintain a sliding window using two
// pointers l and r.
//
// Expand the window by moving r and count
// the number of zeroes in the current window.
//
// If the zero count exceeds K, shrink the
// window from the left until the window
// becomes valid again.
//
// Update the maximum length of all valid
// windows encountered during the traversal.
//
// Return the maximum valid window length.

// TC: O(N)
// N => Size of the Array

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}