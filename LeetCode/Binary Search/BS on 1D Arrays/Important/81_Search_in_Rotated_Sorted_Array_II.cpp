#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return true;

            // Edge Case: When all pointers point to same value due to duplicates
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            // If Left Half is Sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else low = mid + 1;
                    
            }
            // If Right Half is Sorted
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        
        return false; 
    }
};

// Technique:
// BS-Binary Search (on Rotated Sorted Array with Duplicates)

// Approach:
// Use binary search with low and high pointers on the rotated sorted array possibly containing duplicates.
// When elements at low, mid, and high are equal, narrow both ends to skip duplicates.
// Otherwise, check if left half is sorted and whether target lies within it to decide the search side.
// If left half not sorted, right half is sorted, so check if target lies in right half accordingly.
// Return true if target found, else false after searching entire array.

// TC:
// O(log N) => Average
// O(N) => Worst Case due to Duplicates
// SC: O(1)

// Verdict: Optimal considering duplicates

int main(){
    // Main Function placeholder for testing
    return 0;
}