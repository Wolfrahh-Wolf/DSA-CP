#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> divisors(int n){
        vector<int> ans;

        int sqrtN = sqrt(n);

        for(int i = 1; i <= sqrtN; i++){
            if(n % i == 0){
                ans.push_back(i);

                if(i * i != n) ans.push_back(n / i);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// Technique:
// Factor Enumeration
// Square Root Optimization

// Approach:
// Iterate from 1 to sqrt(N).
//
// Whenever a divisor i is found,
// both:
//
// i
//
// and
//
// N / i
//
// are divisors.
//
// Store both divisors while avoiding
// duplicates for perfect squares.
//
// Since divisors are collected in
// arbitrary order, sort the result
// before returning it.

// TC: O(√N log(√N))
// √N => Maximum No of divisors collected
// Sorting dominates after enumeration

// SC: O(√N)
// Storing all divisors

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}