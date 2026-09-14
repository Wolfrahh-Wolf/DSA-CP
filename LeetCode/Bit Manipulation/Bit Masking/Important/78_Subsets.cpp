#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// More Optimal - Bit Manipulation (Bitmasking)

class Solution{
public:	
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;

        int n = nums.size();

        // (2 << n-1) => size of powerSet -> 2 ^ n
    
        for(int i = 0; i < (2 << n-1); i++){
            vector<int> subset;

            for(int j = 0; j < n; j++){
                if(i & 1 << j) subset.push_back(nums[j]);
            }

            ans.push_back(subset);
        }

        return ans;
    }
};

// Technique:
// Bit Manipulation (Bitmasking)

// Approach:
// Generate all subsets using bitmasking.
// Since a set of size N has 2^N subsets,
// iterate from 0 to (2^N - 1).
// Treat each number as a bitmask where
// the jth bit determines whether nums[j]
// belongs to the current subset.
// Build each subset and store it in the answer.

// Dry Run:
// nums => [1, 2, 3]
// n => 3
// Total Subsets => 2^3 = 8

// i = 0 => 000
// No bits set
// subset => {}

// i = 1 => 001
// Bit 0 set
// subset => {1}

// i = 2 => 010
// Bit 1 set
// subset => {2}

// i = 3 => 011
// Bit 0,1 set
// subset => {1,2}

// i = 4 => 100
// Bit 2 set
// subset => {3}

// ...
// Continue until i = 7 => 111
// subset => {1,2,3}

// TC: O(2^N × N)
// 2^N => Total subsets
// N => Checking each bit for every subset

// SC: O(2^N × N)
// 2^N => Number of subsets stored
// N => Maximum subset size

// Verdict: Optimal




// ================================================================
// Optimal Sol -  Recursion (Pick / Not Pick)

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

int main(){
    // Main Function placeholder for testing
    return 0;
}