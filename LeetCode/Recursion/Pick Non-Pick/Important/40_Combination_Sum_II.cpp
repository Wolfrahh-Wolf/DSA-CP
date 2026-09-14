#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findCombinationSum(int idx, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& ds){
            if(target == 0){
                ans.push_back(ds);
                return;
            }

            for(int i = idx; i < candidates.size(); i++){
                if(i > idx && candidates[i] == candidates[i-1]) continue;
                if(candidates[i] > target) break;
                ds.push_back(candidates[i]);

                findCombinationSum(i+1, candidates, target - candidates[i], ans, ds);
                ds.pop_back();
            }
        }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinationSum(0, candidates, target, ans, ds);
        return ans;
    }
};

// Technique:
// Recursion (Backtracking + Sorting (Duplicate Skipping))
// Pick / Skip Technique

// Approach:
// Sort the array to handle duplicates efficiently.
// Use backtracking to generate combinations without reuse of elements.
// Skip duplicate elements at the same recursion level.
// If the current element exceeds the remaining target, stop further exploration.
// Store the combination when target becomes zero.

// TC: O(2^N * K)
// N => Number of Elements
// K => Average length of valid combination
// SC: O(N)
// N => Recursive Stack + Current Combination Storage

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}