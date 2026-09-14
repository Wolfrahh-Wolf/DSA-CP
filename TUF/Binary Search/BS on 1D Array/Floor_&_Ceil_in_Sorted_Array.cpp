#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findFloor(vector<int>& nums, int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] <= x) {
                ans = nums[mid];
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return ans;
    }

    int findCeil(vector<int>& nums, int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= x) {
                ans = nums[mid];
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }

public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        int floor = findFloor(nums, n, x);
        int ceil = findCeil(nums, n, x);
        
        return {floor, ceil};
    }
};

// Technique:
// BS – Binary Search (Lower Bound & Upper Bound variants)

// Approach:
// Use binary search to find the floor (largest element ≤ x).
// Use binary search to find the ceil (smallest element ≥ x).
// Maintain an answer variable and update it whenever a valid
// candidate is found while narrowing the search space.

// TC: O(log N) x O(2) = O(log N)
// N => Number of elements in the array
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}