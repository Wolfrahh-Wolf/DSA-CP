#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countPrimes(int n){
        if(n <= 2) return 0;

        vector<int> isPrime(n, 1);

        int cnt = 0;

        for(long long i = 2; i < n; i++){
            if(isPrime[i]){
                cnt++;

                for(long long j = i * i; j < n; j += i){
                    isPrime[j] = false; 
                }
            }
        }

        return cnt;
    }
};

// Algorithm:
// Sieve of Eratosthenes

// Technique:
// Sieve of Eratosthenes

// Approach:
// Assume all numbers are prime initially.
// Traverse from 2 to n - 1.
// If a number is prime, increment the count.
// Mark all its multiples as non-prime,
// starting from i * i since smaller multiples
// are already processed.
// Return the total count of primes less than n.

// TC: O(N log(log N))
// N => Range till n
// Efficient multiple marking using sieve

// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}