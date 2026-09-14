#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int atMost(vector<int>& nums, int goal){
        if(goal < 0) return 0;

        int n = nums.size();

        int cnt = 0;
        int sum = 0;

        int l = 0;
        int r = 0;

        while(r < n){
            if(nums[r]) sum++;

            while(sum > goal){
                if(nums[l]) sum--;
                l++;
            }

            if(sum <= goal) cnt += (r - l + 1);

            r++;
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal){
        return atMost(nums, goal) - atMost(nums, goal - 1);
        // NOTE: At Most Concept
        // Use the atMost Intuition, when we eed to find
        // A Exact Goal by both expanding and shrinking
    }
};

// Technique:
// Sliding Window
// At Most K Concept

// Approach:
// Count the number of subarrays having
// sum at most Goal.
//
// Maintain a sliding window using two
// pointers l and r while tracking the
// current window sum.
//
// If the sum exceeds Goal, shrink the
// window from the left until it becomes
// valid.
//
// For every valid window, add its length
// to the answer since all subarrays
// ending at r are valid.
//
// The number of subarrays having sum
// exactly Goal is:
//
// At Most(Goal) - At Most(Goal - 1)

// TC: O(N)
// N => Size of the Array

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}