#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;

        int elem1 = 0;
        int elem2 = 0;
        int cnt1  = 0;
        int cnt2  = 0;

        // Finding the Majority Element
        for(int i = 0; i < nums.size(); i++){
            if(elem1 == nums[i])      cnt1++;
            else if(elem2 == nums[i]) cnt2++;

            else if(cnt1 == 0 && elem2 != nums[i]){
                elem1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && elem1 != nums[i]){
                elem2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        // Verification Part, not always necessory
        cnt1 = 0;
        cnt2 = 0;

        for(int i = 0; i<nums.size(); i++){
            if(elem1 == nums[i])      cnt1++;
            else if(elem2 == nums[i]) cnt2++;
        }
        
        if(cnt1 > (nums.size()/3)) ans.push_back(elem1);
        if(cnt2 > (nums.size()/3)) ans.push_back(elem2);

        return ans;
    } 
};

// Algorithm: Boyer–Moore Voting Algorithm

// Approach:
// Track up to two potential majority candidates and their counts.
// Traverse the array, updating candidates and counts based on matches and available slots.
// After the initial pass, verify actual counts of each candidate by traversing the array again.
// Return candidates that appear more than n/3 times.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}