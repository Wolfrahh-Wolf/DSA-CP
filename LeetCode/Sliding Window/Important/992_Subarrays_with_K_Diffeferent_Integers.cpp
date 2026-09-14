#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int atMostK(vector<int>& nums, int k){
        if(k < 0) return 0;
        
        int n = nums.size();

        unordered_map<int, int> freq;

        int l = 0;
        int r = 0;

        int cnt = 0;

        while(r < n){
            freq[nums[r]]++;

            while(freq.size() > k){
                freq[nums[l]]--;
                if(!freq[nums[l]]) freq.erase(nums[l]);
                l++;
            }

            if(freq.size() <= k) cnt += (r - l+ 1);

            r++;
        }

        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

// Technique:
// Sliding Window
// At Most K Concept
// Hashing

// Approach:
// Count the number of subarrays having
// at most K distinct integers.
//
// Maintain a sliding window using two
// pointers l and r.
//
// Use a hash map to store the frequency
// of elements within the current window.
//
// Expand the window by moving r and
// include the current element.
//
// If the number of distinct elements
// exceeds K, shrink the window from
// the left until it becomes valid.
//
// For every valid window, add its length
// to the answer since all subarrays
// ending at r are valid.
//
// The number of subarrays having exactly
// K distinct integers is:
//
// At Most(K) - At Most(K - 1)

// TC: O(N)
// N => Size of the Array

// SC: O(K)
// K => Maximum Distinct Elements Stored

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}