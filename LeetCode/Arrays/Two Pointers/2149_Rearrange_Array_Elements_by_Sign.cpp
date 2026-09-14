#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posInd = 0;
        int negInd = 1;

        for(int i = 0; i<n; i++){
            if (nums[i] > 0){
                ans[posInd] = nums[i];
                posInd += 2;
            }
            else{
                ans[negInd] = nums[i];
                negInd += 2;
            }
        }

        return ans;
    }
};

// Technique;
// Two-Pointer

// Approach:
// Iterate the input array once; every positive number goes to the next even index,
// every negative to the next odd index in the result array.

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