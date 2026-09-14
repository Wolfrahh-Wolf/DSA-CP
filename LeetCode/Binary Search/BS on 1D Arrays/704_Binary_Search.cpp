#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind = -1;

        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                ind = mid;
                return ind;
            }
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return ind;
    }
};

// Technique:
// Binary Search

// Approach:
// Maintain a search space using two pointers.
// Compare the middle element with the target.
// If found, return its index.
// Otherwise, discard the half that cannot
// contain the target and continue searching.
// Return -1 if the target is not present.

// TC: O(log N)
// N => Length of the array

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}