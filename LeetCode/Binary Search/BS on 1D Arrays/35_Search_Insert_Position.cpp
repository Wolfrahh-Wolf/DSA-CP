#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ind = -1;
        int left = 0;
        int right = nums.size()-1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                ind = mid;
                return mid;
            }

            else if(nums[mid] < target) 
                left = mid + 1;

            else right = mid - 1;
        }

        return left;
    }
};

// Technique:
// Binary Search

// Approach:
// Perform Binary Search on the sorted array.
// If the target is found, return its index.
// Otherwise, continue narrowing the search space.
// When the search ends, the left pointer
// represents the position where the target
// should be inserted to maintain sorted order.
// Return left as the insertion index.

// TC: O(log N)
// N => Length of the array

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}
