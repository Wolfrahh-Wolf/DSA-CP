#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n){
        long long N = n; // To Handle INT_MIN

        if(N < 0){
            N = -N;
            x = 1 / x;
        }

        double result = 1.0;

        while(N > 0){
            if(N & 1) result *= x;

            x *= x;
            N >>= 1; // N /= 2;
        }

        return result;
    }
};

// Technique:
// Binary Exponentiation (Exponentiation by Squaring)

// Approach:
// Handle negative powers by converting the base
// to its reciprocal and making the exponent positive.
// Repeatedly square the base and halve the exponent.
// If the current exponent is odd,
// multiply the result by the current base.
// Continue until the exponent becomes 0.
// Return the final computed power.

// TC: O(log N)
// N => Absolute value of exponent
// Exponent is halved in each iteration

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}