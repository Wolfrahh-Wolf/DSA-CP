#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBits(int n){
        int cnt = 0;

        while(n){
            n &= n - 1;
            cnt++;

        }

        return cnt;
    }
};

// Algorithm:
// Brian Kernighan's Algorithm
// => Removes the rightmost set bit in each iteration.

// Technique:
// Bit Manipulation (Brian Kernighan's Algorithm)

// Approach:
// Repeatedly remove the rightmost set bit
// using n &= (n - 1).
// Each operation removes exactly one set bit.
// Count the number of iterations performed,
// which gives the total number of set bits.

// Dry Run:
// n => 13 => 1101

// Step 1:
// n - 1 => 1100

//   1101
// & 1100
// -------
//   1100
// -------

// Step 2:
// n - 1 => 1011

//   1100
// & 1011
// -------
//   1000
// -------

// Step 3:
// n - 1 => 0111

//   1000
// & 0111
// -------
//   0000
// -------

// Total Set Bits = 3

// TC: O(No of Set Bits)
// Each iteration removes one set bit

// SC: O(1)

// Verdict: Optimal


// ===================================
// Better Sol => Manual Traversal

class Solution {
public:
    int countSetBits(int n){
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            if(n & 1 << i) cnt++;
        }

        return cnt;
    }
};

// Technique:
// Bit Manipulation

// Approach:
// Traverse all 32 bit positions.
// Create a bitmask by left shifting 1 to the current position.
// Perform bitwise AND between n and the bitmask.
// If the result is non-zero, increment the set bit count.

// Dry Run:
// n => 13 => 1101

// i = 0
// 1 << 0 => 0001

//   1101
// & 0001
// -------
//   0001
// -------
// Set bit found, cnt++

// i = 1
// 1 << 1 => 0010

//   1101
// & 0010
// -------
//   0000
// -------
// No set bit

// i = 2
// 1 << 2 => 0100

//   1101
// & 0100
// -------
//   0100
// -------
// Set bit found, cnt++

// i = 3
// 1 << 3 => 1000

//   1101
// & 1000
// -------
//   1000
// -------
// Set bit found, cnt++

// Total Set Bits = 3

// TC: O(1)
// SC: O(1)

// Verdict: Better

int main(){
    // Main Function placeholder for testing
    return 0;
}