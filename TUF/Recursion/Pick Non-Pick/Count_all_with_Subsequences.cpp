#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(int ind, int sum, vector<int> &nums) {
        if (sum == 0) return 1;
        if (sum < 0 || ind == nums.size()) return 0;

        return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
    }

public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};

// Technique:
// Recursion (Pick / Not Pick Counting)

// Approach:
// Use recursion to count subsequences with a given sum.
// At each index, either include the current element
// (reduce the target) or exclude it.
// If the sum becomes zero, count it as a valid subsequence.
// If the sum becomes negative or index reaches the end,
// stop that path.

// TC: O(2^N)
// N => Number of elements
// 2^N => Total subsequences explored
// SC: O(N)
// N => Recursive Stack Depth

// Verdict: Brute

int main()
{
    // Main Function placeholder for testing
    return 0;
}