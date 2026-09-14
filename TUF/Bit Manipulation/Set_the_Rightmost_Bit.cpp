#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int setRightmostUnsetBit(int n){
    // Use bitwise OR with n+1 to set rightmost 0
    return n | (n + 1);
}

// Technique:
// Bit Manipulation

// Approach:
// Add 1 to the number to flip the rightmost unset bit
// and reset trailing set bits.
// Perform bitwise OR between n and (n + 1)
// to set the rightmost unset bit while preserving
// all existing set bits.

// Dry Run:
// n       => 10 => 1010
// n + 1   => 11 => 1011

// n | (n + 1)

//   1010
// | 1011
// -------
//   1011
// -------

// Rightmost unset bit is set.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}