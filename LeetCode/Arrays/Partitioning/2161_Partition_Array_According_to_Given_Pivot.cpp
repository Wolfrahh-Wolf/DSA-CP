#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        int pivotCnt = 0;

        for(int num : nums){
            if(num == pivot) pivotCnt++;
            if(num < pivot) ans.push_back(num);
        }

        while(pivotCnt--) ans.push_back(pivot);

        for(int num : nums){
            if(num > pivot) ans.push_back(num);
        }

        return ans;
    }
};

// Technique:
// Array Partitioning

// Approach:
// Traverse the array and collect all elements
// smaller than the pivot.
// Count the occurrences of the pivot element.
// Append all pivot elements to the result.
// Traverse the array again and append all
// elements greater than the pivot.
// The relative order within each group
// is preserved.
// Return the partitioned array.

// TC: O(N)
// N => Length of the array
// Two traversals over the array

// SC: O(N)
// N => Result array storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}