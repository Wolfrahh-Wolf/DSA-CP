#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void func(int idx, int sum, vector<int>& nums, int size, vector<int>& sumSubSet){
        if(idx == size){
            sumSubSet.push_back(sum);
            return;
        }

        func(idx+1, sum + nums[idx], nums, nums.size(), sumSubSet);

        func(idx+1, sum, nums, nums.size(), sumSubSet);        
    }

public:
    vector<int> subsetSums(vector<int>& nums){
        vector<int> sumSubSet;
        func(0, 0, nums, nums.size(), sumSubSet);

        sort(sumSubSet.begin(), sumSubSet.end());

        return sumSubSet;
    }
};

// Technique:
// Recursion / Backtracking
// Pick / Non-Pick Technique

// Approach:
// For every element, make two choices:
// - Pick the current element and add it to the sum.
// - Do not pick the current element.
//
// When all elements have been processed,
// store the current subset sum.
//
// Generate sums for all possible subsets,
// sort them, and return the result.

// TC: O(2^N * N)
// N => Length of the array
// O(2^N) subsets are generated
// O(2^N log(2^N)) sorting the subset sums

// SC: O(2^N)
// Storing all subset sums
// Recursive stack depth = O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}