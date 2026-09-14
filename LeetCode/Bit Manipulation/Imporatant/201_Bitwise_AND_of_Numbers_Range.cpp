#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        while(left != right){
            left >>= 1;
            right >>= 1;
            shift++;
        }

        return left << shift;
    }
};

// Technique:
// Bit Manipulation
// Common Prefix

// Approach:
// Find the common binary prefix of
// `left` and `right`.
//
// Right shift both numbers until
// they become equal. The number of
// shifts represents the differing
// lower bits, which must become 0.
//
// Restore the common prefix by
// shifting it back to the left.

// TC: O(log N)

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}