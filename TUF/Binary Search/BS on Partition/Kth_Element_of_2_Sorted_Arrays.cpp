#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int kthElement(vector<int>& a, vector<int>& b, int k){
        int m = a.size();
        int n = b.size();

        if(m > n) return kthElement(b, a, k);

        int left = k;

        int low = max(0, k - n), high = min(k, m);

        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? b[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1) return max(l1, l2);
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }

        return -1;
    }
};

// Technique:
// Binary Search on Partition

// Approach:
// Always perform binary search on the smaller array.
// Partition both arrays such that the total number
// of elements on the left side equals k.
// Let:
//
// mid1 => Elements taken from first array
// mid2 => Elements taken from second array
//
// Check whether the partition is valid:
//
// l1 <= r2
// l2 <= r1
//
// If valid, the k-th element is the maximum
// element on the left side.
// Otherwise, adjust the partition using
// binary search.
// Continue until the correct partition is found.

// TC: O(log(min(M, N)))
// M => Length of first array
// N => Length of second array
// Binary search is performed on the smaller array

// SC: O(1)

// Verdict: Optimal


int main(){
    // Main Function placeholder for testing
    return 0;
}