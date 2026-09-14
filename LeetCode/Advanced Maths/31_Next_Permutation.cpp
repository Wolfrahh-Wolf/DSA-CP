#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        for(int i = n-2; i>=0; i--){
            if(nums[i]  < nums[i+1]){
                ind = i;
                break;
            }
        }

        // Edge Case: When the given Array is in Descending Order
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i > ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
        return;
    }
};

// Algorithm: Next Lexicographical Permutation

// Approach:
// Traverse from right to left and find the first index `ind` such that
// nums[ind] < nums[ind + 1].
// If no such index exists, reverse the entire array and return.
// Traverse from the end and find the first element greater than nums[ind].
// Swap that element with nums[ind].
// Reverse the subarray from ind + 1 to the end.
// The suffix is initially in descending order; reversing it makes it
// ascending, producing the smallest possible permutation greater than
// the current one.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}