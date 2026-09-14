#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // Sorting the Array
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // Skipping the repeating element

            int j = i+1;
            int k = nums.size() - 1;

            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum < 0)      j++;
                else if(sum > 0) k--;
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);;
                    j++;
                    k--;

                    // Skipping the repeating element
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        
        return ans;
    }
};

// Technique:
// Sorting
// Two-Pointer (j & k)

// Approach:
// Sort the array.
// Traverse each element as the first element of the potential triplet.
// Skip duplicates for the first element.
// Use two pointers (left(i) and right(j)) to find pairs that sum to the negative of the first element.
// Skip duplicates of the second and third elements to avoid repeated triplets.

// TC: O(N^2)
// SC: O(1) (Excluding Output Space)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}