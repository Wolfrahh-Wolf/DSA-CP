#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        int i = 0, j = 0; 
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums2[j] < nums1[i]) j++;
            else{ 
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
       
        return ans;
    }
};

// Technique:
// Two Pointers

// Approach:
// Maintain two pointers for the two sorted arrays.
// If the current element in nums1 is smaller,
// move the first pointer.
// If the current element in nums2 is smaller,
// move the second pointer.
// When both elements are equal,
// add the element to the answer
// and move both pointers.
// Continue until one of the arrays is exhausted.
// Return the intersection array.

// TC: O(N + M)
// N => Length of nums1
// M => Length of nums2

// SC: O(K)
// K => Size of the intersection array

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}