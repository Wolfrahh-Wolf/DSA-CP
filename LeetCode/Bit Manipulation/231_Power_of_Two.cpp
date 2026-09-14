#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n){
        return n > 0 && (n & (n - 1)) == 0;
    }
};

// Technique:
// Bit Manipulation

// Approach:
// A power of 2 has exactly one set bit.
// Subtracting 1 from a power of 2 flips
// all bits after the set bit.
// Perform bitwise AND between n and (n - 1).
// If the result is 0, n contains only one set bit,
// hence it is a power of 2.
// Also ensure n > 0 since non-positive numbers
// cannot be powers of 2.

// Dry Run:
// n       => 8 => 1000
// n - 1   => 7 => 0111

// n & (n - 1)

//   1000
// & 0111
// -------
//   0000
// -------

// Result == 0
// Hence, n is a power of 2.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}