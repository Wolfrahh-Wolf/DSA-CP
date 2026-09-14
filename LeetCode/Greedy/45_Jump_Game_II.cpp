#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums){
        int end = nums.size() - 1;
        int currentEnd = 0;
        int jumps = 0;
        int maxReach = 0;

        for(int i = 0; i < end; i++){
            maxReach = max(maxReach, i + nums[i]);

            if(i == currentEnd){
                jumps++;
                currentEnd = maxReach;
            }       
        }

        return jumps;
    }
};

// Technique:
// Greedy

// Approach:
// Traverse the array while
// maintaining the farthest index
// reachable within the current
// jump.
//
// Whenever the current index
// reaches the end of the current
// jump range, increment the jump
// count and extend the range to
// the farthest reachable index.
//
// Continue until the last index is
// covered.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}