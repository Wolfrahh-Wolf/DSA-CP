#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOdd(int n) {
        return n & 1;
    }
};

// Technique:
// Bit Manipulation

// Approach:
// Perform bitwise AND between the number and 1.
// If the least significant bit (LSB) is 1,
// the number is odd.
// Otherwise, the number is even.

// Dry Run:
// n => 13 => 1101
// 1 => 0001

// n & 1

//   1101
// & 0001
// -------
//   0001
// -------

// Result != 0
// Hence, the number is odd.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}