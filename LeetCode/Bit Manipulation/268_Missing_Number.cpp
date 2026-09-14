#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int missing = n; 

        for(int i = 0; i<n; i++){
            missing = missing ^ i ^ nums[i];
        }

        return missing;
    }
};

// Technique:
// XOR Gate Properties

// Approach:
// Using the XOR operator's properties that identical values cancel out,
// all numbers except the missing one are eliminated, leaving the missing number as the result.

// Property:
//  1) x ^ x = 0
//  2) x ^ 0 = x

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}