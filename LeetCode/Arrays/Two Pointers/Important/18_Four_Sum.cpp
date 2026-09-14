#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // Skipping Duplicates

            for(int j = i + 1; j < nums.size(); j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skipping Duplicates

                int k = j + 1;
                int l = nums.size() - 1;

                while(k < l){
                    // Long Long top avoid Integer Overflow Err
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if(sum < target)      k++;
                    else if(sum > target) l--;
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);

                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k-1]) k++; // Skipping Duplicates
                        while(k < l && nums[l] == nums[l+1]) l--; // Skipping Duplicates
                    }
                }
            }
            
        }
        return ans;
    }
};

// Technique:
// Sorting
// Two-Pointer (k & l) 

// Approach:
// Sort the input array to facilitate duplicate skipping and two-pointer traversal.
// Use two nested loops to fix the first two numbers.
// Use two pointers (k and l) to find pairs that sum to the remaining target value (target - nums[i] - nums[j]).
// Skip duplicates for i, j, k, and l to avoid repeated quadruplets.
// Add valid quadruplets to the answer list.

// TC: O(N^3)
// SC: O(1) (Excluding Output Space)
// or
// O(M) => Output Return, where M is the No. of Unique Quadruplets

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}