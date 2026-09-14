#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums){
        int xorr = 0;

        for(int i = 0; i<nums.size(); i++){
            xorr = xorr ^ nums[i];
        }

        return xorr;
    }
};

// Technique:
// XOR Gate Properties

// Approach:
// Find the missing element using XOR Operator's Property.
// Repeating Nos will cancel and give Zero

// Property:
//  1) x ^ x = 0
//  2) x ^ 0 = x

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}