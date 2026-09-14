#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};

// Technique:
// Bit Manipulation

// Intuition
// XOR => Addition without carry
// AND => Carry generation
// <<1 => Move carry to next bit

// Repeat until carry becomes 0.

// Approach:
// Simulate addition without using '+' or '-'.
// XOR computes the sum of bits without carry.
// AND identifies positions where carry is generated.
// Left shift the carry to move it to the next bit position.
// Repeat until no carry remains.
// The final value of 'a' represents the sum.

// Example:
// a = 5 => 0101
// b = 3 => 0011

// Iteration 1:

// carry = (a & b) << 1

//   0101
// & 0011
// --------
//   0001
// --------

// carry = 0010

// a = a ^ b

//   0101
// ^ 0011
// --------
//   0110
// --------

// a = 0110
// b = 0010

// Iteration 2:

// carry = (0110 & 0010) << 1

//   0110
// & 0010
// --------
//   0010
// --------

// carry = 0100

// a = 0110 ^ 0010

//   0110
// ^ 0010
// --------
//   0100
// --------

// a = 0100
// b = 0100

// Iteration 3:

// carry = (0100 & 0100) << 1

//   0100
// & 0100
// --------
//   0100
// --------

// carry = 1000

// a = 0100 ^ 0100

//   0100
// ^ 0100
// --------
//   0000
// --------

// a = 0000
// b = 1000

// Iteration 4:

// carry = (0000 & 1000) << 1 = 0000

// a = 0000 ^ 1000 = 1000

// b = 0000

// Answer:
// a = 1000 => 8

// TC: O(1)
// Maximum 32 iterations for a 32-bit integer

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}