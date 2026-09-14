#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int ind = arr.size();
        int low = 0;
        int high = arr.size()-1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] >= target){
                ind = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ind;
    }
};

// Lower Bound:
// The lower bound in a sorted array is the smallest index at which the value is greater than or equal to the target.
// It represents the position where the target can be inserted without violating array order.

// Technique:
// BS-Binary Search (Lower Bound)

// Approach:
// Use binary search on the sorted array to find the smallest index where the element is greater than or equal to the target.
// Narrow the search space by adjusting high when mid element meets condition, otherwise move low.
// Return the index of this lower bound or arr.size() if no such element.

// Lower Bound:
// The lower bound in a sorted array is the smallest index at which the value is greater than or equal to the target.
// It represents the position where the target can be inserted without violating array order.

// TC: O(log n)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}