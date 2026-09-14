#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> primeFactors(vector<int>& queries){
        vector<vector<int>> ans;

        int max = *max_element(queries.begin(), queries.end());

        vector<int> SPF(max + 1, 1);

        for(int i = 2; i <= max; i++){
            if(SPF[i] == 1){
                SPF[i] = i;

                for(int j = i * i; j <= max; j+=i){
                    if(SPF[j] == 1) SPF[j] = i;
                }
            }
        }

        for(int num : queries){
            vector<int> primeFact;

            while(num > 1){
                primeFact.push_back(SPF[num]);

                num /= SPF[num];
            }

            ans.push_back(primeFact);
        }

        return ans;
    }
};

// Technique:
// Sieve of Eratosthenes (Smallest Prime Factor - SPF)

// Approach:
// Precompute the smallest prime factor (SPF)
// for every number up to the maximum query value.
// For each prime number, mark it as its own SPF
// and assign it as the smallest prime factor
// for its multiples.
// For every query number, repeatedly divide
// by its SPF to extract prime factors.
// Store the prime factors of each query
// and return the final result.

// TC: O(M log(log M)) + O(Q log M)
// M => Maximum query value for SPF computation
// Q => Number of queries
// O(log M) => Prime factorization per query using SPF

// SC: O(M + Q)
// M => SPF array storage
// Q => Output storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}