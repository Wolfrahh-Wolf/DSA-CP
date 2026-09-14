#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2 < n1) return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1; // Size of Smallest Array

        while (low <= high){
            int mid = low + (high - low) / 2;

            int cut1 = mid;
            int cut2 = ((n1 + n2 + 1) / 2) - cut1; // Floor Division

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if(l1 <= r2 && l2 <= r1){
                if((n1 + n2) % 2 == 0){
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else return max(l1, l2);
            }

            else if(l1 > r2) high = mid - 1;
            else low = mid + 1;
        }

        return 0.0;
    }
};

// Technique:
// BS – Binary Search on Partition

// Approach:
// Always perform binary search on the smaller array.
// Partition both arrays such that the total elements on the left
// side equals half of the combined length.
// Ensure the partition is valid by checking left-max ≤ right-min
// across both arrays.
// Once a valid partition is found, compute the median based on
// total length being even or odd.

// TC: O(log N)
// N => Size of the smaller array
// SC: O(1)

// Verdict: Optimal

// Cut Intuition
// int cut1 = mid;
// int cut2 = ((n1 + n2 + 1) / 2) - cut1;

// Both Sides should have equal No of Elems nad it should be equal to half of the total No of elems in both,
// If total is 11 and cut1 took value 2, the left side nums2 should have totalHalf - cut1 No of Elems.
 
/*
Example:

nums1 = [1, 3, 8, 9]
nums2 = [2, 4, 5, 6, 7, 10, 11]

Total Elements = 11

cut1 = 2
cut2 = ((11 + 1) / 2) - 2
     = 4

nums1: [1, 3 | 8, 9]
             ^
           cut1

nums2: [2, 4, 5, 6 | 7, 10, 11]
                   ^
                 cut2


Visual Representation

 Left Side | Right Side
      1, 3 | 8, 9
2, 4, 5, 6 | 7, 10, 11

l1 = 3   r1 = 8
l2 = 6   r2 = 7

Check:
l1 <= r2  => 3 <= 7  ✓
l2 <= r1  => 6 <= 8  ✓

Valid Partition

Median = max(l1, l2)
       = max(3, 6)
       = 6
*/

int main(){
    // Main Function placeholder for testing
    return 0;
}
