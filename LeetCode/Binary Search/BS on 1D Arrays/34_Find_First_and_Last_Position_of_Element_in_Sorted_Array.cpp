#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Optimal Using C++ STL
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);

        if(lb == nums.end() || *lb != target) return {-1, -1};

        auto ub = upper_bound(nums.begin(), nums.end(), target);
        
        int first = lb - nums.begin();
        int last = ub - nums.begin() - 1;
        
        return {first, last};
    }
};

// Technique:
// BS - Binary Search
// Using C++ STL binary search utilities lower_bound and upper_bound

// Approach:
// Use lower_bound to find the first position
// Check if the element at lower_bound is actually the target to confirm presence.
// If not return{-1, -1}
// Use upper_bound to find the first position greater than target. Subtract 1 to get the last occurrence index.
// Return the pair of indices as the target's starting and ending position.

// TC: O(log n)
// SC: O(1)

// Verdict:
// Optimal
// Use of STL

// Optimal using Raw BS - Binary Search and Modular
class Solution {
public:
    int firstOccurance(vector<int>& nums, int target){
        int low, mid, high;
        int first = -1;

        low = 0;
        high = nums.size() - 1;

        while(low <= high){
            mid = (low+high) / 2;

            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return first;
    }

    int lastOccurance(vector<int>& nums, int target){
        int low, mid, high;
        int last = -1;

        low = 0;
        high = nums.size() - 1;

        while(low <= high){
            mid = (low+high) / 2;

            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target){
    
        int first = firstOccurance(nums, target);
        
        // Edge Case: No Occurance of Target in the given Array
        if(first == -1) return {-1, -1};

        int last = lastOccurance(nums, target);
        
        return {first, last};
    }
};

// Technique:
// BS - Binary Search (Modified)

// Approach:
// 1. For first occurrence:
//    - Use binary search where upon finding target, continue searching left subarray by moving high.
// 2. If target not found in first occurrence search, return {-1, -1} immediately.
// 3. For last occurrence:
//    - Use binary search where upon finding target, continue searching right subarray by moving low.
// 4. Return the pair [first_occurrence, last_occurrence].

// TC: O(log n)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}