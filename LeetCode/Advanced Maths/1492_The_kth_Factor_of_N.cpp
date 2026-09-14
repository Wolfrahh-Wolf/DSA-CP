#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Optimal
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> largestPair;

        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                k--;

                if(k == 0) return i;

                if(n / i != i) largestPair.push_back(n / i);
            }
        }

        if(n > 1) largestPair.push_back(n);

        int size = largestPair.size();

        if(size > k) return largestPair[size - k - 1];

        return -1;
    }
};

// Technique:
// Math (Factor Pair Observation)

// Approach:
// Factors of a number always occur in pairs.
//
// i × (n / i) = n
//
// Traverse only up to √N.
// Whenever a factor is found,
// decrement k.
// If k becomes 0, return the current factor.
// Store the larger paired factors separately.
// After traversal, access the remaining factors
// from the stored list in reverse order.
// If the k-th factor does not exist,
// return -1.

// TC: O(√N)
// √N => Traverse possible factors till √N

// SC: O(√N)
// √N => Store larger factor pairs

// Verdict: Optimal




// ======================================================================

// Brute
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;

        for(int i = 1; i < n; i++){
            if(n % i == 0) factors.push_back(i);
        }

        factors.push_back(n);

        int size = factors.size();

        if(k - 1 < size) return factors[k-1];

        return -1;
    }
};

// Technique:
// Math (Factor Enumeration)

// Approach:
// Traverse all numbers from 1 to n - 1.
// If a number divides n completely,
// store it as a factor.
// Add n itself as the last factor.
// If the k-th factor exists,
// return it.
// Otherwise, return -1.

// TC: O(N)
// N => Check all numbers from 1 to n

// SC: O(N)
// N => Store all factors in the worst case

// Verdict: Brute Force

int main(){
    // Main Function placeholder for testing
    return 0;
}