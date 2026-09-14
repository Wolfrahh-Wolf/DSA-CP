#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> mpp;
        
        for(int i = 0; i < nums.size(); i++){
            int remain = target - nums[i];

            if(mpp.find(remain) != mpp.end()){
                return{mpp[remain], i};
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};

// Technique:
// Hashing (Hash Map)

// Approach:
// Traverse the array once.
// For each element, compute the remaining value
// required to reach the target:
//
// remain = target - nums[i]
//
// Check whether the remaining value has already
// been seen in the hash map.
// If found, return the stored index and
// the current index.
// Otherwise, store the current element
// and its index in the hash map.

// TC: O(N)
// N => Length of the array

// SC: O(N)
// N => Hash map storage in the worst case

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}