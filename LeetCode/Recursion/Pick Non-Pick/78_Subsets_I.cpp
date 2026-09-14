#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void func(int idx, vector<vector<int>>& ans, vector<int>& nums, int size, vector<int>& ds){
        if(idx == size){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        func(idx+1, ans, nums, nums.size(), ds);

        ds.pop_back();
        func(idx+1, ans, nums, nums.size(), ds);        
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        func(0, ans, nums, nums.size(), ds);

        return ans;
    }
};

// Technique:
// Recursion (Pick / Not Pick)

// Approach:
// Use recursion to generate all subsets.
// At each index, either include the current element
// in the current subset or exclude it.
// When the index reaches the end, store the formed subset.
// This explores all possible combinations using
// pick and not-pick branching.

// TC: O(2^N)
// N => Number of Elements
// 2^N => Total subsets generated
// SC: O(N)
// N => Recursive Stack + Current Subset Storage

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}