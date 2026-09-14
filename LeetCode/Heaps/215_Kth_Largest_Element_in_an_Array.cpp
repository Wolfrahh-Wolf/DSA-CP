#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> freq(20001, 0);

        for(int num : nums){
            freq[num + 10000]++;
            // NOTE: Adding 10e4 to get +ve Idx for -ve Nos
        }

        int cnt = 0;
        
        for(int i = 20000; i >= 0; i--){
            cnt  += freq[i];

            if(cnt >= k) return i - 10000; // NOTE
        }

        return -1;
    }
};

// Technique:
// Greedy
// Counting Sort
// Frequency Counting

// Approach:
// Count the frequency of every
// element using a fixed-size
// frequency array.
//
// Traverse the frequency array
// from the largest value to the
// smallest value.
//
// Keep a running count of the
// elements encountered.
//
// Return the value when the
// running count reaches K.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal (Given the Value Range Constraint)

int main(){
    // Main Function placeholder for testing
    return 0;
}