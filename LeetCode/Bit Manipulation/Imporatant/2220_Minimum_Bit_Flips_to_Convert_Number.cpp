#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:    
    int minBitFlips(int start, int goal){
        int temp = start ^ goal;

        int cnt = 0;

        while(temp){
            temp &= temp - 1;
            cnt++; // count the No of removed set Bits 
        }

        return cnt;
    }
};

// Algorithm:
// Brian Kernighan's Algorithm
// => Removes the rightmost set bit in each iteration.

// Technique:
// Bit Manipulation (XOR + Brian Kernighan's Algorithm)

// Approach:
// Perform XOR between start and goal.
// XOR gives set bits at positions where bits differ.
// Count the number of set bits using
// Brian Kernighan's algorithm by repeatedly removing
// the rightmost set bit.
// The count gives the minimum bit flips required.

// Dry Run:
// start => 10 => 1010
// goal  =>  7 => 0111

// start ^ goal

//   1010
// ^ 0111
// -------
//   1101
// -------

// Count Set Bits:

// temp => 1101
// temp &= temp - 1 => 1100

// temp => 1100
// temp &= temp - 1 => 1000

// temp => 1000
// temp &= temp - 1 => 0000

// Total Set Bits = 3
// Hence, minimum flips required = 3

// TC: O(No of Set Bits)
// Each iteration removes one set bit

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}