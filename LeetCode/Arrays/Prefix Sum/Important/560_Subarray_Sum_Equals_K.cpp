#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum = 0;
        int cnt = 0;
        map<int, int> mpp;
        mpp[0] = 1; // For Sequence with K = 0 

        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            
            int targetPrefixSum = preSum - k;
            cnt += mpp[targetPrefixSum]; // <=== TRICKY ===>

            mpp[preSum]++;
        }

        return cnt;
    }
};

// Technique:
// PrefixSum
// Hashmap

// Intuition:
// Use prefix sums as cumulative sums from the start of the array.
// If the difference between two prefix sums is k, it means the subarray between those indices sums to k.
// The map stores how often each prefix sum appears, allowing quick lookup of how many subarrays ending at the current index sum to k.
// By adding the frequency of (current prefix sum - k) from the map, we count all valid subarrays for the current position.

// Approach:
// Iterate through the array, keeping a running prefix sum.
// For each prefix sum, calculate the needed prefix sum (targetPrefixSum = preSum - k)
// & check how many times it appeared before.
// Accumulate counts of valid subarrays from this lookup in the map.

// TC: O(N)
// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}