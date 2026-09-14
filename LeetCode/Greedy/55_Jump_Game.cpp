#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > maxReach) return false;

            maxReach = max(maxReach, i + nums[i]);

            if(maxReach >= nums.size() - 1) return true;
        }

        return true;
    }
};

// Technique:
// Greedy

// Approach:
// Maintain the farthest index that
// can be reached while traversing
// the array.
//
// If the current index is beyond
// the farthest reachable index,
// reaching the last index is
// impossible.
//
// Otherwise, continuously update
// the farthest reachable index
// using the current jump length.
//
// If the farthest reachable index
// reaches or crosses the last
// index, return true.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}