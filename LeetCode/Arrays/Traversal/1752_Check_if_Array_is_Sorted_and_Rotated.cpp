#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
class Solution {
public:
    bool check(vector<int>& nums) {
        bool status = 1;
        for(int i = 0; i < nums.size(); i++){
            status = 1;
            for(int j = 0; j < nums.size() - 1; j++){
                if(nums[(j+i) % nums.size()] > nums[((j+i+1) % nums.size())]){
                    status = 0;
                }
            }
            if(status) return true;
        }
        return false;
    }
};

// Approach: Traverse using 2 for loops, 1 for rotation and 1 for indexing.
// Mark the status flagger false if there is a decrease in value.

// Time Complexity: O(N^2)
// Space Complexity: O(1)

// Verdict: Brute Force

// OPTIMAL
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1) % n]){ 
                cnt++;
            }
            if(cnt > 1) return false;
        }
        return true;
    }
};

// Technique:
// Traversal

// Approach: Traverse once and count the No of times the element is greater than its next element.
// Return false if count is > 1.
// For sorted & rotated array nums[i] > nums[(i+1) % n] be greater than 1 only once.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}