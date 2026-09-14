#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        if (nums.size() < 2) return -1;

        int large = INT_MIN;
        int second_large = INT_MIN;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > large) {
                second_large = large;
                large = nums[i];
            } 
            else if (nums[i] > second_large && nums[i] != large){
                second_large = nums[i];
            }
        }

        return second_large == INT_MIN ? -1 : second_large;
    }
};

// Technique:
// Traversal

// Approach:
// Maintain the largest and second largest
// elements seen so far.
// If the current element is greater than
// the largest element,
// update the second largest to the previous
// largest and update the largest.
// Otherwise, if the current element is
// greater than the second largest and
// different from the largest,
// update the second largest.
// After traversal, return the second largest
// distinct element.
// If no such element exists, return -1.

// TC: O(N)
// N => Length of the array

// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}