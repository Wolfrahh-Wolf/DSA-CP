#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int>& nums){
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        int index = -1;

        while (low <= high){
            int mid = low + ((high - low) / 2);
            
            if(nums[low] <= nums[mid]){
                if(nums[low] < ans){
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;
            }
            else{
                if(nums[mid] < ans){
                    index = mid;
                    ans = nums[mid];
                }
                high = mid - 1;
            }
        }

        return index;
    }

};

// Technique:
// BS – Binary Search on Rotated Sorted Array

// Approach:
// Use binary search to locate the minimum element in the rotated array.
// At each step, determine which half is sorted.
// If the left half is sorted, the minimum lies either at low or in the right half.
// Otherwise, the minimum lies in the left half.
// Track the minimum element and its index during the search.
// The index of the minimum element represents the number of rotations.

// TC: O(log N)
// SC: O(1)

// Verdict: Optimal


int main()
{
    // Main Function placeholder for testing
    return 0;
}