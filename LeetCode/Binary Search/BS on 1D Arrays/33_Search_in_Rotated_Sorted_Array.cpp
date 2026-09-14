#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;

            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else low = mid + 1;
                    
            }
            else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        
        return ans;
    }
};

// Technique:
// Binary Search (on Rotated Sorted Array)

// Approach:
// At each step, use mid to decide which half (left or right) is sorted.
// If left half is sorted, check if target lies in [low, mid], otherwise move to right half.
// If right half is sorted, check if target lies in [mid, high], otherwise move to left half.
// Continue shrinking the range until target is found or search space becomes empty.

// TC: O(log n)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}