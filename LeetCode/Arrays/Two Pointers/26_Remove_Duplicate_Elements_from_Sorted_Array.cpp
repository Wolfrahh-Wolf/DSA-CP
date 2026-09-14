#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int newIndex = 1;

        for(int i = 1; i < n; i++){ 
            if(nums[i] != nums[newIndex - 1]){ 
                nums[newIndex] = nums[i];
                newIndex++;
            }
        }

        return newIndex;
    }
};

// Technique:
// Two-Pointer

// Approach: Traverse and find the unique elements in a Sorted Array and switch them in-place.
// Return the Unique No of Elements

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}