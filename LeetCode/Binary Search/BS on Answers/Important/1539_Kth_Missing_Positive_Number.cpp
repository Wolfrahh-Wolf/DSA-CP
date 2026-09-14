#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        

        while(low <= high){
            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if(missing < k) low = mid + 1;
            else high = mid - 1;
        }

        // K + low since, low will point to mid+1 after polarity reversal/crossing high
        // mid+1 => low => will be the value of a element which has 5 missing Nos preceeding to it
        return k + low;
    }
};

// Technique:
// BS – Binary Search on Index

// Approach:
// Use binary search to find the first index where the count of
// missing positive numbers is at least k.
// The number of missing positives before index mid is
// arr[mid] − (mid + 1).
// After binary search, the answer is k plus the final low index.

// TC: O(log N)
// N => Size of the array
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}