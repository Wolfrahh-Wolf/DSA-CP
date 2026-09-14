#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long modPow(long long base, long long exp) {
        long long result = 1;
        long long MOD = 1e9 + 7;

        base %= MOD;

        while(exp > 0){
            if(exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }

        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7;
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        long long res = (modPow(5, evenPos) * modPow(4, oddPos)) % MOD;

        return res;
    }
};

// Technique:
// Binary Exponentiation + Modular Arithmetic

// Intuition:
// Every even index can contain:
// 0, 2, 4, 6, 8
//
// => 5 choices
//
// Every odd index can contain:
// 2, 3, 5, 7
//
// => 4 choices
//
// Using the Multiplication Principle:
//
// Total Good Numbers
// = 5^(Even Positions) × 4^(Odd Positions)
//
// Since N can be as large as 10^15,
// the powers must be computed efficiently
// using Binary Exponentiation.

// Approach:
// Count the number of even and odd positions.
// Compute:
//
// 5^(even positions)
//
// and
//
// 4^(odd positions)
//
// using Binary Exponentiation under modulo.
// Multiply both results under modulo
// and return the final answer.

// TC: O(log N)
// N => Length of the No

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}