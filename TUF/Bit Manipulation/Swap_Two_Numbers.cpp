#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

// Technique:
// Bit Manipulation (XOR Swap)

// Approach:
// Use XOR operation to swap two numbers
// without using an extra variable.
// First XOR stores combined information.
// Second XOR restores the original first value.
// Third XOR restores the original second value.

// Dry Run:
// a => 5 => 0101
// b => 3 => 0011

// Step 1:
// a = a ^ b

//   0101
// ^ 0011
// -------
//   0110

// a => 0110
// b => 0011

// Step 2:
// b = a ^ b

//   0110
// ^ 0011
// -------
//   0101

// a => 0110
// b => 0101

// Step 3:
// a = a ^ b

//   0110
// ^ 0101
// -------
//   0011

// a => 0011 (3)
// b => 0101 (5)

// Values swapped successfully.

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}