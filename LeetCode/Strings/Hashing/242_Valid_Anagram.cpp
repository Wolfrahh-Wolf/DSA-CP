#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> hashArr(256, 0);

        for(int i = 0; i < s.size(); i++){
            hashArr[s[i]] += 1;
            hashArr[t[i]] -= 1;
        }

        for(int i = 0; i < s.size(); i++){
            if(hashArr[s[i]] != 0) return false;
        }

        return true;
    }
};

// Technique:
// Hashing (Frequency Counting)

// Approach:
// If the strings have different lengths,
// they cannot be anagrams.
// Use a frequency array to count character occurrences.
// Increment frequency for characters in the first string
// and decrement for characters in the second string.
// If all frequencies become zero,
// both strings contain identical character counts.

// TC: O(N)
// N => Length of the strings
// SC: O(1)
// Fixed-size frequency array (256)

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}