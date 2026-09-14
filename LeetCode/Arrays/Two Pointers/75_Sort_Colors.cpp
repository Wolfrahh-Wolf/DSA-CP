#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Technique:
// Multi-Pointer

// Algorithm: Dutch National Flag Algorithm

// Approach:
// Scan the array with three pointers (low, mid, high) and partition the elements in-place: 
// Place 0s at the start, 2s at the end, and 1s in the middle.
// Swap as needed and adjust pointers until the whole array is sorted with a single pass.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}