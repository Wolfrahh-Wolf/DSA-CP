#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void func(int sum, int last, vector<vector<int>> &ans, vector<int> &nums, int &k){
        if(sum == 0 && nums.size() == k){
            ans.push_back(nums);
            return;
        }

        if(sum <= 0 || nums.size() > k) return;

        for(int i = last; i <= 9; i++){
            if(i <= sum){
                nums.push_back(i);
                func(sum-i, i+1, ans, nums, k);
                nums.pop_back();

            }
            else break;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> ans;
        vector<int> nums;

        func(n, 1, ans, nums, k);

        return ans;
    }
};

// Technique:
// Backtracking (Combinations with Constraints)

// Approach:
// Use backtracking to select numbers from 1 to 9.
// Ensure the combination size is exactly k and the sum equals n.
// At each step, pick the next number greater than the previous
// to maintain increasing order and avoid duplicates.
// Stop recursion when the sum becomes zero with k elements
// or when constraints are violated.

// TC: O(2^9) x O(K) => O(2^9 * K)
// 2^9 => Maximum subsets from numbers 1 to 9
// K   => Average length of valid combination
// SC: O(K)
// K => Recursive Stack + Current Combination Storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}