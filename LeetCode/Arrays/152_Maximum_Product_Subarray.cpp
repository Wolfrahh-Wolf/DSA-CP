#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double prefixPro = 1;
        double suffixPro = 1;

        double ans = INT_MIN;

        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(prefixPro == 0) prefixPro = 1;
            if(suffixPro == 0) suffixPro = 1;

            prefixPro *= nums[i];
            suffixPro *= nums[n-i-1];

            ans = max(ans, max(prefixPro, suffixPro));
        }

        return ans;
    }
};

// Technique:
// Prefix Product & Sufffix Product (Since we might encounter negative elements)

// Approach:
// Traverse the array from both left and right simultaneously to compute the product of contiguous subarrays,
// Resetting the product when encountering zero.
// Track and update the maximum product found at each index from both directions to handle negative numbers and zeros efficiently.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}