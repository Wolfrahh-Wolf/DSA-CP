#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i){
        return n & (1 << i);
    }
};

// Technique:
// Bit Manipulation

// Approach:
// Create a bitmask by left shifting 1 to the ith position.
// Perform bitwise AND between n and the bitmask.
// If the result is non-zero, the ith bit is set;
// otherwise, it is unset.

// Dry Run:
// n      => 0110
// i      => 2
// 1 << i => 0100

// n & (1 << i)

//   0110
// & 0100
// -------
//   0100
// -------

// Result != 0
// Hence, ith bit is set.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}