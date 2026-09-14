#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& arr, int target) {
        int ind = arr.size();
        int low = 0;
        int high = arr.size()-1;

        while(low <= high){
            int mid = (low + high) / 2;
            
            if(arr[mid] > target){
                ind = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ind;
    }
};

// Upper Bound:
// The upper bound in a sorted array is the smallest index at which the value is greater than the target.
// It indicates the position where a strictly greater element can be inserted without violating order.

// Technique:
// BS - Binary Search (Upper Bound)

// Approach:
// Use binary search on the sorted array to find the smallest index where the element is strictly greater than the target.
// Narrow the search range by moving high when mid element is greater than target, otherwise move low.
// Return the index of this upper bound or arr.size() if no such element is found.

// Upper Bound:
// The upper bound in a sorted array is the smallest index at which the value is greater than the target.
// It indicates the position where a strictly greater element can be inserted without violating order.

// TC: O(log n)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}
