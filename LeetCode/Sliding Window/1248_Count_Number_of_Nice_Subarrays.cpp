#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private: 
    int atMost(vector<int>& nums, int k){
        if(k < 0) return 0;

        int n = nums.size();

        int cnt = 0;
        int oddCnt = 0;

        int l = 0;
        int r = 0;

        while(r < n){
            if(nums[r] & 1) oddCnt++;

            while(oddCnt > k){
                if(nums[l] & 1) oddCnt--;
                l++;
            }

            if(oddCnt <= k) cnt += (r - l + 1);

            r++;
        }

        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k){
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

// Technique:
// Sliding Window
// At Most K Concept

// Approach:
// Count the number of subarrays having
// at most K odd numbers.
//
// Maintain a sliding window using two
// pointers l and r while tracking the
// number of odd elements in the current
// window.
//
// If the odd count exceeds K, shrink
// the window from the left until it
// becomes valid.
//
// For every valid window, add its length
// to the answer since all subarrays
// ending at r are valid.
//
// The number of subarrays having exactly
// K odd numbers is:
//
// At Most(K) - At Most(K - 1)

// TC: O(N)
// N => Size of the Array

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}