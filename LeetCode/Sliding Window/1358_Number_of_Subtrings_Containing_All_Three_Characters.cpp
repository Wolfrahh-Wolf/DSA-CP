#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int numberOfSubstrings(string s){
        int n = s.size();
        vector<int> lastSeen(3, -1);

        int cnt = 0;

        for(int i = 0; i < n; i++){
            lastSeen[s[i] - 'a'] =  i;

            cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }

        return cnt;
    }
};

// Technique:
// Sliding Window
// Last Seen Indices

// Intuition:
// For a substring ending at index i to be valid,
// it must contain at least one 'a', one 'b',
// and one 'c'.
//
// Once all three characters have appeared,
// the character with the smallest last seen
// index becomes the limiting factor.
//
// Any starting position from 0 up to that
// minimum index will produce a valid substring
// ending at i.
//
// Therefore, the number of valid substrings
// ending at index i is:
//
// 1 + min(lastSeen['a'],
//         lastSeen['b'],
//         lastSeen['c'])

// Approach:
// Maintain the last seen indices of
// 'a', 'b', and 'c'.
//
// Traverse the string and update the
// last seen position of the current
// character.
//
// For every index, find the minimum
// among the three last seen indices.
//
// Add:
//
// 1 + minimum last seen index
//
// to the answer.
//
// Return the accumulated count.

// TC: O(N)
// N => Length of the String

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}