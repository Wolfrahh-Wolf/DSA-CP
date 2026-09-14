#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> primesInRange(vector<vector<int>>& queries){
        if(queries.empty()) return {};

        int maxi = 0;

        for(auto& query : queries){
            maxi = max(maxi, query[1]);
        }

        vector<bool> isPrime(maxi + 1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int p = 2; p * p <= maxi; p++){
            if(isPrime[p]){
                for(int multiple = p * p; multiple <= maxi; multiple += p){
                    isPrime[multiple] = false;
                }
            }
        }

        vector<int> prefixPrime(maxi + 1, 0);

        for(int i = 1; i <= maxi; i++){
            prefixPrime[i] = prefixPrime[i - 1];

            if(isPrime[i]){
                prefixPrime[i]++;
            }
        }

        vector<int> ans;

        for(auto& query : queries){
            int l = query[0];
            int r = query[1];

            if(l == 0) ans.push_back(prefixPrime[r]);
            else ans.push_back(prefixPrime[r] - prefixPrime[l - 1]);
        }

        return ans;
    }
};

// Technique:
// Sieve of Eratosthenes + Prefix Sum

// Approach:
// Find the maximum right boundary among all queries.
// Use the Sieve of Eratosthenes to precompute
// prime numbers up to that maximum value.
// Build a prefix sum array where:
//
// prefixPrime[i]
//
// stores the count of primes from 1 to i.
// For each query [l, r],
// compute the number of primes in the range
// using the prefix sum:
//
// prefixPrime[r] - prefixPrime[l - 1]
//
// Handle the case when l = 0 separately.
// Return the answer for all queries.

// TC: O(M log(log M) + Q)
// M => Maximum value among all query ranges
// Q => Number of queries

// SC: O(M)
// M => Sieve array + Prefix sum array

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}