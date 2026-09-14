#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;

        return n; // if(n % 4 == 0)
    }

public:
    int findRangeXOR(int l,int r){
        return XORtillN(l-1) ^ XORtillN(r);
    }
};

// Technique:
// Bit Manipulation (XOR Properties)

// Approach:
// Use the repeating XOR pattern from 1 to N.
// XOR from 1 to N repeats every 4 numbers:
// N % 4 == 0 -> N
// N % 4 == 1 -> 1
// N % 4 == 2 -> N + 1
// N % 4 == 3 -> 0
// Compute XOR from 1 to (l - 1) and XOR from 1 to r.
// XORing both gives XOR of the range [l, r].

// Dry Run:
// l => 3
// r => 6

// XOR(1 to l - 1)
// 1 ^ 2
// = 3

// XOR(r)
// 1 ^ 2 ^ 3 ^ 4 ^ 5
// = 1

// Range XOR:
// XOR(1 to r) ^ XOR(1 to l - 1)
// (1 ^ 2) ^ (1 ^ 2 ^ 3 ^ 4 ^ 5)
// 3 ^ 4 ^ 5 = 2

// Result => 2
// Hence, XOR(3 to 5) = 2

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}