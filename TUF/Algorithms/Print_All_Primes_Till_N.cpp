#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> primeTillN(int n){
        vector<int> isPrime(n+1, 1);

        vector<int> ans;

        for(long long i = 2; i <= n; i++){
            if(isPrime[i]){
                ans.push_back(i);

                for(long long j = i * i; j <= n; j += i){
                    isPrime[j] = false; 
                }
            }
        }

        return ans;
    }
};

// Technique:
// Sieve of Eratosthenes

// Approach:
// Assume all numbers are prime initially.
// Traverse from 2 to N.
// If a number is prime, add it to the answer.
// Mark all its multiples as non-prime,
// starting from i * i since smaller multiples
// are already processed.

// TC: O(N log(log N))
// N => Range till N
// Efficient multiple marking using sieve

// SC: O(N)
// N => Prime status array

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}