#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        map<int, int> mpp;
        mpp[0] = 1; // For counting cases where the SubArray Starts from Index o
        int xr = 0;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            xr = xr ^ arr[i];
            // 
            int x = xr ^ k; // To check previous occurrence of K
            cnt += mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};

// Technique: 
// Prefix XOR (Similar to PrefixSum)
// Hashing (map)

// Approach: 
//  Maintain a running prefix XOR (xr) while traversing the array.
//  For each index, compute x = xr ^ k; this represents the target XOR value of a required previous prefix for the subarray ending here to have XOR k.
//  Add to the count all times x has been seen before (from the map).
//  Record current prefix XOR in the map for future indices.
//  Initialize mpp[0] = 1 to count subarrays starting from the beginning.

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