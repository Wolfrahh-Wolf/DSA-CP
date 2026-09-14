#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int left = 0;
        int right = n - 1;

        while(left <= right){
            int currentArea = min(height[left], height[right]) * (right - left);
            area = max(area, currentArea);

            if(height[left] < height[right]) left++;
            else right--;
        }

        return area;
    }
};

// Technique:
// Two-Pointers
// Greedy 

// Approach:
// Start with widest possible container (left=0, right=n-1)
// Area = min(height[left], height[right]) * width
// Move pointer of SHORTER height inward:
// - Taller height can't increase area (still limited by shorter one)
// - Shorter height might find taller partner to compensate width loss
// Continue until pointers meet, tracking maximum area

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}