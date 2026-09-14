#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans;

        int low = 1;
        int high = nums.size() - 2;

        if(nums.size() == 1) return nums[0];

        if(nums[0] != nums[low]) return nums[0];
        if(nums[high] != nums[nums.size() - 1]) return nums[nums.size() - 1];

        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

            // If mid is at Even Pos
            if(mid % 2 == 0){ 
                if(nums[mid] == nums[mid+1]){
                    low = mid + 1;
                }
                else high = mid - 1;
                
            }
            else{
                if(nums[mid-1] == nums[mid]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }

        return -1;
    }
};

// Intuition:
// Pair of Elements before the Single Element will be of type (EvenIndex, OddIndex)
// Pair of Elements after the Single Element will be of type (OddIndex, EvenIndex)

// Technique:
// BS-Binary Search (Modified for Sorted Array with Unique Element Condition)

// Approach:
// Use binary search to find the single non-duplicate element in a sorted array where all other elements appear twice.
// Check edges first - if the first or the last element is unique, return it.
// For the middle elements, check if the current element is different from neighbors to identify the single element.
// Use the parity of mid index to decide which half to search next:
// Intuition => Consecute Odd and Even Pos element should be the same
// - If mid is even and nums[mid] equals nums[mid+1], unique element lies in the right half.
// - Else, it lies in the left half.
// Repeat until single element is found or indices cross.

// TC: O(log N)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}
