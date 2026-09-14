#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Optimal
// Best Fit in case of 
// Small Constraints and Low Max Value

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> primes;

        for(int num : nums){
            for(int i = 2; i * i <= num; i++){
                if(num % i == 0){
                    primes.insert(i);

                    while(num % i == 0) num /= i;
                }
            }

            if(num > 1) primes.insert(num);
        }

        return primes.size();
    }
};

// Technique:
// Prime Factorization + Set

// Approach:
// Traverse each number and extract its prime factors.
// For every divisor from 2 to √num,
// if divisible, insert the prime factor into a set
// and repeatedly divide the number to remove
// all occurrences of that factor.
// After factorization, if the remaining number
// is greater than 1, it is also a prime factor.
// Return the count of distinct prime factors stored.

// TC: O(N × √M)
// N => Number of elements
// √M => Prime factorization for each number

// SC: O(K)
// K => Distinct prime factors stored in the set

// Verdict: Optimal


// =============================================================
// Optimal

// Best Fit in case of 
// Many prime factorizations
// Large max value
// Repeated prime queries

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> SPF(maxi + 1, 1);

        for(int i = 2; i <= maxi; i++){
            if(SPF[i] == 1){
                SPF[i] = i;

                for(long long j = i * i; j <= maxi; j += i){
                    if(SPF[j] == 1) SPF[j] = i;
                }
            }
        }

        set<int> primes;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];

            while(num != 1){
                primes.insert(SPF[num]);
                num /= SPF[num];
            }
        }

        return primes.size();
    }
};


// Technique:
// Sieve of Eratosthenes (Smallest Prime Factor - SPF)

// Approach:
// Precompute the smallest prime factor (SPF)
// for every number up to the maximum element.
// For each prime number, mark it as its own SPF
// and assign it as the smallest prime factor
// for its multiples.
// Traverse each number in nums and repeatedly
// divide using SPF to extract prime factors.
// Store distinct prime factors in a set.
// Return the count of unique prime factors.

// TC: O(M log(log M)) + O(N log M)
// M => Maximum element in nums for SPF computation
// N => Number of elements
// O(log M) => Factorization using SPF for each number

// SC: O(M + K)
// M => SPF array storage
// K => Distinct prime factors stored in set

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}