#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private: 
    int maxSum(vector<int>& nums, int& n){
        int maxi = INT_MIN;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxi = max(sum, maxi);

            if(sum < 0) sum = 0;
        }
        
        return maxi;
    }

    int minSum(vector<int>& nums, int& n){
        int mini = INT_MAX;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
            mini = min(sum, mini);

            if(sum > 0) sum = 0;
        }
        
        return mini;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums){
        int n = nums.size();

        int maxxSum = maxSum(nums, n);
        int minnSum = minSum(nums, n);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(maxxSum < 0) return maxxSum;
        return max(maxxSum, totalSum - minnSum);
    }
};

// Technique:
// Kadane's Algorithm
// Prefix/Suffix Insight

// Intuition:
// [MAX PREFIX] [MIN SUBARRAY] [MAX SUFFIX]
//      ↑             ↑              ↑
//    keep          remove          keep

// Approach:
// Find both the maximum and minimum
// subarray sums using Kadane's Algorithm.
//
// A circular maximum subarray can be
// of two types:
//
// 1. Normal subarray:
//    maxSum
//
// 2. Circular subarray:
//    Total Sum - minSum
//
// The second case removes the minimum
// subarray from the middle, leaving
// the maximum possible prefix + suffix.
//
// If all elements are negative,
// totalSum - minSum becomes 0, which
// represents an empty subarray. Hence,
// directly return maxSum in that case.

// TC: O(N)

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}