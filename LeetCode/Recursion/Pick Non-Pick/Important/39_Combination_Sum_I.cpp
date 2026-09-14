#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findCombinationSum(int idx, int target, vector<int>& candidates, vector<vector<int>> &ans, vector<int> &ds){
        if(idx == candidates.size()){
            if(target == 0) ans.push_back(ds); 
            return;
        }

        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            findCombinationSum(idx, target - candidates[idx], candidates, ans, ds);
            ds.pop_back();
        }

        findCombinationSum(idx+1, target, candidates, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinationSum(0, target, candidates, ans, ds);
        return ans;

    }
};

// Technique:
// Backtracking
// Pick / Skip Technique

// Approach:
// Use recursion to generate combinations by either picking
// the current element (allowing reuse) or moving to the next index.
// Reduce the target when an element is picked.
// When the target becomes zero, store the current combination.
// Explore all valid possibilities using include/exclude strategy.

// TC: O(2^T * K)
// T => Target value (recursion depth)
// K => Average length of valid combination -> Stored in the Data Structure
// SC: O(T)
// T => Recursive Stack + Current Combination Storage

// Verdict: Optimal


int main()
{
    // Main Function placeholder for testing
    return 0;
}