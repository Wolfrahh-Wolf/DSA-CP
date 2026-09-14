#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k){
        k = k % nums.size();

        reverse((nums.end() - k), nums.end());
        reverse(nums.begin(), (nums.end() - k));
        
        reverse(nums.begin(), nums.end());
    }
};

// Technique:
// Reversal Algorithm for Array Rotation

// Approach:
// Split the given Array into 2 Hypothetical Arrays based on K value
// i.e., last K elements as 1st Array and the rest as 2nd Array.
// Reverse each of them individually once. Then, reverse the entire Array once.

// TC: O(N) ==> O(K) + O(N-K) + O(N) ≈ O(N) 
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}