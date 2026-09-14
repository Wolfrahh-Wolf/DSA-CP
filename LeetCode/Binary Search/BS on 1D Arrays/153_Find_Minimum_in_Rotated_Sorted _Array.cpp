#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int index;
        // Index will the be Pivot Value for Rotation or No of the Times the Array is Rotated
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = (low+high) / 2;

            // If Search Space is Sorted, then nums[low] will be the Samllest
            if(nums[low] <= nums[high]){
                if(nums[low] < ans){
                    index = low;
                    ans = nums[low];
                    return ans;
                }
            }

            // If Left part is Sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] < ans){
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1; // Shift the pointer to Unsorted Half (Right Half)
            }
            // If Right part is Sorted
            else{
                if(nums[mid] < ans){
                    index = mid;
                    ans = nums[mid];
                }
                high = mid - 1; // Shift the pointer to Unsorted Half (Left Half)
            }
        }

        return ans;
    }
};

// Technique:
// BS-Binary Search (Modified to find minimum in a rotated sorted array)

// Approach:
// Use binary search with low and high pointers.
// If the current search space is sorted (nums[low] <= nums[high]), nums[low] is the minimum in this range.
// Update answer and return immediately in this case for early stopping.
// Otherwise, identify which part (left or right) is sorted.
// Update answer with the minimum in the sorted half and search the unsorted half.
// Continue until the range is exhausted and return the minimum found.

// TC:
// O(log N) => Average Case
// O(N) => Worst Case due to Duplicates
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}