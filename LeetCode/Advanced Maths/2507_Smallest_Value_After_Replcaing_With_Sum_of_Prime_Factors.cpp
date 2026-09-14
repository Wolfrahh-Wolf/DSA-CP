#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getPrimeSum(int n){
        int primeSum = 0;

        for(int i = 2; i * i <= n; i++){ // optimization => i * i
            while(n % i == 0){
                primeSum += i;
                n /= i;
            }
        }

        if(n > 1) primeSum += n; // Edge Case for Optimization

        return primeSum;
    }

public:
    int smallestValue(int n) {
        int primeSum = getPrimeSum(n);

        while(n != primeSum){
            n = primeSum;
            primeSum = getPrimeSum(n);
        }

        return primeSum;

    }
};

// Technique:
// Prime Factorization (Simulation)

// Approach:
// Compute the sum of prime factors
// of the current number, including multiplicity.
// Replace the number with this sum.
// Repeat the process until the number becomes
// equal to the sum of its prime factors.
// Return the resulting stable value.

// TC: O(K × √N)
// K  => Number of replacement iterations
// √N => Factorization loop from 2 to root of current No

// Most Precise  : O(K × √N)
// Worst-Case UB : O(√N log N)

// SC: O(1)

// Verdict: Optimal -> For Smaller N and single inputs.

int main(){
    // Main Function placeholder for testing
    return 0;
}