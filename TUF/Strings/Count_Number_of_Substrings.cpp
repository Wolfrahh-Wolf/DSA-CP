#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long countSubstrings(string s){
        int n = s.size();

        unordered_map<int, long long> freq;

        long long cnt = 0;

        int mask = 0;
        freq[0] = 1;

        for(int i = 0; i < n; i++){
            mask ^= (1 << (s[i] - 'a'));   

            cnt += freq[mask];

            for(int j = 0; j <= 9; j++){
                int newMask = mask ^ (1 << j);
                cnt += freq[newMask];
            }

            freq[mask]++;            
        }
        
        return cnt;
    }
}; 

// Concept:
// Character-frequency parity
// Prefix Frequency Hash Map: A non-obvious extension of prefix sums.

// Technique:
// Bit Manipulation
// Prefix XOR
// Bitmasking
// Hash Map
// Prefix Frequency Counting

// Approach:
// Maintain a 10-bit mask representing the
// parity of character frequencies in the prefix.
//
// Toggle the corresponding bit whenever a
// character is encountered.
//
// For each position, count previous prefixes
// having the same mask (all even frequencies).
//
// Also check masks differing by exactly one bit,
// representing substrings with exactly one
// character having an odd frequency.
//
// Store the frequency of the current mask
// for subsequent prefix comparisons.

// TC: O(N)

// O(N) => Traverse the String
// O(10) => Check Masks Differing by One Bit

// SC: O(N)

// O(N) => Hash Map Storing Prefix Mask Frequencies

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}