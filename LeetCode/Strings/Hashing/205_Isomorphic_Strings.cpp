#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hashArr1(256, 0);
        vector<int> hashArr2(256, 0);

        for(int i = 0; i < s.size(); i++){
            if(hashArr1[s[i]] != hashArr2[t[i]]) return false;

            hashArr1[s[i]] = i+1;
            hashArr2[t[i]] = i+1;            
        }

        return true;        
    }
};

// Technique:
// Hashing

// Approach:
// Maintain two hash arrays to store the
// most recent occurrence position of
// characters from both strings.
// For every index, the last seen positions
// of the current characters must match.
// If they differ, the mapping is inconsistent
// and the strings are not isomorphic.
// Otherwise, update both positions and
// continue checking all characters.

// TC: O(N)
// N => Length of the strings

// SC: O(1)
// Fixed-size hash arrays of size 256

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}