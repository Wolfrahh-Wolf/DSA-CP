#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> pairXor;
        unordered_set<int> tripletXor;

        for(int num : nums)
            tripletXor.insert(num);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        for(int x : pairXor){
            for(int num : nums){
                tripletXor.insert(x ^ num);
            }
        }

        return tripletXor.size();
    }
};

// Technique:
// Bit Manipulation
// Hashing

// Approach:
// Store all unique XOR values of
// every pair of elements.
//
// Every triplet XOR can be written
// as (a XOR b) XOR c.
//
// XOR each unique pair XOR with
// every element and store the
// resulting values in a hash set.
//
// Also insert every individual
// element since x XOR x XOR x = x.

// TC: O(N²)

// SC: O(N²)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}