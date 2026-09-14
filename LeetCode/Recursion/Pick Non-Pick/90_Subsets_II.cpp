#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void finSubSets(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        ans.push_back(ds);

        for(int i = idx; i < nums.size(); i++){
            if(i != idx && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            finSubSets(i+1, nums, ans, ds);
            ds.pop_back();
        }
    } 

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());

        finSubSets(0, nums, ans, ds); 

        return ans;
    }
};

// Technique:
// Backtracking + Sorting (Duplicate Skipping)

// Approach:
// Sort the array to group duplicate elements.
// Use backtracking to generate subsets starting from a given index.
// At each step, add the current subset to the answer.
// Skip duplicate elements at the same recursion level to
// avoid generating duplicate subsets.
// Recursively explore further elements and backtrack.

// TC: O(2^N * N)
// N => Number of elements
// 2^N => Total subsets generated
// SC: O(N)
// N => Recursive Stack + Current Subset Storage

// Verdict: Optimal


int main()
{
    // Main Function placeholder for testing
    return 0;
}