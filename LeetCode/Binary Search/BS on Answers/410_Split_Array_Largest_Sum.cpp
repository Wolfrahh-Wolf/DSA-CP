#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countSubarrays(vector<int>& nums, int k, int maxSum){
        int subarrayCnt = 1;
        int total = nums[0];

        for(int i = 1; i < nums.size(); i++){
            total += nums[i];

            if(total > maxSum){
                subarrayCnt++;
                total = nums[i];
                if(subarrayCnt > k) return subarrayCnt;
            }
        }

        return subarrayCnt;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;

            int subarrayCnt = countSubarrays(nums, k, mid);

            if(subarrayCnt > k) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
};

// Technique:
// BS – Binary Search on Answer

// Approach:
// Search for the minimum possible maximum subarray sum in the range
// [max(nums), sum(nums)].
// For a given maximum sum, greedily split the array into subarrays
// such that no subarray exceeds this sum.
// Use binary search to minimize the maximum sum while keeping
// the number of subarrays ≤ k.

// TC: O(N) x O(log M) = O(N log M)
// N => Number of Elements in the Array
// M => Search Space
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}