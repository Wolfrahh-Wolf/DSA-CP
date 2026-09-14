#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left  = 0;
        int right = n -  1;
        int waterTrapped = 0;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;

        while(left < right){
            if(height[left] <= height[right]){
                leftMax = max(leftMax, height[left]);
                waterTrapped += leftMax - height[left];
                left++;
            }
            else{
                rightMax = max(rightMax, height[right]);
                waterTrapped += rightMax - height[right];
                right--;
            }
        }

        return waterTrapped;

    }
};

// Technique:
// Two-Pointers (Optimal Space - Trapping Rain Water)

// Approach:
// Start pointers from both ends with running maximum heights
// Process the side with smaller current height (water level bottleneck):
// 1. Update running max height for that side
// 2. Add trapped water = (running_max - current_height)
// 3. Move pointer inward to find potentially taller boundary
// Repeat until pointers meet in middle

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}