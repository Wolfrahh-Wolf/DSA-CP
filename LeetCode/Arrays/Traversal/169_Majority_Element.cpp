#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curEle;
        int cnt = 0;
        int actualCnt = 0;

        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                curEle = nums[i];
            }

            if(curEle == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        // For Verification(No need for LC)
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == curEle){
                actualCnt++;
            }
        }

        if(actualCnt > nums.size() / 2) return curEle;
        return -1; // No Need for LC
    }
};

// Algorithm: Boyer–Moore Majority Vote Algorithm

// Approach:
// Traverse the array while tracking a candidate and a vote count.
// Increase the count when you see the same element and decrease it for different ones;
// when the count hits zero, pick a new candidate.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}