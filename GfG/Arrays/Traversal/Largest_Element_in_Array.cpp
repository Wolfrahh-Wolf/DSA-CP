#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largestElement = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > largestElement){
                largestElement = nums[i];
            }
        }

        return largestElement;
    }
};

// Technique:
// Traversal

// Approach: Just travserse the array and store the largest element in a variable and return it after the traversal.

// TC: O(N) 
// SC: O(1) 

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}