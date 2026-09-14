#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool func(int ind, int sum, std::vector<int> &nums){
        if (ind == nums.size()) {
            return sum == 0;
        }
        
        return func(ind + 1, sum - nums[ind], nums) || func(ind + 1, sum, nums);
    }

public:
    bool checkSubsequenceSum(std::vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};

// Technique:
// Recursion (Pick / Not Pick)

// Approach:
// Use recursion to check if any subsequence sums to the target.
// At each index, either include the current element
// (reduce the target) or exclude it.
// When the index reaches the end, verify if the sum is zero.
// Use short-circuiting to stop early when a valid subsequence is found.

// TC: O(2^N)
// 2^N => Total subsequences explored
// SC: O(N)
// N => Recursive Stack Depth

// Verdict: Brute

int main()
{
    // Main Function placeholder for testing
    return 0;
}