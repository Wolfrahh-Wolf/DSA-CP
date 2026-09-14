#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int rightSum = 0;

        for(int num : nums)
            rightSum += num;

        int leftSum = 0;

        for(int i = 0; i < n; i++){
            rightSum -= nums[i];

            ans[i] = abs(leftSum - rightSum);

            leftSum += nums[i];
        }

        return ans;
    }
};

// Technique:
// Prefix Sum (Running Left and Right Sums)

// Approach:
// Compute the total sum of the array,
// which initially represents the right sum.
// Traverse the array once.
// Remove the current element from the right sum.
// Compute the absolute difference between
// the current left sum and right sum.
// Store the result in the answer array.
// Add the current element to the left sum
// and continue for all indices.

// TC: O(N)
// N => Length of the array

// SC: O(1)
// Excluding output array

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}