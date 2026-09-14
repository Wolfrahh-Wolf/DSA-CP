#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums){
        int n = nums.size();

        vector<int> ans(n);

        int left  = 0;
        int right = n - 1;

        for(int pos = n - 1; pos >= 0; pos--){
            if(abs(nums[left]) > abs(nums[right])){
                ans[pos] = nums[left] * nums[left];
                left++;
            }
            else{
                ans[pos] = nums[right] * nums[right];
                right--;
            }
        }

        return ans;
    }
};

// Technique:
// Two Pointers

// Intuition:
// The array is sorted, but squaring can
// disturb the order because negative values
// become positive.
//
// The largest square will always come from
// either the leftmost or rightmost element.

// Approach:
// Use two pointers:
//
// left  -> Start of array
// right -> End of array
//
// Compare absolute values at both ends.
//
// Place the larger square at the current
// position from the back of the answer array.
//
// Move the corresponding pointer and
// continue until all positions are filled.

// TC: O(N)

// SC: O(N)
// N => Size of the Array

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}