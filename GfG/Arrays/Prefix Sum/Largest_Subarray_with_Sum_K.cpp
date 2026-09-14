#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Optimal Sol for Array with both +ve & -ve Elements
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
            if(sum == k){
                maxLen = max(maxLen, i+1);
            }
            
            long long rem = sum - k;
            if(preSumMap.find(rem) != preSumMap.end()){
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if(preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    }
};

// Technique:
// Prefix Sum
// Hashing (map to store prefix sums)

// Approach:
// Calculate prefix sum as you iterate.
// If prefix sum equals k, update maxLen.
// Check if (prefix sum - k) exists in the map to find previously seen prefix that helps form subarray sum k.
// Store only first occurrence of each prefix sum for max length optimization.

// TC: O(N)
// SC: O(N)
// Verdict: Optimal

// GitHub: https://github.com/yashwanth-a-ssn
// LeetCode: https://leetcode.com/u/yashwanth-a-ssn/
// CodeForces: https://codeforces.com/profile/yashwanth-a-ssn

// Verdict: Optimal Sol for Array with only +ve Elements

// ===========================================


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        long long sum = arr[0];
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int n = arr.size();
        
        while(right < n){
            while(left <= right && sum > k){
                sum -= arr[left];
                left++;
            }
            if(sum == k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
            if(right < n) sum += arr[right];
        }
        return maxLen;
    }
};

// Technique:
// Prefix Sum
// Hashing (map to store prefix sums)

// Approach:
// Calculate prefix sum as you iterate.
// If prefix sum equals k, update maxLen.
// Check if (prefix sum - k) exists in the map to find previously seen prefix that helps form subarray sum k.
// Store only first occurrence of each prefix sum for max length optimization.

// TC: O(N)
// SC: O(N)
// Verdict: Optimal

// GitHub: https://github.com/yashwanth-a-ssn
// LeetCode: https://leetcode.com/u/yashwanth-a-ssn/
// CodeForces: https://codeforces.com/profile/yashwanth-a-ssn

int main()
{
    // Main Function placeholder for testing
    return 0;
}