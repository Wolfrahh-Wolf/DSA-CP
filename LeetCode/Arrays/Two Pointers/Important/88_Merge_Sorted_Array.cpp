#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Optimal Sol
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // last index of nums1's valid part
        int j = n - 1;  // last index of nums2
        int k = m + n - 1;  // last index of nums1 including extra space

        while (i >= 0 && j >=  0) {
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

// Technique:
// Two-Pointer

// Intuition:
// Traverse from the back and append elements of decresing order in the reverese direction

// Approach:
// Initialize Pointers
// i at the end of the valid part of nums
// j at the end of nums2
// k at the end of total space in nums1
// Compare elements nums1[i] and nums2[j] and insert the larger one at position k in nums1.
// Move pointers accordingly and repeat until all elements are merged.
// If elements remain in nums2, copy them to nums1.

// TC: O(m + n) — Each pointer traverses the Arrays at most once.
// SC: O(1) 

// Verdict: Optimal


// Better Sol
class Solution {
public:
    void swapIfGreater(vector<int>& nums1, int ind1, int ind2){
        if(nums1[ind1] > nums1[ind2]){
            swap(nums1[ind1], nums1[ind2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Merging
        // Appending Elements of nums2 into nums1
        for(int i = m; i<m+n; i++){
            nums1[i] = nums2[i-m];
        }

        // Sorting
        int length =  m+n;
        int gap = (length/2) + (length%2); // (length/2) + (length%2); ==> Equivalent of ceil()
 
        while(gap > 0){
            int left = 0;
            int right = left + gap;

            while(right < length){
                swapIfGreater(nums1, left, right);
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = (gap/2) + (gap%2);
        }
    }
};


// Algorithm: Shell Sort Gap Method to merge and sort the arrays in place.

// Approach:
// 1. Append all elements from nums2 into nums1 starting from index m.
// 2. Use the gap method to sort merged nums1 in-place:
// - Initialize gap size as ceiling of half the array length.
// - Compare elements at distance gap and swap if out-of-order.
// - Reduce the gap each iteration using ceiling(gap/2).
// - Continue until gap is zero (array fully sorted).

// TC: O((m+n)log(m+n)).
// O(m+n) => Work per Pass
// O(log(m+n)) => No of Passes
// SC: O(1) 

// Verdict: Better

int main(){
    // Main Function placeholder for testing
    return 0;
}

