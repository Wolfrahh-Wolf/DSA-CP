#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(sum, maxi);

            if(sum < 0) sum = 0;
        }
        
        return maxi;
    }
};

// Algorithm: Kadence's Algorithm - Maximum Subarray Sum

// Technique:
// Kadane's Algorithm

// Approach:
// Maintain the maximum subarray sum
// ending at the current index.
//
// Add the current element to the
// running sum and update the maximum.
//
// If the running sum becomes
// negative, discard it and start a
// new subarray from the next element.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}